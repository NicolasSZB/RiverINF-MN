#ifndef ENTITIES_H_
#define ENTITIES_H_

#include "raylib.h"
#include "config.h"

typedef enum{
    ENTITY_NONE,
    ENTITY_SHIP,
    ENTITY_HELI,
    ENTITY_FUEL
} ENTITYTYPE;

typedef struct {
    Vector2 position;
    ENTITYTYPE type;
    bool active;
} ENTITY;

void initEntities(void);

void loadEntitiesFromMap(const char map[MAP_HEIGHT][MAP_WIDTH]);

void updateEntities(void);

void drawEntities(void);

ENTITYTYPE checkPlayerCollision(Vector2 playerPosition);

#endif // ENTITIES_H_
