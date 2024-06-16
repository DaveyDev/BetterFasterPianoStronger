#ifndef LEVELDATA_H
#define LEVELDATA_H


typedef struct {
    int timestamp;
    int columns[6];
    bool isEndCondition;
} LevelData;

LevelData *levelData = NULL;
int levelDataCount = 0;
int currentLevelIndex = 0;

#endif