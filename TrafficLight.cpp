#include "TrafficLight.h"
#include "config.h"

TrafficLight::TrafficLight(int x, int y) {
	this->x = x;
	this->y = y;
}

void TrafficLight::toGreen() {
	img[0].drawBmp(x, y);
	img[1].drawBmp(x, y);
}
void TrafficLight::toYellow() {
	img[0].drawBmp(x, y);
	img[2].drawBmp(x, y);
}
void TrafficLight::toRed() {
	img[0].drawBmp(x, y);
	img[3].drawBmp(x, y);
}

TrafficLightL::TrafficLightL(int x, int y): TrafficLight(x, y) {
	img[0].loadBmp(IMG_TFLIGHTL_DIR);
	img[1].loadBmp(IMG_GREENL_DIR);
	img[2].loadBmp(IMG_YELLOWL_DIR);
	img[3].loadBmp(IMG_REDL_DIR);
	img[0].drawBmp(x, y);
}

TrafficLightR::TrafficLightR(int x, int y) : TrafficLight(x, y) {
	img[0].loadBmp(IMG_TFLIGHTR_DIR);
	img[1].loadBmp(IMG_GREENR_DIR);
	img[2].loadBmp(IMG_YELLOWR_DIR);
	img[3].loadBmp(IMG_REDR_DIR);
	img[0].drawBmp(x, y);
}