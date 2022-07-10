//#pragma once

#ifndef TextureManager_hpp
#define TextureManager_hpp
#include "Game.hpp"

class TextureManager{
    
    public:
        static SDL_Texture* LoadTexture(const char* texture, SDL_Renderer* ren);

};

#endif