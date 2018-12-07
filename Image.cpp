#include "Image.h"
#include "config.h"
#include <iostream>
#include <Windows.h>
#include <stdint.h>
#include <stdio.h>

Image::Image()
{
}


Image::~Image()
{
}

void scanBmpPixelLine(FILE *f, Color *&line, uint32_t length)
{
	if (f == NULL)
	{
		return;
	}
	line = new Color[length];
	fread(line, sizeof(Color), length, f);
}

BmpHeader& Image::readBmpHeader(FILE *f)
{
	BmpHeader temp;
	fseek(f, 0, 0L);
	fread(&temp, sizeof(BmpHeader), 1, f);
	return temp;
}

BmpDib& Image::readBmpDib(FILE *f)
{
	BmpDib temp;
	fseek(f, 14, 0L);
	fread(&temp, sizeof(BmpDib), 1, f);

	return temp;
}
void skipBmpPadding(FILE *f, char count);
void readBmpPixelArray(FILE *f, BmpHeader header, BmpDib dib, PixelArray &data)
{
	if (f == NULL)
	{
		return;
	}

	data.rowCount = dib.imageHeight;
	data.columnCount = dib.imageWidth;
	data.pixels = new Color*[data.rowCount];

	char paddingCount = (4 - (dib.imageWidth * (dib.pixelSize / 8) % 4)) % 4;

	fseek(f, header.dataOffset, 0L);

	for (int i = 0; i < data.rowCount; i++)
	{
		scanBmpPixelLine(f, data.pixels[data.rowCount - 1 - i], dib.imageWidth);
		skipBmpPadding(f, paddingCount);
	}
}

void skipBmpPadding(FILE *f, char count)
{
	if (f == NULL)
	{
		return;
	}

	if (count == 0)
	{
		return;
	}

	char padding[3];
	fread(padding, count, 1, f);
}

void releaseBmpPixelArray(PixelArray data)
{
	for (uint32_t i = 0; i < data.rowCount; i++)
	{
		delete[]data.pixels[i];
	}

	delete[]data.pixels;
}

void Image::drawBmp(int x, int y)
{
	HWND console = GetConsoleWindow();
	HDC hdc = GetDC(console);
	Color pixel;

	for (int i = 0; i < dib.imageHeight; i++)
	{
		for (int j = 0; j < dib.imageWidth; j++)
		{
			pixel = data.pixels[i][j];
			if (pixel.red != LIQUID || pixel.green != LIQUID || pixel.blue != LIQUID)
			{
				SetPixel(hdc, x + j, y + i, RGB(pixel.red, pixel.green, pixel.blue));
			}
		}
	}

	ReleaseDC(console, hdc);
}

int Image::loadBmp(const char link[])
{
	FILE *f;
	fopen_s(&f, link, "rb");
	if (!f)
		return 0;
	header = readBmpHeader(f);
	dib = readBmpDib(f);
	readBmpPixelArray(f, header, dib, data);

	return 1;
}
