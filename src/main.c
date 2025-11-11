#include "map.h"
#include "config.h"
#include "player.h"
#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
    char map[MAP_HEIGHT][MAP_WIDTH];
    PLAYER myPlayer;
    initPlayer(&myPlayer);

    InitWindow(WIDTH, HEIGHT, "RiverINF");
    SetTargetFPS(60);

    loadMap("levels/first.txt", map);
    while(!WindowShouldClose()){
        updatePlayer(&myPlayer);

        BeginDrawing();
        ClearBackground(LIME);
        drawMap(map);
        drawPlayer(myPlayer);
        EndDrawing();
    };

    CloseWindow();
    return 0;
}
