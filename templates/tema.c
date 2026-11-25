/*
 * Predložak teme. Kopiraj ga:   cp templates/tema.c topics/pNN.c
 * Zatim u kopiji:
 *   1. zamijeni SVAKI "pNN" svojim brojem (npr. p07) — ima ih dva u zadnjem redu
 *   2. upiši naziv svoje teme
 *   3. zamijeni TODO tekstove svojim pitanjem i odgovorima
 *   4. postavi broj točnog odgovora: 0 = A, 1 = B, 2 = C, 3 = D
 */
#include "quiz.h"

static const Question pitanja[] = {
    {"TODO: tvoje pitanje?",
     {"TODO odgovor A", "TODO odgovor B", "TODO odgovor C", "TODO odgovor D"}, 0},
};

const Topic topic_pNN = {"pNN", "TODO naziv teme", pitanja, BROJ(pitanja)};
