# Pong-game-Udacity-Nanodegree

This is a game developed for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The Capstone project considered is Capstion Option 2. The Game developed is Pong. It is a two player game.

The winner of the game is the first one to score 30 points. The "player one" can control the paddle using the Up and Down arrows and the "player two" can control the paddle using the number 8 and 2 in the numpad.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
* SDL2 >= 2.0
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./Pong`.

## List of rubric points addressed.
# Loops, Functions, I/O
1. The project code compiles and runs without any errors.
2. While loop is used in file "main.cpp" in line "19" to run the game in the loop.
3. The project reads the inputs from the user, which is shown in the file "controller.cpp" in the function given in line "4".
# Object Oriented Programming
4. The project code is clearly organised into classes in various files.
5. The project is organised into classes with class attributes and class methods in the files "controller.h, controller.cpp, game.h, game.cpp, renderer.h, renderer.cpp".
6. All class data members are explicitly specified as public and private in the above mentioned files.
7. All class members that are set to argument values are initialized through member initialization list in file "game.cpp" in line "4" and in file "renderer.cpp" in line "5".
8. Comments are provided for all the class functions to describe its purpose.
9. All the class members are private and are accessed by member functions(getters).
10. Composition is used which can be seen in the file "game.h" in the lines "40 & 41".
# Memory Management
11. All the member functions of the class use pass-by-reference except one function in file "renderer.h" in line "19", as arrays can't be passed by reference.
12. The project uses one smart pointer "unique_ptr" in the file "main.cpp" in the line "26".
