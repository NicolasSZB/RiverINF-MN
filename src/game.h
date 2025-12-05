#ifndef GAME_H
#define GAME_H

#include "config.h"

typedef enum{
    STATE_MAINMENU,
    STATE_GAMEPLAY,
    STATE_GAMEOVER,
    STATE_OPTIONS,
    STATE_RANKINGS
} GAMESTATE;

void loadLevel(int currentLevel, char* filename, char map[MAP_HEIGHT][MAP_WIDTH]);
#endif // GAME_H
