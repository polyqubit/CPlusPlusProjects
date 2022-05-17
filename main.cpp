#include <iostream>
#include <conio.h>
#include "Application.cpp"
// terminal -> command in make.txt
// following tutorial for now lol
const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char *argv[]) {
	Application app;

    app.update();
    app.draw();
	return EXIT_SUCCESS;
}