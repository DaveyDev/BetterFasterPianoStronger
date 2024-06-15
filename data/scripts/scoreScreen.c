#include "raylib.h"


    
void UpdateDrawScoreScreen(GameScreen *currentScreen) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Betoniarz to pedal", 20, 20, 40, LIGHTGRAY);
    //DrawTexture(logoTexture, GetScreenWidth()/2 - 128, GetScreenHeight()/2 - 128, WHITE);
    int testscore = score;
    DrawText(TextFormat("BEST: %i", testscore), 40, 200, 20, LIGHTGRAY);

    EndDrawing();
    
    if (IsKeyPressed(KEY_ENTER)) {
        *currentScreen = MENU; // Change current screen
    }
}
