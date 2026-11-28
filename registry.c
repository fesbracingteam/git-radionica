#include <stddef.h>
#include "quiz.h"

/*
 * Popis svih tema u kvizu.
 * Osoba A upiše red SVOG PARA ispod oznake SVOG tima, u obliku:   &topic_p01,
 * (zarez na kraju je obavezan)
 */
const Topic *const registry[] = {
    &topic_git_osnove,

    /* ===== TIM A (parovi p01–p03): dodaj red ispod ove linije ===== */

    /* ===== TIM B (parovi p04–p05): dodaj red ispod ove linije ===== */

    /* ===== TIM C (parovi p06–p08): dodaj red ispod ove linije ===== */
    &topic_p03,
    /* ===== TIM D (par p09): dodaj red ispod ove linije ===== */

    NULL
};
