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

    dvx[0] = 100.0;
    dvx[1] = 200.0;
    dvx[2] = 300.0;
    
    dvy[0] = 100.0;
    dvy[1] = 300.0;
    dvy[2] = 100.0;

    vx[0] = dvx[0];
    vx[1] = dvx[1];
    vx[2] = dvx[2];

    vy[0] = dvy[0];
    vy[1] = dvy[1];
    vy[2] = dvy[2];
}

void Face::update(double delta_time) {
    switch(m_direction) {
        case Direction::NONE: {
            dvx[0] += 0;
            dvx[1] += 0;
            dvx[2] += 0;
    
            dvy[0] += 0;
            dvy[1] += 0;
            dvy[2] += 0;
            break;
        }
        case Direction::UP: {
            // m_y = m_y - (10.0 * delta_time); preserve
            dvy[0] -= 50.0 * delta_time;
            dvy[1] -= 50.0 * delta_time;
            dvy[2] -= 50.0 * delta_time;
            break;
        }
        case Direction::DOWN: {
            // m_y = m_y + (10.0 * delta_time);
            dvy[0] += 50.0 * delta_time;
            dvy[1] += 50.0 * delta_time;
            dvy[2] += 50.0 * delta_time;
            break;
        }
        case Direction::LEFT: {
            // m_x = m_x - (10.0 * delta_time);
            dvx[0] -= 50.0 * delta_time;
            dvx[1] -= 50.0 * delta_time;
            dvx[2] -= 50.0 * delta_time;
            break;
        }
        case Direction::RIGHT: {
            // m_x = m_x + (10.0 * delta_time);
            dvx[0] += 50.0 * delta_time;
            dvx[1] += 50.0 * delta_time;
            dvx[2] += 50.0 * delta_time;
            break;
        }
        // case Direction::EXPAND: {
        //     // m_x = m_x - (m_position.w);
        //     // m_y = m_y - (m_position.h);
        //     m_image = rotozoomSurface(m_image, 0, 1.01, 0);
        //     break;
        // }
    }

    vx[0] = dvx[0];
    vx[1] = dvx[1];
    vx[2] = dvx[2];

    vy[0] = dvy[0];
    vy[1] = dvy[1];
    vy[2] = dvy[2];
    // m_position.x = m_x;
    // m_position.y = m_y;
}

// void Face::draw(SDL_Renderer *renderer, const Sint16 *vx, const Sint16 *vy) {
void Face::draw(SDL_Renderer *renderer) {
    // make a struct containing coords
    aapolygonRGBA(renderer,nullptr,nullptr,3,0,100,0,255);
    if(aapolygonRGBA(renderer,vx,vy,3,0,100,0,255)!=0) { // aaTrigonColor does not work(?)
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