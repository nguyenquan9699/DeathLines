#include "Game.h"
#include <Windows.h>
#include "Menu.h"
#include "Stage.h"
#include "config.h"
#include "Player.h"
#include "Console.h"
#include "Animal.h"
#include "Vehicle.h"
using namespace std;

int TrafficLight::lightControler = 0;
Player::playerstt Player::status = live;
Game::Game() {
	Console::gotoXY(0, 21); cout << "Loading............................................................";
	Console::showConsoleCursor(0);
	Console::FixConsoleWindow();
	Console::resize(CONSOLE_WIDTH, CONSOLE_HEIGH);
	Console::removeScrollbar();
	Console::disableMouse();
	Console::hidePointer();
}

void Game::start() {
	Sleep(100);
	Image background, empty, winImg, loseImg;
	winImg.loadBmp(IMG_WIN_DIR);
	loseImg.loadBmp(IMG_LOSE_DIR);
	empty.loadBmp(IMG_UNITBACKGROUND_DIR);
	background.loadBmp(IMG_BACKGROUND_DIR);
	background.drawBmp(0, 0);
	
	Menu menu;
	while (true)
	{
		empty.drawBmp(START_RIGHT + UNIT_SIZE, TITLE_HEIGH + UNIT_SIZE * 2);
		empty.drawBmp(START_RIGHT + UNIT_SIZE + UNIT_SIZE, TITLE_HEIGH + UNIT_SIZE * 2);
		Stage::backdoor = false;
		empty.drawBmp(495, 107);
		empty.drawBmp(495, 145);
		if (menu.choose())
			break;

		Player theOne;
		// Play
		for (int i = 1; i <= 4; i++) {
			Player::status = Player::live;
			Stage *stage = new NormalStage(i);
			stage->init();
			i = stage->startLoop();

			
			if (Player::status == Player::levelup)
				continue;
			if (Player::status == Player::die) // Lose
				break;
			if (Player::status == Player::escape) // Return to menu
				break;
			//if (i == 4) Player::status = Player::win; // Win
		}
		if (Player::status == Player::levelup) {
			winImg.drawBmp(3 * UNIT_SIZE, TITLE_HEIGH + 1 * UNIT_SIZE);
			Sleep(4000);
		}
		if (Player::status == Player::die) {
			if (Game::music) PlaySound(SOUND_SCREAM_DIR, NULL, SND_FILENAME | SND_ASYNC);
			loseImg.drawBmp(2 * UNIT_SIZE, TITLE_HEIGH + 1* UNIT_SIZE);
			Sleep(4000);
		}
	}
}