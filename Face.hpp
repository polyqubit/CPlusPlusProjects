#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_rotozoom.c>

enum class Direction {
    NONE,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    EXPAND
};

class Face {
    public:
        Face();
        ~Face() = default;
    
        void update(double delta_time);
        void draw(SDL_Surface *window_surface);
        void handle_events(SDL_Event const &event);
    private:
        SDL_Surface *m_image;
        SDL_Rect     m_position;
        Direction    m_direction;
        double       m_x;
        double       m_y;
        bool         direction; // true = right, false = left
};