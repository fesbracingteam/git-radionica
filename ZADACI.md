# Zadaci

Radite u **parovima**. Svaki par ima broj od `p01` do `p09`, i jednu zajedničku granu `parPP-korak-1` (PP = broj para, npr. par p01 ima granu `par01-korak-1`).

- **Osoba A** stvara: radi granu, piše, sprema commitove, šalje na GitHub, otvara i spaja PR-ove.
- **Osoba B** preuzima i dopunjuje: dohvaća A-ov rad, prebacuje se na granu para, dodaje svoje, rebasea, cherry-picka i pregledava PR-ove.

Na svojoj kartici u `cards/` imaš: svoj broj (NN, npr. `07`), broj para (PP), ulogu (A ili B) i temu.
Trojka p09 (P17, P18, P19): P17 je A, P18 i P19 su oboje B.

Nakon svake promjene **pokreni kviz** i odigraj temu svog para — tako provjeravaš da sve stvarno radi.

Ovdje piše **što** treba napraviti. Naredbe koje to rješavaju su u [KOMANDE_RJESENJA.md](KOMANDE_RJESENJA.md) — pogledaj ih tek ako zapneš.

---

## Prije radionice (oboje, kod kuće)

Trebaju ti Git, GitHub CLI (`gh`), C prevoditelj i `make`. Naredbe za instalaciju `gcc` i `make` na svim sustavima (i drugim Linux distribucijama) su u [INSTALACIJA.md](INSTALACIJA.md).

**macOS** — Xcode Command Line Tools daju `clang`, `make` i `git`; `gh` instaliraj preko Homebrewa:
```bash
xcode-select --install
brew install gh
```

**Linux (Ubuntu/Debian)** — paket `build-essential` daje `gcc` i `make`:
```bash
sudo apt update
sudo apt install build-essential git gh
```
Ako `apt` ne nađe `gh`, uputa je na https://github.com/cli/cli/blob/trunk/docs/install_linux.md

**Windows** — preporučujemo WSL s Ubuntuom, jer `make` i skripta iz zadatka 2b trebaju Unix ljusku. U PowerShellu pokrenutom kao administrator:
```powershell
wsl --install
```
Ponovno pokreni računalo, otvori aplikaciju **Ubuntu** i u njoj napravi korake za Linux. Sve naredbe na radionici upisuješ u Ubuntu terminal.

Provjeri da sve radi:
```bash
cc --version
make --version
git --version
gh --version
```

Postavi ime i e-mail i prijavi se na GitHub:
```bash
git config --global user.name "Ime Prezime"
git config --global user.email "ti@example.com"
gh auth login
gh auth status
```

Prihvati pozivnicu za repozitorij `fesbracingteam/git-radionica`, kloniraj ga i pokreni provjeru kviza. Kad vidiš `Sve u redu.`, javi voditelju.

---

## Dan 1 — Zadatak 1: pitanja para (30 min)

A napravi temu para i pošalje je na GitHub, B je preuzme i doda svoje pitanje, A na kraju preuzme B-ov rad. Danas se ništa ne spaja u `remote`.

### Osoba A

1. Kloniraj repozitorij, uđi u njegovu mapu i pokreni kviz da vidiš da radi.
2. Napravi granu za svog para `parPP-korak-1` i provjeri da si na njoj (PP je broj para, npr. par p01 radi granu `par01-korak-1`).
3. Kopiraj predložak `templates/tema.c` u `topics/pPP.c`. U kopiji zamijeni `pPP` brojem para, upiši naziv teme (obje teme para) i napiši jedno pitanje o svojoj temi.
4. Pokreni kviz i odigraj temu svog para: pitanje se mora prikazati, a točan odgovor mora biti stvarno točan.
5. Pogledaj stanje repozitorija: nova datoteka još nije praćena. Dodaj je i spremi commit s porukom „Dodaj pitanje”.
6. U `registry.c` upiši red svog para ispod oznake svog tima. Prije commita pogledaj razliku: trebao bi vidjeti točno jedan novi red.
7. Spremi tu promjenu u commit s porukom „Upisi temu u registar”. Zatim ispravi poruku zadnjeg commita u „Upiši temu u registar” (bez novog commita).
8. Kroz Git obriši svoju staru datoteku `legacy/junk_NN.txt` (NN = tvoj osobni broj) i spremi commit.
9. Pokreni provjeru kviza i opet pogledaj stanje. Izgrađena datoteka `quiz` se ne vidi — zašto?
10. Pogledaj povijest commitova, pošalji granu na GitHub i javi osobi B da je grana gore.
11. Kad ti B javi da je poslao svoje: preuzmi B-ove promjene u svoju granu, pogledaj povijest (vidiš B-ove commitove) i pokreni kviz — tema para sad ima dva pitanja.

### Osoba B

1. Kloniraj repozitorij, uđi u njegovu mapu i pokreni kviz da vidiš da radi.
2. Pričekaj da ti A javi. Zatim dohvati novosti s GitHuba (bez spajanja) i pogledaj popis udaljenih grana — mora se vidjeti `origin/parPP-korak-1`.
3. Prebaci se na granu svog para i pokreni kviz: tema para ima A-ovo pitanje.
4. U `topics/pPP.c` dodaj svoje pitanje o svojoj temi kao novi element niza, ispod A-ovog pitanja.
5. Pogledaj razliku (samo tvoje pitanje je novo) i pokreni kviz: tema mora imati oba pitanja.
6. Pogledaj stanje, dodaj promjenu i spremi commit s porukom „Dodaj pitanje osobe B”.
7. Kroz Git obriši svoju staru datoteku `legacy/junk_NN.txt` (NN = tvoj osobni broj) i spremi commit.
8. Pokreni provjeru kviza, pošalji granu na GitHub i javi osobi A.

---

## Dan 2 — Zadatak 2a: spajanje grana (10 min)

Svatko na svom računalu, na svojoj probnoj grani. Ništa se ne šalje na GitHub.

### Oboje, na početku

1. Prebaci se na granu para i preuzmi njezino najnovije stanje.
2. Napravi svoju probnu granu `pNN-pokus` (NN = tvoj osobni broj).

### Osoba A — stash i merge

3. Promijeni bilo što u `topics/pPP.c`. Sakrij promjenu u stash i pogledaj stanje: radni direktorij je čist.
4. Vrati sakrivenu promjenu iz stasha, provjeri da je opet tu, pa je odbaci.
5. Dohvati novosti s GitHuba i spoji granu `develop` u svoju probnu granu. Pogledaj što je stiglo (`docs/okruzenja.md`) i pokreni kviz.

### Osoba B — rebase i cherry-pick

3. Dohvati novosti s GitHuba i premjesti commitove svoje probne grane na vrh grane `remote`. Pogledaj povijest kao graf.
4. Pokreni kviz, namjerno odgovori jedno pitanje krivo i pogledaj postotak na kraju: pokazuje 0%, što nije točno.
5. Na grani `hotfix` nađi commit „Popravak: postotak rezultata” i uzmi u svoju granu samo njega.
6. Pokreni kviz ponovno: postotak sad mora biti točan.

### Oboje, na kraju

7. Vrati se na granu para i obriši svoju probnu granu.

---

## Dan 2 — Zadatak 2b: poništavanje (8 min)

Oboje, svatko na svom računalu.

1. Napravi probnu granu `pNN-oops` (NN = tvoj osobni broj) i pokreni scenarij „oops” sa svojim brojem. Skripta napravi nered.
2. Pogledaj stanje i zadnja tri commita. Popravi nered ovim redom:
   - vrati pokvareni `registry.c` na zadnje spremljeno stanje,
   - makni `tajna_pNN.txt` iz staginga i obriši je,
   - poništi zadnji commit tako da promjene ostanu, makni `biljeske_pNN.txt` iz staginga i obriši je.
3. Provjeri: stanje je čisto, u povijesti nema „Oops” commita, a kviz se pokreće i radi.
4. Vrati se na granu para i obriši probnu granu.

---

## Dan 2 — Zadatak 2c: pull requestovi (23 min)

A otvara i spaja PR-ove, B pregledava, a ako se pojavi konflikt, B ga rješava.

### Osoba A

1. Prebaci se na granu para i preuzmi najnovije stanje. Otvori **PR #1**: grana para → `remote`. Na GitHubu pogledaj kako CI provjerava PR.
2. Od grane para napravi granu `parPP-korak-2`. U `topics/pPP.c` dodaj treće pitanje i pokreni kviz da ga vidiš.
3. Spremi commit, pošalji granu na GitHub i otvori **PR #2**: `parPP-korak-2` → `parPP-korak-1` (PR složen na PR). Javi osobi B.

### Osoba B

4. Pregledaj oba PR-a: pročitaj promjene i provjeri da je CI zelen. Odobri oba. (Trojka: P18 i P19 oboje pregledaju.)

### Osoba A

5. Spoji PR #2 u granu para. Prebaci se na granu para, preuzmi najnovije i pokreni kviz: tema ima tri pitanja.
6. Kad voditelj kaže da je red na vaš par (spaja se redom: p01, p02, p03, zatim p04, p05, …), spoji PR #1 u `remote` kao **squash**.
7. Ako GitHub javi konflikt, javi osobi B i pričekaj. Kad B javi da je gotovo, ponovno spoji PR #1 kao squash.

### Osoba B — samo ako je konflikt

(Trojka: konflikt rješava P18, a P19 gleda i pomaže.)

8. Prebaci se na granu para i preuzmi najnovije stanje.
9. Dohvati novosti s GitHuba i premjesti granu para na vrh grane `remote`. Git staje na konfliktu u `registry.c`.
10. Otvori `registry.c`: zadrži **oba** reda (drugog para i vašeg) i obriši oznake `<<<<<<<`, `=======`, `>>>>>>>`.
11. Pokreni provjeru kviza i kviz. Označi konflikt riješenim i nastavi rebase.
12. Pošalji granu na GitHub (nakon rebasea treba sigurni prisilni push) i javi osobi A.

### Oboje, na kraju

13. Kad su svi parovi spojeni: prebaci se na `remote`, preuzmi najnovije i odigraj cijeli kviz — sve teme svih parova.
