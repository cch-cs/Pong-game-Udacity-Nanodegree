#include <SDL2/SDL.h>
#include <iostream>
#include "renderer.h"
#include "controller.h"
#include "game.h"
#include <memory>

int main(){
    constexpr int width = 1000;
    constexpr int height = 700;
    constexpr int framesPerSec{60};
    constexpr int MsPerFrame = 1000/framesPerSec;
    bool running{true};
    Uint32 timestamp = SDL_GetTicks();
    Uint32 frame_start, frame_end, frame_duration;
    int frame_count{0};
    std::shared_ptr<Game> game(new Game(width,height));
    game->Init();
    while(running)
    {
        frame_start = SDL_GetTicks();
        game->play(running);
        frame_end = SDL_GetTicks();
        frame_count++;
        frame_duration = frame_end - frame_start;
        if ((frame_end - timestamp) > 1000){
            game->windowscoreupdate(frame_count);
            timestamp = frame_end;
            frame_count = 0;
        }

        if(frame_duration < MsPerFrame)
            SDL_Delay(MsPerFrame - frame_duration);

    }
    game->windowscoreupdate(frame_count);
    std::cout << "Press any key followed by enter to close the window!!!!!!!!!!!" << std::endl;
    std::string temp;
    std::cin >> temp;
}
