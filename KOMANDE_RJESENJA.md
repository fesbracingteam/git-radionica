# Naredbe — rješenja zadataka

Isti koraci i brojevi kao u [ZADACI.md](ZADACI.md). Zamijeni:
- `PP` brojem para (npr. `par01-korak-1`, `topics/p01.c`)
- `NN` svojim osobnim brojem (npr. `junk_07.txt`, `ID=07`)

---

## Dan 1 — Zadatak 1

### Osoba A

1. ```bash
   gh repo clone fesbracingteam/git-radionica
   cd git-radionica
   make run
   ```
2. ```bash
   git checkout -b parPP-korak-1
   git branch
   ```
3. ```bash
   cp templates/tema.c topics/pPP.c
   ```
   Uredi `topics/pPP.c` u editoru.
4. ```bash
   make run
   ```
5. ```bash
   git status
   git add topics/pPP.c
   git commit -m "Dodaj pitanje"
   ```
6. U `registry.c` ispod oznake svog tima upiši `&topic_pPP,`, pa:
   ```bash
   git diff
   ```
7. ```bash
   git add registry.c
   git commit -m "Upisi temu u registar"
   git commit --amend -m "Upiši temu u registar"
   ```
8. ```bash
   git rm legacy/junk_NN.txt
   git commit -m "Obriši staru datoteku"
   ```
9. ```bash
   make check
   git status
   ```
   `quiz` se ne vidi jer je upisan u `.gitignore`.
10. ```bash
    git log
    git push -u origin parPP-korak-1
    ```
11. ```bash
    git pull
    git log --oneline
    make run
    ```

### Osoba B

1. ```bash
   gh repo clone fesbracingteam/git-radionica
   cd git-radionica
   make run
   ```
2. ```bash
   git fetch
   git branch -r
   ```
3. ```bash
   git checkout parPP-korak-1
   make run
   ```
4. U `topics/pPP.c` dodaj novi element niza `pitanja` ispod A-ovog:
   ```c
       {"Tvoje pitanje?",
        {"odgovor A", "odgovor B", "odgovor C", "odgovor D"}, 2},
   ```
5. ```bash
   git diff
   make run
   ```
6. ```bash
   git status
   git add topics/pPP.c
   git commit -m "Dodaj pitanje osobe B"
   ```
7. ```bash
   git rm legacy/junk_NN.txt
   git commit -m "Obriši staru datoteku"
   ```
8. ```bash
   make check
   git push
   ```

---

## Dan 2 — Zadatak 2a

### Oboje, na početku

1. ```bash
   git checkout parPP-korak-1
   git pull
   ```
2. ```bash
   git checkout -b pNN-pokus
   ```

### Osoba A

3. Promijeni nešto u `topics/pPP.c`, pa:
   ```bash
   git stash
   git status
   ```
4. ```bash
   git stash pop
   git status
   git restore topics/pPP.c
   ```
5. ```bash
   git fetch origin
   git merge origin/develop
   cat docs/okruzenja.md
   make run
   ```

### Osoba B

3. ```bash
   git fetch origin
   git rebase origin/remote
   git log --oneline --graph
   ```
4. ```bash
   make run
   ```
5. ```bash
   git log --oneline origin/hotfix
   git cherry-pick <hash commita "Popravak: postotak rezultata">
   ```
6. ```bash
   make run
   ```

### Oboje, na kraju

7. ```bash
   git checkout parPP-korak-1
   git branch -D pNN-pokus
   ```

---

## Dan 2 — Zadatak 2b

1. ```bash
   git checkout -b pNN-oops
   make scenario-oops ID=NN
   ```
2. ```bash
   git status
   git log --oneline -3
   git restore registry.c
   git restore --staged tajna_pNN.txt
   rm tajna_pNN.txt
   git reset --soft HEAD~1
   git restore --staged biljeske_pNN.txt
   rm biljeske_pNN.txt
   ```
3. ```bash
   git status
   git log --oneline -3
   make run
   ```
4. ```bash
   git checkout parPP-korak-1
   git branch -D pNN-oops
   ```

---

## Dan 2 — Zadatak 2c

### Osoba A

1. ```bash
   git checkout parPP-korak-1
   git pull
   gh pr create --base remote --fill
   gh pr checks
   ```
2. ```bash
   git switch -c parPP-korak-2
   ```
   Dodaj treće pitanje u `topics/pPP.c`, pa:
   ```bash
   make run
   ```
3. ```bash
   git commit -am "Dodaj treće pitanje"
   git push -u origin parPP-korak-2
   gh pr create --base parPP-korak-1 --fill
   ```

### Osoba B

4. ```bash
   gh pr list
   gh pr diff parPP-korak-1
   gh pr checks parPP-korak-1
   gh pr review parPP-korak-1 --approve
   gh pr diff parPP-korak-2
   gh pr review parPP-korak-2 --approve
   ```

### Osoba A

5. ```bash
   gh pr merge parPP-korak-2 --merge
   git checkout parPP-korak-1
   git pull
   make run
   ```
6. ```bash
   gh pr merge parPP-korak-1 --squash
   ```
7. Nakon što B riješi konflikt:
   ```bash
   gh pr merge parPP-korak-1 --squash
   ```

### Osoba B — samo ako je konflikt

8. ```bash
   git checkout parPP-korak-1
   git pull
   ```
9. ```bash
   git fetch origin
   git rebase origin/remote
   ```
10. Uredi `registry.c`: zadrži oba reda `&topic_...,`, obriši redove s `<<<<<<<`, `=======`, `>>>>>>>`.
11. ```bash
    make check
    make run
    git add registry.c
    git rebase --continue
    ```
12. ```bash
    git push --force-with-lease
    ```

### Oboje, na kraju

13. ```bash
    git checkout remote
    git pull
    make run
    ```
    Na pitanje o temi upiši `0` za sve teme.
