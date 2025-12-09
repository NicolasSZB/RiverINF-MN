#include "map.h"
#include "config.h"
#include "player.h"
#include "raylib.h"
#include "entities.h"
#include "game.h"
#include "bullet.h"
#include "hud.h"
<<<<<<< Updated upstream
=======
#include "sprite.h"
#include "scoring.h"
#include "audio.h"
>>>>>>> Stashed changes

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

<<<<<<< Updated upstream
=======
SpriteSheet gameSprites;

>>>>>>> Stashed changes
int main(void){
    char map[MAP_HEIGHT][MAP_WIDTH];
    int currentLevel = 1;
    char mapFilename[50];

    PLAYER myPlayer;
<<<<<<< Updated upstream
    GAMESTATE currentState = STATE_GAMEPLAY;

    InitWindow(WIDTH, HEIGHT, "RiverINF");
=======
    GAMESTATE currentState = STATE_MAINMENU;//STATE_GAMEPLAY;
    GAMESTATE *gamestate = &currentState; // teste

    InitWindow(WIDTH, HEIGHT, "RiverINF");
    initAudio();
    playMusic();

    gameSprites = Carregarsprites();
    int sair = 0;

>>>>>>> Stashed changes
    loadLevel(currentLevel, mapFilename, map);
    initPlayer(&myPlayer, map);
    initBullets();
    SetTargetFPS(60);

<<<<<<< Updated upstream
    while(!WindowShouldClose()){

=======
    HIGHSCORE highscores [MAX_HIGHSCORES];
    loadHighScores(highscores);

    char playerName[NAME_MAX_LEN + 2];
    int letterCount = 0;

    while(!WindowShouldClose()&& sair == 0){
        updateMusic();
>>>>>>> Stashed changes
        switch(currentState){
            case STATE_GAMEPLAY:
                bool levelComplete = updatePlayer(&myPlayer, map);
                if(levelComplete){
                    currentLevel++;
                    loadLevel(currentLevel, mapFilename, map);
                    resetPlayerPosition(&myPlayer, map);
                }
                int scoreBullets = updateBullets(map);
                updateEntities(map);
                if(scoreBullets > 0){
                    myPlayer.score += scoreBullets;

                    int oldScore = myPlayer.score - scoreBullets;
                    int newScore = myPlayer.score;

                    if((oldScore / 1000) < (newScore/1000))
                       myPlayer.life++;
                }
<<<<<<< Updated upstream
                if(myPlayer.life <= 0)
                    currentState = STATE_GAMEOVER;
=======
                if(myPlayer.life <= 0){
                    if(checkNewHighScore(myPlayer.score, highscores)){
                        currentState = STATE_NAMEINPUT;
                        letterCount = 0;
                        for(int i = 0; i < NAME_MAX_LEN; i++)
                            playerName[i] = '\0';
                    }
                        else
                            currentState = STATE_GAMEOVER;
                }

                if(IsKeyPressed(KEY_R)){
                    initPlayer(&myPlayer,map);
                    loadLevel(currentLevel,mapFilename,map);
                }
>>>>>>> Stashed changes
                break;
            case STATE_NAMEINPUT:
                int key = GetCharPressed();
                while (key > 0){
                    if((key >= 32) && (key <= 125) && (letterCount < NAME_MAX_LEN)){
                        playerName[letterCount] = (char)key;
                        playerName[letterCount + 1] = '\0';
                        letterCount++;
                    }
                    key = GetCharPressed();
                }

                if(IsKeyPressed(KEY_BACKSPACE)){
                    letterCount--;
                    if(letterCount < 0)
                        letterCount = 0;
                    playerName[letterCount] = '\0';
                }

                if(IsKeyPressed(KEY_ENTER)){
                    if(letterCount > 0){
                        addHighScore(playerName, myPlayer.score, highscores);
                        currentState = STATE_RANKINGS;
                    }
                }
                break;
            case STATE_GAMEOVER:
                if(IsKeyPressed(KEY_ENTER)){
                    currentLevel = 1;
                    loadLevel(currentLevel, mapFilename, map);
                    initPlayer(&myPlayer, map);
<<<<<<< Updated upstream
                    currentState = STATE_GAMEPLAY;
                }
                break;
=======
                   *gamestate = STATE_GAMEPLAY;
                }
                if(IsKeyPressed(KEY_TAB))
                    *gamestate = STATE_MAINMENU;
                break;
            case STATE_MAINMENU:
                 if(IsKeyPressed(KEY_ENTER)){
                    *gamestate = STATE_OPTIONS;
                 }
                break;
            case STATE_OPTIONS:
                float btnWidth = 300;
                float btnHeight = 50;
                float btnX = (WIDTH - btnWidth)/2;
                float btnY = HEIGHT/2 - 50;
                float spacing = 70;

                Rectangle button_newgame = {btnX, btnY, btnWidth, btnHeight};
                Rectangle button_rankings = {btnX, btnY + spacing, btnWidth, btnHeight};
                Rectangle button_sair = {btnX, btnY + spacing*2, btnWidth, btnHeight};

                Vector2 mouse_position = GetMousePosition();

                    if(CheckCollisionPointRec(mouse_position,button_newgame)){
                        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
                           currentLevel = 1;
                           loadLevel(currentLevel,mapFilename,map);
                           initPlayer(&myPlayer,map);
                           *gamestate = STATE_GAMEPLAY;
                        }
                    }
                if(CheckCollisionPointRec(mouse_position,button_rankings)){
                    if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
                        *gamestate = STATE_RANKINGS;
                }
                  if(CheckCollisionPointRec(mouse_position,button_sair)){
                    if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
                        sair = 1;
                }

                break;

            case STATE_RANKINGS:
                if(IsKeyPressed(KEY_TAB) || IsKeyPressed(KEY_ENTER))
                    currentState = STATE_OPTIONS;
                break;
>>>>>>> Stashed changes
        }

        BeginDrawing();
        ClearBackground(LIME);

        switch(currentState){
            case STATE_GAMEPLAY:
                drawMap(map);
                drawPlayer(myPlayer);
                drawBullets();
                drawEntities();
                drawHud(myPlayer, currentLevel);
                break;
            case STATE_GAMEOVER:
                DrawText("GAME OVER",
                         WIDTH/2 - MeasureText("GAME OVER", 40) / 2,
                         HEIGHT/2 - 40, 40, YELLOW);
                DrawText("Pressione ENTER para reiniciar",
                         WIDTH/2 - MeasureText("Pressione ENTER para reiniciar", 20) / 2,
                         HEIGHT/2 + 20, 20, YELLOW);
                break;
<<<<<<< Updated upstream
        }
        EndDrawing();
    };

=======
            case STATE_NAMEINPUT:
                DrawText("Novo Recorde!", WIDTH/2 - MeasureText("Novo Recorde!", 40)/2, 100, 40, YELLOW);
                DrawText(TextFormat("Pontuacao: %d", myPlayer.score), WIDTH/2 - MeasureText(TextFormat("Pontuacao: %d", myPlayer.score), 30)/2, 160, 30, WHITE);

                DrawText("Digite seu nome: ", WIDTH/2 - MeasureText("Digite seu nome: ", 20)/2, 250, 20, WHITE);

                DrawRectangleLines(WIDTH/2 - 100, 300, 200, 50, YELLOW);
                DrawText(playerName, WIDTH/2 - MeasureText(playerName, 30)/2, 310, 30, WHITE);

                DrawText("Pressione ENTER para salvar", WIDTH/2 - MeasureText("Pressione ENTER para salvar", 20)/2, 400, 20, GREEN);
                break;
            case STATE_RANKINGS:
                DrawText("TOP 5 PILOTOS", WIDTH/2 - MeasureText("TOP 5 PILOTOS", 40)/2, 50, 40, YELLOW);

                for(int i = 0; i < MAX_HIGHSCORES; i++){
                    DrawText(TextFormat ("%d. %s", i+1, highscores[i].name),
                             WIDTH/2 - 150,
                             150 + (i * 40),
                             30, WHITE);
                    DrawText(TextFormat("%05d", highscores[i].score),
                             WIDTH/2 + 50,
                             150 + (i * 40),
                             30, YELLOW);
                }
                DrawText("Pressione TAB para voltar", WIDTH/2 - MeasureText("Pressione TAB para voltar", 20)/2, HEIGHT - 40, 20, LIGHTGRAY);
                break;
            case STATE_MAINMENU:
                DrawText("RIVER INF", WIDTH/2 - MeasureText("RIVER INF",20)-30,HEIGHT/3,50,YELLOW);
                DrawText("Pressione Enter para Iniciar", WIDTH/2 - MeasureText("Pressione Enter para Iniciar",20)+ 10,HEIGHT/2,40,YELLOW);
                break;
            case STATE_OPTIONS:
                char* title = "RIVERINF-MN";
                int titleSize = 60;
                int titleWidth = MeasureText(title, titleSize);
                DrawText(title, (WIDTH - titleWidth)/2, 100, titleSize, YELLOW);

                float btnWidth = 300;
                float btnHeight = 50;
                float btnX = (WIDTH - btnWidth)/2;
                float btnY = HEIGHT/2 - 50;
                float spacing = 70;
                int fontSize = 30;

                DrawRectangle(btnX, btnY, btnWidth, btnHeight, BLUE);
                DrawRectangleLines(btnX, btnY, btnWidth, btnHeight, YELLOW);
                int newgameW = MeasureText("Novo Jogo", fontSize);
                DrawText("Novo Jogo", btnX + (btnWidth - newgameW)/2, btnY + 10, fontSize, YELLOW);

                DrawRectangle(btnX, btnY + spacing, btnWidth, btnHeight, BLUE);
                DrawRectangleLines(btnX, btnY + spacing, btnWidth, btnHeight, YELLOW);
                int rankingW = MeasureText("Ranking", fontSize);
                DrawText("Ranking", btnX + (btnWidth - rankingW)/2, btnY + spacing + 10, fontSize, YELLOW);

                DrawRectangle(btnX, btnY + spacing*2, btnWidth, btnHeight, BLUE);
                DrawRectangleLines(btnX, btnY + spacing*2, btnWidth, btnHeight, YELLOW);
                int exitW = MeasureText("Sair", fontSize);
                DrawText("Sair",btnX + (btnWidth - exitW)/2, btnY + spacing*2 + 10, fontSize, YELLOW);
                break;
            }
        EndDrawing();
    }
    unload_sprite(&gameSprites);
    closeAudio();
>>>>>>> Stashed changes
    CloseWindow();
    return 0;
}
