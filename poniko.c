#include "raylib.h"
#include "poniko.h"

Poniko poniko;

void SetPoniko(void) {
    poniko.texture = LoadTexture(spriteFront);   
    poniko.spritePosition = (Vector2){SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2};
    poniko.frameWidth = poniko.texture.width / 4;
    poniko.frameBorder = (Rectangle){0, 0, poniko.frameWidth, 63};
    
}

void DrawPoniko(void) {
    DrawTextureRec(poniko.texture, poniko.frameBorder, poniko.spritePosition, WHITE);
}