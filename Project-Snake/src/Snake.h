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

	Snake() : length(5), direction(UP) {
		snake.resize(length);
		for (int i = 0; i < length; i++) {
			snake[i].first = 10 + i;
			snake[i].second = 10;
		}

		movement = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
	}

	void Append() {
		snake.push_back({snake[length - 1].first, snake[length - 1].second});
		length++;
	}

	void Collision() {
		for (int i = 1; i < length; i++) {
			if (snake[0].first == snake[i].first && snake[0].second == snake[i].second) {
				window.close();
			}
		}
	}

	void Tick(Fruit &fruit, Sound & eatSound, int &score) {
		for (int i = length - 1; i > 0; --i) {
			snake[i].first= snake[i - 1].first;
			snake[i].second = snake[i - 1].second;
		}

		snake[0].first+= movement[direction].first;
		snake[0].second += movement[direction].second;

		if (snake[0].first >= N) snake[0].first = 0;
		if (snake[0].first < 0) snake[0].first = N - 1;
		if (snake[0].second >= N) snake[0].second = 0;
		if (snake[0].second < 0) snake[0].second = N - 1;

		if (fruit.IsReachedFruit(snake)) {
			score++;
			eatSound.play();
			fruit.NewFruit();
			Append();
		}

		Collision();
	}
};