#include "raylib.h"
#include "sprite.h"
#define TILE 40
#define ARQUIVOSPRITE "sprites.png"
#include<stdlib.h>
#include<stdio.h>


SpriteSheet Carregarsprites(void){
    SpriteSheet sheet = {0};

    sheet.arquivo = LoadTexture(ARQUIVOSPRITE);

//PLAYER & BULLET

    sheet.jogador_aviao_reto = (Rectangle){101.0f,68.0f,57,57};//57,57
    sheet.jogador_aviao_direita = (Rectangle){169.0f,71.0f,42,58};

    sheet.jogador_aviao_esquerda= (Rectangle){49.0f,74.0f,42,56};

    sheet.bala = (Rectangle){22.0f,85.0f,9,32};


// ENEMIES

    sheet.helicoptero = (Rectangle){10.0f,184.0f,64,41};
    sheet.jato_inimigo = (Rectangle){159.0f,197.0f,65,25};
    sheet.lancha = (Rectangle){10.0f,231.0f,39,19};

// EFFECTS
    sheet.fuel =(Rectangle){611.0f,61.0f,56,96};
    sheet.explosao_amarela = (Rectangle){30.0f,314.0f,56,44};

    // BACKGROUND

    sheet.ponte_nivel =(Rectangle) {685.0f,64.0f,254,89};
    sheet.estrada = (Rectangle){267.0f,58.0f,64,104};

    sheet.campo_verde =(Rectangle) {335.0f,62.0f,126,95};

    sheet.hipotenusa_esquerda =(Rectangle){335.0f,25.0f,127,32};

    sheet.hipotenusa_esquerda_invertida = (Rectangle){334.0f,162.0f,128,32};

    sheet.hipotenusa_direita =(Rectangle) {467.0f,25.0f,128,32};

    sheet.hipotenusa_direita_invertida =(Rectangle) {467.0f,161.0f,128,32};

    sheet.campo_verde_casa =(Rectangle) {467.0f,62.0f,128,96};


    //INTERFACE

    sheet.fuel_bar =(Rectangle) {295.0f,265.0f,312,61};

    sheet.activision_logo = (Rectangle){350.0f,337.0f,257,28};

    sheet.um= (Rectangle){294.0f,385.0f,32,32};
    sheet.dois= (Rectangle){336.0f,385.0f,48,32};
    sheet.tres= (Rectangle){390.0f,385.0f,48,32};
    sheet.quatro= (Rectangle){446.0f,385.0f,48,32};
    sheet.cinco= (Rectangle){502.0f,385.0f,48,32};
    sheet.seis= (Rectangle){558.0f,385.0f,48,32};
    sheet.sete= (Rectangle){615.0f,385.0f,48,32};
    sheet.oito= (Rectangle){670.0f,385.0f,48,32};
    sheet.nove= (Rectangle){726.0f,385.0f,48,32};
    sheet.zero=(Rectangle){782.0f,385.0f,48,32};

    return sheet;
}

void drawing_sprite(SpriteSheet *sprite,Rectangle sprite_corte,float x,float y,float escala){
   const float rotacao = 0.0f;

   float largura_final = sprite_corte.width*escala;
   float altura_final = sprite_corte.height*escala;

   Rectangle destino={x,y,largura_final,altura_final};

   Vector2 origem = {0.0f,0.0f};

   DrawTexturePro(sprite->arquivo,sprite_corte,destino,origem,rotacao,WHITE);

}

void unload_sprite(SpriteSheet *sheet){
    if(sheet !=NULL && sheet->arquivo.id != 0){
        UnloadTexture(sheet->arquivo);
    }
}
