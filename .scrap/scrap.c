#include <raylib.h>
#include "main.h"
#include "button.h"

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Poniko test");
    
    Texture2D ponikoFrontSprite = LoadTexture(spriteFront);
    Texture2D ponikoBackSprite = LoadTexture(spriteBack);
    Texture2D ponikoRightSprite = LoadTexture(spriteRight);
    Texture2D ponikoLeftSprite = LoadTexture(spriteLeft);
    
    Texture2D MainMenu = LoadTexture(MainPage);
    Texture2D mainButton = LoadTexture(MainButton);
    Texture2D ponikoRoomLight = LoadTexture(lightBackgroundPath);
    //Frame att
    int frameWidth = ponikoFrontSprite.width/ 4;
    //int frameHeight = ponikoFrontSprite.height / 4;
    
    Rectangle frameBorder = {20, 0, frameWidth, 63};
    Rectangle btnBounds = {SCREEN_WIDTH / 2 - 250, SCREEN_HEIGHT / 2 + 50};
    Vector2 mousePos = {0.0f, 0.0f};
    Vector2 position = {SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2};
    int currentFrame = 0;
    float frameCounter = 0;
    float frameSpeed = 4.0f;
    TitleScreen currentScreen = TITLE;
 
    //WINDOW
    while (!WindowShouldClose()) {
        switch (currentScreen) {
            case TITLE: {
                if (IsKeyPressed(KEY_ENTER)) {
                    currentScreen = GAMEPLAY;
                }
            } break;
                default: break;
        }
        if (IsKeyDown(KEY_RIGHT) && position.x < SCREEN_WIDTH - ponikoFrontSprite.width) position.x += 0.01f;
        if (IsKeyDown(KEY_LEFT) && position.x > 0) position.x -= 0.01f;
        if (IsKeyDown(KEY_DOWN) && position.y < SCREEN_HEIGHT - 220 - ponikoFrontSprite.height) position.y += 0.01f;
        if (IsKeyDown(KEY_UP) && position.y > 300) position.y -= 0.01f;      
        
        frameCounter += GetFrameTime() * frameSpeed;
        
        if (frameCounter >= 1) {
            currentFrame++;
            frameCounter = 0;
            if (currentFrame > 3) {
                currentFrame = 0;
            }
        }
        frameBorder.x = currentFrame * frameWidth;

        BeginDrawing();
        switch(currentScreen) {
            case TITLE:
            {
                mousePos = GetMousePosition();
                DrawTexture(MainMenu, 0, 0, WHITE);
                if (CheckCollisionPointRec(mousePos, btnBounds)) {
                    DrawTexture(mainButton, SCREEN_WIDTH / 2 - 250, SCREEN_HEIGHT / 2 + 50, BLACK);
                } else {
                    DrawTexture(mainButton, SCREEN_WIDTH / 2 - 250, SCREEN_HEIGHT / 2 + 50, WHITE);                    
                }                
            } 
            break;
            case GAMEPLAY:
            {
                DrawTexture(ponikoRoomLight, 0, 0, WHITE);
                Rectangle source = (Rectangle){0,0,63,63};
                
                if(IsKeyDown(KEY_DOWN)) {
                    DIR_LAST = DIR_DOWN;
                    DrawTextureRec(ponikoFrontSprite, frameBorder, position, WHITE);
                } else if(IsKeyDown(KEY_UP)) {
                    DIR_LAST = DIR_UP;
                    DrawTextureRec(ponikoBackSprite, frameBorder, position, WHITE);
                } else if(IsKeyDown(KEY_RIGHT)) {
                    DIR_LAST = DIR_RIGHT;
                    DrawTextureRec(ponikoRightSprite, frameBorder, position, WHITE);
                } else if(IsKeyDown(KEY_LEFT)) {
                    DIR_LAST = DIR_LEFT;
                    DrawTextureRec(ponikoLeftSprite, frameBorder, position, WHITE);
                } else {             
                if (DIR_LAST == DIR_DOWN) {
                    DrawTextureRec(ponikoFrontSprite, source, position, WHITE);
                } else if (DIR_LAST == DIR_UP) {
                    DrawTextureRec(ponikoBackSprite, source, position, WHITE); 
                } else if (DIR_LAST == DIR_LEFT){
                    DrawTextureRec(ponikoLeftSprite, source, position, WHITE); 
                } else if (DIR_LAST == DIR_RIGHT){
                    DrawTextureRec(ponikoRightSprite, source, position, WHITE); 
                } else {
                    DrawTextureRec(ponikoFrontSprite, source, position, WHITE);
                }
                };                
            }
            break;
            default: break;
        }        
            ClearBackground(RAYWHITE);
        EndDrawing();
    }
    UnloadTexture(ponikoFrontSprite);
    UnloadTexture(ponikoRoomLight);
    CloseWindow();
    
    return 0;
}

