#ifndef TILE_H
#define TILE_H

#include "raylib.h"
#include "constants.h"
//#include "tile.c"



typedef struct Tile {
    Rectangle rect;
    bool active;
    Color color;
    bool wasHit;
} Tile;

typedef struct TileManager {
    Tile tiles[MAX_TILES];
    int activeCount;
} TileManager;

void InitTileManager(TileManager* manager);
void SpawnTile(TileManager* manager, int column);
void UpdateTiles(TileManager* manager, float deltaTime);
void DrawTiles(TileManager* manager);

#endif
