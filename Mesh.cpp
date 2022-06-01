#include "Mesh.hpp"

#include <iostream>

Mesh::Mesh() {
    // initialize vector array
}

void Mesh::update(double delta_time) {
    // transformations
    switch(direction) {
        case State::NONE: {
            
            break;
        }
        case State::UP: {
            
            break;
        }
        case State::DOWN: {
            
            
            break;
        }
        case State::LEFT: {
            
            break;
        }
        case State::RIGHT: {
            
            break;
        }
        // case Direction::EXPAND: {
        //     // m_x = m_x - (m_position.w);
        //     // m_y = m_y - (m_position.h);
        //     m_image = rotozoomSurface(m_image, 0, 1.01, 0);
        //     break;
        // }
    }
}

// void Face::draw(SDL_Renderer *renderer, const Sint16 *vx, const Sint16 *vy) {
void Mesh::draw(SDL_Renderer *renderer) {
    // loop through vertex array and construct mesh
}

void Mesh::handle_events(SDL_Event const &event) {
    switch(event.type) {
        case SDL_KEYDOWN: {
            Uint8 const *keys = SDL_GetKeyboardState(nullptr);

            if(keys[SDL_SCANCODE_W] == 1) {
                direction = State::UP;
            }
            else if(keys[SDL_SCANCODE_S] == 1) {
                direction = State::DOWN;
            }
            else if(keys[SDL_SCANCODE_A] == 1) {
                direction = State::LEFT;
            }
            else if(keys[SDL_SCANCODE_D] == 1) {
                direction = State::RIGHT;
            }
            // else if(keys[SDL_SCANCODE_E] == 1) {
            //     m_direction = Direction::EXPAND;
            //     std::cout << "EXPANDING\n";
            // }
            break;
        }
        case SDL_KEYUP: {
            direction = State::NONE;
            break;
        }
    }
}