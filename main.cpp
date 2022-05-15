#include <iostream>
#include <SDL2/SDL.h>
#include <conio.h>
// terminal -> make
const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *window = SDL_CreateWindow("TestSDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN || SDL_WINDOW_ALLOW_HIGHDPI);
	if(window == NULL) {std::cout << "error creating window" << SDL_GetError() << std::endl; return 1;}

	SDL_Event windowEvent;
	while(true) {
		if(SDL_PollEvent(&windowEvent)) {
			if(SDL_QUIT == windowEvent.type) {break;}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}