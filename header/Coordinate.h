#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{
private:
	int x;
	int y;

public:
	Coordinate(int x, int y) : x(x), y(y) {}
	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}
};

#endif // !COORDINATE_H
