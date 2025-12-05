#include "map.h"
#include "raylib.h"
#include <stdio.h>

void loadMap(const char* filename, char map[MAP_HEIGHT][MAP_WIDTH]){
    FILE* file = fopen(filename, "r");
    printf("Tentando abrir: %s\n", filename);
    if(file == NULL){
        printf("ERRO! Não foi possível ler o arquivo de mapa!");
        return;
    }
    else {
        for (int i = 0; i < MAP_HEIGHT; i++){
            for (int j = 0; j < MAP_WIDTH; j++){
                char c = fgetc(file);
                if (feof(file))
                    map[i][j] = ' ';
                else
                    map[i][j] = c;
            }
            char extra_c;
            do {
                extra_c = fgetc(file);
            } while (extra_c != '\n' && extra_c != EOF);
        }

        fclose(file);
    }
}

void drawMap(const char map[MAP_HEIGHT][MAP_WIDTH]){
    for(int i = 0; i < MAP_HEIGHT; i++){
        for(int j = 0; j < MAP_WIDTH; j++){
            int posY = i * TILE_SIZE;
            int posX = j * TILE_SIZE;
            char tile = map[i][j];

            if(tile == 'T')
                DrawRectangle(posX, posY, TILE_SIZE, TILE_SIZE, LIME);
        }
    }
}
