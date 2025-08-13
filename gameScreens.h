#ifndef GAMESCREENS_H
#define GAMESCREENS_H

#define lightBackgroundPath "PonikoHouse/PonikoRoom_Light_On.png"
#ifdef __cplusplus
extern "C" { 
#endif
/*typedef enum = {
    titleScreen,
    gameplayScreen,
} currentScreen;
*/
void setGameplayScreen(void);
void drawGameplayScreen(void);

#ifdef __cplusplus
}
#endif

#endif