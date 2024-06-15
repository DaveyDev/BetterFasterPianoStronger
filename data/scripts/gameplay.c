#include "stdlib.h"

typedef struct {
    int timestamp;
    int columns[6];
    bool isEndCondition;
} LevelData;

LevelData *levelData = NULL;
int levelDataCount = 0;
int currentLevelIndex = 0;


void ResetTiles(TileManager *timeManager) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < MAX_TILES; j++) {
            timeManager[i].tiles[j].active = false;
        }
        timeManager[i].activeCount = 0;
    }
}



void LoadLevel(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open level file.\n");
        return;
    }

    char line[256];
    int count = 0;

    while (fgets(line, sizeof(line), file)) {
        count++;
    }

    rewind(file);
    levelData = (LevelData *)malloc(count * sizeof(LevelData));
    levelDataCount = count;
    count = 0;

    while (fgets(line, sizeof(line), file)) {
        int result = sscanf(line, "%d %d %d %d %d %d %d",
               &levelData[count].timestamp,
               &levelData[count].columns[0],
               &levelData[count].columns[1],
               &levelData[count].columns[2],
               &levelData[count].columns[3],
               &levelData[count].columns[4],
               &levelData[count].columns[5]);
               
        // Check if the line is an end condition (all zeros after timestamp)
        if (result == 7 && levelData[count].columns[0] == 0 && levelData[count].columns[1] == 0 &&
            levelData[count].columns[2] == 0 && levelData[count].columns[3] == 0 &&
            levelData[count].columns[4] == 0 && levelData[count].columns[5] == 0) {
            levelData[count].isEndCondition = true;
        } else {
            levelData[count].isEndCondition = false;
        }
               
        count++;
    }

    fclose(file);
}

// Function to free allocated memory for levelData
void FreeLevelData() {
    if (levelData != NULL) {
        free(levelData);
        levelData = NULL; // Optional: Set pointer to NULL after freeing
        levelDataCount = 0;
    }
}


    const char *keyLabels[6] = { "A", "S", "D", "J", "K", "L" };

    int score = 0;
    float spawnTime = 0.0f;
    float timeBetweenSpawns = 0.5f;

void UpdateDrawGameplayScreen(GameScreen *currentScreen, TileManager *timeManager) {
    
    
    static bool firstEnter = true;
    static float gameTime = 0.0f;
    
    if (firstEnter) {
        ResetTiles(timeManager);
        currentLevelIndex = 0;
        gameTime = 0.0f;
        LoadLevel("levels/level1/tiles.txt");
        firstEnter = false;
    }
    
    //float deltaTime = GetFrameTime();
        //spawnTime += deltaTime;

        // Spawn a new tile in a random column
        //if (spawnTime >= timeBetweenSpawns) {
           // spawnTime = 0.0f;
            //int column = rand() % 6;
           // SpawnTile(&timeManager[column], column);
        //}

    float deltaTime = GetFrameTime();
    gameTime += deltaTime * 1000; // Convert to milliseconds

    // Check if it's time to spawn tiles from the level data
    if (currentLevelIndex < levelDataCount && gameTime >= levelData[currentLevelIndex].timestamp) {
        for (int i = 0; i < 6; i++) {
            if (levelData[currentLevelIndex].columns[i] == 1) {
                SpawnTile(&timeManager[i], i);
            }
        }
        
        if (levelData[currentLevelIndex].isEndCondition) {
            
            FreeLevelData();
            firstEnter = true;
            score = 0;            
            *currentScreen = MENU;
            return; // Exit function early to avoid further updates/draws
        }        
        
        currentLevelIndex++;
    }
    
        // Update tiles
        for (int i = 0; i < 6; i++) {
            UpdateTiles(&timeManager[i], deltaTime);
            
                    // Check if any tiles go off the screen
        for (int j = 0; j < MAX_TILES; j++) {
            if (timeManager[i].tiles[j].active && timeManager[i].tiles[j].rect.y + TILE_HEIGHT > SCREEN_HEIGHT + 30) {
                timeManager[i].tiles[j].active = false;
                timeManager[i].activeCount--;
                score -= 3; // Deduct points for missing a tile
                //FreeLevelData();
                //firstEnter = true;
                //score = 0;
                //*currentScreen = MENU;
                
            }
        }

        }

        // Check for user input
        if (IsKeyPressed(KEY_A)) {
            for (int i = 0; i < MAX_TILES; i++) {
                if (timeManager[0].tiles[i].active && timeManager[0].tiles[i].rect.y + TILE_HEIGHT >= SCREEN_HEIGHT - 50) {
                    timeManager[0].tiles[i].active = false;
                    score += 5;
                    timeManager[0].activeCount--;
                    break;
                } else { 
                score -= 3; 
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
                } else { 
                score -= 3; 
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
                } else { 
                score -= 3; 
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
                } else { 
                score -= 3; 
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
                } else { 
                score -= 3; 
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
                } else { 
                score -= 3; 
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

