# Upute za voditelja

## Jednom, prije radionice

1. Na GitHubu: zadana grana je `remote` (Settings → Branches), a sudionici su suradnici s pravom pisanja.
2. Svaki sudionik javi da mu `make check` radi (README, „Prije radionice”).
3. Ispiši ili podijeli kartice iz `cards/`.

## Dan 1

- **Pull demo (25–35 min):** dok sudionici gledaju, na grani `remote` dodaj u `README.md` odjeljak „Pravila kviza” (npr. „Svako pitanje ima točno jedan točan odgovor.”), pa `git commit -am "Pravila kviza"` i `git push`. Sudionici: `git fetch`, `git status` (vide da je `origin/remote` ispred), `git pull`.
- **Zaštita grane je ISKLJUČENA** cijeli dan 1, inače ne možeš gurnuti „Pravila kviza”.
- **Kraj:** `git fetch && git branch -r` treba pokazati 19 grana `pNN-korak-1`.

## Prije dana 2

Uključi zaštitu grane `remote`: obavezan PR, 1 odobrenje i zeleni CI check (`check`).

## Dan 2

- **2a/2b:** ništa ne treba pripremati; `develop` i `hotfix` već postoje.
- **2c:** prati redoslijed spajanja po timovima. Od druge osobe u timu `registry.c` ima konflikt — to je namjerno.
- **CI/CD (80–88 min):** pokaži `.github/workflows/ci.yml` i kartice „Checks” na PR-ovima (zeleni i crveni).

## Parovi (tko odobrava čiji PR #1)

P01↔P02, P03↔P04, P05↔P06, P07↔P08, P09↔P10, P11↔P12, P13↔P14, P15↔P16; P18 odobrava P17, P19 odobrava P18, P17 odobrava P19.

## Ako netko zapne

| Problem | Rješenje |
|---|---|
| `undefined reference to topic_pNN` | u `topics/pNN.c` nije zamijenjen `pNN` u zadnjem redu |
| `pNN nije upisan u registry.c` | nedostaje `&topic_pNN,` (sa zarezom) |
| `pitanje još sadrži TODO` | nije zamijenio tekst iz predloška |
| push odbijen nakon rebasea | `git push --force-with-lease` |
| izgubljen u rebaseu | `git rebase --abort` i ispočetka |
