#include "Game.h"
#include "Stage.h"

bool Game::music = 1;
bool Stage::backdoor = false;
bool NormalStage::isPause = false;
int main() {
	Game dl;
	dl.start();
	
}