#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite {
    public:
        Sprite();
        ~Sprite() = default;
        
        void update(double delta_time);
        void draw(SDL_Surface *window_surface);
    private:
        SDL_Surface *m_image;
        SDL_Rect     m_position;
        int          m_x;
        int          m_y;
};