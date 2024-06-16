#include "raylib.h"
#include "data/scripts/tile.c"
#include "data/scripts/save.c"
#include "data/scripts/constants.h"
#include "data/scripts/scene.h"
#include "data/scripts/logo.c"
#include "data/scripts/title.c"
#include "data/scripts/gameplay.c"
#include "data/scripts/textures.c"
#include "data/scripts/textures.h"
#include "data/scripts/menuScreen.c"
#include "data/scripts/scoreScreen.c"
#include "data/scripts/levelHandling.c"
#include "data/scripts/levelData.h"
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
    Font playtoy = LoadFontEx("data/fonts/playtoy.ttf", 32, 0, 0);
    Font schluber = LoadFontEx("data/fonts/Schluber.ttf", 32, 0, 0);
    
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
                switch (currentScreen) {
            case LOGO:
                UpdateDrawLogoScreen(&currentScreen, logoTexture);
                break;
            case MENU:
                UpdateDrawMenuScreen(&currentScreen, playtoy);
                break;
            case GAMEPLAY:
                UpdateDrawGameplayScreen(&currentScreen, tileManager);
                break;
            case SCORE:
                UpdateDrawScoreScreen(&currentScreen, schluber);
                break;
            default:
                WindowShouldClose();
                break;
        }
    }
    
    UnloadTextures();
    UnloadFont(playtoy);
    UnloadFont(schluber);
    
    //SaveGame(score);
    CloseWindow();
    return 0;
}
