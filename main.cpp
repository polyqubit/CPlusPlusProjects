#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <conio.h>
// terminal -> command in make.txt
// following tutorial for now lol
const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *window = SDL_CreateWindow("TestSDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
	if(window == NULL) {
		std::cout << "error creating window" << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	if(renderer == NULL) {
		std::cout << "error getting renderer" << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Surface *window_surface = SDL_GetWindowSurface(window);
    if(!window_surface) {
        std::cout << "error getting window surface" << SDL_GetError() << std::endl;
		return 1;
    }

	SDL_Surface *image = IMG_Load("resources/test.png");
	if(!image) {
    	std::cout << "error loading image" << SDL_GetError() << std::endl;
    	return 1;
	}

	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
	if(!texture) {
		std::cout << "error creating texture" << SDL_GetError() << std::endl;
		return 1;
	}

	int image_width = image->w;
	int image_height = image->h;
	SDL_Rect dimensions = {0, 0, image_width, image_height};
	SDL_RenderCopy(renderer, texture, NULL, &dimensions);

	bool keep_window_open = true;
	bool a = false;
	while(keep_window_open) {
    	SDL_Event e;
    	while(SDL_PollEvent(&e) > 0) {
        	switch(e.type) {
            	case SDL_QUIT:
                	keep_window_open = false;
                break;
				case SDL_MOUSEBUTTONDOWN:
					if(!a) {
						dimensions = {0, 0, 500, image_height};
						std::cout << "MOUSE BUTTON PRESSED!!!\n";
						SDL_UpdateWindowSurface(window);
						a = true;
					}
				break;
				case SDL_MOUSEBUTTONUP:
					if(a) {
						dimensions = {0, 0, image_width, image_height};
						SDL_UpdateWindowSurface(window);
						a = false;
					}
				break;
			}
			SDL_RenderCopy(renderer, texture, NULL, &dimensions);
			SDL_RenderPresent(renderer);
        	SDL_BlitSurface(image, NULL, window_surface, NULL);
        	// SDL_UpdateWindowSurface(window);
    	}
	}

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}