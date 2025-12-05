#ifndef ENTITIES_H_
#define ENTITIES_H_
#include "sprite.h"
#include "raylib.h"
#include "config.h"

typedef enum{
    ENTITY_NONE,
    ENTITY_SHIP,
    ENTITY_HELI,
    ENTITY_FUEL,
    ENTITY_EXPLOSION //adicao
} ENTITYTYPE;

typedef struct {
    Vector2 position;
    ENTITYTYPE type;
    bool active;
    float timer;
} ENTITY;

void initEntities(void);

void loadEntitiesFromMap(const char map[MAP_HEIGHT][MAP_WIDTH]);

void updateEntities(void);

void drawEntities(SpriteSheet*sheet);

ENTITYTYPE checkPlayerCollision(Vector2 playerPosition);

int checkBulletCollision(Vector2 bulletPosition);

#endif // ENTITIES_H_
