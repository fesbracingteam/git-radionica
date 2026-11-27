# Upute za voditelja

## Jednom, prije radionice

1. Na GitHubu: zadana grana je `remote` (Settings → Branches), a sudionici su suradnici s pravom pisanja.
2. Svaki sudionik javi da mu `make check` radi (ZADACI.md, „Prije radionice”).
3. Ispiši ili podijeli kartice iz `cards/`.

## Parovi i uloge

| Par | Osoba A | Osoba B | Tim |
|---|---|---|---|
| p01 | P01 | P02 | A |
| p02 | P03 | P04 | A |
| p03 | P05 | P06 | A |
| p04 | P07 | P08 | B |
| p05 | P09 | P10 | B |
| p06 | P11 | P12 | C |
| p07 | P13 | P14 | C |
| p08 | P15 | P16 | C |
| p09 | P17 | P18, P19 | D |

A stvara (grana, commitovi, push, PR-ovi, merge), B preuzima (fetch, checkout, pull, rebase, cherry-pick) i odobrava A-ove PR-ove.

## Dan 1

- **Pull demo (25–35 min):** dok sudionici gledaju, na grani `remote` dodaj u `README.md` odjeljak „Pravila kviza” (npr. „Svako pitanje ima točno jedan točan odgovor.”), pa `git commit -am "Pravila kviza"` i `git push`. Sudionici: `git fetch`, `git status` (vide da je `origin/remote` ispred), `git pull`.
- **Zaštita grane je ISKLJUČENA** cijeli dan 1, inače ne možeš gurnuti „Pravila kviza”.
- **Trojka p09:** P19 dodaje svoje pitanje tek kad P18 pošalje svoje, inače dobiju konflikt već na dan 1.
- **Kraj:** `git fetch && git branch -r` treba pokazati 9 grana `p01-korak-1` … `p09-korak-1`, svaka s commitovima obje osobe.

## Prije dana 2

Uključi zaštitu grane `remote`: obavezan PR, 1 odobrenje i zeleni CI check (`check`). Ostavi isključeno „Require branches to be up to date”, „Dismiss stale approvals” i „Require approval of the most recent push” — inače B-ov force push nakon rebasea poništi odobrenje.

## Dan 2

- **2a/2b:** ništa ne treba pripremati; `develop` i `hotfix` već postoje.
- **2c:** prozivaj parove za spajanje PR #1 redom: p01, p02, p03, p04, p05, p06, p07, p08, p09. Od drugog para u timu `registry.c` ima konflikt — to je namjerno (tim A: p02 i p03, tim B: p05, tim C: p07 i p08; tim D ima samo jedan par pa nema konflikta).
- **CI/CD (80–88 min):** pokaži `.github/workflows/ci.yml` i kartice „Checks” na PR-ovima (zeleni i crveni).

## Vraćanje repozitorija

`./reset-radionica.sh` zatvara otvorene PR-ove, briše grane parova i vraća `remote`, `develop`, `staging` i `hotfix` na tagove `pocetno-*`.

## Ako netko zapne

| Problem | Rješenje |
|---|---|
| `undefined reference to topic_pPP` | u `topics/pPP.c` nije zamijenjen `pPP` u zadnjem redu |
| `pPP nije upisan u registry.c` | nedostaje `&topic_pPP,` (sa zarezom) |
| `pitanje još sadrži TODO` | nije zamijenjen tekst iz predloška |
| B ne vidi granu para | A još nije napravio push, ili B nije napravio `git fetch` |
| push odbijen (`fetch first`) | netko iz para je već poslao: `git pull`, pa ponovno `git push` |
| push odbijen nakon rebasea | `git push --force-with-lease` |
| izgubljen u rebaseu | `git rebase --abort` i ispočetka |
