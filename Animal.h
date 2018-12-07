#ifndef ANIMAL_H
#define ANIMAL_H
#include "Image.h"

class Animal {
protected:
	Image img[3]; // 0: stand, 1: move, 2: background (forest)
	int x, y;
	int speed; // pixel per move
	bool stt; // 0: standing, 1: moving
	bool direct; // 0: left, 1: right
public:
	Animal();
	Animal(int); // speed
	int getX() const;
	int getY() const;
	void setX(int);
	void setY(int);
	void setSpd(int);
	void setDir(bool);
	virtual void move();
	void show();
	void hide();
	virtual void talk() = 0;
};

class Dinosaur : public Animal {
private:
	Image yasuo, hasagi, empty;
public:
	Dinosaur();
	Dinosaur(int);
	void talk();
	void move();
};

class Bird : public Animal {
public:
	Bird();
	Bird(int);
	void talk();
};

#endif // !ANIMAL_H