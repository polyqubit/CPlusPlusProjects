#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Face.cpp"

// hpp is an interface?
class Application {
    public:
        Application();
        ~Application();

        void loop();
        void draw();
        void update(double delta_time);
        SDL_Surface *load_surface(char const *path);
    private:
        Face      m_face;

        SDL_Window   *m_window;
        SDL_Surface  *m_window_surface;
        SDL_Renderer *m_renderer;
        SDL_Event     m_window_event;
};