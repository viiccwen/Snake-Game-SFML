#pragma once

class Game {
private:
    float timer = 0, interval = 0.3, speed = 0.3;
    int speedup = N / 5;
    int score = 0;

    Texture background, snakeColor, appleColor;
    
    Sprite s_backgound;
    Sprite s_snake;
    Sprite s_apple;

    Font font;
    Text text;

    Snake snake;
    Fruit apple;
    Clock clock;
public:
    Game() {
        background.loadFromFile(_BACKGROUND);
        snakeColor.loadFromFile(_SNAKE);
        appleColor.loadFromFile(_APPLE);

        s_backgound.setTexture(background);
        s_snake.setTexture(snakeColor);
        s_apple.setTexture(appleColor);

        font.loadFromFile(_FONT);
    }

    void draw() {
        window.clear();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                s_backgound.setPosition(i * SIZE, title + j * SIZE);
                window.draw(s_backgound);
            }
        }

        for (int i = 0; i < snake.length; i++) {
            s_snake.setPosition(snake.snake[i].first * SIZE, title + snake.snake[i].second * SIZE);
            window.draw(s_snake);
        }

        s_apple.setPosition(apple.position.first * SIZE, title + apple.position.second * SIZE);
        window.draw(s_apple);

        SetupTitleText(text, font, "Score: " + to_string(score), 14, Color::White);
        text.setPosition(10 , SIZE);
        window.draw(text);

        window.display();
    }

    void keyboardControl() {
        if (Keyboard::isKeyPressed(Keyboard::Up) && snake.direction != snake.DOWN) snake.direction = snake.UP;
        if (Keyboard::isKeyPressed(Keyboard::Down) && snake.direction != snake.UP) snake.direction = snake.DOWN;
        if (Keyboard::isKeyPressed(Keyboard::Left) && snake.direction != snake.RIGHT) snake.direction = snake.LEFT;
        if (Keyboard::isKeyPressed(Keyboard::Right) && snake.direction != snake.LEFT) snake.direction = snake.RIGHT;
    }

    float SpeedLevel() {
        return score / speedup > 0 ? interval * 4 / 5 : 0.3;
    }

    void TimeSetup() {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        if (timer > speed) {
            timer = 0;
            snake.Tick(apple, score);
            speed = SpeedLevel();
        }
    }

    void IsExit() {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
        
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed)
                window.close();
        }
    }

    void SetupTitleText(Text &text, Font &font, string str, int fontsize, Color fillcolor) {
        text.setFont(font);
        text.setString(str);
        text.setCharacterSize(fontsize);
        text.setFillColor(fillcolor);
    }

	void game() {
        while (window.isOpen()) {

            TimeSetup();

            IsExit();

            keyboardControl();

            draw();
        }

	}
};