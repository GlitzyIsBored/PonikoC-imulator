#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 600

#include "raylib.h"
#include "poniko.c"
#include "screen_main.c"

Poniko poniko;

int main(void) {
    currentScreen TitleScreen = TITLE;
    InitWindow(SCREEN_HEIGHT, SCREEN_WIDTH, "omg Poniko Simulator");
    //omg Icon
    SetWindowIcon(LoadImage("Other/ponICON.png"));
    
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
                int btnIndex = 0;
                float btnTime = 1.0;
                Rectangle btnSource = (Rectangle){btnIndex * 2,0, 480, 175};
                if (btnTime < 0) {
                    btnTime = 1;
                    btnIndex++;
                    if (btnIndex >= 1) {
                        btnIndex = 0;
                    }
                }      
                btnTime -= GetFrameTime();         
        BeginDrawing();
        switch(TitleScreen) {
            case TITLE:
            {
                DrawTexture(title, 0, 0, WHITE);
                DrawTextureRec(button, btnSource, (Vector2){55 ,350}, WHITE);
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