#include "Player.h"
#include "config.h"
#include <Windows.h>

Player::Player() {
	x = START_PLAYER_X;
	y = START_PLAYER_Y;
	imgFinish.loadBmp(IMG_FINISHLINE_DIR);
	imgRoad.loadBmp(IMG_ROAD_DIR);
	imgForest.loadBmp(IMG_FOREST_DIR);
	imgBG.loadBmp(IMG_UNITBACKGROUND_DIR);
	img[0].loadBmp(IMG_PLAYER_DIRU);
	img[1].loadBmp(IMG_PLAYER_DIRD);
	img[2].loadBmp(IMG_PLAYER_DIRL);
	img[3].loadBmp(IMG_PLAYER_DIRR);

	img[0].drawBmp(x, y);
}

void Player::resetPos() {
	clearPath();

	x = START_PLAYER_X;
	y = START_PLAYER_Y;
	img[0].drawBmp(x, y);
}

void Player::goUp() {
	clearPath();

	y -= MOVE_STEP;
	if (y < TITLE_HEIGH) y = TITLE_HEIGH;

	img[0].drawBmp(x, y);
}
void Player::goDown() {
	clearPath();

	y += MOVE_STEP;
	if (y > START_PLAYER_Y) y = START_PLAYER_Y;

	img[1].drawBmp(x, y);
}
void Player::goLeft() {
	clearPath();

	x -= MOVE_STEP;
	if (x < START_LEFT) x = START_LEFT;

	img[2].drawBmp(x, y);
}
void Player::goRight() {
	clearPath();

	x += MOVE_STEP;
	if (x > START_RIGHT) x = START_RIGHT;

	img[3].drawBmp(x, y);
}
void Player::clearPath() {
	switch (y)
	{
	case TITLE_HEIGH:
		imgFinish.drawBmp(x, y);
		break;
	case TITLE_HEIGH + 16:
		imgFinish.drawBmp(x, y - 16);
		imgForest.drawBmp(x, y + 16);
		break;
	case TITLE_HEIGH + UNIT_SIZE: case TITLE_HEIGH + UNIT_SIZE + 16: case TITLE_HEIGH + UNIT_SIZE + 32:
		imgForest.drawBmp(x, y);
		break;
	case TITLE_HEIGH + UNIT_SIZE + 48:
		imgForest.drawBmp(x, y - 16);
		imgRoad.drawBmp(x, y + 16);
		break;
	case TITLE_HEIGH + UNIT_SIZE + 64: case TITLE_HEIGH + UNIT_SIZE + 80: case TITLE_HEIGH + UNIT_SIZE + 96:
		imgRoad.drawBmp(x, y);
		break;
	case TITLE_HEIGH + UNIT_SIZE + 112:
		imgRoad.drawBmp(x, y - 16);
		imgBG.drawBmp(x, y + 16);
		break;
	default:
		imgBG.drawBmp(x, y);
		break;
	}
}

int Player::control() {

	// move
	if (GetAsyncKeyState(VK_UP))
		goUp();
	else if (GetAsyncKeyState(VK_DOWN))
		goDown();
	else if (GetAsyncKeyState(VK_LEFT))
		goLeft();
	else if (GetAsyncKeyState(VK_RIGHT))
		goRight();
	return 1;
}