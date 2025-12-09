#include "bullet.h"
#include "config.h"
#include "entities.h"
#include "audio.h"

static BULLET bullets[MAX_BULLETS];

void initBullets(void){
    for(int i = 0; i < MAX_BULLETS; i++)
        bullets[i].active = false;
}

void spawnBullet(Vector2 startPosition){
    for(int i = 0; i < MAX_BULLETS; i++){
        if(!bullets[i].active){
            bullets[i].active = true;

            bullets[i].position.x = startPosition.x + (PLAYER_WIDTH/2);
            bullets[i].position.y = startPosition.y;

            return;
        }
    }
}

int updateBullets(char map[MAP_HEIGHT][MAP_WIDTH]){
    int scoreFrame = 0;

    for(int i = 0; i < MAX_BULLETS; i++){
        if(!bullets[i].active)
            continue;

        bullets[i].position.y -= BULLET_SPEED;

        if(bullets[i].position.y <= 0){
            bullets[i].active = false;
            continue;
        }

        int gridCol = (bullets[i].position.x + 2) / TILE_SIZE;
        int gridRow = bullets[i].position.y / TILE_SIZE;

        if(gridCol >= 0 && gridCol < MAP_WIDTH && gridRow >= 0 && gridRow < MAP_HEIGHT){
            if(map[gridRow][gridCol] == 'T'){
                bullets[i].active = false;
                continue;
            }
        }

        int score = checkBulletCollision(bullets[i].position);

        if(score > 0){
            bullets[i].active = false;
            scoreFrame += score;
            playExplosionSound();
        }
    }

    return scoreFrame;
}

void drawBullets(void){
    for(int i = 0; i < MAX_BULLETS; i++){
        if(bullets[i].active){
            DrawRectangle(bullets[i].position.x,
                          bullets[i].position.y,
                          4,
                          10,
                          YELLOW);
        }
    }
}
