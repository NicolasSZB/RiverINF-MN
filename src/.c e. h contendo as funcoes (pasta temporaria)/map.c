#include "map.h"
#include <stdio.h>
#include "raylib.h"

void loadMap(const char* filename, char map[MAP_HEIGHT][MAP_WIDTH]){
    FILE* file = fopen(filename, "r")

    if(file == NULL)
        printf("ERRO! Não foi possível ler o arquivo de mapa!");
    else{
        for(int i = 0; i < MAP_HEIGHT; i++){
            for(int j = 0; j < MAP_WIDTH; j++){

            }
        }
    }
}
