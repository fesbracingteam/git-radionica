/*
 * Predložak teme para. Osoba A ga kopira u topics/pPP.c (PP = broj para, npr. p01).
 * Zatim u kopiji:
 *   1. zamijeni SVAKI "pPP" brojem para (npr. p01) — ima ih dva u zadnjem redu
 *   2. upiši naziv teme: obje teme para, npr. "Nogomet / F1 i Formula Student"
 *   3. zamijeni TODO tekstove svojim pitanjem i odgovorima
 *   4. postavi broj točnog odgovora: 0 = A, 1 = B, 2 = C, 3 = D
 * Osoba B kasnije doda svoje pitanje kao novi element niza, ispod pitanja osobe A.
 */
#include "quiz.h"

static const Question pitanja[] = {
    {"Najveca povrsinom zemlja na svijetu?",
     {"Rusija", "Kina", "SAD", "Brazil"}, 0},
};

const Topic zemlja_p01 = {"p01", "zemlja / F1", pitanja, BROJ(pitanja)};
