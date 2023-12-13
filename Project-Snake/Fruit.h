#pragma once
class Fruit {
public:
	pair<int, int> position;
	Fruit() : position({10, 10}) {}

	void NewFruit() {
		srand((int)time(NULL));
		position.first = rand() % N;
		position.second = rand() % N;
	}

	bool IsReachedFruit(vector<pair<int, int>> &snake) {
		for (int i = 0; i < snake.size(); i++) {
			if (position.first == snake[i].first && position.second == snake[i].second) 
				return true;
		}
		
		return false;
	}
};