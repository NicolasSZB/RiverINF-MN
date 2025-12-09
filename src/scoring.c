#include <stdio.h>
#include <string.h>
#include "scoring.h"

void loadHighScores(HIGHSCORE entries[MAX_HIGHSCORES]){
    FILE* fp = fopen("highscore.bin", "rb");

    if(fp == NULL){
        for(int i = 0; i < MAX_HIGHSCORES; i++){
            strcpy(entries[i].name, "--------");
            entries[i].score = 0;
        }
        return;
    }

    fread(entries, sizeof(HIGHSCORE), MAX_HIGHSCORES, fp);
    fclose(fp);
}

void saveHighScores(HIGHSCORE entries[MAX_HIGHSCORES]){
    FILE* fp = fopen("highscore.bin", "wb");
    if(fp != NULL){
        fwrite(entries, sizeof(HIGHSCORE), MAX_HIGHSCORES, fp);
        fclose(fp);
    }
}

bool checkNewHighScore(int score, HIGHSCORE entries[MAX_HIGHSCORES]){
    return (score > entries[MAX_HIGHSCORES - 1].score);
}

void addHighScore(char* name, int score, HIGHSCORE entries[MAX_HIGHSCORES]){
    if(!checkNewHighScore(score, entries))
        return;

    strcpy(entries[MAX_HIGHSCORES - 1].name, name);
    entries[MAX_HIGHSCORES - 1].score = score;

    for(int i = 0; i < MAX_HIGHSCORES - 1; i++){
        for(int j = 0; j < MAX_HIGHSCORES - 1 - i; j++){
            if(entries[j].score < entries[j + 1].score){
                HIGHSCORE temp = entries[j];
                entries[j] = entries[j + 1];
                entries[j + 1] = temp;
            }
        }
    }

    saveHighScores(entries);
}
