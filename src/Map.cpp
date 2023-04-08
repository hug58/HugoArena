
#include "Map.hpp"
#include "TextureManager.hpp"
#include "Tile.hpp"
#include <vector>
#include <fstream>
#include <cmath>


using std::string;
using std::ifstream;

int lvl1[20][25] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,3,3,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,2,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,2,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};


int lvl2[20][25] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},

    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
};

Map::~Map()
{
    //dtor

}

Map::Map(SDL_Renderer* renderer, std::string path, int height, int width)
{
    background = TextureManager::LoadTexture("./assets/tiles.png",renderer);

    //LoadMap(lvl1);
    /*
        LEER UN ARCHIVO Y CARGARLO EN EL ARRAY DE MAP
    */
    //create map
    std::cout << path << height << width << std::endl;
    LoadMapWithFile(path,height,width);

    int positions[4][2] = {
        {0,0},
        {32,0},
        {64,0},
        {96,0}
    };
    //size positions
    int sizeArr = sizeof(positions)/sizeof(positions[0]);

    for (int i = 0; i < sizeArr; i++)
    {
        //std::cout << "x: " << positions[i][0] << " y: " << positions[i][1] << std::endl;
        this -> tilesX.insert(std::pair<int,int>(i,positions[i][0]));
        this -> tilesY.insert(std::pair<int,int>(i,positions[i][1]));
        //this -> tilesX[i] = positions[i][0];
        std::cout << "X: " << this -> tilesX[i];
    }



    //tiles = new int[2];
   // tiles = new int[0,32,64];

    // int positionsTiles[3] = {32,64,96};
    /*
    POSICIONES DE LA HOJA DE SPRITE. exampleL imagen de 64x64, si lo dividimos en un bloque de 32 entonces la primera
    posicion seria (0,0) y la segunda (32,21)
    */
    src.y = 0;
    src.x = 32;


    //src.x = src.y = 0;
    src.w = dest.w = 32;
    src.h = dest.h = 32;

    //dest.x = dest.y = 0;
    dest.y = 0;
    dest.x = 0;


};

void Map::LoadMap(int arr[20][25])
{
     for (int row = 0; row < 20; row++){
        for(int column = 0; column < 25; column++){
            map[row][column] = arr[row][column];
        }
     }
}


void Map::LoadMapWithFile(string path, int height, int width){

    ifstream myfile;

    myfile.open(path);
    string mapText [20][25];  
    string line;  

    std::vector<string> lines;


    if(myfile.is_open())
    {
        while (getline(myfile, line)){
            lines.push_back(line);
        }
        // leer el archivo
        for(int i = 0; i < 20; i++)
        {
            for(int j = 0; j < 25; j++)
            {
                if (lines[i][j] == '0') {
                    map[i][j] = STONE;
                    SDL_Rect stone;
                    stone.x = j * 32;
                    stone.y = i * 32;
                    stone.w = 32;
                    stone.h = 32;
                    this->obstacles.push_back({stone});
                }
                else if (lines[i][j] == '1') {
                    map[i][j] = EARTH;
                }
                else if (lines[i][j] == '2') {
                    map[i][j] = GRASS;
                }
                else if (lines[i][j] == '3') {
                    map[i][j] = WALL;

                    //CREATE A RECT 
                    /**/
                    SDL_Rect wall;
                    wall.x = j * 32;
                    wall.y = i * 32;
                    wall.w = 32;
                    wall.h = 32;
                    this->obstacles.push_back({wall});
                }
            }
        }
        myfile.close();
    }
    else
    {
        std::cout << "No se pudo abrir el archivo" << std::endl;
    }

}       

void Map::Render(SDL_Renderer* renderer, SDL_Texture* texture ,SDL_Rect srcRect, SDL_Rect destR){
    SDL_RenderCopy(renderer, texture, &srcRect, &destR);
}

void Map::DrawMap(SDL_Renderer* renderer)
{
    int type = 0;
    for (int row = 0; row < 20; row++){
        for(int column = 0; column < 25; column++){

            dest.x = column * 32;
            dest.y = row * 32;

            /*

                POSICION DEL TILE EN LA IMAGEN

            */

           
            type = map[row][column];
            src.x = this ->tilesX[type];
            src.y = this ->tilesY[type];


            //std::cout << "x: " << src.x << std::endl;

            Map::Render(renderer,background,src,dest);


        }
     }
}


void Map::Collision(SDL_Renderer* renderer,Player* player) {
    /*
        DETECT COLLISION
    */
    int y1 = (player->getY() + 32 )  / 32;
    int x1 = (player->getX() + 32)  / 32;


    //std::cout << "X1: " << x1 << " Y1:" << y1 << std::endl;

    //limit screen
    if (x1 > 24) {
        player -> setX(24 * 32);
    } else if (x1 < 1) {
        player -> setX(1);
    }

    if (y1 > 19) {
        player -> setY((y1 -1) * 32);
    } else if (y1 < 1) {
        player -> setY(0);
    }

for (int i = 0; i < this->obstacles.size(); i++)
{
    SDL_Rect obstacle = this->obstacles[i];
    SDL_Rect playerRect = { player->getX(), player->getY(), 32, 32 };

    if (SDL_HasIntersection(&obstacle, &playerRect)) {

        // Calcular el vector de separación
        float dx = obstacle.x + obstacle.w / 2 - (player->destR.x + player->destR.w / 2);
        float dy = obstacle.y + obstacle.h / 2 - (player->destR.y + player->destR.h / 2);
        float distance = sqrt(dx * dx + dy * dy);

        float width = player->destR.w;
        float height = player->destR.h;
        float radiusPlayer = sqrt(width * width + height * height) / 2.0f;

        //radius obstacle
        float widthO = obstacle.w;
        float heightO = obstacle.h;
        float radiusObstacle = sqrt(widthO * widthO + heightO * heightO) / 2.0f;


        float radiusSum = radiusObstacle + radiusPlayer;

        if (distance >= radiusSum) {
            // No hay colisión, salir
            return;
        }
        float separation = radiusSum - distance;
        dx /= distance;
        dy /= distance;

        // Ajustar las posiciones de los objetos
        player->destR.x -= dx * separation * 0.5f;
        player->destR.y -= dy * separation * 0.5f;


    }
}
    
}

