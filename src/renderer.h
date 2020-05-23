#ifndef RENDERER_H
#define RENDERER_H
#include <SDL2/SDL.h>

class Renderer
{
 public:
   // Constructor
    Renderer(int width, int height);
    // Destructor
    ~Renderer();
    // getWidth function returns the width of the screen
    const int getWidth() const;
    // getHeight function returns the height of the screen
    const int getHeight() const;
    // render function renders the paddles and the ball on the screen
    const void render(const SDL_Rect& left_paddle, const SDL_Rect& right_paddle, const SDL_Rect& ball) const;
    // write_score function prints the score on the title of the window
    const void write_score(const int score[2], const int& fps) const;

 private:
    SDL_Window *_window;
    SDL_Renderer* _renderer;
    // _width denotes the width of the screen
    int _width;
    // _height denotes the height of the screen
    int _height;
};
#endif