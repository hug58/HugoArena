
#ifndef Map_hpp
#define Map_hpp
#include "Game.hpp"
#include "Player.hpp"
#include <map>

/*
    clase mapa par en cuadrillas de 0 y 1
*/

//definir tile constantes
//TIERRA = 1
//PISO = 2
//MURO = 3
//BLOQUE = 0

//TIERRA IS EARTH
//PISO IS GRASS
//MURO IS WALL
//BLOQUE IS STONE
#define STONE 0
#define EARTH 1
#define GRASS 2
#define WALL 3

#define TILE_SIZE 32



class Map
{
    public:
        Map(SDL_Renderer* renderer, std::string path, int height, int width);
        virtual ~Map();
        void LoadMap(int arr[20][25]);
        void LoadMapWithFile(std::string path, int height, int width);
        void DrawMap(SDL_Renderer* renderer);
        void Render(SDL_Renderer* renderer, SDL_Texture* texture ,SDL_Rect srcRect, SDL_Rect destR);
        void Collision(SDL_Renderer* renderer,Player* player);

    private:
        SDL_Rect src,dest;
        SDL_Texture* background;
        SDL_Texture* grass;
        SDL_Texture* water;
        SDL_Renderer* rendererMap;
        int map[20][25];
        //int** map;
        std::map<int, int> tilesX;
        std::map<int, int> tilesY;


};


#endif /* Map_hpp */