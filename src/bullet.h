#ifndef BULLET_H_
#define BULLET_H_

#include "raylib.h"
#include <stdbool.h>

typedef struct {
    Vector2 position;
    bool active;
} BULLET;

#define MAX_BULLETS 50

void initBullets(void);

void spawnBullet(Vector2 startPosition);

void updateBullets(void);

void drawBullets(void);

#endif // BULLET_H_
