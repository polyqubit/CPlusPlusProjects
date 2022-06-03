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
        void update(double delta_time);
        // void draw(SDL_Renderer *renderer, const Sint16 *vx, const Sint16 *vy);
        void draw(SDL_Renderer *renderer);
        void handle_events(SDL_Event const &event);
    protected:
        State      motion;
        vertex     *vs;
};

// inheritance :o
class Cube : public Mesh {
    public:
        Cube();
        ~Cube() = default;
};