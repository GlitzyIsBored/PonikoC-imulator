#include "raylib.h"
#include "gameScreens.h"

static Texture2D title;

void setGameplayScreen(void)  {
    title = LoadTexture(lightBackgroundPath);
}

void drawGameplayScreen(void) {
    DrawTexture(title, 0, 0, WHITE);
}

