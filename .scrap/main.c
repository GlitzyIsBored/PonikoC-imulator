#include "raylib.h"
#include "poniko.h"
#include "main.h"

Poniko poniko;

void DrawPoniko();

int main(void) {
    InitWindow(SCREEN_HEIGHT, SCREEN_WIDTH, "omg Poniko Simulator");
    void SetPoniko();
    SetPoniko();
    //window
    while (!WindowShouldClose()) {
        
        BeginDrawing();
            ClearBackground(omgpurple);
            void DrawPoniko();
        EndDrawing();
    }
    CloseWindow();
    
    return 0;
}