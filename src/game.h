#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <vector>
#include "renderer.h"
#include "controller.h"

class Game{
    public:
        // Constructor
        Game(int width, int height);
        // Init function is used to define the position and shape of the paddles and ball
        const void Init();
        // play function is used to run the enire process which includes getting control inputs from
        // the player, update the paddle movement and ball movement, and finally update the scores
        // and render the image on the screen
        const void play(bool& running);
        // windowscoreupdate to used to print the scores on the window and the final winner
        const void windowscoreupdate(const int& fps) const;
        // paddleupdate  moves the paddles based on the user input
        const void paddleupdate(const Controller::Direction& direction, SDL_Rect& paddle);
        // scoreupdate is used to update scores of the player
        const void scoreupdate();
        // ballmovement moves the ball
        const void ballmovement();
    private:
        // _speed denotes the speed of the paddle movement
        const int _speed = 20;
        // _ballspeed denotes the speed of the ball
        const int _ballspeed = 10;
        // _bounce_angle denotes the angle of ball bouncing from the surfaces of paddle and sides
        float _bounce_angle{0.0};
        // _score denotes the scores of the player initalized as zeros
        int _score[2]{0,0};
        // _left_paddle, _right_paddle, _ball denotes the shape of the paddles and ball
        SDL_Rect _left_paddle;
        SDL_Rect _right_paddle;
        SDL_Rect _ball;
        // declaration of classes Renderer and Controller
        Renderer _render;
        Controller _control;
        // _turn denotes player has played currently, intialized as player 1.
        // for player 2, the value is 2
        int _turn{1};
};
#endif