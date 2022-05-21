#include <iostream>
#include "Sprite.hpp"
#include "helper.cpp"

Sprite::Sprite() {
    m_image = helper::load_surface("resources/test.png");
    if(!m_image) {
        std::cout << "Failed to access image\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

    m_position.x = 20.0;
    m_position.y = 20.0;
    m_position.w = 94;
    m_position.h = 128;

    m_x = m_position.x;
    m_y = m_position.y;
}

void Sprite::update(double delta_time) {
    if(m_position.x < 20.0) {
        direction = true;
    }
    if(m_position.x > 70.0) {
        direction = false;
    }
    if(direction) {
        m_x = m_x + (5.0 * delta_time);
        m_position.x = m_x;
    }
    else {
        m_x = m_x - (5.0 * delta_time);
        m_position.x = m_x;
    }
}

void Sprite::draw(SDL_Surface *window_surface) {
    SDL_BlitSurface(m_image, nullptr, window_surface, &m_position);
}