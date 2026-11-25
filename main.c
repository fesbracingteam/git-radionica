/* Ne mijenjaj ovu datoteku. */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quiz.h"

static int greska(const Topic *t, int i, const char *poruka) {
    printf("GREŠKA [%s, pitanje %d]: %s\n", t->id, i + 1, poruka);
    return 1;
}

/* make check: provjerava svako pitanje svake teme iz registry.c */
static int provjeri(void) {
    int greske = 0, teme = 0, pitanja = 0;
    for (const Topic *const *t = registry; *t; t++, teme++) {
        const Topic *tp = *t;
        for (const Topic *const *u = registry; u != t; u++)
            if (*u == tp || strcmp((*u)->id, tp->id) == 0) {
                printf("GREŠKA: tema %s je dvaput u registry.c\n", tp->id);
                greske++;
            }
        if (tp->broj < 1) {
            printf("GREŠKA [%s]: tema nema pitanja\n", tp->id);
            greske++;
        }
        for (int i = 0; i < tp->broj; i++, pitanja++) {
            const Question *q = &tp->pitanja[i];
            size_t n = q->tekst ? strlen(q->tekst) : 0;
            if (n == 0) greske += greska(tp, i, "pitanje je prazno");
            else if (q->tekst[n - 1] != '?') greske += greska(tp, i, "pitanje mora završiti upitnikom");
            if (q->tekst && strstr(q->tekst, "TODO")) greske += greska(tp, i, "pitanje još sadrži TODO");
            if (q->tocan < 0 || q->tocan > 3) greske += greska(tp, i, "tocan mora biti 0, 1, 2 ili 3");
            for (int j = 0; j < 4; j++) {
                if (!q->odgovori[j] || !q->odgovori[j][0]) greske += greska(tp, i, "neki odgovor je prazan");
                else if (strstr(q->odgovori[j], "TODO")) greske += greska(tp, i, "odgovor još sadrži TODO");
            }
        }
    }
    printf("%d tema, %d pitanja, %d grešaka\n", teme, pitanja, greske);
    return greske ? 1 : 0;
}

static int procitaj_slovo(void) {
    char red[64];
    if (!fgets(red, sizeof red, stdin)) return -1;
    int c = toupper((unsigned char)red[0]);
    return (c >= 'A' && c <= 'D') ? c - 'A' : -2;
}

static void igraj(const Topic *t, int *tocno, int *ukupno) {
    printf("\n== %s ==\n", t->naziv);
    for (int i = 0; i < t->broj; i++) {
        const Question *q = &t->pitanja[i];
        printf("\n%s\n", q->tekst);
        for (int j = 0; j < 4; j++) printf("  %c) %s\n", 'A' + j, q->odgovori[j]);
        int odg;
        do {
            printf("Odgovor (A-D): ");
            odg = procitaj_slovo();
        } while (odg == -2);
        if (odg == -1) return;
        (*ukupno)++;
        if (odg == q->tocan) {
            (*tocno)++;
            printf("Točno!\n");
        } else {
            printf("Netočno, točan je %c.\n", 'A' + q->tocan);
        }
    }
}

int main(int argc, char **argv) {
    if (argc > 1 && strcmp(argv[1], "--check") == 0) return provjeri();

    int n = 0;
    printf("Git kviz — teme:\n");
    for (const Topic *const *t = registry; *t; t++) printf("  %d) %s\n", ++n, (*t)->naziv);
    printf("Odaberi temu (0 = sve): ");

    char red[64];
    int izbor = fgets(red, sizeof red, stdin) ? atoi(red) : 0;
    int tocno = 0, ukupno = 0;
    for (int i = 0; i < n; i++)
        if (izbor == 0 || izbor == i + 1) igraj(registry[i], &tocno, &ukupno);

    if (ukupno > 0) printf("\nRezultat: %d/%d (%d%%)\n", tocno, ukupno, 100 * tocno / ukupno);
    return 0;
}
