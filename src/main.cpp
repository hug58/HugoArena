#include "Game.hpp"


Game *game = nullptr;
//Player *player = nullptr;
int main(int argv, char** args)
{
	//player = new Player();
	//player -> run (12,12);
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;


 	const char* name =  "GAME Test";//std::getenv("NAME");
	const char* icon_path = "./assets/paty.png";

	std::cout << name;

	game = new Game();
	game -> init(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 32*25, 32*20, false, icon_path);


	while (game -> running()){
		frameStart = SDL_GetTicks();
		game -> handleEvents();
		game -> render();
		game -> update();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
		
	}
	
	game -> clean();



	/* code */
	return 0;
}