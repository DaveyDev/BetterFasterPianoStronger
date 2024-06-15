#include "raylib.h"
#include "textures.h"


Texture2D logoTexture;
Texture2D keysTexture;




void LoadTextures(){
    
     
    logoTexture = LoadTexture("data/textures/logo.png");
    keysTexture = LoadTexture("data/textures/keys.png");
    
    
}

void UnloadTextures(){
    
    UnloadTexture(logoTexture);
    UnloadTexture(keysTexture);
    
}