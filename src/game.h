#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <vector>
#include "renderer.h"
#include "controller.h"

class Game{
    public:
        Game(int width, int height);
        const void Init();
        const void play(bool& running);
        const void windowscoreupdate(const int& fps) const;
        const void paddleupdate(const Controller::Direction& direction, SDL_Rect& paddle);
        const void scoreupdate();
        const void ballmovement();
    private:
        const int _speed = 20;
        const int _ballspeed = 10;
        float _bounce_angle{0.0};
        int _score[2]{0,0};
        SDL_Rect _left_paddle;
        SDL_Rect _right_paddle;
        SDL_Rect _ball;
        Renderer _render;
        Controller _control;
        int _turn{1};
};
#endif