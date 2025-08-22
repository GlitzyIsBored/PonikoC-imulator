#include "raylib.h"
#include "gameScreens.h"

static Texture2D title, lighton, lightoff;
bool light_isOn = true;

void setGameplayScreen(void)  {
    title = LoadTexture(titleScreen);
    lighton = LoadTexture(lightBackgroundPath);
    lightoff = LoadTexture(darkBackgroundPath);
}

void drawGameplayScreen(void) {    
    if (IsKeyPressed(KEY_SPACE)) {
        light_isOn = !light_isOn;
    } else {
        light_isOn = light_isOn;
    }
    
    if (light_isOn == true) {
        DrawTexture(lighton, 0, 0, WHITE);
    } else {
        DrawTexture(lightoff, 0, 0, WHITE);
    }
}

