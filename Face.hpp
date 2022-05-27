#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_rotozoom.c>
#include <SDL2/SDL2_gfxPrimitives.c>

enum class Direction {
    NONE,
    UP,
    DOWN,
    LEFT,
    RIGHT
    // EXPAND
};

// Face is a triangle drawn using gfx's 
class Face {
    public:
        Face();
        ~Face() = default;
    
        void update(double delta_time);
        // void draw(SDL_Renderer *renderer, const Sint16 *vx, const Sint16 *vy);
        void draw(SDL_Renderer *renderer);
        void handle_events(SDL_Event const &event);
    private:
        SDL_Surface *m_image;
        SDL_Rect     m_position;
        Direction    m_direction;
        
        Sint16 vx[3];  // = {50,100,50};
        Sint16 vy[3];  // = {50,100,10};
        double dvx[3];
        double dvy[3];

        double       m_x;
        double       m_y;
};