/* Ne mijenjaj ovu datoteku. */
#ifndef QUIZ_H
#define QUIZ_H

typedef struct {
    const char *tekst;       /* pitanje, završava upitnikom */
    const char *odgovori[4]; /* odgovori A, B, C, D */
    int tocan;               /* 0 = A, 1 = B, 2 = C, 3 = D */
} Question;

typedef struct {
    const char *id;          /* npr. "p07" */
    const char *naziv;       /* npr. "Glazba" */
    const Question *pitanja;
    int broj;
} Topic;

#define BROJ(niz) ((int)(sizeof(niz) / sizeof((niz)[0])))

/* Svaka tema iz topics/ — deklarirane unaprijed da registry.c ostane jedan red po osobi. */
extern const Topic topic_git_osnove,
    topic_p01, topic_p02, topic_p03, topic_p04, topic_p05,
    topic_p06, topic_p07, topic_p08, topic_p09, topic_p10,
    topic_p11, topic_p12, topic_p13, topic_p14, topic_p15,
    topic_p16, topic_p17, topic_p18, topic_p19;

extern const Topic *const registry[]; /* završava s NULL */

#endif
