#pragma once
#include "src/Game.h"

class Menu {
public:
	Menu() {
        font.loadFromFile(_FONT);
        
        SetupTitleText(StartText, font, "Start", 32, Color::White);
        SetupTitleText(QuitText, font, "Quit", 32, Color::White);
        SetupTitleText(TenText, font, "10", 20, Color::White);
        SetupTitleText(TwentyText, font, "20", 20, Color::White);
        SetupTitleText(ThirtyText, font, "30", 20, Color::White);
	
        TitleText.setPosition(40, 30);
        StartText.setPosition(130, 150);
        QuitText.setPosition(135, 250);

        TenText.setPosition(160, 150);
        TwentyText.setPosition(160, 200);
        ThirtyText.setPosition(160, 250);
    }

    void ChoiceSizeMenu() {
        SetupTitleText(TitleText, font, "Choose your gameboard size!", 20, Color::White);
        TitleText.setPosition(30, 30);
        
        while (window.isOpen()) {
            while (window.pollEvent(event)) {
                if (event.type == Event::MouseButtonPressed) {
                    Vector2i mousePosition = Mouse::getPosition(window);

                    if (TenText.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        N = 10;
                        return;
                    }
                    else if (TwentyText.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        N = 20;
                        return;
                    }
                    else if (ThirtyText.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        N = 30;
                        return;
                    }
                }
            }

            window.clear();
            window.draw(TitleText);
            window.draw(TenText);
            window.draw(TwentyText);
            window.draw(ThirtyText);
            window.display();
        }
    }

    void StartMenu() {
        window.create(VideoMode(320, 320), "Snake Game");
        SetupTitleText(TitleText, font, "Snake Game", 40, Color::White);

        while (window.isOpen()) {
            while (window.pollEvent(event)) {
                if (event.type == Event::MouseButtonPressed) {
                    Vector2i mousePosition = Mouse::getPosition(window);

                    if (StartText.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        ChoiceSizeMenu();
                        startFlag = true;
                    }
                    else if (QuitText.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        window.close();
                    }
                }
            }

            window.clear();

            if (startFlag) break;

            window.draw(TitleText);
            window.draw(StartText);
            window.draw(QuitText);
            window.display();
        }

        Game game;
        game.game();
    }
};