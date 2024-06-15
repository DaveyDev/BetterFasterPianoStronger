#include "raylib.h"
//#include "scene.h" // Include the header file

Vector2 mousePoint = {};
Color buttonColor = (Color){0, 0, 0, 50};
Color bgColor = (Color){205, 255, 205, 255};
Color noColor = (Color){0, 0, 0, 0};


Rectangle playButton = {100 - 50, 300 - 16, 200, 50};



const char *menuText = "PLAY";
Vector2 position = { 100, 300 };
float fontSize = 32.0f;
float spacing = 2.0f;
Color tint = BLACK;

// Custom function to draw text with adjusted position. XD i really wanted to make this font work //next update make it work properly
void DrawTextExAdjusted(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint) {
    Vector2 adjustedPosition = position;

    for (int i = 0; text[i] != '\0'; i++) {
        // Adjust position for 'E' character
        if (text[i] == 'A') {
        //adjustedPosition.x -= 2;  // Adjust this value as needed
        }
        if (text[i] == 'A') {
            //adjustedPosition.x += 2;  // Adjust this value as needed
        }
        if (text[i] == 'B') {
            adjustedPosition.x += 15;  // Adjust this value as needed
        }
        if (text[i] == 'C') {
            adjustedPosition.x += 15;  // Adjust this value as needed
        }

        // Draw each character
        DrawTextEx(font, TextFormat("%c", text[i]), adjustedPosition, fontSize, spacing, tint);

        // Update position for the next character
        adjustedPosition.x += MeasureTextEx(font, TextFormat("%c", text[i]), fontSize, spacing).x;

        // Reset the position adjustment for next characters
        if (text[i] == 'E') {
            adjustedPosition.x -= 15;
        }
        if (text[i] == 'A') {
            adjustedPosition.x += 2;
        }
        if (text[i] == 'B') {
            adjustedPosition.x -= 15;
        }
        if (text[i] == 'C') {
        adjustedPosition.x += 2;  // Adjust this value as needed
        }
        if (text[i] == 'L') {
        adjustedPosition.x += 2;  // Adjust this value as needed
        }
        
    }
}

void UpdateDrawMenuScreen(GameScreen *currentScreen, Font playtoy) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    
    mousePoint = GetMousePosition(); //gets mouse position
    
    if (CheckCollisionPointRec(mousePoint, playButton)) DrawRectangleRec(playButton, buttonColor);
    else DrawRectangleRec(playButton, noColor);
    
    if (CheckCollisionPointRec(mousePoint, playButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        *currentScreen = GAMEPLAY;
    } 
    
    // Use the custom drawing function
    DrawTextExAdjusted(playtoy, menuText, position, fontSize, spacing, tint);
    
    // Uncomment and adjust if needed
    // DrawTexture(logoTexture, GetScreenWidth()/2 - 128, GetScreenHeight()/2 - 128, WHITE);

    //float deltaTime = GetFrameTime();
    // Uncomment and adjust if needed
    // logoTime += deltaTime;

    EndDrawing();
    
    if (IsKeyPressed(KEY_ENTER)) {
        *currentScreen = GAMEPLAY; // Change current screen
    }
}
