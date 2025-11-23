#ifndef PLAYER_H
#define PLAYER_H
#include"sprite.h"
#include "raylib.h"
#include "config.h"
#include <stdbool.h>

typedef struct player{
    Vector2 position;
    float fuel;
    int life;
    int score;
    Rectangle currentSprite;
} PLAYER;

void initPlayer(PLAYER* player, char map[MAP_HEIGHT][MAP_WIDTH]);
bool updatePlayer(PLAYER* player, char map[MAP_HEIGHT][MAP_WIDTH]);
void drawPlayer(PLAYER player,SpriteSheet *sheet);
void resetPlayerPosition(PLAYER* player, char map[MAP_HEIGHT][MAP_WIDTH]);

#endif // PLAYER_H
