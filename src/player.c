#include "raylib.h"
#include "player.h"
#include "config.h"
#include "entities.h"
#include "bullet.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


void initPlayer(PLAYER* player, char map[MAP_HEIGHT][MAP_WIDTH]){
    player->fuel = 100;
    player->life = 3;
    player->score = 0;
    resetPlayerPosition(player, map);
}

bool updatePlayer(PLAYER* player, char map[MAP_HEIGHT][MAP_WIDTH]){
    bool reachedTop = false;
    if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
        player->position.x -= PLAYER_SPEED;
    if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
        player->position.x += PLAYER_SPEED;
    if(IsKeyPressed(KEY_K) || IsKeyPressed(KEY_SPACE))
        spawnBullet(player->position);

    player->position.y -= PLAYER_SPEED;

    int topLeftRow = player->position.y / TILE_SIZE;
    int topLeftCol = player->position.x / TILE_SIZE;

    int topRightRow = player->position.y / TILE_SIZE;
    int topRightCol = (player->position.x + PLAYER_WIDTH) / TILE_SIZE;

    int bottomLeftRow = (player->position.y + PLAYER_HEIGHT) / TILE_SIZE;
    int bottomLeftCol = player->position.x / TILE_SIZE;

    int bottomRightRow = (player->position.y  + PLAYER_HEIGHT) / TILE_SIZE;
    int bottomRightCol = (player->position.x + PLAYER_WIDTH) / TILE_SIZE;

    if(
       map[topLeftRow][topLeftCol] == 'T' ||
       map[topRightRow][topRightCol] == 'T' ||
       map[bottomLeftRow][bottomLeftCol] == 'T' ||
       map[bottomRightRow][bottomRightCol] == 'T'
       ){
        player->life--;
        resetPlayerPosition(player, map);
       }

    ENTITYTYPE collisionType = checkPlayerCollision(player->position);

    if(collisionType == ENTITY_HELI || collisionType == ENTITY_SHIP){
        player->life--;
        resetPlayerPosition(player, map);
    }
    else if(collisionType == ENTITY_FUEL){
        player->fuel += 30;
        if(player-> fuel > 100)
            player->fuel = 100;
    }

    player->fuel -= 0.1f;

    if(player->fuel <= 0){
        player->life--;
        resetPlayerPosition(player, map);
        player->fuel = 100;
    }

    if(player->position.y <= 0)
        reachedTop = true;
    return reachedTop;
}

void drawPlayer(PLAYER player){
    DrawRectangleV(player.position,
                   (Vector2){PLAYER_WIDTH, PLAYER_HEIGHT},
                   YELLOW);
}

void resetPlayerPosition(PLAYER* player, char map[MAP_HEIGHT][MAP_WIDTH]){
    float startX, startY;
    for(int i = 0; i < MAP_HEIGHT; i++){
        for(int j = 0; j < MAP_WIDTH; j++){
            if(map[i][j] == 'A'){
                startX = j * TILE_SIZE + (TILE_SIZE - PLAYER_WIDTH)/2;
                startY = i * TILE_SIZE + (TILE_SIZE - PLAYER_HEIGHT)/2;
                player->position = (Vector2){startX, startY};
                return;
            }
        }
    };
}
