# Git radionica — kviz u C-u

Mali kviz u C-u na kojem vježbamo Git. Radimo u 9 parova (p01–p09): u svakom paru osoba A stvara i šalje, a osoba B preuzima i dopunjuje. Svaki par dodaje svoju temu s pitanjima na svojoj grani, a na kraju sve spajamo pull requestovima.

## Prije radionice

1. Instaliraj C prevoditelj (`gcc`), `make`, Git i GitHub CLI (`gh`) prema [INSTALACIJA.md](INSTALACIJA.md).
2. Postavi ime i e-mail:
   ```bash
   git config --global user.name "Ime Prezime"
   git config --global user.email "ti@example.com"
   ```
3. Prijavi se: `gh auth login`, pa provjeri s `gh auth status`.
4. Prihvati pozivnicu za repozitorij, zatim:
   ```bash
   gh repo clone fesbracingteam/git-radionica
   cd git-radionica
   make check
   ```
   Ako vidiš `Sve u redu.`, javi voditelju.
5. Pronađi svoju karticu u `cards/` (npr. `cards/P07.md`): na njoj su tvoj par, uloga (A ili B) i tema.

## Naredbe

| Naredba | Što radi |
|---|---|
| `make run` | pokreće kviz |
| `make check` | provjerava sva pitanja (isto radi CI na svakom PR-u) |
| `make scenario-oops ID=07` | dan 2, zadatak 2b (tvoj osobni broj) |

## Grane

- `remote` — glavna grana; na nju se ide samo preko PR-a
- `develop`, `staging` — grane po okruženjima
- `hotfix` — sadrži popravak koji ćemo cherry-pickati
- `parPP-korak-1`, `parPP-korak-2` — grane tvog para (PP = broj para, npr. `par01-korak-1`)
- `pNN-pokus`, `pNN-oops` — tvoje probne grane na dan 2 (NN = tvoj osobni broj), ne šalju se na GitHub

## Što gdje

```
main.c, quiz.h, Makefile    ne mijenjaj
registry.c                  popis tema — ovdje osoba A upisuje red para
topics/                     teme; tema vašeg para je topics/pPP.c
templates/tema.c            predložak za temu para
legacy/junk_NN.txt          datoteka koju brišeš s git rm (tvoj osobni broj)
scenarios/oops.sh           zadatak 2b
cards/PNN.md                tvoja kartica
ZADACI.md                   što treba napraviti, po ulogama A i B
KOMANDE_RJESENJA.md         naredbe koje rješavaju svaki korak
INSTALACIJA.md              instalacija gcc, make, git i gh na svim sustavima (i PATH na Windowsu)
```

Zadaci su u [ZADACI.md](ZADACI.md), a rješenja u [KOMANDE_RJESENJA.md](KOMANDE_RJESENJA.md).
