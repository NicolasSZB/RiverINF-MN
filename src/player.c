#include "raylib.h"
#include "player.h"
#include "config.h"

#include <stdlib.h>
#include <stdio.h>



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

void updatePlayer(PLAYER* player){
    if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
        player->position.x -= PLAYER_SPEED;
    if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
        player->position.x += PLAYER_SPEED;

    player->position.y -= PLAYER_SPEED;
}

void drawPlayer(PLAYER player){
    DrawRectangleV(player.position,
                   (Vector2){PLAYER_WIDTH, PLAYER_HEIGHT},
                   YELLOW);
}
