#include <stdio.h>

#include "config.h"
#include "map.h"
#include "game.h"
#include "entities.h"

void loadLevel(int currentLevel, char* filename, char map[MAP_HEIGHT][MAP_WIDTH]){
    sprintf(filename, "levels/fase%d.txt", currentLevel);
    loadMap(filename, map);
    loadEntitiesFromMap(map);
}
