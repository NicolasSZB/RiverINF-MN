#include "raylib.h"
#include "entities.h"
#include "sprite.h"
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

void drawEntities(SpriteSheet *sheet){
    float timer = GetFrameTime();
    for(int i = 0; i < MAX_ENTITIES; i++){
        if(!entities[i].active)
            continue;

        float scale =ENTITYSCALE;

        ENTITY *e = &entities[i];
        Rectangle spriteRec; // Variavel recorte sa ser usado


        if(e->type == ENTITY_EXPLOSION){
            e->timer -= timer;

            if(e->timer <= 0.0f){
                e->type == ENTITY_NONE;
                e->active = false;
                continue;
            }
        }
        switch (e->type){
            case ENTITY_HELI:
                spriteRec = sheet->helicoptero;
               // DrawRectangleV(e.position,
                            //(Vector2){PLAYER_WIDTH, PLAYER_HEIGHT},
                              //  RED);
                break;
            case ENTITY_SHIP:
                spriteRec = sheet->lancha;
                scale = 1.0f;

                break;
            case ENTITY_FUEL:
                spriteRec = sheet->fuel;
                scale = 0.6;
                //DrawRectangleV(e.position,
                  //              (Vector2){PLAYER_WIDTH, PLAYER_HEIGHT},
                    //            WHITE);
                break;
            case ENTITY_EXPLOSION:
                spriteRec = sheet->explosao_amarela;
                break;
            default:
                continue;
        }
        drawing_sprite(sheet,
                       spriteRec,
                       e->position.x,
                       e->position.y,
                       scale);
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

        Rectangle original;
        switch(e->type){
        case ENTITY_HELI:
            original = gameSprites.helicoptero;
            break;
        case ENTITY_SHIP:
            original = gameSprites.lancha;
            break;
        case ENTITY_FUEL:
            original = gameSprites.fuel;
            break;
        default:
            continue;
        }

        Rectangle entityRect = {
            e->position.x,
            e->position.y,
            original.width*0.6,
            original.height*0.6

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

int checkBulletCollision(Vector2 bulletPosition){
    Rectangle bulletRect = {bulletPosition.x, bulletPosition.y, 4, 10};
    Rectangle original;
    for(int i = 0; i < MAX_ENTITIES; i++){
        if(!entities[i].active)
           continue;

        ENTITY* e = &entities[i];

        if(e->type == ENTITY_HELI || e->type == ENTITY_SHIP){
                if (e->type == ENTITY_HELI) {
                original=  gameSprites.helicoptero;
            } else { // ENTITY_SHIP
                original= gameSprites.lancha;
            }
            Rectangle entityRect = {
                e->position.x,
                e->position.y,
                original.width*0.6,//ENTITYSCALE,//antigo player width e height
                original.height*0.6//ENTITYSCALE
            };

            if(CheckCollisionRecs(bulletRect, entityRect)){
               // e->active = false;

                if(e->type == ENTITY_HELI){
                        e->type = ENTITY_EXPLOSION;
                        e->timer= 0.3f;

                        return 60;
                }

                else if(e->type == ENTITY_SHIP){
                        e->type = ENTITY_EXPLOSION;
                        e->timer= 0.3f;

                        return 30;
                }
            }
        }
    }
    return 0;
}
