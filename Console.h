#ifndef CONSOLE_H

class Console {
public:
	static void FixConsoleWindow();
	static void resize(int width, int heigh);
	static void removeScrollbar();
	static void showConsoleCursor(bool showFlag);
	static void hidePointer();
	static void showPointer();
	static void disableMouse();
	static void gotoXY(int, int);
};
#endif // !CONSOLE_H