#include "bullet.h"
#include "config.h"

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

void updateBullets(void){
    for(int i = 0; i < MAX_BULLETS; i++){
        if(!bullets[i].active)
            continue;

        bullets[i].position.y -= BULLET_SPEED;

        if(bullets[i].position.y <= 0)
            bullets[i].active = false;
    }
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
