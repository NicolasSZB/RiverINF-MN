#ifndef SPRITES_H
#define SPRITES_H
#include "raylib.h"

typedef struct {
    Texture2D  arquivo;

    //PLAYER & BULLET

    Rectangle jogador_aviao_reto;
    Rectangle jogador_aviao_direita;
    Rectangle jogador_aviao_esquerda;
    Rectangle bala;

    //ENEMIES

    Rectangle helicoptero;
    Rectangle jato_inimigo;
    Rectangle lancha;

    //EFFECTS

    Rectangle fuel;
    Rectangle explosao_amarela;

    // BACKGROUND

    Rectangle ponte_nivel;
    Rectangle estrada;
    Rectangle campo_verde;
    Rectangle hipotenusa_esquerda;
    Rectangle hipotenusa_esquerda_invertida;
    Rectangle hipotenusa_direita;
    Rectangle hipotenusa_direita_invertida;
    Rectangle campo_verde_casa;

    // INTERFACE

    Rectangle fuel_bar;
    Rectangle activision_logo;
    Rectangle um;
    Rectangle dois;
    Rectangle tres;
    Rectangle quatro;
    Rectangle cinco;
    Rectangle seis;
    Rectangle sete;
    Rectangle oito;
    Rectangle nove;
    Rectangle zero;
}SpriteSheet;

//PROTOTIPO FUNCOES

SpriteSheet Carregarsprites(void);
void drawing_sprite(SpriteSheet *sheet, Rectangle sprite, float x,float y);
void unload_sprite(SpriteSheet *sheet);

#endif // SPRITES_H
