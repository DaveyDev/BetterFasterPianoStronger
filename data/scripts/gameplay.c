

    const char *keyLabels[6] = { "A", "S", "D", "J", "K", "L" };

    int score = 0;
    float spawnTime = 0.0f;
    float timeBetweenSpawns = 0.5f;

void UpdateDrawGameplayScreen(GameScreen *currentScreen, TileManager *timeManager) {
    float deltaTime = GetFrameTime();
        spawnTime += deltaTime;

        // Spawn a new tile in a random column
        if (spawnTime >= timeBetweenSpawns) {
            spawnTime = 0.0f;
            int column = rand() % 6;
            SpawnTile(&timeManager[column], column);
        }

        // Update tiles
        for (int i = 0; i < 6; i++) {
            UpdateTiles(&timeManager[i], deltaTime);
        }

        // Check for user input
        if (IsKeyPressed(KEY_A)) {
            for (int i = 0; i < MAX_TILES; i++) {
                if (timeManager[0].tiles[i].active && timeManager[0].tiles[i].rect.y + TILE_HEIGHT >= SCREEN_HEIGHT - 50) {
                    timeManager[0].tiles[i].active = false;
                    score += 5;
                    timeManager[0].activeCount--;
                    break;
                }
            }
        }
        if (IsKeyPressed(KEY_S)) {
            for (int i = 0; i < MAX_TILES; i++) {
                if (timeManager[1].tiles[i].active && timeManager[1].tiles[i].rect.y + TILE_HEIGHT >= SCREEN_HEIGHT - 50) {
                    timeManager[1].tiles[i].active = false;
                    score += 5;
                    timeManager[1].activeCount--;
                    break;
                }
            }
        }
        if (IsKeyPressed(KEY_D)) {
            for (int i = 0; i < MAX_TILES; i++) {
                if (timeManager[2].tiles[i].active && timeManager[2].tiles[i].rect.y + TILE_HEIGHT >= SCREEN_HEIGHT - 50) {
                    timeManager[2].tiles[i].active = false;
                    score += 5;
                    timeManager[2].activeCount--;
                    break;
                }
            }
        }
        if (IsKeyPressed(KEY_J)) {
            for (int i = 0; i < MAX_TILES; i++) {
                if (timeManager[3].tiles[i].active && timeManager[3].tiles[i].rect.y + TILE_HEIGHT >= SCREEN_HEIGHT - 50) {
                    timeManager[3].tiles[i].active = false;
                    score += 5;
                    timeManager[3].activeCount--;
                    break;
                }
            }
        }
        if (IsKeyPressed(KEY_K)) {
            for (int i = 0; i < MAX_TILES; i++) {
                if (timeManager[4].tiles[i].active && timeManager[4].tiles[i].rect.y + TILE_HEIGHT >= SCREEN_HEIGHT - 50) {
                    timeManager[4].tiles[i].active = false;
                    score += 5;
                    timeManager[4].activeCount--;
                    break;
                }
            }
        }
        if (IsKeyPressed(KEY_L)) {
            for (int i = 0; i < MAX_TILES; i++) {
                if (timeManager[5].tiles[i].active && timeManager[5].tiles[i].rect.y + TILE_HEIGHT >= SCREEN_HEIGHT - 50) {
                    timeManager[5].tiles[i].active = false;
                    score += 5;
                    timeManager[5].activeCount--;
                    break;
                }
            }
        }

        // Draw everything
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0; i < 6; i++) {
            DrawTiles(&timeManager[i]);
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