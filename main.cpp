#include <iostream>
#include <SDL2/SDL.h>
#include <conio.h>
#include <Application.hpp>
// terminal -> command in make.txt
// following tutorial for now lol
const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char *argv[]) {
	Application app;

    app.update();
    app.draw();
	return EXIT_SUCCESS;
}