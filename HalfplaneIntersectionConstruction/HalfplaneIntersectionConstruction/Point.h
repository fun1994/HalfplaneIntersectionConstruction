#pragma once

class Point {
public:
	double x;
	double y;
	std::pair<int, int> index;
	char type;
	bool operator==(Point& p) {
		return x == p.x && y == p.y;
	}
};
