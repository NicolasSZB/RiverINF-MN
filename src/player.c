#include "raylib.h"
#include "player.h"
#include "config.h"
#include "entities.h"
#include "bullet.h"
#include "sprite.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

extern SpriteSheet gameSprites;

void initPlayer(PLAYER* player, char map[MAP_HEIGHT][MAP_WIDTH]){
    player->fuel = 100;
    player->life = 3;
    player->score = 0;
    resetPlayerPosition(player, map);
}

bool updatePlayer(PLAYER* player, char map[MAP_HEIGHT][MAP_WIDTH]){
    bool reachedTop = false;
    bool horizontal_movement = false;

    float scaled_tile_size = TILE_SIZE;

    if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)){
        player->position.x -= PLAYER_SPEED;
        player->currentSprite = gameSprites.jogador_aviao_esquerda;
        horizontal_movement = true;
    }
    if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)){
        player->position.x += PLAYER_SPEED;
        player->currentSprite = gameSprites.jogador_aviao_direita;
        horizontal_movement = true;
    }
    if(!horizontal_movement){
        player->currentSprite = gameSprites.jogador_aviao_reto;
    }
    if(IsKeyPressed(KEY_K) || IsKeyPressed(KEY_SPACE))
        spawnBullet(player->position);

    player->position.y -= PLAYER_SPEED;

    int topLeftRow = player->position.y / scaled_tile_size;
    int topLeftCol = player->position.x / scaled_tile_size;

    int topRightRow = player->position.y / scaled_tile_size;
    int topRightCol = (player->position.x + PLAYER_WIDTH) / scaled_tile_size;

    int bottomLeftRow = (player->position.y + PLAYER_HEIGHT) / scaled_tile_size;
    int bottomLeftCol = player->position.x / scaled_tile_size;

    int bottomRightRow = (player->position.y  + PLAYER_HEIGHT) / scaled_tile_size;
    int bottomRightCol = (player->position.x + PLAYER_WIDTH) / scaled_tile_size;

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
void drawPlayer(PLAYER player,SpriteSheet*sheet){
    drawing_sprite(sheet,player.currentSprite,player.position.x,player.position.y,JET_SCALE);
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
    }
}
