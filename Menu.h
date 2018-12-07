#ifndef MENU_H
#define MENU_H
#include <Windows.h>
#include "config.h"
#include "Image.h"

class Menu {
private:
	Image img[3];
public:
	Menu() { img[2].loadBmp(IMG_MENU_DIR); img[1].loadBmp(IMG_SELECT_DIR); img[0].loadBmp(IMG_UNSELECT_DIR); }
	int choose() {
		img[2].drawBmp(0, TITLE_HEIGH);
		img[1].drawBmp(113, 38 + TITLE_HEIGH);
		img[0].drawBmp(113, 105 + TITLE_HEIGH);
		bool rs = 0;
		while (!GetAsyncKeyState(VK_RETURN)) {
			if (GetAsyncKeyState(VK_UP) && rs == 1) {
				rs = !rs;
				img[1].drawBmp(113, 38 + TITLE_HEIGH);
				img[0].drawBmp(113, 105 + TITLE_HEIGH);
			}
			if (GetAsyncKeyState(VK_DOWN) && rs == 0) {
				rs = !rs;
				img[0].drawBmp(113, 38 + TITLE_HEIGH);
				img[1].drawBmp(113, 105 + TITLE_HEIGH);
			}
		}
		return rs;
	}
};

#endif // !MENU_