
#include "Player.hpp"
#include <iostream>

#define SPEED_SPRITE 4

//SDL_Texture* playerText;
SDL_Rect srcR,destR;

void Sprite::Init(SDL_Renderer* renderer, int x, int y, int w, int h, int* speed,SDL_RendererFlip flip) {
    /*
        spanish: Constructor de la clase Sprite
        english: Sprite class constructor
    */
    this -> destR = {x,y,w,h};
    const int WIDTH_IMAGE = 32;
    const int HEIGTH_IMAGE = 52;

    this -> srcRect = {0,0,WIDTH_IMAGE,HEIGTH_IMAGE};
    this -> image = TextureManager::LoadTexture("assets/hug.png", renderer);
    this -> flip = flip;

    if (speed != NULL) {
        this -> speed = *speed;
    } else {
        this -> speed = SPEED_SPRITE;
    }


    this -> frames = {
        {0, new int[2]{0,0}},
        {1, new int[2]{32,0}},
        {2, new int[2]{64,0}},
   };

    this ->srcRect.x = this -> frames[1][0];
    this ->srcRect.y = this -> frames[1][1];

    this -> setImage(image);
    this -> sizeFrame = this->frames.size();

    //len frames map
    //std::cout << this -> frames.size() << std::endl;

    std::cout << "Sprite initialized: " << this -> frames[2][0] << std::endl;

}

void Sprite::setImage(SDL_Texture* image) {  
    this->image = image;
}

void Sprite::render(SDL_Renderer* renderer, double degree){
    //SDL_RenderCopy(renderer, this -> image, &this->srcRect, &this -> destR);
    SDL_RenderCopyEx(renderer, this -> image, &this->srcRect, &this -> destR, degree, NULL, this -> flip);
    //dibujar cuadrado del destR    
    SDL_RenderDrawRect(renderer, &this -> destR);
}


/*
    player
*/

void Player::move(int x, int y){
    this -> destR.x += x;
    this -> destR.y += y;

    //std::cout << "Player moved: " << this -> destR.x << "," << this -> destR.y << std::endl;
    if (this -> positionFrame < this -> sizeFrame - 1) {
        positionFrame++;
    } else {
        this -> positionFrame = 0;
    }

   //comparar si position frame es menor que frames.size()
    //si es menor, sumar 1
    //si es mayor, poner a 0


    this -> srcRect.x = this -> frames[positionFrame][0];
    this -> srcRect.y = this -> frames[positionFrame][1];
}

int Sprite::getSpeed(){
    return this -> speed;
}

SDL_Texture* Sprite::getImage(){
    return this -> image;
}

void Player::setRigth(bool right){
    this -> directions[0] = right;
    this -> flip = SDL_FLIP_NONE;
}

void Player::setLeft(bool left){
    this -> directions[1] = left;
    this -> flip = SDL_FLIP_HORIZONTAL;
}

void Player::setUp(bool up){
    this -> directions[2] = up;
}

void Player::setDown(bool down){
    this -> directions[3] = down;
}

bool *Player::getDirections(){
    return this -> directions;
}

int Player::getX(){
    return this -> destR.x;
}

int Player::getY(){
    return this -> destR.y;
}

int Player::setX(int x){
    this -> destR.x = x;
    return this -> destR.x;
}

int Player::setY(int y){
    this -> destR.y = y;
    return this -> destR.y;
}

