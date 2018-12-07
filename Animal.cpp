#include "Animal.h"
#include "config.h"
#include "Game.h"
#include <Windows.h>
Animal::Animal() {
	y = stt = 0;
	speed = MOVE_STEP;
	img[2].loadBmp(IMG_FOREST_DIR);
}
Animal::Animal(int spd) {
	y = stt = 0;
	speed = spd;
	img[2].loadBmp(IMG_FOREST_DIR);
}
void Animal::setSpd(int spd) {
	speed = spd;
}
void Animal::setDir(bool dir) {
	direct = dir;
}
int Animal::getX() const { return x; }
int Animal::getY() const { return y; }
void Animal::setX(int x) {
	this->x = x;
}
void Animal::setY(int y) {
	this->y = y;
}
void Animal::move() {
	if (x >= START_LEFT && x <= START_RIGHT)
		hide();

	/*if (x == START_LEFT + speed * 2)
		talk();*/

	x += (direct == 1 ? 1 : -1) * speed;
	int i = (int)stt;
	if (x < START_LEFT) x += BOARD_WIDTH;
	else if (x > START_RIGHT) x -= BOARD_WIDTH;
	
	if (x >= START_LEFT && x <= START_RIGHT)
		img[i].drawBmp(x, y);
	stt = !stt;
}

void Animal::show() {
	img[1].drawBmp(x, y);
}
void Animal::hide() {
	if (x >= START_LEFT && x <= START_RIGHT)
		img[2].drawBmp(x, y);
}

Dinosaur::Dinosaur(): Animal() {
	x = START_RIGHT;
	direct = 0;
	empty.loadBmp(IMG_UNITBACKGROUND_DIR);
	yasuo.loadBmp(IMG_YASUO_DIR);
	hasagi.loadBmp(IMG_HASAGI_DIR);
	img[0].loadBmp(IMG_TORNADO1_DIR);
	img[1].loadBmp(IMG_TORNADO2_DIR);
}
Dinosaur::Dinosaur(int spd): Animal(spd) {
	x = START_RIGHT;
	direct = 0;
	img[0].loadBmp(IMG_DINOSAUR1_DIR);
	img[1].loadBmp(IMG_DINOSAUR2_DIR);
}
void Dinosaur::talk() {
	if (Game::music);
		//PlaySound(SOUND_DINO_DIR, NULL, SND_FILENAME | SND_ASYNC);
}

Bird::Bird(): Animal() {
	x = START_LEFT;
	direct = 1;
	img[0].loadBmp(IMG_BIRD1_DIR);
	img[1].loadBmp(IMG_BIRD2_DIR);
}
Bird::Bird(int spd): Animal(spd)  {
	x = START_LEFT;
	direct = 1;
	img[0].loadBmp(IMG_BIRD1_DIR);
	img[1].loadBmp(IMG_BIRD2_DIR);
}
void Bird::talk() {
	if (Game::music)
		PlaySound(SOUND_BIRD_DIR, NULL, SND_FILENAME | SND_ASYNC);
}
void Dinosaur::move() {
	if (x >= START_LEFT && x <= START_RIGHT)
		hide();

	if (x == START_RIGHT) {
		empty.drawBmp(START_RIGHT + UNIT_SIZE, y);
		empty.drawBmp(START_RIGHT + UNIT_SIZE + UNIT_SIZE, y);
		hasagi.drawBmp(START_RIGHT + UNIT_SIZE, y);
	}
	else if (x == START_RIGHT - 16) {
		empty.drawBmp(START_RIGHT + UNIT_SIZE, y);
		empty.drawBmp(START_RIGHT + UNIT_SIZE + UNIT_SIZE, y);
		yasuo.drawBmp(START_RIGHT + UNIT_SIZE, y);
	}

	x += (direct == 1 ? 1 : -1) * speed;
	int i = (int)stt;
	if (x < START_LEFT) x += BOARD_WIDTH;
	else if (x > START_RIGHT) x -= BOARD_WIDTH;

	if (x >= START_LEFT && x <= START_RIGHT)
		img[i].drawBmp(x, y);
	stt = !stt;
}