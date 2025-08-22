#include "raylib.h"
#include "poniko.h"

Poniko poniko;

void SetPoniko(void) {
    //sprite paths
    poniko.ponikoFrontSprite = LoadTexture(spriteFront);   
    poniko.ponikoBackSprite = LoadTexture(spriteBack); 
    poniko.ponikoLeftSprite = LoadTexture(spriteLeft); 
    poniko.ponikoRightSprite = LoadTexture(spriteRight); 
    //set sprites
    poniko.spritePosition = (Vector2){SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2};
    poniko.frameWidth = poniko.ponikoFrontSprite.width / 4;
    poniko.frameBorder = (Rectangle){0, 0, poniko.frameWidth, 63};
    poniko.spriteSpeed = 0.01f;
    //set sprite animation
    poniko.currentFrame = 0;
    poniko.frameCounter = 0;
    poniko.frameSpeed = 4.0f;
}

void UpdatePoniko(void) {
    if (IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_UP) && !IsKeyDown(KEY_DOWN)) {
        if (poniko.spritePosition.x < SCREEN_WIDTH - poniko.ponikoFrontSprite.width) {
            poniko.spritePosition.x += poniko.spriteSpeed;
        }
    }
    if (IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_UP) && !IsKeyDown(KEY_DOWN)) {
        if (poniko.spritePosition.x > 0)  {
            poniko.spritePosition.x -= poniko.spriteSpeed;
        }
    }
    if (IsKeyDown(KEY_DOWN) && poniko.spritePosition.y < SCREEN_HEIGHT - 185 - poniko.ponikoFrontSprite.height) poniko.spritePosition.y += poniko.spriteSpeed;
    if (IsKeyDown(KEY_UP) && poniko.spritePosition.y > 250) poniko.spritePosition.y -= poniko.spriteSpeed;     
    
    poniko.frameCounter += GetFrameTime() * poniko.frameSpeed;
    
    if (poniko.frameCounter >= 1) {
        poniko.currentFrame++;
        poniko.frameCounter = 0;
        if (poniko.currentFrame > 3) {
            poniko.currentFrame = 0;
        }
    }
    poniko.frameBorder.x = poniko.currentFrame * poniko.frameWidth;
     
}

void DrawPoniko(void) {
    Rectangle source = (Rectangle){0,0,63,63};
    //DrawTextureRec(poniko.ponikoFrontSprite, poniko.frameBorder, poniko.spritePosition, WHITE);
    if (IsKeyDown(KEY_DOWN)) {
        DIR_LAST = DIR_DOWN;
        DrawTextureRec(poniko.ponikoFrontSprite, poniko.frameBorder, poniko.spritePosition, WHITE);
    } else if(IsKeyDown(KEY_UP)) {
        DIR_LAST = DIR_UP;
        DrawTextureRec(poniko.ponikoBackSprite, poniko.frameBorder, poniko.spritePosition, WHITE);
    } else if(IsKeyDown(KEY_RIGHT)) {
        DIR_LAST = DIR_RIGHT;
        DrawTextureRec(poniko.ponikoRightSprite, poniko.frameBorder, poniko.spritePosition, WHITE);
    } else if(IsKeyDown(KEY_LEFT)) {
        DIR_LAST = DIR_LEFT;
        DrawTextureRec(poniko.ponikoLeftSprite, poniko.frameBorder, poniko.spritePosition, WHITE);
    } else {
        if (DIR_LAST == DIR_DOWN) {
            DrawTextureRec(poniko.ponikoFrontSprite, source, poniko.spritePosition, WHITE);
        } else if (DIR_LAST == DIR_UP) {
            DrawTextureRec(poniko.ponikoBackSprite, source, poniko.spritePosition, WHITE); 
        } else if (DIR_LAST == DIR_LEFT) {
            DrawTextureRec(poniko.ponikoLeftSprite, source, poniko.spritePosition, WHITE);
        } else if (DIR_LAST == DIR_RIGHT) {
            DrawTextureRec(poniko.ponikoRightSprite, source, poniko.spritePosition, WHITE); 
        } else {
            DrawTextureRec(poniko.ponikoFrontSprite, source, poniko.spritePosition, WHITE);
        }
    };
}

