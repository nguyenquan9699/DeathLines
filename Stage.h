#ifndef STAGE_H
#define STAGE_H
#include "Player.h"
#include <string>
#include "Animal.h"
#include "Vehicle.h"
#include "TrafficLight.h"
using namespace std;

class Stage {
protected:
	Player theOne;
	int isMoving;
	Image name;
	Image backgrounds[3];
	Animal** animals;
	Vehicle** vehicles;
	TrafficLight** tflights;
	void saveBinary(FILE*, int);
	void loadBinary(FILE*, int&);
public:
	Stage();
	virtual ~Stage();

	void StageManager(); // Load & Save

	static bool backdoor;
	virtual bool isImpact() = 0;
	virtual void loadStage(string) = 0;
	virtual void saveStage(string) = 0;
	virtual void init() = 0;
	virtual int startLoop() = 0;
};

class NormalStage: public Stage {
private:
	int objPerLine;
public:
	NormalStage(int);
	~NormalStage();

	bool isImpact();
	void loadStage(string);
	void saveStage(string);
	void init();
	int startLoop();
	static bool isPause;
};

class BossStage : public Stage {
private:

public:
	BossStage();
	~BossStage();
	
	bool isImpact();
	void loadStage(string);
	void saveStage(string);
	void init();
	int startLoop();
};
#endif // STAGE_H