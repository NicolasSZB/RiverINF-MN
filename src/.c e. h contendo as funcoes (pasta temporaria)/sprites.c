#include "raylib.h"
#include "sprite.h"

#define ARQUIVOSPRITE "sprites.png"


SpriteSheet Carregarsprites(void){
    SpriteSheet sheet = {0};

    sheet.arquivo = LoadTexture(ARQUIVOSPRITE);

//PLAYER & BULLET

    sheet.jogador_aviao_reto = {101.0f,68.0f,57,57};
    sheet.jogador_aviao_direita = {169.0f,71.0f,42,58};

    sheet.jogador_aviao_esquerda= {49.0f,74.0f,42,56};

    sheet.bala = {22.0f,85.0f,9,32};


// ENEMIES

    sheet.helicoptero = {10.0f,184.0f,64,41};
    sheet.jato_inimigo = {159.0f,197.0f,65,25};
    sheet.lancha = {15.0f,234.0f,128,32};

// EFFECTS
    sheet.fuel = {611.0f,61.0f,56,96};
    sheet.explosao_amarela = {30.0f,314.0f,56,44};

    // BACKGROUND

    sheet.ponte_nivel = {685.0f,64.0f,254,89};
    sheet.estrada = {267.0f,58.0f,64,104};

    sheet.campo_verde = {335.0f,62.0f,126,95};

    sheet.hipotenusa_esquerda = {335.0f,25.0f,127,32};

    sheet.hipotenusa_esquerda_invertida = {334.0f,162.0f,128,32};

    sheet.hipotenusa_direita = {467.0f,25.0f,128,32};

    sheet.hipotenusa_direita_invertida = {467.0f,161.0f,128,32};

    sheet.campo_verde_casa = {467.0f,62.0f,128,96};


    //INTERFACE

    sheet.fuel_bar = {295.0f,265.0f,312,61};

    sheet.activision_logo = {350.0f,337.0f,257,28};

    sheet.um= {294.0f,385.0f,32,32};
    sheet.dois= {336.0f,385.0f,48,32};
    sheet.tres= {390.0f,385.0f,48,32};
    sheet.quatro= {446.0f,385.0f,48,32};
    sheet.cinco= {502.0f,385.0f,48,32};
    sheet.seis= {558.0f,385.0f,48,32};
    sheet.sete= {615.0f,385.0f,48,32};
    sheet.oito= {670.0f,385.0f,48,32};
    sheet.nove= {726.0f,385.0f,48,32};
    sheet.zero={782.0f,385.0f,48,32};

    return sheet;
}

void drawing_sprite(SpriteSheet *sprite,Rectangle sprite_corte,float x,float y){
   const float escala= 1.0f;
   const float rotacao = 0.0f;

   Rectangle sprite_cortado = sprite_corte;

   float largura_final = sprite_cortado.width*escala;
   float altura_final = sprite_cortado.height*escala;

   Rectangle destino={x,y,largura_final,altura_final};

   Vector2 origem = {0.0f,0.0f};

   DrawTexturePro(sprite->arquivo,sprite_cortado,destino,origem,rotacao,WHITE);

}

void unload_sprite(SpriteSheet *sheet){
    if(sheet != false && sheet->arquivo.id != 0){
        UnloadTexture(sheet.arquivo);
    }
}
