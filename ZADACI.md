# Zadaci

`NN` je uvijek tvoj broj s kartice, s dvije znamenke (npr. `07`). Tvoj tim, tema i par su na kartici u `cards/`.

---

## Dan 1 — Zadatak 1: moje pitanje (30 min)

Radiš na svojoj grani. Danas nitko ništa ne spaja.

1. Kloniraj repozitorij i pokreni kviz:
   ```bash
   gh repo clone domeepc/git-radionica
   cd git-radionica
   make run
   ```
2. Napravi svoju granu i provjeri da si na njoj:
   ```bash
   git checkout -b pNN-korak-1
   git branch
   ```
3. Napravi svoju temu i napiši jedno pitanje:
   ```bash
   cp templates/tema.c topics/pNN.c
   ```
   Uredi `topics/pNN.c` (upute su na vrhu datoteke), pa:
   ```bash
   git status
   git add .
   git commit -m "Dodaj pitanje"
   ```
4. U `registry.c` upiši `&topic_pNN,` ispod oznake svog tima i spremi commit:
   ```bash
   git add registry.c
   git commit -m "Upisi temu u registar"
   ```
   Ispravi poruku zadnjeg commita (npr. `Upisi` → `Upiši`):
   ```bash
   git commit --amend -m "Upiši temu u registar"
   ```
5. Obriši svoju staru datoteku i provjeri kviz:
   ```bash
   git rm legacy/junk_NN.txt
   git commit -m "Obriši staru datoteku"
   make check
   git status
   ```
   `make check` je izgradio datoteku `quiz`, ali je `git status` ne prikazuje — skriva je `.gitignore`.
6. Pogledaj povijest i pošalji granu na GitHub:
   ```bash
   git log
   git push -u origin pNN-korak-1
   ```

---

## Dan 2 — Zadatak 2a: spajanje grana (10 min)

Probna grana, ništa se ne šalje na GitHub.

```bash
git checkout pNN-korak-1
git checkout -b pNN-pokus
```

1. **stash** — promijeni bilo što u `topics/pNN.c`, pa:
   ```bash
   git stash          # promjena nestaje
   git status
   git stash pop      # promjena se vraća
   git restore topics/pNN.c
   ```
2. **merge** — spoji granu `develop`:
   ```bash
   git fetch origin
   git merge origin/develop
   ```
3. **rebase** — premjesti svoje commitove na vrh grane `remote`:
   ```bash
   git rebase origin/remote
   git log --oneline --graph
   ```
4. **cherry-pick** — na grani `hotfix` nađi commit „Popravak: postotak rezultata” i uzmi samo njega:
   ```bash
   git log --oneline origin/hotfix
   git cherry-pick <hash>
   make run           # rezultat sad pokazuje pravi postotak
   ```
5. Obriši probnu granu:
   ```bash
   git checkout pNN-korak-1
   git branch -D pNN-pokus
   ```

---

## Dan 2 — Zadatak 2b: poništavanje (8 min)

```bash
git checkout -b pNN-oops
make scenario-oops ID=NN
```

Skripta napravi nered i ispiše kako ga popraviti s `git restore`, `git restore --staged` i `git reset --soft HEAD~1`. Kad je `git status` čist:

```bash
git checkout pNN-korak-1
git branch -D pNN-oops
```

---

## Dan 2 — Zadatak 2c: pull requestovi (23 min)

1. **PR #1** — tvoja grana od jučer ide u `remote`. CI pokreće `make check`.
   ```bash
   git checkout pNN-korak-1
   gh pr create --base remote --fill
   ```
2. **PR #2** — druga grana, složena na prvu:
   ```bash
   git switch -c pNN-korak-2
   ```
   U `topics/pNN.c` dodaj drugo pitanje, pa:
   ```bash
   git commit -am "Dodaj drugo pitanje"
   git push -u origin pNN-korak-2
   gh pr create --base pNN-korak-1 --fill
   ```
3. Spoji PR #2 u `pNN-korak-1`, pa dohvati rezultat lokalno:
   ```bash
   gh pr merge pNN-korak-2 --merge
   git checkout pNN-korak-1
   git pull
   ```
   Tvoj par (s kartice) odobri tvoj PR #1: `gh pr review <broj> --approve`.
4. **Spajanje u `remote`**, redom unutar tima (P01, P02, …):
   ```bash
   gh pr merge pNN-korak-1 --squash
   ```
   Ako GitHub javi konflikt u `registry.c` (netko iz tvog tima je bio brži):
   ```bash
   git fetch origin
   git rebase origin/remote
   ```
   Otvori `registry.c`, zadrži **oba** reda između oznaka `<<<<<<<`, `=======`, `>>>>>>>` i obriši same oznake. Zatim:
   ```bash
   make check
   git add registry.c
   git rebase --continue
   git push --force-with-lease
   gh pr merge pNN-korak-1 --squash
   ```
