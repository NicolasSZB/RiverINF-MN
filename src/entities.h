#ifndef ENTITIES_H_
#define ENTITIES_H_

#include "raylib.h"
#include "config.h"

typedef enum{
    ENTITY_NONE,
    ENTITY_SHIP,
    ENTITY_HELI,
<<<<<<< Updated upstream
    ENTITY_FUEL
=======
    ENTITY_FUEL,
    ENTITY_EXPLOSION,
    ENTITY_BRIDGE
>>>>>>> Stashed changes
} ENTITYTYPE;

typedef struct {
    Vector2 position;
    ENTITYTYPE type;
    bool active;
<<<<<<< Updated upstream
=======
    float timer;
    float velocity;
>>>>>>> Stashed changes
} ENTITY;

void initEntities(void);

void loadEntitiesFromMap(const char map[MAP_HEIGHT][MAP_WIDTH]);

void updateEntities(char map[MAP_HEIGHT][MAP_WIDTH]);

void drawEntities(void);

ENTITYTYPE checkPlayerCollision(Vector2 playerPosition);

int checkBulletCollision(Vector2 bulletPosition);

#endif // ENTITIES_H_
