#include "map.h"
#include "config.h"
#include "player.h"
#include "raylib.h"
#include "entities.h"
#include "game.h"
#include "bullet.h"
#include "hud.h"
#include "sprite.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

SpriteSheet gameSprites;
int main(void){
    char map[MAP_HEIGHT][MAP_WIDTH];
    int currentLevel = 1;
    char mapFilename[50];
    PLAYER myPlayer;
    GAMESTATE currentState = STATE_MAINMENU;//STATE_GAMEPLAY;
    GAMESTATE *gamestate = &currentState; // teste
    InitWindow(WIDTH, HEIGHT, "RiverINF");
    gameSprites = Carregarsprites();
    int sair =0;
    loadLevel(currentLevel, mapFilename, map);
    initPlayer(&myPlayer, map);
    initBullets();
    SetTargetFPS(60);

    float rec_width= WIDTH*0.2,rec_height= HEIGHT*0.2;
    int font_size = 40;

    while(!WindowShouldClose()&& sair == 0){

        switch(currentState){
            case STATE_GAMEPLAY:
                bool levelComplete = updatePlayer(&myPlayer, map);
                if(levelComplete){
                    currentLevel++;
                    loadLevel(currentLevel, mapFilename, map);
                    resetPlayerPosition(&myPlayer, map);
                }
                int scoreBullets = updateBullets();
                if(scoreBullets > 0){
                    myPlayer.score += scoreBullets;

                    int oldScore = myPlayer.score - scoreBullets;
                    int newScore = myPlayer.score;

                    if((oldScore / 1000) < (newScore/1000))
                       myPlayer.life++;
                }
                if(myPlayer.life <= 0)
                    //currentState
                    *gamestate = STATE_GAMEOVER;
            //A PARTIR DAQUI TESTE DE R (REINICIAR NIVEL)
                if(IsKeyPressed(KEY_R)){
                    initPlayer(&myPlayer,map);
                    loadLevel(currentLevel,mapFilename,map);
                }
                break;
            case STATE_GAMEOVER:
                if(IsKeyPressed(KEY_ENTER)){
                    currentLevel = 1;
                    loadLevel(currentLevel, mapFilename, map);
                    initPlayer(&myPlayer, map);
                   // currentState = STATE_GAMEPLAY;
                   *gamestate = STATE_GAMEPLAY;
                }
                if(IsKeyPressed(KEY_TAB)){
                    //currentState = STATE_MAINMENU;
                    *gamestate = STATE_MAINMENU;
                }
                break;
            case STATE_MAINMENU:
                 if(IsKeyPressed(KEY_ENTER)){
                    *gamestate = STATE_OPTIONS;
                 }
                break;
            case STATE_OPTIONS:
                Vector2 mouse_position = GetMousePosition();
                Rectangle button_newgame = {rec_width-100,rec_height,MeasureText("Novo  Jogo",font_size),font_size};
                Rectangle button_rankings = {rec_width-100,rec_height+60,MeasureText("Ranking ",font_size),font_size};
                Rectangle button_sair = {rec_width-100,rec_height+120,MeasureText("Sair ",font_size),font_size};
                    if(CheckCollisionPointRec(mouse_position,button_newgame)){
                        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
                           // currentState = STATE_GAMEPLAY;
                           currentLevel = 1;
                           loadLevel(currentLevel,mapFilename,map);
                           initPlayer(&myPlayer,map);
                           *gamestate = STATE_GAMEPLAY;
                        }
                    }
                if(CheckCollisionPointRec(mouse_position,button_rankings)){
                        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
                        *gamestate = STATE_RANKINGS;
                    }
                }
                  if(CheckCollisionPointRec(mouse_position,button_sair)){
                        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
                                sair = 1;
                    }
                }

                        break;
        }

        BeginDrawing();
        ClearBackground(BLUE);

        switch(currentState){
            case STATE_GAMEPLAY:
                drawMap(map);
                drawPlayer(myPlayer, &gameSprites);
                drawBullets();
                drawEntities(&gameSprites);
                drawHud(myPlayer, currentLevel);
                break;
            case STATE_GAMEOVER:
                DrawText("GAME OVER",
                         WIDTH/2 - MeasureText("GAME OVER", 40) / 2,
                         HEIGHT/2 - 40, 40, YELLOW);
                DrawText("Pressione ENTER para reiniciar",
                         WIDTH/2 - MeasureText("Pressione ENTER para reiniciar", 20) / 2,
                         HEIGHT/2 + 20, 20, YELLOW);
                DrawText("Pressione TAB para ir pro Menu",
                         WIDTH/2 -MeasureText("Pressione TAB para ir pro Menu",20)/2,
                         HEIGHT/2 +40,20, YELLOW);
                break;
            case STATE_MAINMENU:
                DrawText("RIVER INF", WIDTH/2 - MeasureText("RIVER INF",20)-30,HEIGHT/3,50,YELLOW);
                DrawText("Pressione Enter para Iniciar", WIDTH/2 - MeasureText("Pressione Enter para Iniciar",20)+ 10,HEIGHT/2,40,YELLOW);
                break;
            case STATE_OPTIONS:
                DrawRectangle(rec_width-100,rec_height,MeasureText("Novo  Jogo",font_size),font_size,BLUE);
                DrawText("Novo Jogo",WIDTH*0.1,rec_height,font_size,YELLOW);

                DrawRectangle(rec_width-100,rec_height+60,MeasureText("Ranking ",font_size),font_size,BLUE);
                DrawText("Ranking",WIDTH*0.10,rec_height+60,font_size,YELLOW);

                DrawRectangle(rec_width-100,rec_height+120,MeasureText("Sair ",font_size),font_size,BLUE);
                DrawText("Sair",WIDTH*0.10,rec_height+120,font_size,YELLOW);
                break;
            case STATE_RANKINGS:
                DrawText("Pressione TAB para ir pro Menu",
                         WIDTH/2 -MeasureText("Pressione TAB para ir pro Menu",20)/2,
                         HEIGHT - 20,10, YELLOW);
                continue;
        }
        EndDrawing();
    }
    unload_sprite(&gameSprites);
    CloseWindow();
    return 0;
}
