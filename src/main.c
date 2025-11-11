#include "map.h"
#include "config.h"
#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
    char map[MAP_HEIGHT][MAP_WIDTH];

    Vector2 playerPosition = {
        (float)WIDTH/2 - PLAYER_WIDTH/2,
        (float)(HEIGHT - 50) - PLAYER_HEIGHT/2
    };

    InitWindow(WIDTH, HEIGHT, "RiverINF");
    SetTargetFPS(60);

    loadMap("levels/first.txt", map);
    while(!WindowShouldClose()){

            if(IsKeyDown(KEY_W)|| IsKeyDown(KEY_UP))
                playerPosition.y -= PLAYER_SPEED;
            if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
                playerPosition.x -= PLAYER_SPEED;
            if(IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
                playerPosition.y += PLAYER_SPEED;
            if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
                playerPosition.x += PLAYER_SPEED;

            if(playerPosition.x < 0)
                playerPosition.x = 0;
            else if(playerPosition.x + PLAYER_WIDTH > WIDTH)
                playerPosition.x = WIDTH - PLAYER_WIDTH;

            if(playerPosition.y < 0)
                playerPosition.y = 0;
            else if(playerPosition.y + PLAYER_HEIGHT > HEIGHT)
                playerPosition.y = HEIGHT - PLAYER_HEIGHT;

        BeginDrawing();
        ClearBackground(LIME);
        drawMap(map);
        DrawRectangleV(playerPosition, (Vector2){PLAYER_WIDTH, PLAYER_HEIGHT}, YELLOW);
        EndDrawing();
    };

    CloseWindow();
    return 0;
}
