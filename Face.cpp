#include <iostream>
#include "Face.hpp"
#include "helper.cpp"

Face::Face() {
    // m_image = helper::load_surface("resources/test.png");
    // if(!m_image) {
    //     std::cout << "Failed to access image\n";
    //     std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
    //     return;
    // }

    // m_position.x = 70.0;
    // m_position.y = 70.0;
    // m_position.w = 94;
    // m_position.h = 128;

    // m_x = m_position.x;
    // m_y = m_position.y;

    vx[0] = 50;
    vx[1] = 150;
    vx[2] = 250;
    
    vy[0] = 50;
    vy[1] = 250;
    vy[2] = 50;
}

void Face::update(double delta_time) {
    switch(m_direction) {
        case Direction::NONE: {
            vx[0] += 0;
            vx[1] += 0;
            vx[2] += 0;
    
            vy[0] += 0;
            vy[1] += 0;
            vy[2] += 0;
            break;
        }
        case Direction::UP: {
            // m_y = m_y - (10.0 * delta_time); preserve
            vy[0] -= 10.0 * delta_time;
            vy[1] -= 10.0 * delta_time;
            vy[2] -= 10.0 * delta_time;
            break;
        }
        case Direction::DOWN: {
            // m_y = m_y + (10.0 * delta_time);
            vy[0] += 10.0 * delta_time;
            vy[1] += 10.0 * delta_time;
            vy[2] += 10.0 * delta_time;
            break;
        }
        case Direction::LEFT: {
            // m_x = m_x - (10.0 * delta_time);
            vx[0] -= 10.0 * delta_time;
            vx[1] -= 10.0 * delta_time;
            vx[2] -= 10.0 * delta_time;
            break;
        }
        case Direction::RIGHT: {
            // m_x = m_x + (10.0 * delta_time);
            vx[0] += 10.0 * delta_time;
            vx[1] += 10.0 * delta_time;
            vx[2] += 10.0 * delta_time;
            break;
        }
        // case Direction::EXPAND: {
        //     // m_x = m_x - (m_position.w);
        //     // m_y = m_y - (m_position.h);
        //     m_image = rotozoomSurface(m_image, 0, 1.01, 0);
        //     break;
        // }
    }

    m_position.x = m_x;
    m_position.y = m_y;
}

// void Face::draw(SDL_Renderer *renderer, const Sint16 *vx, const Sint16 *vy) {
void Face::draw(SDL_Renderer *renderer) {
    // make a struct containing coords
    if(filledPolygonRGBA(renderer,vx,vy,3,0,100,0,255)!=0) { //aaTrigonColor does not work(?)
        std::cout << "error";
        return;
    }
    // std::cout << "didn't break";
    // SDL_BlitSurface(m_image, nullptr, window_surface, &m_position);
}

void Face::handle_events(SDL_Event const &event) {
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
            // else if(keys[SDL_SCANCODE_E] == 1) {
            //     m_direction = Direction::EXPAND;
            //     std::cout << "EXPANDING\n";
            // }
            break;
        }
        case SDL_KEYUP: {
            m_direction = Direction::NONE;
            break;
        }
    }
}