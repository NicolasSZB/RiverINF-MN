#include "map.h"
#include "config.h"
#include "player.h"
#include "raylib.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(void){
    char map[MAP_HEIGHT][MAP_WIDTH];
    int currentLevel = 1;
    char mapFilename[50];

    PLAYER myPlayer;
    initPlayer(&myPlayer);

    InitWindow(WIDTH, HEIGHT, "RiverINF");
    SetTargetFPS(60);

    sprintf(mapFilename, "levels/fase%d.txt", currentLevel);
    loadMap(mapFilename, map);
    while(!WindowShouldClose()){
        bool levelComplete = updatePlayer(&myPlayer);
        if(levelComplete){
            currentLevel++;
            sprintf(mapFilename, "levels/fase%d.txt", currentLevel);
            loadMap(mapFilename, map);
            resetPlayerPosition(&myPlayer);
        }

        BeginDrawing();
        ClearBackground(LIME);
        drawMap(map);
        drawPlayer(myPlayer);
        EndDrawing();
    };

    CloseWindow();
    return 0;
}
