#ifndef BMP_H
#define BMP_H
#include <stdint.h>
#pragma pack(1)

struct BmpSignature
{
	unsigned char data[2];
};

struct BmpHeader
{
	BmpSignature signature;
	uint16_t reserved1;
	uint16_t reserved2;
	uint32_t fileSize;
	uint32_t dataOffset;
};

struct BmpDib
{
	uint32_t dibSize;
	int32_t	 imageWidth;
	int32_t  imageHeight;
	uint16_t colorPlaneCount;
	uint16_t pixelSize;
	uint32_t compressMethod;
	uint32_t bitmapByteCount;
	int32_t  horizontalResolution;
	int32_t  verticalResolution;
	uint32_t colorCount;
	uint32_t importantColorCount;
};

struct Color
{
	unsigned char blue;
	unsigned char green;
	unsigned char red;
};

struct ColorTable
{
	Color	 *colors;
	uint32_t length;
};

struct PixelArray
{
	Color	 **pixels;
	uint32_t rowCount;
	uint32_t columnCount;
};

#endif // !BMP_H