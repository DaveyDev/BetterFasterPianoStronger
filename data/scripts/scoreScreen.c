#include "raylib.h"


void UpdateDrawScoreScreen(GameScreen *currentScreen, Font schluber) {

    BeginDrawing();
    ClearBackground(RAYWHITE);
    
    //DrawTexture(logoTexture, GetScreenWidth()/2 - 128, GetScreenHeight()/2 - 128, WHITE);
   
    if(score > bestScore) bestScore = score;

   

   
   
    //int testscore = score;
    //DrawText(TextFormat("SCORE: %i", score), 40, 150, 32, DARKGRAY);
    //DrawText(TextFormat("BEST: %i", bestScore), 45, 200, 32, DARKGRAY); // meh, good enough. to do next time: make it look better
    DrawTextEx(schluber, TextFormat("SCORE: %i", score), (Vector2){ 120, 150 }, 64, 0, DARKGRAY);
    DrawTextEx(schluber, TextFormat("BEST:  %i", bestScore), (Vector2){ 120, 200 }, 64, 0, DARKGRAY);
    
    //DrawText(TextFormat("PRESS SPACE TO CONTINUE"), 120, 400, 25, DARKGRAY);
    //DrawText(TextFormat("R - RESET BEST SCORE"), 120, 450, 25, DARKGRAY);
    
    DrawTextEx(schluber, TextFormat("PRESS SPACE TO CONTINUE"), (Vector2){ 120, 400 }, 32, 0, DARKGRAY);
    DrawTextEx(schluber, TextFormat("R - RESET SCORE"), (Vector2){ 120, 450 }, 32, 0, DARKGRAY);
    
    
    EndDrawing();
    
    if(IsKeyPressed('R')){
        score = 0;
        SaveLevelScore(0);
        LoadLevelScore();
        
    }
    
    if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
        SaveLevelScore(bestScore);
        *currentScreen = MENU; // Change current screen
    }
}
