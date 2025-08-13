#define SCREEN_HEIGHT 700
#define SCREEN_WIDTH 700

#define spritePath "PonikoSprite/poniko1.png"
#define spriteBackPath "PonikoSprite/PonikoBack1.png"
#define lightBackgroundPath "PonikoHouse/PonikoRoom_Light_On.png"

#define spriteFront "PonikoSprite/Poniko_FrontSheet.png"
#define spriteBack "PonikoSprite/Poniko_BackSheet.png"
#define spriteLeft "PonikoSprite/Poniko_LeftSheet.png"
#define spriteRight "PonikoSprite/Poniko_RightSheet.png"

#define MainPage "Other/Title_Screen.png"
#define MainButton "Other/Start_Button.png"

typedef enum {
    DIR_UP,
    DIR_DOWN,
    DIR_RIGHT,
    DIR_LEFT,
    DIR_NULL,
    } direction;
direction DIR_LAST = DIR_NULL;

typedef enum TitleScreen {
    TITLE,
    GAMEPLAY,
} TitleScreen;