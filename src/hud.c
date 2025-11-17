#include "raylib.h"
#include "hud.h"

void drawHud(PLAYER player, int level){
    DrawRectangle(0, 0, WIDTH, 40, BLACK);
    DrawText(TextFormat("Vidas: %d", player.life), 10, 10, 20, WHITE);

    Color fuelColor = (player.fuel < 30) ? RED : WHITE;
    DrawText(TextFormat("Fuel: %.0f", player.fuel), 150, 10, 20, fuelColor);

    DrawRectangle(250, 10, 100, 20, DARKGRAY);
    DrawRectangle(250, 10, player.fuel, 20, fuelColor);

    DrawText(TextFormat("Nivel %d", level), 400, 10, 20, YELLOW);

    DrawText(TextFormat("Score: %d", player.score), 600, 10, 20, WHITE);
}
