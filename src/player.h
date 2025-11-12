#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include <stdbool.h>

typedef struct player{
    Vector2 position;
    int fuel;
    int life;
    int score;
} PLAYER;

void initPlayer(PLAYER* player);
bool updatePlayer(PLAYER* player, const char map[MAP_HEIGHT][MAP_WIDTH]);
void drawPlayer(PLAYER player);
void resetPlayerPosition(PLAYER* player);

#endif // PLAYER_H
