#pragma once

#include "Face.hpp"
#include <vector>

struct vertex {
    int x;
    int y;
    vertex() {x=0;y=0;}
    vertex(int a, int b) {x=a;y=b;};
    void modX(int a) {x=a;};
    void modY(int a) {y=a;};
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
        std::vector<vertex> vs;
        State motion;
};

// inheritance :o
class Cube : public Mesh {
    public:
        Cube();
        ~Cube() = default;
};