#ifndef GAMESCREENS_H
#define GAMESCREENS_H

#define titleScreen "Other/Title_Screen.png"
#define lightBackgroundPath "PonikoHouse/PonikoRoom_Light_On.png"
#define darkBackgroundPath "PonikoHouse/PonikoRoom_Light_Off.png"

#ifdef __cplusplus
extern "C" { 
#endif
typedef enum currentScreen {
    TITLE,
    GAMEPLAY,
} currentScreen;

void setGameplayScreen(void);
void drawGameplayScreen(void);

#ifdef __cplusplus
}
#endif

#endif