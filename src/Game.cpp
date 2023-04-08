
#include "Player.hpp"
#include "Map.hpp"

//SDL_Texture* playerText;
//SDL_Rect srcR,destR;
Player* player;
Map* map;


Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen, const char* icon_path){
	int flags = 0;
	if (fullscreen){ 
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem initialized..." << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window){
			std::cout << "Window created!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window,-1,0 );
		if (renderer){
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			std::cout << "Renderer created!" << std::endl;
		}
		isRunning = true;

	} else {
		isRunning = false;
	} 

 	SDL_Surface* tempSurface = IMG_Load(icon_path);
	SDL_SetWindowIcon(window,tempSurface);


	player = new Player();
	map = new Map(renderer, "./assets/lvls/lvl_0.txt",20, 25);
	player -> Init(renderer, 100, 10, WIDTH_PLAYER, HEIGHT_PLAYER, NULL ,SDL_FLIP_NONE);
	
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch(event.type){
		case SDL_QUIT:
			isRunning = false;
			break;

		case SDL_KEYDOWN:
			//rigth
			if (event.key.keysym.sym == SDLK_RIGHT){
				player -> setRigth(true);
				//player->destR.x += player->getSpeed();

			}else if (event.key.keysym.sym == SDLK_LEFT){
				player -> setLeft(true);
				//player->destR.x -= player->getSpeed();

			} else if (event.key.keysym.sym == SDLK_UP){
				player -> setUp(true);
				//player->destR.y -= player->getSpeed();

			} else if (event.key.keysym.sym == SDLK_DOWN){
				player -> setDown(true);
				//player->destR.y += player->getSpeed();
			}
			break;

		case SDL_KEYUP:
			//rigth
			if (event.key.keysym.sym == SDLK_RIGHT){
				player -> setRigth(false);
			}else if (event.key.keysym.sym == SDLK_LEFT){
				player -> setLeft(false);
			} else if (event.key.keysym.sym == SDLK_ESCAPE){
				isRunning = false;
			} else if (event.key.keysym.sym == SDLK_UP){
				player -> setUp(false);

			} else if (event.key.keysym.sym == SDLK_DOWN){
				player -> setDown(false);
			}

			break;

		default:
			break;
	}
}

void Game::update()
{
	if (player -> getDirections()[0]){
		player -> move(player -> getSpeed(),0);
	}else if (player -> getDirections()[1]){
		player -> move(- player -> getSpeed(),0);
	}else if (player -> getDirections()[2]){
		player -> move(0,- player -> getSpeed());
	}else if (player -> getDirections()[3]){
		player -> move(0,player -> getSpeed());
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);

	//SDL_RenderCopy(renderer,player->getImage(),NULL,&destR);
	map -> DrawMap(renderer);
	map ->Collision(renderer,player);
	player -> render(renderer,0);

	//SDL_RenderCopy(renderer,playerText,NULL,&destR);
	//
	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	std::cout << "Game Cleaned" << std::endl;
}