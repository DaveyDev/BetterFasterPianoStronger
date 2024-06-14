#include "raylib.h"
#include "data/scripts/tile.c"
#include "data/scripts/save.c"
#include "data/scripts/constants.h"
#include "data/scripts/scene.h"
#include "data/scripts/logo.c"
#include "data/scripts/title.c"
#include "data/scripts/gameplay.c"
#include "data/scripts/textures.c"
#include <stdlib.h>
#include <time.h>



int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Better Faster Piano Stronger");
     
    GameScreen currentScreen = LOGO;

    TileManager tileManager[6];
    for (int i = 0; i < 6; i++) {
        InitTileManager(&tileManager[i]);
    }
    
    LoadGame();
    LoadTextures();
    
    
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
                switch (currentScreen) {
            case LOGO:
                UpdateDrawLogoScreen(&currentScreen, logoTexture);
                break;
            case TITLE:
                //UpdateDrawTitleScreen(&currentScreen);
                break;
            case GAMEPLAY:
                UpdateDrawGameplayScreen(&currentScreen, &tileManager);
                break;
            case ENDING:
                //UpdateDrawEndingScreen(&currentScreen);
                break;
            default:
                break;
        }
    }
    
    UnloadTextures();
    
    SaveGame(score);
    CloseWindow();
    return 0;
}
