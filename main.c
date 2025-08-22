#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 600

#include "raylib.h"
#include "poniko.c"
#include "screen_main.c"

Poniko poniko;

int main(void) {
    currentScreen TitleScreen = TITLE;
    InitWindow(SCREEN_HEIGHT, SCREEN_WIDTH, "omg Poniko Simulator");
    setGameplayScreen();
    SetPoniko();
    //window
        
    while (!WindowShouldClose()) {   
        switch (TitleScreen) {
            case TITLE: {
                if (IsKeyPressed(KEY_ENTER)) {
                    TitleScreen = GAMEPLAY;
                }
            } break;
                default: break;
        }    
        UpdatePoniko();
        
        BeginDrawing();
        switch(TitleScreen) {
            case TITLE:
            {
                DrawTexture(title, 0, 0, WHITE);
                
            } 
            break;
            case GAMEPLAY:
            {
                drawGameplayScreen();           
                DrawPoniko();             
            }
            break;
            default: break;
        }           
        EndDrawing();
    }
    CloseWindow();
    
    return 0;
}