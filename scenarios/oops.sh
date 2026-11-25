#!/bin/sh
# Zadatak 2b: napravi nered na tvojoj grani, a ti ga pospremi.
# Pokreni:  make scenario-oops ID=07
set -e

ID="$1"
case "$ID" in
    [0-1][0-9]) ;;
    *) echo "Upotreba: make scenario-oops ID=07   (tvoj broj s kartice, dvije znamenke)"; exit 1 ;;
esac

grana=$(git rev-parse --abbrev-ref HEAD)
case "$grana" in
    remote|develop|staging|hotfix|HEAD|*-korak-1|*-korak-2)
        echo "Ne na grani '$grana'. Prvo napravi probnu granu:"
        echo "  git checkout -b p$ID-oops"
        exit 1 ;;
esac

if [ -n "$(git status --porcelain)" ]; then
    echo "Imaš nespremljene promjene. Spremi ih (git stash) pa pokušaj ponovno."
    exit 1
fi

# 1) commit koji nije trebao nastati
echo "moje privremene bilješke, ne idu u repozitorij" > "biljeske_p$ID.txt"
git add "biljeske_p$ID.txt"
git commit -q -m "Oops: slučajno commitane bilješke"

# 2) datoteka slučajno dodana u staging
echo "lozinka=1234" > "tajna_p$ID.txt"
git add "tajna_p$ID.txt"

# 3) pokvarena datoteka u radnom direktoriju
echo "/* oops, sve je obrisano */" > registry.c

cat <<EOF

Nered je napravljen! Pogledaj ga:  git status  i  git log --oneline -3

Popravi ga, ovim redom:
  1. registry.c je pokvaren        ->  git restore registry.c
  2. tajna_p$ID.txt je u stagingu   ->  git restore --staged tajna_p$ID.txt   pa  rm tajna_p$ID.txt
  3. zadnji commit ne valja        ->  git reset --soft HEAD~1
                                      git restore --staged biljeske_p$ID.txt   pa  rm biljeske_p$ID.txt

Gotovo je kad  git status  kaže da je sve čisto, a  git log  nema "Oops" commita.
EOF
