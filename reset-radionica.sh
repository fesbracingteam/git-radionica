#!/bin/bash
# SAMO ZA VODITELJA. Vraća fesbracingteam/git-radionica u početno stanje:
#   - zatvara sve otvorene PR-ove
#   - briše sve grane na GitHubu osim remote, develop, staging, hotfix
#   - vraća te četiri grane na početne commitove (force push)
#   - u ovom lokalnom klonu vraća iste četiri grane
# Početni commitovi su tagovi pocetno-remote, pocetno-develop, pocetno-staging, pocetno-hotfix.
# Novo početno stanje (npr. nakon izmjene uputa na remote) postaviš pomicanjem taga:
#   git tag -f pocetno-remote remote && git push -f origin pocetno-remote
# Spojeni PR-ovi ostaju u povijesti na GitHubu — njih nije moguće obrisati.
# Pokreni iz klona:  ./reset-radionica.sh
set -euo pipefail

REPO=fesbracingteam/git-radionica
GRANE="remote develop staging hotfix"

cd "$(dirname "$0")"
if [ -n "$(git status --porcelain --untracked-files=no)" ]; then
    echo "Lokalni klon ima nespremljene promjene. Spremi ih ili ih odbaci, pa pokreni ponovno."
    exit 1
fi

git fetch -q --prune --tags origin
POCETNO=""
for grana in $GRANE; do
    sha=$(git rev-parse -q --verify "refs/tags/pocetno-$grana^{commit}") || { echo "Nema taga pocetno-$grana."; exit 1; }
    POCETNO+="$grana $sha"$'\n'
done

visak=$(git ls-remote --heads origin | sed 's|.*refs/heads/||' | grep -vxE 'remote|develop|staging|hotfix' || true)
otvoreni=$(gh pr list -R "$REPO" --state open -L 500 --json number -q '.[].number')

echo "Repozitorij: $REPO"
echo "PR-ovi koji se zatvaraju: ${otvoreni:-(nema)}" | tr '\n' ' '; echo
echo "Grane koje se brišu na GitHubu: $(echo ${visak:-(nema)})"
echo "Grane koje se vraćaju:"; echo "$POCETNO" | sed '/^$/d; s/^/  /'
read -r -p "Upiši 'reset' za nastavak: " potvrda
[ "$potvrda" = reset ] || { echo "Odustajem."; exit 1; }

for pr in $otvoreni; do gh pr close "$pr" -R "$REPO" >/dev/null && echo "Zatvoren PR #$pr"; done
[ -z "$visak" ] || git push origin --delete $visak

refspecs=()
while read -r grana sha; do
    [ -n "$grana" ] && refspecs+=("+$sha:refs/heads/$grana")
done <<< "$POCETNO"
if ! git push origin "${refspecs[@]}"; then
    echo "Force push nije uspio. Privremeno isključi zaštitu grane 'remote' na GitHubu i pokreni ponovno."
    exit 1
fi

trenutna=$(git rev-parse --abbrev-ref HEAD)
while read -r grana sha; do
    [ -n "$grana" ] || continue
    if [ "$grana" = "$trenutna" ]; then git reset -q --hard "$sha"; else git branch -f "$grana" "$sha" >/dev/null; fi
done <<< "$POCETNO"
git fetch -q --prune origin
echo "Gotovo: repozitorij je u početnom stanju."
