#include "quiz.h"

static const Question pitanja[] = {
    {"Koja naredba sprema promjene u lokalni repozitorij?",
     {"git push", "git commit", "git add", "git fetch"}, 1},
    {"Koja naredba dohvaća promjene s poslužitelja i odmah ih spaja u tvoju granu?",
     {"git fetch", "git clone", "git pull", "git status"}, 2},
    {"Je li Git isto što i GitHub?",
     {"Da", "Ne, GitHub je servis koji hostira Git repozitorije", "Samo na Windowsima", "Samo od 2020."}, 1},
};

const Topic topic_git_osnove = {"git_osnove", "Git osnove", pitanja, BROJ(pitanja)};
