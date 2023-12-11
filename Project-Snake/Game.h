#pragma once

class Game {
private:
    float timer = 0, delay = 0.1;

    Texture background, snakeColor;
    
    Sprite s1;
    Sprite s2;

    Snake snake;
    Fruit fruit;
    Clock clock;
public:
    Game() {
        background.loadFromFile("images/background.jpg");
        snakeColor.loadFromFile("images/red.jpg");

        s1.setTexture(background);
        s2.setTexture(snakeColor);
    }

    void draw() {
        window.clear();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                s1.setPosition(i * SIZE, j * SIZE);
                window.draw(s1);
            }
        }
        snake.Show(s2);
        fruit.Show(s2);
        window.display();
    }

    void keyboardControl() {
        if (Keyboard::isKeyPressed(Keyboard::Up) && snake.direction != snake.DOWN) snake.direction = snake.UP;
        if (Keyboard::isKeyPressed(Keyboard::Down) && snake.direction != snake.UP) snake.direction = snake.DOWN;
        if (Keyboard::isKeyPressed(Keyboard::Left) && snake.direction != snake.RIGHT) snake.direction = snake.LEFT;
        if (Keyboard::isKeyPressed(Keyboard::Right) && snake.direction != snake.LEFT) snake.direction = snake.RIGHT;
    }

    void TimeSetup() {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        if (timer > delay) {
            timer = 0;
            snake.Tick(fruit);
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
        while (window.isOpen()) {

            TimeSetup();

            IsExit();

            keyboardControl();

            draw();
        }

	}
};