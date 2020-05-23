#include <SDL2/SDL.h>
#include <iostream>
#include "renderer.h"
#include "controller.h"
#include "game.h"
#include <memory>

int main(){
    // width defines the screenwidth of the game window
    constexpr int width = 1000;
    // height defines the screenheight of the game window
    constexpr int height = 700;
    // framesPerSec defines the framerate
    constexpr int framesPerSec{60};
    // MsPerFrame defines the time taken in milliseconds per frame
    constexpr int MsPerFrame = 1000/framesPerSec;
    // running is initialized to true to run the game in the loop, once the 
    // game is over running is set to false
    bool running{true};
    // timestamp defines the current ticks
    Uint32 timestamp = SDL_GetTicks();
    Uint32 frame_start, frame_end, frame_duration;
    // frame_count keeps track of the number of frames rendered
    int frame_count{0};
    // Game class has been initialized
    std::unique_ptr<Game> game(new Game(width,height));
    // sets the intial postions and shapes of the paddles and the ball
    game->Init();
    // while loop keeps running until the game over or the the game is closed
    while(running)
    {
        frame_start = SDL_GetTicks();
        game->play(running);
        frame_end = SDL_GetTicks();
        frame_count++;
        frame_duration = frame_end - frame_start;
        // the scores are updated every one second
        if ((frame_end - timestamp) > 1000){
            game->windowscoreupdate(frame_count);
            timestamp = frame_end;
            frame_count = 0;
        }
        // the condition is provided to have uniform frame rate
        if(frame_duration < MsPerFrame)
            SDL_Delay(MsPerFrame - frame_duration);

    }
    // after the game is over the final winner is printed on the window title
    game->windowscoreupdate(frame_count);
    std::cout << "Press any key followed by enter to close the window!!!!!!!!!!!" << std::endl;
    std::string temp;
    std::cin >> temp;
}
