#include "save.h"


#include <stdio.h>
#include <errno.h>

void SaveGame(int score) {
    const char *filename = "data/save/save.txt"; // Specify the filename you want to save to

    FILE *file = fopen(filename, "w"); // Open file in write mode ("w")

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Write data to file
    fprintf(file, "%d", score);

    fclose(file); // Close the file after writing
}
