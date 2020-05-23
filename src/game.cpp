#include "game.h"
#include <cmath>
// object _render of class Renderer is initialized
Game::Game(int width, int height):_render(width,height){}
// Init function is used to define the position and shape of the paddles and ball
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
// paddleupdate  moves the paddles based on the user input
const void Game::paddleupdate(const Controller::Direction& direction, SDL_Rect& paddle){
    if ((direction == Controller::Direction::Up) && (paddle.y > 0)){
        paddle.y -= _speed;
    }
    else if((direction == Controller::Direction::Down) && (paddle.y < _render.getHeight()-150)){
        paddle.y += _speed;
    }
}
// play function is used to run the enire process which includes getting control inputs from
// the player, update the paddle movement and ball movement, and finally update the scores
// and render the image on the screen
const void Game::play(bool& running){
    // checks for user input and updates the paddle movement
    _control.input(running);
    // based onteh user input the respective paddle is moved as per if else condition
    if(_control.getPaddle() == Controller::Paddle::l_paddle){
        paddleupdate(_control.getDirection(),_left_paddle);
    }
    else if(_control.getPaddle() == Controller::Paddle::r_paddle) {
        paddleupdate(_control.getDirection(),_right_paddle);
    }
    // the ball position is updated
    ballmovement();
    // the scores are updated if any player gains a point
    scoreupdate();
    // if any player reaches 30 points wins and the running is set to false to 
    // come out of the loop in the main fuction
    if((_score[0] == 30) || (_score[1] == 30)){
        running = false;
        return;
    }
    // render the positions of the paddles and the ball
    _render.render(_left_paddle,_right_paddle,_ball);

}
// scoreupdate is used to update scores of the player of anyone gains a point
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
// ballmovement updates the position of the ball
const void Game::ballmovement(){
    float num;
    float den; 
    if(SDL_HasIntersection(&_ball,&_left_paddle)){
        // _bounce_angle is computed based on the horizontal distance and the vertical
        // distance between the ball and the paddle using arctan
        num = ((_left_paddle.x+_left_paddle.w/2) - (_ball.x+_ball.w/2));
        den = ((_left_paddle.y+_left_paddle.h/2) - (_ball.y+_ball.h/2));
        _turn = 1;
        if(den != 0)
            _bounce_angle = atan(num/den);
        else
            _bounce_angle = 0;
    }
    else if(SDL_HasIntersection(&_ball,&_right_paddle)){
        // _bounce_angle is computed based on the horizontal distance and the vertical
        // distance between the ball and the paddle using arctan
        num = ((_right_paddle.x+_right_paddle.w/2) - (_ball.x+_ball.w/2));
        den = ((_right_paddle.y+_right_paddle.h/2) - (_ball.y+_ball.h/2));
        _turn = 2;
        if(den != 0)
            _bounce_angle = atan(num/den);
        else
            _bounce_angle = 0;
    }
    // if the ball reaches the sides of the window, the ball is bounched back by
    // negating the _bounce_angle
    if((_ball.y <= 0) || (_ball.y >= _render.getHeight())){
        _bounce_angle = -_bounce_angle;
    }
    // the below conditions changes the direction of the ball movement based on the 
    // bounce angle and the current player who played the ball
    if(_turn == 1){
        _ball.x += _ballspeed*cos(_bounce_angle);
        _ball.y += _ballspeed*sin(_bounce_angle);
    }
    if(_turn == 2){
        _ball.x -= _ballspeed*cos(_bounce_angle);
        _ball.y -= _ballspeed*sin(_bounce_angle);
    }

}
// windowscoreupdate to used to print the scores on the window and the final winner 
const void Game::windowscoreupdate(const int& fps) const{
    _render.write_score(_score,fps);
}