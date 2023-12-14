#pragma once

class Game {
private:
    Snake snake;
    Fruit apple;
    Clock clock;
public:
    Game() {
        background.loadFromFile(_BACKGROUND);
        snakeColor.loadFromFile(_SNAKE);
        appleColor.loadFromFile(_APPLE);

        eatSound_Buffer.loadFromFile(_EAT_SOUND);
        LeftPress_Buffer.loadFromFile(_LEFT_PRESS_SOUND);
        RightPress_Buffer.loadFromFile(_RIGHT_PRESS_SOUND);
        UpPress_Buffer.loadFromFile(_UP_PRESS_SOUND);
        DownPress_Buffer.loadFromFile(_DOWN_PRESS_SOUND);

        eatSound.setBuffer(eatSound_Buffer);
        LeftPress.setBuffer(LeftPress_Buffer);
        RightPress.setBuffer(RightPress_Buffer);
        UpPress.setBuffer(UpPress_Buffer);
        DownPress.setBuffer(DownPress_Buffer);

        s_backgound.setTexture(background);
        s_snake.setTexture(snakeColor);
        s_apple.setTexture(appleColor);

        

        
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

        SetupTitleText(ScoreText, font, "Score: " + to_string(score), 14, Color::White);
        
        ScoreText.setPosition(10 , SIZE);
        window.draw(ScoreText);

        window.display();
    }

    void keyboardControl() {
        if (Keyboard::isKeyPressed(Keyboard::Up) && snake.direction != snake.DOWN && snake.direction != snake.UP) {
            UpPress.play();
            snake.direction = snake.UP;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down) && snake.direction != snake.UP && snake.direction != snake.DOWN) {
            DownPress.play();
            snake.direction = snake.DOWN;
        }
        if (Keyboard::isKeyPressed(Keyboard::Left) && snake.direction != snake.RIGHT && snake.direction != snake.LEFT) {
            LeftPress.play();
            snake.direction = snake.LEFT;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right) && snake.direction != snake.LEFT && snake.direction != snake.RIGHT) {
            RightPress.play();
            snake.direction = snake.RIGHT;
        }
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
            snake.Tick(apple, eatSound, score);
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


	void game() {
        w = N * SIZE;
        window.create(VideoMode(w + border, w + title + border), "Snake Game");

        while (window.isOpen()) {

            TimeSetup();

            IsExit();

            keyboardControl();

            draw();
        }

	}
};