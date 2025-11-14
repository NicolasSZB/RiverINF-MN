#include "raylib.h"
#include "entities.h"

#include <stdlib.h>

static ENTITY entities[MAX_ENTITIES];

void initEntities(void){
    for(int i = 0; i < MAX_ENTITIES; i++){
        entities[i].active = false;
        entities[i].type = ENTITY_NONE;
    }
}

// void updateEntities(void){}

void loadEntitiesFromMap(const char map[MAP_HEIGHT][MAP_WIDTH]){
    initEntities();

    int entityCount = 0;

    for(int i = 0; i < MAP_HEIGHT; i++){
        for(int j = 0; j < MAP_WIDTH; j++){
            if(entityCount >= MAX_ENTITIES)
                return;

            char tile = map[i][j];

            if(tile == 'X' || tile == 'N' || tile == 'G'){

                ENTITY* e = &entities[entityCount];

                e->active = true;

                e->position.y = (float)i * TILE_SIZE + (TILE_SIZE - PLAYER_HEIGHT) /2;
                e->position.x = (float)j * TILE_SIZE + (TILE_SIZE - PLAYER_WIDTH) /2;

            if(tile == 'X')
                e->type = ENTITY_HELI;
            else if(tile == 'N')
                e->type = ENTITY_SHIP;
            else if(tile == 'G')
                e->type = ENTITY_FUEL;

            entityCount++;
            }
        }
    }
}

void drawEntities(void){
    for(int i = 0; i < MAX_ENTITIES; i++){
        if(!entities[i].active)
            continue;

        ENTITY e = entities[i];

        switch (e.type){
            case ENTITY_HELI:
                DrawRectangleV(e.position,
                                (Vector2){PLAYER_WIDTH, PLAYER_HEIGHT},
                                RED);
                break;
            case ENTITY_SHIP:
                DrawRectangleV(e.position,
                                (Vector2){PLAYER_WIDTH, PLAYER_HEIGHT},
                                GRAY);
                break;
            case ENTITY_FUEL:
                DrawRectangleV(e.position,
                                (Vector2){PLAYER_WIDTH, PLAYER_HEIGHT},
                                WHITE);
                break;
            default:
                break;
        }
    }
}

ENTITYTYPE checkPlayerCollision(Vector2 playerPosition){
    Rectangle playerRect = {
        playerPosition.x,
        playerPosition.y,
        PLAYER_WIDTH,
        PLAYER_HEIGHT
    };

    for(int i = 0; i < MAX_ENTITIES; i++){
        if(!entities[i].active)
            continue;

        ENTITY* e = &entities[i];

        Rectangle entityRect = {
            e->position.x,
            e->position.y,
            PLAYER_WIDTH,
            PLAYER_HEIGHT
        };

        if(CheckCollisionRecs(playerRect, entityRect)){
            if(e->type == ENTITY_FUEL){
                e->active = false;
                return ENTITY_FUEL;
            }

            if(e->type == ENTITY_HELI || e->type == ENTITY_SHIP)
                return e->type;
        }
    }

    return ENTITY_NONE;
}
