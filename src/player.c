#include "raylib.h"
#include "player.h"
#include "config.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


void initPlayer(PLAYER* player, char map[MAP_HEIGHT][MAP_WIDTH]){
    player->fuel = 100;
    player->life = 3;
    player->score = 0;
    resetPlayerPosition(player, map);
}

bool updatePlayer(PLAYER* player, const char map[MAP_HEIGHT][MAP_WIDTH]){
    bool reachedTop = false;
    if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
        player->position.x -= PLAYER_SPEED;
    if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
        player->position.x += PLAYER_SPEED;

    player->position.y -= PLAYER_SPEED;

    int centerX = player->position.x + (PLAYER_WIDTH/2);
    int centerY = player->position.y + (PLAYER_HEIGHT/2);

    int playerGridCol = centerX / TILE_SIZE;
    int playerGridRow = centerY / TILE_SIZE;

    char tile = map[playerGridRow][playerGridCol];

    if(tile == 'T'){
        player->life--;
        resetPlayerPosition(player, map);
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
