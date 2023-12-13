#include <SFML/Graphics.hpp>

#include<iostream>
#include<stdlib.h>
#include <time.h>
#include<vector>
#include<utility>

using namespace std;
using namespace sf;

const int N = 20;
const int SIZE = 16;
const int w = SIZE * N;
const int title = 48;
const int border = 15;

const string _BACKGROUND = "images/background.png";
const string _SNAKE = "images/snake.png";
const string _APPLE = "images/apple.png";
const string _FONT = "arial.ttf";

RenderWindow window(VideoMode(w + border, title + w + border), "Snake Game");

#include "Fruit.h"
#include "Snake.h"
#include "Game.h"

int main()
{   
    Game game;
    game.game();

    return EXIT_SUCCESS;
}