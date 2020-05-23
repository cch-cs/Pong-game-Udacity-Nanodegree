#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "SDL2/SDL.h"

class Controller{
    public:
        enum class Direction{Stop, Up, Down};
        enum class Paddle{None, l_paddle,r_paddle};
        const void input(bool& running);
        const Direction getDirection() const;
        const Paddle getPaddle() const;
    private:
        Direction _direction;
        Paddle _paddle;
};
#endif