#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "SDL2/SDL.h"

class Controller{
    public:
        //enum class Direction used to denote the direction of movement of paddle 
        enum class Direction{Stop, Up, Down};
        //enum class Paddle used to denote which paddle need to be moved
        enum class Paddle{None, l_paddle,r_paddle};
        //input function gets the input from the user and moves the appropriate paddle
        //if the game is still running
        const void input(bool& running);
        //getDirection function to get the current direction of the respective paddle
        const Direction getDirection() const;
        //getPaddle function to get the current paddle getting input from user
        const Paddle getPaddle() const;
    private:
        // declaration of enum type
        Direction _direction;
        Paddle _paddle;
};
#endif