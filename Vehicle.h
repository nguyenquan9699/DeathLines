#ifndef VEHICLE_H
#define VEHICLE_H
#include "Image.h"

class Vehicle {
protected:
	Image img[2]; // 0: background (road), 1: vehicle
	int x, y;
	int speed; // pixel per move
	bool direct; // 0: to left, 1: to right
public:
	Vehicle();
	Vehicle(int); // speed
	int getX() const;
	int getY() const;
	void setX(int);
	void setY(int);
	void setSpd(int);
	void setDir(bool);
	void move();
	void show();
	void hide();
	virtual void talk() = 0;
};

class Car : public Vehicle {
public:
	Car();
	Car(int);
	void talk();
};

class Truck : public Vehicle {
public:
	Truck();
	Truck(int);
	void talk();
};

#endif // !VEHICLE_H