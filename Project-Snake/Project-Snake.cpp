#include <SFML/Graphics.hpp>

#include<iostream>
#include<stdlib.h>
#include <time.h>
#include<vector>
#include<utility>

using namespace std;
using namespace sf;

const int N = 20, M = 20;
const int SIZE = 30;
const int w = SIZE * N;
const int h = SIZE * M;

RenderWindow window(VideoMode(w, h), "Snake Game");

#include "Fruit.h"
#include "Snake.h"
#include "Game.h"

int main()
{   
    Game game;
    game.game();

    return EXIT_SUCCESS;
}