#include "Vehicle.h"
#include "config.h"
#include <Windows.h>

Vehicle::Vehicle() {
	y = 0;
	speed = MOVE_STEP;
	img[0].loadBmp(IMG_ROAD_DIR);
}
Vehicle::Vehicle(int spd) {
	y = 0;
	speed = spd;
	img[0].loadBmp(IMG_ROAD_DIR);
}
void Vehicle::setSpd(int spd) {
	speed = spd;
}
void Vehicle::setDir(bool dir) {
	direct = dir;
}
int Vehicle::getX() const { return x; }
int Vehicle::getY() const { return y; }
void Vehicle::setX(int x) {
	this->x = x;
}
void Vehicle::setY(int y) {
	this->y = y;
}
void Vehicle::move() {
	if (x >= START_LEFT && x <= START_RIGHT)
		hide();

	if (x == START_RIGHT - speed * 3)
		talk();
	
	x += (direct == 1 ? 1 : -1) * speed;
	if (x < START_LEFT) x += BOARD_WIDTH;
	else if (x > START_RIGHT) x -= BOARD_WIDTH;

	if (x >= START_LEFT && x <= START_RIGHT)
		img[1].drawBmp(x, y);
}
void Vehicle::show() {
	img[1].drawBmp(x, y);
}
void Vehicle::hide() {
	if (x >= START_LEFT && x <= START_RIGHT)
		img[0].drawBmp(x, y);
}

Car::Car(): Vehicle() {
	x = START_LEFT;
	direct = 1;
	img[1].loadBmp(IMG_CAR_DIR);
}
Car::Car(int spd): Vehicle(spd) {
	x = START_LEFT;
	direct = 1;
	img[1].loadBmp(IMG_CAR_DIR);
}
void Car::talk() {
	//PlaySound(SOUND_CAR_DIR, NULL, SND_FILENAME | SND_ASYNC);
}

Truck::Truck(): Vehicle() {
	x = START_RIGHT;
	direct = 0;
	img[1].loadBmp(IMG_TRUCK_DIR);
}
Truck::Truck(int spd): Vehicle(spd) {
	x = START_RIGHT;
	direct = 0;
	img[1].loadBmp(IMG_TRUCK_DIR);
}
void Truck::talk() {
	//PlaySound(SOUND_TRUCK_DIR, NULL, SND_FILENAME | SND_ASYNC);
}