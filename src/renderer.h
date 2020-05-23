#ifndef RENDERER_H
#define RENDERER_H
#include <SDL2/SDL.h>

class Renderer
{
 public:
    Renderer(int width, int height);
    ~Renderer();
    const int getWidth() const;
    const int getHeight() const;
    const void render(const SDL_Rect& left_paddle, const SDL_Rect& right_paddle, const SDL_Rect& ball) const;
    const void render_score(const int score[2], const int& fps) const;
    const void left_paddle_render(const SDL_Rect& left_paddle) const;
    const void right_paddle_render(const SDL_Rect& right_paddle) const;
    const void ball_render(const SDL_Rect& ball) const;

 private:
    SDL_Window *_window;
    SDL_Renderer* _renderer;
    int _width;
    int _height;
};
#endif