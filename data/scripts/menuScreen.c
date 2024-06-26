#include "raylib.h"

#include "font.c"

Vector2 mousePoint = {};
Color buttonColor = (Color){0, 0, 0, 50};
Color bgColor = (Color){205, 255, 205, 255};
Color noColor = (Color){0, 0, 0, 0};


Rectangle playButton = {250 - 50, 400 - 16, 200, 50};



const char *menuText = "PLAY";
Vector2 position = { 250, 400 };
float fontSize = 32.0f;
float spacing = 2.0f;
Color tint = BLACK;



void UpdateDrawMenuScreen(GameScreen *currentScreen, Font playtoy, Font schluber) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    
    mousePoint = GetMousePosition(); //gets mouse position
    
    
    DrawTexture(titleTexture, 0, 50, WHITE);
    
    if (CheckCollisionPointRec(mousePoint, playButton)) DrawRectangleRec(playButton, buttonColor);
    else DrawRectangleRec(playButton, noColor);
    
    if (CheckCollisionPointRec(mousePoint, playButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        *currentScreen = GAMEPLAY;
    } 
    
    // Use the custom drawing function
    
    DrawTextExAdjusted(playtoy, menuText, position, fontSize, spacing, tint);
    //DrawText("v160624", 500, 760, 24, DARKGRAY);
    DrawTextEx(schluber, "v210624", (Vector2){ 500, 760 }, 32, 0, BLACK);
    
    // Uncomment and adjust if needed
    // DrawTexture(logoTexture, GetScreenWidth()/2 - 128, GetScreenHeight()/2 - 128, WHITE);

    //float deltaTime = GetFrameTime();
    // Uncomment and adjust if needed
    // logoTime += deltaTime;

    EndDrawing();
    
    if (IsKeyPressed(KEY_SPACE)) {
        *currentScreen = GAMEPLAY; // Change current screen
    }
}
