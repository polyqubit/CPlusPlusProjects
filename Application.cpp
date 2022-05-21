#include <iostream>
#include "Application.hpp"

// somewhat translates to implementing an interface?

// constructor
Application::Application() {
    m_window = SDL_CreateWindow("Shapes",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, 0);
    if(!m_window) {
        std::cout << "Failed to create window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

    m_window_surface = SDL_GetWindowSurface(m_window);
    if(!m_window_surface) {
        std::cout << "Failed to get window's surface\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }
}

// destructor(def not in java)
Application::~Application() {
    SDL_FreeSurface(m_window_surface);
    SDL_DestroyWindow(m_window);
}

// implementation of methods

// if there is an event to be handled, do something
void Application::loop() {
    bool keep_window_open = true;
    while(keep_window_open) {
        while(SDL_PollEvent(&m_window_event) > 0) {
            m_sprite.handle_events(m_window_event);
            switch(m_window_event.type) {
                case SDL_QUIT:
                    keep_window_open = false;
                break;
            }
        }
        update(0.01667); // 60 fps
        draw();
    }
}

void Application::update(double delta_time) {
    m_sprite.update(delta_time);
}

// updates window ig
void Application::draw() {
    SDL_FillRect(m_window_surface, nullptr, SDL_MapRGB(m_window_surface->format, 0, 0, 0));
    m_sprite.draw(m_window_surface);
    SDL_UpdateWindowSurface(m_window);
}