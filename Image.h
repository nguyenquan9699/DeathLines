#ifndef IMAGE_H
#define IMAGE_H
#include "bmp.h"
#include <iostream>

class Image
{
private:
	BmpHeader header;
	BmpDib dib;
	PixelArray data;

	BmpHeader& readBmpHeader(FILE *f);
	BmpDib& readBmpDib(FILE *f);
public:
	Image();
	~Image();
	
	int loadBmp(const char link[]);
	// x, y: pixel
	void drawBmp(int x, int y);
};

#endif // !IMAGE_H