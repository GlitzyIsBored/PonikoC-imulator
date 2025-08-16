#include "raylib.h"
#include "poniko.h"

Poniko poniko;

void SetPoniko(void) {
    poniko.ponikoFrontSprite = LoadTexture(spriteFront);   
    poniko.ponikoBackSprite = LoadTexture(spriteBack); 
    poniko.ponikoLeftSprite = LoadTexture(spriteLeft); 
    poniko.ponikoRightSprite = LoadTexture(spriteRight); 
    
    poniko.spritePosition = (Vector2){SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2};
    poniko.frameWidth = poniko.ponikoFrontSprite.width / 4;
    poniko.frameBorder = (Rectangle){0, 0, poniko.frameWidth, 63};
}

void DrawPoniko(void) {
    DrawTextureRec(poniko.ponikoFrontSprite, poniko.frameBorder, poniko.spritePosition, WHITE);
}

void UpdatePoniko(void) {
    if (IsKeyDown(KEY_RIGHT) && poniko.spritePosition.x < SCREEN_WIDTH - poniko.ponikoFrontSprite.width) poniko.spritePosition.x += 0.01f;
    if (IsKeyDown(KEY_LEFT) && poniko.spritePosition.x > 0) poniko.spritePosition.x -= 0.01f;
    if (IsKeyDown(KEY_DOWN) && poniko.spritePosition.y < SCREEN_HEIGHT - 185 - poniko.ponikoFrontSprite.height) poniko.spritePosition.y += 0.01f;
    if (IsKeyDown(KEY_UP) && poniko.spritePosition.y > 250) poniko.spritePosition.y -= 0.01f;     
}
