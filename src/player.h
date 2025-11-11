#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct player{
    Vector2 position;
    int fuel;
    int life;
    int score;
} PLAYER;

void initPlayer(PLAYER* player);
void updatePlayer(PLAYER* player);
void drawPlayer(PLAYER player);

#endif // PLAYER_H
