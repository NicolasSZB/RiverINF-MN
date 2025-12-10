#ifndef ENTITIES_H_
#define ENTITIES_H_
#include "sprite.h"
#include "raylib.h"
#include "config.h"

typedef enum{
    ENTITY_NONE,
    ENTITY_SHIP,
    ENTITY_HELI,
<<<<<<< HEAD
    ENTITY_FUEL,
    ENTITY_EXPLOSION //adicao
=======
<<<<<<< Updated upstream
    ENTITY_FUEL
=======
    ENTITY_FUEL,
    ENTITY_EXPLOSION,
    ENTITY_BRIDGE
>>>>>>> Stashed changes
>>>>>>> 38adb048f742436ec7ad35800588e0e31bbeedd5
} ENTITYTYPE;

typedef struct {
    Vector2 position;
    ENTITYTYPE type;
    bool active;
<<<<<<< HEAD
    float timer;
=======
<<<<<<< Updated upstream
=======
    float timer;
    float velocity;
>>>>>>> Stashed changes
>>>>>>> 38adb048f742436ec7ad35800588e0e31bbeedd5
} ENTITY;

void initEntities(void);

void loadEntitiesFromMap(const char map[MAP_HEIGHT][MAP_WIDTH]);

void updateEntities(char map[MAP_HEIGHT][MAP_WIDTH]);

void drawEntities(SpriteSheet*sheet);

ENTITYTYPE checkPlayerCollision(Vector2 playerPosition);

int checkBulletCollision(Vector2 bulletPosition);

#endif // ENTITIES_H_
