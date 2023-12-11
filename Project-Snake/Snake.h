#pragma once

class Snake {
private:
	vector<pair<int, int>> movement;
public:
	enum Direction {
		UP, RIGHT, DOWN, LEFT
	};
	vector<pair<int, int>> snake;
	int	length;
	int direction;

	Snake() : length(3), direction(UP) {
		snake.resize(3);
		for (int i = 0; i < 3; i++) {
			snake[i].first = 10 + i;
			snake[i].second = 10;
		}

		movement = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
	}

	void Append() {
		snake.push_back({snake[length - 1].first, snake[length - 1].second});
		length++;
	}

	void Show(Sprite s) {
		for (int i = 0; i < length; i++) {
			s.setPosition(snake[i].first * SIZE, snake[i].second * SIZE);
			window.draw(s);
		}
	}

	void Tick(Fruit &fruit) {
		for (int i = length - 1; i > 0; --i) {
			snake[i].first= snake[i - 1].first;
			snake[i].second = snake[i - 1].second;
		}

		snake[0].first+= movement[direction].first;
		snake[0].second += movement[direction].second;

		if (snake[0].first >= N) snake[0].first = 0;
		if (snake[0].first < 0) snake[0].first = N;
		if (snake[0].second >= M) snake[0].second = 0;
		if (snake[0].second < 0) snake[0].second = M;

		if (fruit.IsReachedFruit(snake[0].first, snake[0].second)) {
			fruit.NewFruit();
			Append();
		}
	}
};