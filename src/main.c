#include "map.h"
#include "config.h"
#include "player.h"
#include "raylib.h"
#include "entities.h"
#include "game.h"
#include "bullet.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(void){
    char map[MAP_HEIGHT][MAP_WIDTH];
    int currentLevel = 1;
    char mapFilename[50];

    PLAYER myPlayer;
    GAMESTATE currentState = STATE_GAMEPLAY;

    InitWindow(WIDTH, HEIGHT, "RiverINF");
    loadLevel(currentLevel, mapFilename, map);
    initPlayer(&myPlayer, map);
    initBullets();
    SetTargetFPS(60);

    while(!WindowShouldClose()){

        switch(currentState){
            case STATE_GAMEPLAY:
                bool levelComplete = updatePlayer(&myPlayer, map);
                updateBullets();
                if(levelComplete){
                    currentLevel++;
                    loadLevel(currentLevel, mapFilename, map);
                    resetPlayerPosition(&myPlayer, map);
                }
                if(myPlayer.life <= 0)
                    currentState = STATE_GAMEOVER;
                break;
            case STATE_GAMEOVER:
                if(IsKeyPressed(KEY_ENTER)){
                    currentLevel = 1;
                    loadLevel(currentLevel, mapFilename, map);
                    initPlayer(&myPlayer, map);
                    currentState = STATE_GAMEPLAY;
                }
                break;
        }

        BeginDrawing();
        ClearBackground(LIME);

        switch(currentState){
            case STATE_GAMEPLAY:
                drawMap(map);
                drawPlayer(myPlayer);
                drawBullets();
                drawEntities();
                break;
            case STATE_GAMEOVER:
                DrawText("GAME OVER",
                         WIDTH/2 - MeasureText("GAME OVER", 40) / 2,
                         HEIGHT/2 - 40, 40, YELLOW);
                DrawText("Pressione ENTER para reiniciar",
                         WIDTH/2 - MeasureText("Pressione ENTER para reiniciar", 20) / 2,
                         HEIGHT/2 + 20, 20, YELLOW);
                break;
        }
        EndDrawing();
    };

    CloseWindow();
    return 0;
}
