#ifndef PONIKO_H
#define PONIKO_H

#define spriteFront "PonikoSprite/Poniko_FrontSheet.png"
#define spriteBack "PonikoSprite/Poniko_BackSheet.png"
#define spriteLeft "PonikoSprite/Poniko_LeftSheet.png"
#define spriteRight "PonikoSprite/Poniko_RightSheet.png"

typedef enum {
    DIR_UP,
    DIR_DOWN,
    DIR_RIGHT,
    DIR_LEFT,
    DIR_NULL,
    } direction;
direction DIR_LAST = DIR_NULL;

typedef struct Poniko {
    Vector2 spritePosition;
    Texture2D texture;
    Rectangle frameBorder;
    
    int currentFrame;
    int frameWidth;
    float frameCounter;
    float frameSpeed;
} Poniko;

extern Poniko poniko;

#ifdef __cplusplus
extern "C" { 
#endif

void SetPoniko(void);
void DrawPoniko(void);

#ifdef __cplusplus
}
#endif

#endif