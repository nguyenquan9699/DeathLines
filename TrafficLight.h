#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT__H
#include "Image.h"

class TrafficLight {
protected:
	int x, y;
	Image img[4];
public:
	TrafficLight(int, int);
	void toGreen();
	void toYellow();
	void toRed();
	static int lightControler;
};

class TrafficLightL : public TrafficLight {
public:
	TrafficLightL(int, int);
};

class TrafficLightR : public TrafficLight {
public:
	TrafficLightR(int, int);
};
#endif // !TRAFFICLIGHT_H