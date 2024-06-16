#include "stdlib.h"


typedef struct {
    int timestamp;
    int columns[6];
    bool isEndCondition;
} LevelData;

LevelData *levelData = NULL;
int levelDataCount = 0;
int currentLevelIndex = 0;


void ResetTiles(TileManager *tileManager) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < MAX_TILES; j++) {
            tileManager[i].tiles[j].active = false;
        }
        tileManager[i].activeCount = 0;
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
    int bestScore;
    float spawnTime = 0.0f;
    float timeBetweenSpawns = 0.5f;
    
    Color buttonColors[6]; // Add array to keep track of button colors
    bool buttonPressed[6]; // Add array to keep track of key pressed state




void UpdateDrawGameplayScreen(GameScreen *currentScreen, TileManager *tileManager) {
    
    
    static bool firstEnter = true;
    static float gameTime = 0.0f;
    
    if (firstEnter) {
        score = 0;
        ResetTiles(tileManager);
        currentLevelIndex = 0;
        gameTime = 0.0f;
        LoadLevel("levels/level1/tiles.txt");
        firstEnter = false;
        for (int i = 0; i < 6; i++) {
            buttonColors[i] = LIGHTGRAY;  // Initialize button colors to default
            buttonPressed[i] = false; // Initialize button pressed state
        }        
    }
    
    //float deltaTime = GetFrameTime();
        //spawnTime += deltaTime;

        // Spawn a new tile in a random column
        //if (spawnTime >= timeBetweenSpawns) {
           // spawnTime = 0.0f;
            //int column = rand() % 6;
           // SpawnTile(&tileManager[column], column);
        //}

    float deltaTime = GetFrameTime();
    gameTime += deltaTime * 1000; // Convert to milliseconds

    // Check if it's time to spawn tiles from the level data
    if (currentLevelIndex < levelDataCount && gameTime >= levelData[currentLevelIndex].timestamp) {
        for (int i = 0; i < 6; i++) {
            if (levelData[currentLevelIndex].columns[i] == 1) {
                SpawnTile(&tileManager[i], i);
            }
        }
        
        if (levelData[currentLevelIndex].isEndCondition) {
            
            FreeLevelData();
            firstEnter = true;
            //score = 0;            
            *currentScreen = SCORE;
            return; // Exit function early to avoid further updates/draws
        }        
        
        currentLevelIndex++;
    }
    
        // Update tiles
        for (int i = 0; i < 6; i++) {
            UpdateTiles(&tileManager[i], deltaTime);
            
                    // Check if any tiles go off the screen
        for (int j = 0; j < MAX_TILES; j++) {
            if (tileManager[i].tiles[j].active && tileManager[i].tiles[j].rect.y + TILE_HEIGHT > SCREEN_HEIGHT + 100 && !tileManager[i].tiles[j].wasHit) {
                //tileManager[i].tiles[j].active = false;
                tileManager[i].tiles[j].color = RED;
                //tileManager[i].activeCount--;
                
                
                score -= 3; // Deduct points for missing a tile
                tileManager[i].tiles[j].wasHit = true;
                //FreeLevelData();
                //firstEnter = true;
                //score = 0;
                //*currentScreen = MENU;
                
            }
        }

        }

            // Check for user input
            
// Initialize key states
              
            
            
    for (int i = 0; i < 6; i++) {
        int keyPressed = 0;
        switch (i) {
            case 0: keyPressed = IsKeyDown(KEY_A); break;
            case 1: keyPressed = IsKeyDown(KEY_S); break;
            case 2: keyPressed = IsKeyDown(KEY_D); break;
            case 3: keyPressed = IsKeyDown(KEY_J); break;
            case 4: keyPressed = IsKeyDown(KEY_K); break;
            case 5: keyPressed = IsKeyDown(KEY_L); break;
        }

        
        if (keyPressed) {
            bool hit = false;
            for (int j = 0; j < MAX_TILES; j++) {
                if (tileManager[i].tiles[j].active && tileManager[i].tiles[j].rect.y + TILE_HEIGHT >= SCREEN_HEIGHT - 50 && tileManager[i].tiles[j].rect.y + TILE_HEIGHT <= SCREEN_HEIGHT + 50) {
                    tileManager[i].tiles[j].wasHit = true;
                    
                    if(!buttonPressed[i]){
                    score += 5;
                    tileManager[i].tiles[j].color = GRAY;
                    buttonPressed[i] = true;
                    }
                    //tileManager[i].activeCount--;
                    buttonColors[i] = GRAY;  // Set button color to green for correct hit
                    hit = true;
                    break;
                }
            }
        if (!buttonPressed[i]) {
            buttonColors[i] = GRAY;
            score -= 3;
            buttonPressed[i] = true;

                  // Set button color to red for incorrect hit
        }
              // Mark button as pressed
        } else {
            buttonPressed[i] = false;  // Mark button as not pressed
        }
    }
    
    
    
    // Reset button colors if keys are not pressed
    for (int i = 0; i < 6; i++) {
        if (!buttonPressed[i]) {
            buttonColors[i] = LIGHTGRAY;
        }
    }


        // Draw everything
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0; i < 6; i++) {
            DrawTiles(&tileManager[i]);
        }

        // Draw buttons with text
        for (int i = 0; i < 6; i++) {
            DrawRectangle(i * TILE_WIDTH, SCREEN_HEIGHT - 80, TILE_WIDTH, 50, buttonColors[i]);
            int textWidth = MeasureText(keyLabels[i], 20);
            DrawText(keyLabels[i], i * TILE_WIDTH + (TILE_WIDTH - textWidth) / 2, SCREEN_HEIGHT - 65, 20, DARKGRAY);
        }

        DrawText(TextFormat("Score: %d", score), 10, 10, 20, DARKGRAY);
        EndDrawing();
}

