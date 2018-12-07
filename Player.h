#ifndef PLAYER_H
#define PLAYER_H
#include "Image.h"
#include "Animal.h"
#include "Vehicle.h"

class Player {
private:
	int x, y;
	Image img[4]; // Up down left right
	Image imgFinish;
	Image imgForest;
	Image imgRoad;
	Image imgBG;
public:
	Player();

	int getX() { return x; }
	int getY() { return y; }
	void setXY(int newX, int newY) { x = newX; y = newY; }
	void resetPos();
	void goUp();
	void goDown();
	void goLeft();
	void goRight();
	void show() { img[0].drawBmp(x, y); }
	void clearPath();

	int control();
	enum playerstt { live, die, reset, win, levelup, escape };
	static playerstt status;
};

#endif // !PLAYER_H