#include "raylib.h"

float logoTime = 0.0f;
float setLogoTime = 2.0f;
    
    
void UpdateDrawLogoScreen(GameScreen *currentScreen, Texture2D logoTexture) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    //DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
    DrawTexture(logoTexture, GetScreenWidth()/2 - 128, GetScreenHeight()/2 - 150, WHITE);
    
    float deltaTime = GetFrameTime();
    logoTime += deltaTime;

    // Spawn a new tile in a random column
    if (logoTime >= setLogoTime) {
        logoTime = 0.0f;
        *currentScreen = MENU;
        
    }
    EndDrawing();
    
    if (IsKeyPressed(KEY_ENTER)) {
        *currentScreen = MENU; // Change current screen
    }
}
