#include "game.h"
#include <cmath>

Game::Game(int width, int height):_render(width,height){}

const void Game::Init(){
    _left_paddle.x = 50;
    _left_paddle.y = _render.getHeight()/2 - _render.getHeight()/10;
    _left_paddle.w = 20;
    _left_paddle.h = _render.getHeight()/5;
    _right_paddle.x = _render.getWidth()-70;
    _right_paddle.y = _render.getHeight()/2 - _render.getHeight()/10;
    _right_paddle.w = 20;
    _right_paddle.h = _render.getHeight()/5;
    _ball.w = 20;
    _ball.h = 20;
    if(_turn == 1){
        _ball.x = 80;
        _ball.y = _render.getHeight()/2 + _ball.h/2;
    }
    else if(_turn == 2){
        _ball.x = 900;
        _ball.y = _render.getHeight()/2 + _ball.h/2;
    }
}
const void Game::paddleupdate(const Controller::Direction& direction, SDL_Rect& paddle){
    if ((direction == Controller::Direction::Up) && (paddle.y > 0)){
        paddle.y -= _speed;
    }
    else if((direction == Controller::Direction::Down) && (paddle.y < _render.getHeight()-150)){
        paddle.y += _speed;
    }
}

const void Game::play(bool& running){
    _control.input(running);
    if(_control.getPaddle() == Controller::Paddle::l_paddle){
        paddleupdate(_control.getDirection(),_left_paddle);
    }
    else if(_control.getPaddle() == Controller::Paddle::r_paddle) {
        paddleupdate(_control.getDirection(),_right_paddle);
    }
    ballmovement();
    scoreupdate();
    if((_score[0] == 30) || (_score[1] == 30)){
        running = false;
        return;
    }
    _render.render(_left_paddle,_right_paddle,_ball);

}

const void Game::scoreupdate(){
    if (_ball.x > 990){
        _score[0]++;
        _turn = 2;
        Init();
    }
    if (_ball.x < 10){
        _score[1]++;
        _turn = 1;
        Init();
    }
}

const void Game::ballmovement(){
    float num;
    float den; 
    if(SDL_HasIntersection(&_ball,&_left_paddle)){
        num = ((_left_paddle.x+_left_paddle.w/2) - (_ball.x+_ball.w/2));
        den = ((_left_paddle.y+_left_paddle.h/2) - (_ball.y+_ball.h/2));
        _turn = 1;
        if(den != 0)
            _bounce_angle = atan(num/den);
        else
            _bounce_angle = 0;
    }
    else if(SDL_HasIntersection(&_ball,&_right_paddle)){
        num = ((_right_paddle.x+_right_paddle.w/2) - (_ball.x+_ball.w/2));
        den = ((_right_paddle.y+_right_paddle.h/2) - (_ball.y+_ball.h/2));
        _turn = 2;
        if(den != 0)
            _bounce_angle = atan(num/den);
        else
            _bounce_angle = 0;
    }
    if((_ball.y <= 0) || (_ball.y >= _render.getHeight())){
        _bounce_angle = -_bounce_angle;
    }
    if(_turn == 1){
        _ball.x += _ballspeed*cos(_bounce_angle);
        _ball.y += _ballspeed*sin(_bounce_angle);
    }
    if(_turn == 2){
        _ball.x -= _ballspeed*cos(_bounce_angle);
        _ball.y -= _ballspeed*sin(_bounce_angle);
    }

}

const void Game::windowscoreupdate(const int& fps) const{
    _render.render_score(_score,fps);
}