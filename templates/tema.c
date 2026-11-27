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
    {"TODO: tvoje pitanje?",
     {"TODO odgovor A", "TODO odgovor B", "TODO odgovor C", "TODO odgovor D"}, 0},
};

const Topic topic_pPP = {"pPP", "TODO naziv teme", pitanja, BROJ(pitanja)};
