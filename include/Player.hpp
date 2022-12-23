#ifndef Player_hpp
#define Player_hpp
#include "Game.hpp"
#include <map>
#include "TextureManager.hpp"

#define WIDTH_PLAYER 32
#define HEIGHT_PLAYER 32

class Sprite {
    /*
        spanish: Clase para gestionar animaciones y colisines
        english: Sprite class for animations and collisions
    */

   private:
        int speed;

    public:
        void Init(SDL_Renderer* renderer, int x, int y, int w, int h, int* speed, SDL_RendererFlip flip);
        int getSpeed();

        SDL_Texture* image;
        SDL_Rect destR, srcRect;
        int positionFrame;
        int sizeFrame;
        SDL_RendererFlip flip;
        //array with sprites xy coordinates
        std::map<int, int*> frames;
        void setAnimation (int id);
        void render(SDL_Renderer* renderer, double degree);
        void setImage(SDL_Texture* image );
        SDL_Texture* getImage();


};

class Player: public Sprite {

        
    private:
        int x, y;
        bool directions[4] = {false, false, false, false};
        //rigth, left, up, down
    public:
        void move (int x, int y);
        void setRigth(bool right);
        void setLeft(bool left);
        void setUp(bool up);
        void setDown(bool down);
        bool* getDirections();
        // getters and setters
        int getX();
        int getY();
        int setX(int x);
        int setY(int y);
        //get image
        

};

#endif /* Player_hpp */