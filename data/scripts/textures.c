#include "raylib.h"
#include "textures.h"


Texture2D logoTexture;
Texture2D keysTexture;
Texture2D titleTexture;




void LoadTextures(){
    
     
    logoTexture = LoadTexture("data/textures/logo.png");
    keysTexture = LoadTexture("data/textures/keys.png");
    titleTexture = LoadTexture("data/textures/title.png");
    
}

void UnloadTextures(){
    
    UnloadTexture(logoTexture);
    UnloadTexture(keysTexture);
    UnloadTexture(titleTexture);
    
}