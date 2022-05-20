#include "Application.hpp"

namespace helper{
    // loads image
    SDL_Surface *load_surface(char const *path) {
        SDL_Surface *image_surface = IMG_Load(path);

        if(!image_surface) {return 0;}

        return image_surface;
    }
}