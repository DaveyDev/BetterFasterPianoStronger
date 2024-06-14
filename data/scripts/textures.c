#include "raylib.h"
#include "textures.h"


Texture2D logoTexture;




void LoadTextures(){
    
     
    logoTexture = LoadTexture("data/textures/logo.png"); 
    
}

void UnloadTextures(){
    
    UnloadTexture(logoTexture);
    
}