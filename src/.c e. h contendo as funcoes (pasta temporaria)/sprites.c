#include "raylib.h"

#define TAMANHO_PIXEL 57.0f
#define ARQUIVOSPRITE "C:\\Users\\mathe\\OneDrive\\Imagens\\sprites.png"
#define LARGURA 800
#define ALTURA 450

int main(void){

    InitWindow(LARGURA,ALTURA,"TESTE SPRITE");
    SetTargetFPS(60);

    Texture2D arquivo = LoadTexture(ARQUIVOSPRITE);

    Rectangle jogador_aviao_reto = {
            101.0f,68.0f,57,57// PEGA PRIMEIRO AVIAO DO INDO RETO
            };

    Rectangle jogador_aviao_direita = {
        169.0f,71.0f,42,58
    };

    Rectangle jogador_aviao_esquerda= {
        49.0f,74.0f,42,56
    };

    Rectangle bala = {
        22.0f,85.0f,9,32
    };

    Rectangle helicoptero = {
        10.0f,184.0f,64,41
    };
    Rectangle explosao_amarela = {
        30.0f,314.0f,56,44
    };
    Rectangle fuel = {
        611.0f,61.0f,56,96
    };

    Rectangle ponte_nivel = {
        685.0f,64.0f,254,89
    }
    Rectangle estrada = {
        267.0f,58.0f,64,104
    };

    Rectangle campo_verde = {
        335.0f,62.0f,126,95
    };

    Rectangle hipotenusa_esquerda = {
        335.0f,25.0f,127,32
    };

    Rectangle hipotenusa_esquerda_invertida = {
        334.0f,162.0f,128,32
    };

    Rectangle explosao_amarela = {
        30.0f,314.0f,56,44
    };
 /*   Vector2 posicao_aviao_reto = {
            (float)LARGURA/2 - TAMANHO_PIXEL/2,
            (float)ALTURA  - TAMANHO_PIXEL - 20
        };// POSICAO ONDE VAI FICAR NA JANELA DO JOGO
    Vector2 posicao_aviao_direita = {
            (float)LARGURA/2 - 58,
            (float)ALTURA  - 30
        };// POSICAO ONDE VAI FICAR NA JANELA DO JOGO
*/
       while(!WindowShouldClose()){
            BeginDrawing();
            ClearBackground(BLUE);

        //DrawTextureRec(arquivo,jogador_aviao_reto,posicao_aviao_reto,YELLOW);
        //    DrawTextureRec(arquivo,jogador_aviao_direita,posicao_aviao_direita,YELLOW);

            EndDrawing();
       }
       UnloadTexture(arquivo);
       CloseWindow();

       return 0;
}
