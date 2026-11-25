# Git radionica — kviz u C-u

Mali kviz u C-u na kojem vježbamo Git. Svatko od 19 sudionika dodaje svoju temu s pitanjima, na svojoj grani, a na kraju sve spajamo pull requestovima.

## Prije radionice

1. Instaliraj Git, GitHub CLI (`gh`), C prevoditelj i `make`.
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
5. Pronađi svoju karticu u `cards/` (npr. `cards/P07.md`).

## Naredbe

| Naredba | Što radi |
|---|---|
| `make run` | pokreće kviz |
| `make check` | provjerava sva pitanja (isto radi CI na svakom PR-u) |
| `make scenario-oops ID=07` | dan 2, zadatak 2b |

## Grane

- `remote` — glavna grana; na nju se ide samo preko PR-a
- `develop`, `staging` — grane po okruženjima
- `hotfix` — sadrži popravak koji ćemo cherry-pickati
- `pNN-korak-1`, `pNN-korak-2` — tvoje grane

## Što gdje

```
main.c, quiz.h, Makefile    ne mijenjaj
registry.c                  popis tema — ovdje upisuješ svoj red
topics/                     teme; tvoja je topics/pNN.c
templates/tema.c            predložak za tvoju temu
legacy/junk_NN.txt          datoteka koju brišeš s git rm
scenarios/oops.sh           zadatak 2b
cards/PNN.md                tvoja kartica
ZADACI.md                   svi zadaci, korak po korak
```

Zadaci su u [ZADACI.md](ZADACI.md).
