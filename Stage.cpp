#include "Stage.h"
#include "config.h"
#include "Player.h"
#include "Game.h"
#include <Windows.h>
#include <fstream>
#include <thread>

Stage::Stage() {
	isMoving = 1;
	backgrounds[0].loadBmp(IMG_ROAD_DIR);
	backgrounds[1].loadBmp(IMG_FOREST_DIR);
	backgrounds[2].loadBmp(IMG_FINISHLINE_DIR);
	for (int i = 1; i <= 9; i++) {
		backgrounds[2].drawBmp(i * UNIT_SIZE, TITLE_HEIGH + UNIT_SIZE * 0);
		backgrounds[1].drawBmp(i * UNIT_SIZE, TITLE_HEIGH + UNIT_SIZE * 1);
		backgrounds[1].drawBmp(i * UNIT_SIZE, TITLE_HEIGH + UNIT_SIZE * 2);
		backgrounds[0].drawBmp(i * UNIT_SIZE, TITLE_HEIGH + UNIT_SIZE * 3);
		backgrounds[0].drawBmp(i * UNIT_SIZE, TITLE_HEIGH + UNIT_SIZE * 4);
	}
}
Stage::~Stage() {
	delete[] animals;
	delete[] vehicles;
	delete[] tflights;
}

void Stage::StageManager() {
	if (GetAsyncKeyState(VK_F1)) { loadStage(SAVE1_DIR); }
	if (GetAsyncKeyState(VK_F2)) { loadStage(SAVE2_DIR); }
	if (GetAsyncKeyState(VK_F3)) { loadStage(SAVE3_DIR); }
	if (GetAsyncKeyState(VK_F4)) { loadStage(SAVE4_DIR); }
	if (GetAsyncKeyState(VK_F5)) { loadStage(SAVE5_DIR); }
	if (GetAsyncKeyState(VK_F6)) { saveStage(SAVE1_DIR); }
	if (GetAsyncKeyState(VK_F7)) { saveStage(SAVE2_DIR); }
	if (GetAsyncKeyState(VK_F8)) { saveStage(SAVE3_DIR); }
	if (GetAsyncKeyState(VK_F9)) { saveStage(SAVE4_DIR); }
	if (GetAsyncKeyState(VK_F10)) { saveStage(SAVE5_DIR); }
}

bool NormalStage::isImpact() {
	if (Stage::backdoor) return false;
	for (int i = 0; i < objPerLine * 2; i++) {
		int X = theOne.getX(), Y = theOne.getY();
		if (X > animals[i]->getX() - UNIT_SIZE && X < animals[i]->getX() + UNIT_SIZE
			&& Y > animals[i]->getY() - UNIT_SIZE && Y < animals[i]->getY() + UNIT_SIZE)
			return true;
		if (X > vehicles[i]->getX() - UNIT_SIZE && X < vehicles[i]->getX() + UNIT_SIZE
			&& Y > vehicles[i]->getY() - UNIT_SIZE && Y < vehicles[i]->getY() + UNIT_SIZE)
			return true;
	}
	return false;
}

NormalStage::NormalStage(int n): Stage() {
	objPerLine = n;
	if (n > 4) objPerLine = 4;
	switch (objPerLine)	{
	case 1: name.loadBmp(IMG_1_DIR); break;
	case 2: name.loadBmp(IMG_2_DIR); break;
	case 3: name.loadBmp(IMG_3_DIR); break;
	case 4: name.loadBmp(IMG_4_DIR); break;
	}
}
NormalStage::~NormalStage() {
	for (int i = 0; i < objPerLine * 2; i++) {
		delete animals[i];
		delete vehicles[i];
	}
	delete tflights[0];
	delete tflights[1];
}
void NormalStage::init() {
	theOne.resetPos();
	animals = new Animal*[objPerLine * 2];
	for (int i = 0; i < objPerLine; i++) {
		animals[i] = new Bird;
		animals[i]->setY(0 * UNIT_SIZE + TITLE_HEIGH + UNIT_SIZE);
		animals[i]->setX(UNIT_SIZE + i * UNIT_SIZE * 2);
		animals[i]->show();
	}
	for (int i = objPerLine; i < 2 * objPerLine; i++) {
		animals[i] = new Dinosaur;
		animals[i]->setY(1 * UNIT_SIZE + TITLE_HEIGH + UNIT_SIZE);
		animals[i]->setX(UNIT_SIZE + (i - objPerLine) * UNIT_SIZE * 2);
		animals[i]->show();
	}
	vehicles = new Vehicle*[objPerLine * 2];
	for (int i = 0; i < objPerLine; i++) {
		vehicles[i] = new Car;
		vehicles[i]->setY(2 * UNIT_SIZE + TITLE_HEIGH + UNIT_SIZE);
		vehicles[i]->setX(UNIT_SIZE + i * UNIT_SIZE * 2);
		vehicles[i]->show();
	}
	for (int i = objPerLine; i < 2 * objPerLine; i++) {
		vehicles[i] = new Truck;
		vehicles[i]->setY(3 * UNIT_SIZE + TITLE_HEIGH + UNIT_SIZE);
		vehicles[i]->setX(UNIT_SIZE + (i - objPerLine) * UNIT_SIZE * 2);
		vehicles[i]->show();
	}

	tflights = new TrafficLight*[2];
	tflights[0] = new TrafficLightR(BOARD_WIDTH + UNIT_SIZE, 2 * UNIT_SIZE + TITLE_HEIGH + UNIT_SIZE);
	tflights[0]->toGreen();
	tflights[1] = new TrafficLightL(0, 3 * UNIT_SIZE + TITLE_HEIGH + UNIT_SIZE);
	tflights[1]->toGreen();

	name.drawBmp(495, 107);
	name.drawBmp(495, 145);
}

int NormalStage::startLoop() {
	while (true)
	{
		if (GetAsyncKeyState(VK_SPACE)) {
			NormalStage::isPause = !NormalStage::isPause;
			Sleep(1000);
		}
		if (NormalStage::isPause)
			continue;
		StageManager();

		for (int i = 0; i < objPerLine * 2; i++) {
			animals[i]->move();
			if (isMoving) vehicles[i]->move();
		}
		
		TrafficLight::lightControler++;
		switch (TrafficLight::lightControler % 40)
		{
		case GREEN_TIME:
			isMoving = 1;
			tflights[0]->toGreen();
			tflights[1]->toGreen();
			break;
		case YELLOW_TIME:
			isMoving = 0;
			tflights[0]->toYellow();
			tflights[1]->toYellow();
			break;
		case RED_TIME:
			tflights[0]->toRed();
			tflights[1]->toRed();
			animals[0]->talk();
			break;
		}
		// Player
		theOne.control();
		if (isImpact()) {
			theOne.clearPath();
			Image grave; grave.loadBmp("./resource/img/player/grave.bmp"); grave.drawBmp(theOne.getX(), theOne.getY());
			Player::status = Player::die;
			break;
		}
		else if (theOne.getY() == TITLE_HEIGH) {
			Player::status = Player::levelup;
			break;
		}
		// Sound
		if (GetAsyncKeyState(VK_OEM_3))
			Game::music = !Game::music;
		// Backdoor
		if (GetAsyncKeyState(VK_LEFT) && GetAsyncKeyState(VK_RIGHT) &&
			GetAsyncKeyState(0x41) && GetAsyncKeyState(0x42))
			Stage::backdoor = !Stage::backdoor;
		// Break to menu
		if (GetAsyncKeyState(VK_ESCAPE)) {
			Player::status = Player::escape;
			break;
		}
	}
	return objPerLine;
}
void NormalStage::loadStage(string path) {
	FILE* f;
	fopen_s(&f, path.c_str(), "rb");
	if (f == NULL)
		return;
	// clear
	for (int i = 0; i < objPerLine * 2; i++) {
		animals[i]->hide();
		vehicles[i]->hide();
	}
	theOne.clearPath();
	// load & show
	int temp1, temp2;
	loadBinary(f, temp1);
	loadBinary(f, temp2);
	theOne.setXY(temp1, temp2); theOne.show();
	loadBinary(f, objPerLine);
	loadBinary(f, TrafficLight::lightControler);
	loadBinary(f, isMoving);
	switch (objPerLine) {
	case 1: name.loadBmp(IMG_1_DIR); break;
	case 2: name.loadBmp(IMG_2_DIR); break;
	case 3: name.loadBmp(IMG_3_DIR); break;
	case 4: name.loadBmp(IMG_4_DIR); break;
	}
	name.drawBmp(495, 107);
	name.drawBmp(495, 145);
	animals = new Animal*[objPerLine * 2];
	for (int i = 0; i < objPerLine; i++) {
		animals[i] = new Bird;
		loadBinary(f, temp1);
		loadBinary(f, temp2);
		animals[i]->setX(temp1);
		animals[i]->setY(temp2);
		if (animals[i]->getX() >= START_LEFT && animals[i]->getX() <= START_RIGHT)
			animals[i]->show();
	}
	for (int i = objPerLine; i < 2 * objPerLine; i++) {
		animals[i] = new Dinosaur;
		loadBinary(f, temp1);
		loadBinary(f, temp2);
		animals[i]->setX(temp1);
		animals[i]->setY(temp2);
		if (animals[i]->getX() >= START_LEFT && animals[i]->getX() <= START_RIGHT)
			animals[i]->show();
	}
	vehicles = new Vehicle*[objPerLine * 2];
	for (int i = 0; i < objPerLine; i++) {
		vehicles[i] = new Car;
		loadBinary(f, temp1);
		loadBinary(f, temp2);
		vehicles[i]->setX(temp1);
		vehicles[i]->setY(temp2);
		if (vehicles[i]->getX() >= START_LEFT && vehicles[i]->getX() <= START_RIGHT)
			vehicles[i]->show();
	}
	for (int i = objPerLine; i < 2 * objPerLine; i++) {
		vehicles[i] = new Truck;
		loadBinary(f, temp1);
		loadBinary(f, temp2);
		vehicles[i]->setX(temp1);
		vehicles[i]->setY(temp2);
		if (vehicles[i]->getX() >= START_LEFT && vehicles[i]->getX() <= START_RIGHT)
			vehicles[i]->show();
	}
	fclose(f);
	Sleep(2000);
}

void NormalStage::saveStage(string path) {
	FILE* f;
	fopen_s(&f, path.c_str(), "wb");

	saveBinary(f, theOne.getX());
	saveBinary(f, theOne.getY());
	saveBinary(f, objPerLine);
	saveBinary(f, TrafficLight::lightControler);
	saveBinary(f, isMoving);
	for (int i = 0; i < objPerLine * 2; i++) {
		saveBinary(f, animals[i]->getX());
		saveBinary(f, animals[i]->getY());
	}
	for (int i = 0; i < objPerLine * 2; i++) {
		saveBinary(f, vehicles[i]->getX());
		saveBinary(f, vehicles[i]->getY());
	}

	fclose(f);
}

BossStage::BossStage() : Stage() {

}
BossStage::~BossStage() {

}

void BossStage::init() {

}

int BossStage::startLoop() {
	return 5;
}

bool BossStage::isImpact() {
	return true;
}

void BossStage::loadStage(string path) {

}

void BossStage::saveStage(string path) {

}

void Stage::saveBinary(FILE* f, int num) {
	fwrite(&num, sizeof(int), 1, f);
}
void Stage::loadBinary(FILE* f, int &num) {
	fread(&num, sizeof(int), 1, f);
}