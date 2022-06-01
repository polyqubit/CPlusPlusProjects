#pragma once

#include "Face.hpp"

struct vertex {
    int x;
    int y;
};

enum class State {
    NONE,
    UP,
    DOWN,
    LEFT,
    RIGHT
    // EXPAND
};
// Mesh is an array of vertices, rendered using Faces
class Mesh {
    public:
        Mesh();
        ~Mesh() = default;
    
        void update(double delta_time);
        // void draw(SDL_Renderer *renderer, const Sint16 *vx, const Sint16 *vy);
        void draw(SDL_Renderer *renderer);
        void handle_events(SDL_Event const &event);
    private:
        State      direction;
        vertex     vs[3];
};