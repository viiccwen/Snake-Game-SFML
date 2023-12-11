#pragma once
class Fruit {
private:
	pair<int, int> position;
public:
	Fruit() : position({0, 0}) {}

	void NewFruit() {
		srand((int)time(NULL));
		position.first = rand() % 20;
		position.second = rand() % 20;
	}

	void Show(Sprite s) {
		s.setPosition(position.first * SIZE, position.second * SIZE);
		window.draw(s);
	}

	bool IsReachedFruit(int& x, int& y) {
		return (x == position.first && y == position.second);
	}
};