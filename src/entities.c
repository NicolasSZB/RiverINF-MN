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

void updateEntities(char map[MAP_HEIGHT][MAP_WIDTH]){
    float dt = GetFrameTime();

    for(int i = 0; i < MAX_ENTITIES; i++){
        if(!entities[i].active)
            continue;

        ENTITY* e = &entities[i];

        if(e->type == ENTITY_EXPLOSION){
            e->timer -= dt;
            if(e->timer <= 0.0f){
                e->active = false;
                e->type = ENTITY_NONE;
            }
            continue;
        }

        if(e->velocity != 0.0f){
            float nextX = e->position.x + e->velocity;

            int col = (nextX + PLAYER_WIDTH/2) / TILE_SIZE;
            int row = (e->position.y + PLAYER_HEIGHT/2) / TILE_SIZE;

            if(col < 0 || col >= MAP_WIDTH || map[row][col] == 'T')
                e->velocity *= -1;
            else
                e->position.x = nextX;
        }
    }
}

void loadEntitiesFromMap(const char map[MAP_HEIGHT][MAP_WIDTH]){
    initEntities();
    int entityCount = 0;

    for(int i = 0; i < MAP_HEIGHT; i++){

        for(int j = 0; j < MAP_WIDTH; j++){
            if(entityCount >= MAX_ENTITIES)
                return;

            char tile = map[i][j];

            if(tile == 'X' || tile == 'N' || tile == 'G' || tile == 'P'){

                ENTITY* e = &entities[entityCount];
                e->active = true;
                e->position.y = (float)i * TILE_SIZE + (TILE_SIZE - PLAYER_HEIGHT) /2;
                e->position.x = (float)j * TILE_SIZE + (TILE_SIZE - PLAYER_WIDTH) /2;

                if(tile == 'X'){
                    e->type = ENTITY_HELI;
                    e->velocity = 2.0f;
                }
                else if(tile == 'N'){
                    e->type = ENTITY_SHIP;
                    e->velocity = 1.5f;
                }
                else if(tile == 'G'){
                    e->type = ENTITY_FUEL;
                    e->velocity = 0.0f;
                }
                else if(tile == 'P'){
                    e->type = ENTITY_BRIDGE;
                    e->velocity = 0.0f;
                }

                entityCount++;
            }
        }
    }
}

void drawEntities(void){
    for(int i = 0; i < MAX_ENTITIES; i++){
        if(!entities[i].active)
            continue;

<<<<<<< Updated upstream
        ENTITY e = entities[i];

        switch (e.type){
            case ENTITY_HELI:
                DrawRectangleV(e.position,
                                (Vector2){PLAYER_WIDTH, PLAYER_HEIGHT},
                                RED);
=======
        float scale = ENTITYSCALE;
        ENTITY *e = &entities[i];
        Rectangle spriteRec;

        float drawX = e->position.x;
        float drawY = e->position.y;

        if(e->type == ENTITY_EXPLOSION){
            e->timer -= timer;

            if(e->timer <= 0.0f){
                e->type = ENTITY_NONE;
                e->active = false;
                continue;
            }
        }
        switch (e->type){
            case ENTITY_HELI:
                spriteRec = sheet->helicoptero;
>>>>>>> Stashed changes
                break;
            case ENTITY_BRIDGE:
                DrawRectangle(drawX, drawY, 40, 20, YELLOW);
                DrawRectangleLines(drawX, drawY, 40, 20, BLACK);
                DrawLine(drawX, drawY+5, drawX+40, drawY+5, BLACK);
                DrawLine(drawX, drawY+15, drawX+40, drawY+15, BLACK);
                continue;
            case ENTITY_SHIP:
<<<<<<< Updated upstream
                DrawRectangleV(e.position,
                                (Vector2){PLAYER_WIDTH, PLAYER_HEIGHT},
                                GRAY);
                break;
            case ENTITY_FUEL:
                DrawRectangleV(e.position,
                                (Vector2){PLAYER_WIDTH, PLAYER_HEIGHT},
                                WHITE);
=======
                scale = 1.0f;
                spriteRec = sheet->lancha;
                break;
            case ENTITY_FUEL:
                scale = 0.6;
                spriteRec = sheet->fuel;
                break;
            case ENTITY_EXPLOSION:
                spriteRec = sheet->explosao_amarela;
>>>>>>> Stashed changes
                break;
            default:
                break;
        }
<<<<<<< Updated upstream
=======
        drawing_sprite(sheet,
                       spriteRec,
                       drawX,
                       drawY,
                       scale);
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
=======
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
            case ENTITY_BRIDGE:
                original = gameSprites.ponte_nivel;
                break;
            default:
                continue;
        }

        float hitW, hitH;

        if(e->type == ENTITY_BRIDGE){
            hitW = 40.0f;
            hitH = 20.0f;
        } else {
            hitW = original.width * 0.6f;
            hitH = original.height * 0.6f;
        }
>>>>>>> Stashed changes

        Rectangle entityRect = {
            e->position.x,
            e->position.y,
<<<<<<< Updated upstream
            PLAYER_WIDTH,
            PLAYER_HEIGHT
=======
            hitW,
            hitH
>>>>>>> Stashed changes
        };

        if(CheckCollisionRecs(playerRect, entityRect)){
            if(e->type == ENTITY_FUEL){
                e->active = false;
                return ENTITY_FUEL;
            }
            return e->type;
        }
    }

    return ENTITY_NONE;
}

int checkBulletCollision(Vector2 bulletPosition){
    Rectangle bulletRect = {bulletPosition.x, bulletPosition.y, 4, 10};

    for(int i = 0; i < MAX_ENTITIES; i++){
        if(!entities[i].active)
           continue;

        ENTITY* e = &entities[i];

<<<<<<< Updated upstream
        if(e->type == ENTITY_HELI || e->type == ENTITY_SHIP){
            Rectangle entityRect = {
                e->position.x,
                e->position.y,
                PLAYER_WIDTH,
                PLAYER_HEIGHT
            };

            if(CheckCollisionRecs(bulletRect, entityRect)){
                e->active = false;

                if(e->type == ENTITY_HELI)
                    return 60;
                else if(e->type == ENTITY_SHIP)
                    return 30;
=======
        if(e->type != ENTITY_HELI && e->type != ENTITY_SHIP && e-> type != ENTITY_BRIDGE)
            continue;

        Rectangle entityRect = {
            e->position.x,
            e->position.y,
            40,
            20
        };

        if(CheckCollisionRecs(bulletRect, entityRect)){
            int points = 0;

            if(e->type == ENTITY_BRIDGE){
                float bridgeY = e->position.y;

                for(int j = 0; j < MAX_ENTITIES; j++){
                    if(entities[j].active && entities[j].type == ENTITY_BRIDGE){
                        if(abs(entities[j].position.y - bridgeY) < 5){
                            entities[j].type = ENTITY_EXPLOSION;
                            entities[j].timer = 0.3f;
                        }
                    }
                }
                points = 200;
>>>>>>> Stashed changes
            }
            else {
                if(e->type == ENTITY_HELI)
                    points = 60;
                else if(e->type == ENTITY_SHIP)
                    points = 30;

                e->type = ENTITY_EXPLOSION;
                e->timer = 0.3f;
            }

            return points;
        }
    }
    return 0;
}
