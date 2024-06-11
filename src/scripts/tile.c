#include "tile.h"

void InitTileManager(TileManager* manager) {
    for (int i = 0; i < MAX_TILES; i++) {
        manager->tiles[i].active = false;
    }
    manager->activeCount = 0;
}

void SpawnTile(TileManager* manager, int column) {
    for (int i = 0; i < MAX_TILES; i++) {
        if (!manager->tiles[i].active) {
            manager->tiles[i].rect = (Rectangle){ column * TILE_WIDTH, -TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT };
            manager->tiles[i].active = true;
            manager->activeCount++;
            break;
        }
    }
}

void UpdateTiles(TileManager* manager, float deltaTime) {
    for (int i = 0; i < MAX_TILES; i++) {
        if (manager->tiles[i].active) {
            manager->tiles[i].rect.y += TILE_SPEED * deltaTime;
            if (manager->tiles[i].rect.y > SCREEN_HEIGHT) {
                manager->tiles[i].active = false;
                manager->activeCount--;
            }
        }
    }
}

void DrawTiles(TileManager* manager) {
    for (int i = 0; i < MAX_TILES; i++) {
        if (manager->tiles[i].active) {
            DrawRectangleRec(manager->tiles[i].rect, BLACK);
        }
    }
}
