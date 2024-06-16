#include "raylib.h"
//#include "font.c"

const char *scoreText = "SCORE";
Vector2 scorePosition = { 100, 300 };
float scoreFontSize = 32.0f;
//float spacing = 2.0f;
//Color tint = BLACK;


    
void UpdateDrawScoreScreen(GameScreen *currentScreen, Font playtoy) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Betoniarz to pedal", 20, 20, 40, LIGHTGRAY);
    //DrawTexture(logoTexture, GetScreenWidth()/2 - 128, GetScreenHeight()/2 - 128, WHITE);
    
    // Use the custom drawing function
    DrawTextExAdjusted(playtoy, scoreText, scorePosition, scoreFontSize, spacing, tint);
    
    int testscore = score;
    DrawText(TextFormat("BEST: %i", testscore), 40, 200, 20, LIGHTGRAY);
    playtoy;

    EndDrawing();
    
    if (IsKeyPressed(KEY_ENTER)) {
        *currentScreen = MENU; // Change current screen
    }
}
