#include "controller.h"

const void Controller::input(bool& running){
    SDL_Event e;
    const Uint8 *keystates = SDL_GetKeyboardState(nullptr);
    while(SDL_PollEvent(&e)){
        if(e.type==SDL_QUIT)
            running=false;
        if(keystates[SDL_SCANCODE_ESCAPE])
            running=false;
        if(e.type == SDL_KEYDOWN){
            switch(e.key.keysym.sym){
                case SDLK_KP_8:
                    _direction = Direction::Up;
                    _paddle = Paddle::r_paddle;
                    break;
                case SDLK_KP_2:
                    _direction = Direction::Down;
                    _paddle = Paddle::r_paddle;
                    break;
                case SDLK_UP:
                    _direction = Direction::Up;
                    _paddle = Paddle::l_paddle;
                    break;
                case SDLK_DOWN:
                    _direction = Direction::Down;
                    _paddle = Paddle::l_paddle;
                    break;
                default:
                    _direction = Direction::Stop;
                    _paddle = Paddle::None;
                    break;
            }
        }
        else {
            _direction = Direction::Stop;
            _paddle = Paddle::None;
        }
    }
}

const Controller::Direction Controller::getDirection() const{
    return _direction;
}

const Controller::Paddle Controller::getPaddle() const{
    return _paddle;
}