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

    m_position.x = 70.0;
    m_position.y = 70.0;
    m_position.w = 94;
    m_position.h = 128;

    m_x = m_position.x;
    m_y = m_position.y;
}

void Sprite::update(double delta_time) {
    switch(m_direction) {
        case Direction::NONE: {
            m_x += 0.0;
            m_y += 0.0;
            break;
        }
        case Direction::UP: {
            m_y = m_y - (10.0 * delta_time);
            break;
        }
        case Direction::DOWN: {
            m_y = m_y + (10.0 * delta_time);
            break;
        }
        case Direction::LEFT: {
            m_x = m_x - (10.0 * delta_time);
            break;
        }
        case Direction::RIGHT: {
            m_x = m_x + (10.0 * delta_time);
            break;
        }
        case Direction::EXPAND: {
            // m_x = m_x - (m_position.w);
            // m_y = m_y - (m_position.h);
            m_image = rotozoomSurface(m_image, 0, 1.01, 0);
            break;
        }
    }

    m_position.x = m_x;
    m_position.y = m_y;
}

void Sprite::draw(SDL_Surface *window_surface) {
    SDL_BlitSurface(m_image, nullptr, window_surface, &m_position);
}

void Sprite::handle_events(SDL_Event const &event) {
    switch(event.type) {
        case SDL_KEYDOWN: {
            Uint8 const *keys = SDL_GetKeyboardState(nullptr);

            if(keys[SDL_SCANCODE_W] == 1) {
                m_direction = Direction::UP;
                std::cout << "moving UP\n";
            }
            else if(keys[SDL_SCANCODE_S] == 1) {
                m_direction = Direction::DOWN;
                std::cout << "moving DOWN\n";
            }
            else if(keys[SDL_SCANCODE_A] == 1) {
                m_direction = Direction::LEFT;
                std::cout << "moving LEFT\n";
            }
            else if(keys[SDL_SCANCODE_D] == 1) {
                m_direction = Direction::RIGHT;
                std::cout << "moving RIGHT\n";
            }
            else if(keys[SDL_SCANCODE_E] == 1) {
                m_direction = Direction::EXPAND;
                std::cout << "EXPANDING\n";
            }
            break;
        }
        case SDL_KEYUP: {
            m_direction = Direction::NONE;
            break;
        }
    }
}