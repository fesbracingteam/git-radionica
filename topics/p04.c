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
    {"Koja je prva igra vezana za svemir ?",
    {"Star Citizen odgovor A", "Spacewar! odgovor B", "Starfield odgovor C", "No man's sky odgovor D"}, 1},
    {"Koja svemirska igra ima 1:1 velicinu mlijecnog sustava ?",
    {"No man's sky odgovor A","Starfield odgovor B", "Elite Dangerous odgovor C", "Eve Online odgovor D"}, 2}
};

const Topic topic_p04 = {"p04", "Igre / Svemir", pitanja, BROJ(pitanja)};
