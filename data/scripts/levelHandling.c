#include <stdio.h>
#include <errno.h>


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


void LoadLevelScore(){
    const char *filename = "levels/level1/save.txt"; // Specify the filename you want to load from
    int score = 0;

    FILE *file = fopen(filename, "r"); // Open file in read mode ("r")

    if (file == NULL) {
        perror("Error opening file");
        return 0; // Return 0 or any default value if file does not exist
    }

    // Read data from file
    if (fscanf(file, "%d", &score) != 1) {
        fprintf(stderr, "Error reading score from file\n");
        score = 0; // Set score to default value if reading fails
    }

    fclose(file); // Close the file after reading

    bestScore = score;
}


void SaveLevelScore(int score){
    const char *filename = "levels/level1/save.txt"; // Specify the filename you want to save to

    FILE *file = fopen(filename, "w"); // Open file in write mode ("w")

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Write data to file
    fprintf(file, "%d", score);

    fclose(file); // Close the file after writing
}