#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<utility>

using namespace std;
using namespace sf;

#include "src/Perameter.h"
#include "src/Fruit.h"
#include "src/Snake.h"
#include "src/Menu.h"
#include "src/Game.h"

int main()
{   
    Menu menu;
    menu.StartMenu();

    return EXIT_SUCCESS;
}