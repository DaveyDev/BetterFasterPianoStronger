#include "raylib.h"
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800
#define TILE_WIDTH 100
#define TILE_HEIGHT 200
#define TILE_SPEED 400 // Pixels per second

typedef struct Tile {
    Rectangle rect;
    bool active;
} Tile;

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Better Faster Piano Stronger");

    Tile tiles[6];  // One tile for each column
    for (int i = 0; i < 6; i++) {
        tiles[i].rect = (Rectangle){ i * TILE_WIDTH, -TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT };
        tiles[i].active = false;
    }

    const char *keyLabels[6] = { "A", "S", "D", "J", "K", "L" };
    
    int score = 0;
    float spawnTime = 0.0f;
    float timeBetweenSpawns = 1.0f;  // Time in seconds between tile spawns

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        //float deltaTime = 0.02f;
        spawnTime += deltaTime;

        // Spawn a new tile in a random column
        if (spawnTime >= timeBetweenSpawns) {
            spawnTime = 0.0f;
            int column = rand() % 6;
            if (!tiles[column].active) {
                tiles[column].rect.y = -TILE_HEIGHT;
                tiles[column].active = true;
                
            } //doesnt work when game wants to spawn multiple tiles in one column, write a manager for it or sth
        }

        // Update tiles
        for (int i = 0; i < 6; i++) {
            if (tiles[i].active) {
                tiles[i].rect.y += TILE_SPEED * deltaTime;
                if (tiles[i].rect.y > SCREEN_HEIGHT) {
                    tiles[i].active = false;
                    // Decrease score or end game if tile is missed
                    //score = score - 10;
                    
                }
            }
        }

        // Check for user input
        if (IsKeyPressed(KEY_A)) {
            if (tiles[0].active && tiles[0].rect.y + TILE_HEIGHT >= SCREEN_HEIGHT - 50) {
                tiles[0].active = false;
                score = score + 5;
            }
        }
        if (IsKeyPressed(KEY_S)) {
            if (tiles[1].active && tiles[1].rect.y + TILE_HEIGHT >= SCREEN_HEIGHT - 50) {
                tiles[1].active = false;
                score = score + 5;
            }
        }
        if (IsKeyPressed(KEY_D)) {
            if (tiles[2].active && tiles[2].rect.y + TILE_HEIGHT >= SCREEN_HEIGHT - 50) {
                tiles[2].active = false;
                score = score + 5;
            }
        }
        if (IsKeyPressed(KEY_J)) {
            if (tiles[3].active && tiles[3].rect.y + TILE_HEIGHT >= SCREEN_HEIGHT - 50) {
                tiles[3].active = false;
                score = score + 5;
            }
        }
        if (IsKeyPressed(KEY_K)) {
            if (tiles[4].active && tiles[4].rect.y + TILE_HEIGHT >= SCREEN_HEIGHT - 50) {
                tiles[4].active = false;
                score = score + 5;
            }
        }
        if (IsKeyPressed(KEY_L)) {
            if (tiles[5].active && tiles[5].rect.y + TILE_HEIGHT >= SCREEN_HEIGHT - 50) {
                tiles[5].active = false;
                score = score + 5;
            }
        }

        // Draw everything
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0; i < 6; i++) {
            if (tiles[i].active) {
                DrawRectangleRec(tiles[i].rect, BLACK);
            }
        }

        // Draw buttons with text
        for (int i = 0; i < 6; i++) {
            DrawRectangle(i * TILE_WIDTH, SCREEN_HEIGHT - 50, TILE_WIDTH, 50, LIGHTGRAY);
            int textWidth = MeasureText(keyLabels[i], 20);
            DrawText(keyLabels[i], i * TILE_WIDTH + (TILE_WIDTH - textWidth) / 2, SCREEN_HEIGHT - 40, 20, DARKGRAY);
        }

        DrawText(TextFormat("Score: %d", score), 10, 10, 20, DARKGRAY);
        DrawText(TextFormat("Score: %f", spawnTime), 10, 50, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
