#include "raylib.h"
#include "player.h"
#include "config.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


void initPlayer(PLAYER* player){
    player->position =
    (Vector2){
        (float)WIDTH/2 - PLAYER_WIDTH/2,
        (float)(HEIGHT - 50) - PLAYER_HEIGHT/2
    };
    player->fuel = 100;
    player->life = 3;
    player->score = 0;
}

bool updatePlayer(PLAYER* player, const char map[MAP_HEIGHT][MAP_WIDTH]){
    bool reachedTop = false;
    if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
        player->position.x -= PLAYER_SPEED;
    if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
        player->position.x += PLAYER_SPEED;

    player->position.y -= PLAYER_SPEED;

    if(player->position.y <= 0)
        reachedTop = true;
    return reachedTop;
}

void drawPlayer(PLAYER player){
    DrawRectangleV(player.position,
                   (Vector2){PLAYER_WIDTH, PLAYER_HEIGHT},
                   YELLOW);
}

void resetPlayerPosition(PLAYER* player){
    player->position.y = (float)HEIGHT - PLAYER_HEIGHT/2;
}
