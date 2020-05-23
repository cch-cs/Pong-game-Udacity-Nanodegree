#include "renderer.h"
#include <iostream>
#include <string>
// Constructor initialzes the screen width and height and defines the 
// _window and _renderer objects
Renderer::Renderer(int width, int height):_width(width),_height(height){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
        std::cerr << "Failed at SDL_Init()" << std::endl;

    _window = SDL_CreateWindow("My Pong Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_SHOWN);

    if(_window == nullptr) {
        std::cerr << "Window could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";

    }
    _renderer = SDL_CreateRenderer(_window, -1, 0);

    if (_renderer == nullptr) {
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }
}
// Destructor destroys the _renderer and _window objects and quits the SDL
Renderer::~Renderer(){
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}
// getWidth function returns the width of the screen
const int Renderer::getWidth() const{
    return _width;
}
// getHeight function returns the height of the screen
const int Renderer::getHeight() const{
    return _height;
}
// render function renders the paddles and the ball on the screen
const void Renderer::render(const SDL_Rect& left_paddle, const SDL_Rect& right_paddle, const SDL_Rect& ball) const{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(_renderer, &left_paddle);
    SDL_RenderFillRect(_renderer, &right_paddle);
    SDL_SetRenderDrawColor(_renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(_renderer, &ball);
    SDL_RenderPresent(_renderer);
}
// write_score function prints the score and the winner on the title of the window
const void Renderer::write_score(const int score[2], const int& fps) const{
    std::string title;
    if(score[0] == 30)
        title = "Game Over Player 1 has won the Game!!!!!!!!!!!!!";
    else if(score[1] == 30)
        title = "Game Over Player 2 has won the Game!!!!!!!!!!!!!";
    else
        title = "My Pong Game Scores Player 1: " + std::to_string(score[0]) + " Player 2: " + std::to_string(score[1]) + "   FPS: " + std::to_string(fps);
    SDL_SetWindowTitle(_window,title.c_str());
}