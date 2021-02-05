# CPPND: Capstone *The Vicious Snake Game*

Remenicent to today's world *The Vicious Snake Game* challenges the player to survive in an environment filled with consumables. The game will test the player's disipline and strategic movements.

Based on the starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Rubric Requirements Satisfied

1. The project demonstrates an understanding of C++ functions and control structures.
> This is present throughout the code. Functions and control sturctures were used.

2. The project reads data from a file and process the data, or the program writes data to a file.
> In main.cpp line 22, the game reads the ascii art title from the data folder.

3. The project accepts user input and processes the input.
> In main.cpp line 46, the game reads user input to to play again. 

4. The project uses Object Oriented Programming techniques.
> The game impliments the class Food. 

5. Classes use appropriate access specifiers for class members.
> The Food class has both public and private variables and functions.

6. Class constructors utilize member initialization lists.
> The Food class utilizes member initialization lists. 

7. Classes abstract implementation details from their interfaces.
> The Food class abstracts the food operations allowing for more features such as having mutiple food cells in the map.

8. Overloaded functions allow the same function to operate on different parameters.
> The Food class overloads the foodCell() function line 60 in food.h.



