#ifndef BULLET_H_
#define BULLET_H_

#include "raylib.h"
#include "config.h"
#include "audio.h"
#include <stdbool.h>

typedef struct {
    Vector2 position;
    bool active;
} BULLET;

#define MAX_BULLETS 50

void initBullets(void);

void spawnBullet(Vector2 startPosition);

int updateBullets(char map[MAP_HEIGHT][MAP_WIDTH]);

void drawBullets(void);

#endif // BULLET_H_
