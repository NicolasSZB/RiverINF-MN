#include "raylib.h"
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

#define MAP_WIDTH 20
#define MAP_HEIGHT 24

#define PLAYER_SPEED 3.0f
#define PLAYER_WIDTH 20.0f
#define PLAYER_HEIGHT 20.0f

int main(){
    char map[MAP_HEIGHT][MAP_WIDTH];

    Vector2 playerPosition = {
        (float)WIDTH/2 - PLAYER_WIDTH/2,
        (float)HEIGHT/2 - PLAYER_HEIGHT/2
    };

    InitWindow(WIDTH, HEIGHT, "RiverINF");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangleV(playerPosition, (Vector2){PLAYER_WIDTH, PLAYER_HEIGHT}, YELLOW);
        EndDrawing();

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
    }

    CloseWindow();
    return 0;
}
