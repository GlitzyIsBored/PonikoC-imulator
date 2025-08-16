#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 600

#include "raylib.h"
#include "poniko.c"
#include "screen_main.c"

Poniko poniko;

int main(void) {
    InitWindow(SCREEN_HEIGHT, SCREEN_WIDTH, "omg Poniko Simulator");
    setGameplayScreen();
    SetPoniko();
    //window
        
    while (!WindowShouldClose()) {
        UpdatePoniko();
        
        BeginDrawing();
            ClearBackground(WHITE);
            drawGameplayScreen();
            DrawPoniko();
        EndDrawing();
    }
    CloseWindow();
    
    return 0;
}