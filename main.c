#include "raylib.h"
#include "data/scripts/tile.c"
#include "data/scripts/save.c"
#include "data/scripts/constants.h"
#include <stdlib.h>
#include <time.h>



int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Better Faster Piano Stronger");

    TileManager tileManagers[6];
    for (int i = 0; i < 6; i++) {
        InitTileManager(&tileManagers[i]);
    }

    const char *keyLabels[6] = { "A", "S", "D", "J", "K", "L" };
    
    int score = 0;
    float spawnTime = 0.0f;
    float timeBetweenSpawns = 0.5f;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        spawnTime += deltaTime;

        // Spawn a new tile in a random column
        if (spawnTime >= timeBetweenSpawns) {
            spawnTime = 0.0f;
            int column = rand() % 6;
            SpawnTile(&tileManagers[column], column);
        }

        // Update tiles
        for (int i = 0; i < 6; i++) {
            UpdateTiles(&tileManagers[i], deltaTime);
        }

        // Check for user input
        if (IsKeyPressed(KEY_A)) {
            for (int i = 0; i < MAX_TILES; i++) {
                if (tileManagers[0].tiles[i].active && tileManagers[0].tiles[i].rect.y + TILE_HEIGHT >= SCREEN_HEIGHT - 50) {
                    tileManagers[0].tiles[i].active = false;
                    score += 5;
                    tileManagers[0].activeCount--;
                    break;
                }
            }
        }
        if (IsKeyPressed(KEY_S)) {
            for (int i = 0; i < MAX_TILES; i++) {
                if (tileManagers[1].tiles[i].active && tileManagers[1].tiles[i].rect.y + TILE_HEIGHT >= SCREEN_HEIGHT - 50) {
                    tileManagers[1].tiles[i].active = false;
                    score += 5;
                    tileManagers[1].activeCount--;
                    break;
                }
            }
        }
        if (IsKeyPressed(KEY_D)) {
            for (int i = 0; i < MAX_TILES; i++) {
                if (tileManagers[2].tiles[i].active && tileManagers[2].tiles[i].rect.y + TILE_HEIGHT >= SCREEN_HEIGHT - 50) {
                    tileManagers[2].tiles[i].active = false;
                    score += 5;
                    tileManagers[2].activeCount--;
                    break;
                }
            }
        }
        if (IsKeyPressed(KEY_J)) {
            for (int i = 0; i < MAX_TILES; i++) {
                if (tileManagers[3].tiles[i].active && tileManagers[3].tiles[i].rect.y + TILE_HEIGHT >= SCREEN_HEIGHT - 50) {
                    tileManagers[3].tiles[i].active = false;
                    score += 5;
                    tileManagers[3].activeCount--;
                    break;
                }
            }
        }
        if (IsKeyPressed(KEY_K)) {
            for (int i = 0; i < MAX_TILES; i++) {
                if (tileManagers[4].tiles[i].active && tileManagers[4].tiles[i].rect.y + TILE_HEIGHT >= SCREEN_HEIGHT - 50) {
                    tileManagers[4].tiles[i].active = false;
                    score += 5;
                    tileManagers[4].activeCount--;
                    break;
                }
            }
        }
        if (IsKeyPressed(KEY_L)) {
            for (int i = 0; i < MAX_TILES; i++) {
                if (tileManagers[5].tiles[i].active && tileManagers[5].tiles[i].rect.y + TILE_HEIGHT >= SCREEN_HEIGHT - 50) {
                    tileManagers[5].tiles[i].active = false;
                    score += 5;
                    tileManagers[5].activeCount--;
                    break;
                }
            }
        }

        // Draw everything
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0; i < 6; i++) {
            DrawTiles(&tileManagers[i]);
        }

        // Draw buttons with text
        for (int i = 0; i < 6; i++) {
            DrawRectangle(i * TILE_WIDTH, SCREEN_HEIGHT - 50, TILE_WIDTH, 50, LIGHTGRAY);
            int textWidth = MeasureText(keyLabels[i], 20);
            DrawText(keyLabels[i], i * TILE_WIDTH + (TILE_WIDTH - textWidth) / 2, SCREEN_HEIGHT - 35, 20, DARKGRAY);
        }

        DrawText(TextFormat("Score: %d", score), 10, 10, 20, DARKGRAY);
        EndDrawing();
    }
    
    SaveGame(score);
    CloseWindow();
    return 0;
}
