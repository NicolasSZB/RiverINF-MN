#ifndef GAME_H
#define GAME_H

#include "config.h"

typedef enum{
    STATE_MAINMENU,
    STATE_GAMEPLAY,
<<<<<<< Updated upstream
    STATE_GAMEOVER
=======
    STATE_GAMEOVER,
    STATE_OPTIONS,
    STATE_RANKINGS,
    STATE_NAMEINPUT
>>>>>>> Stashed changes
} GAMESTATE;

void loadLevel(int currentLevel, char* filename, char map[MAP_HEIGHT][MAP_WIDTH]);
#endif // GAME_H
