#ifndef SCORING_H
#define SCORING_H

#include <stdbool.h>

#define MAX_HIGHSCORES 5
#define NAME_MAX_LEN 10

typedef struct {
    char name[NAME_MAX_LEN + 1];
    int score;
} HIGHSCORE;

void loadHighScores(HIGHSCORE entries[MAX_HIGHSCORES]);

void saveHighScores(HIGHSCORE entires[MAX_HIGHSCORES]);

bool checkNewHighScore(int score, HIGHSCORE entires[MAX_HIGHSCORES]);

void addHighScore(char* name, int score, HIGHSCORE entires[MAX_HIGHSCORES]);
#endif // SCORING_H
