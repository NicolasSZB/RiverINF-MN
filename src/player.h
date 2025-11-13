#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "config.h"
#include <stdbool.h>

typedef struct player{
    Vector2 position;
    int fuel;
    int life;
    int score;
} PLAYER;

void initPlayer(PLAYER* player, char map[MAP_HEIGHT][MAP_WIDTH]);
bool updatePlayer(PLAYER* player, const char map[MAP_HEIGHT][MAP_WIDTH]);
void drawPlayer(PLAYER player);
void resetPlayerPosition(PLAYER* player, char map[MAP_HEIGHT][MAP_WIDTH]);

#endif // PLAYER_H
