#ifndef GAME_H
#define GAME_H

#include "config.h"

typedef enum{
    STATE_MAINMENU,
    STATE_GAMEPLAY,
<<<<<<< HEAD
    STATE_GAMEOVER,
    STATE_OPTIONS,
    STATE_RANKINGS
=======
<<<<<<< Updated upstream
    STATE_GAMEOVER
=======
    STATE_GAMEOVER,
    STATE_OPTIONS,
    STATE_RANKINGS,
    STATE_NAMEINPUT
>>>>>>> Stashed changes
>>>>>>> 38adb048f742436ec7ad35800588e0e31bbeedd5
} GAMESTATE;

void loadLevel(int currentLevel, char* filename, char map[MAP_HEIGHT][MAP_WIDTH]);
#endif // GAME_H
