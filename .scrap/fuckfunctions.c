#include "raylib.h"

int main(void) {
    InitWindow(700, 700, "omg Poniko Simulator");
    
    Texture2D ponikoFrontSprite = LoadTexture("PonikoSprite/Poniko_FrontSheet.png");
    void ihateeverything(void) {
        DrawTexture(ponikoFrontSprite, 0, 0, WHITE);
    }
    //window
    while (!WindowShouldClose()) {
        
        BeginDrawing();
            ClearBackground(WHITE);
            ihateeverything();
        EndDrawing();
    }
    CloseWindow();
    
    return 0;
}