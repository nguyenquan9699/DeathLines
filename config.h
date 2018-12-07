#ifndef CONFIG_H
#define CONFIG_H
#pragma comment(lib,"winmm.lib")
// Traffic light
#define GREEN_TIME 0
#define YELLOW_TIME 20
#define RED_TIME 27

// Image
#define LIQUID 191

// Sound
#define SOUND_STEP 10
#define SOUND_DINO_DIR "./resource/sound/dinosaur.wav"
#define SOUND_BIRD_DIR "./resource/sound/bird.wav"
#define SOUND_CAR_DIR "./resource/sound/car.wav"
#define SOUND_TRUCK_DIR "./resource/sound/truck.wav"
#define SOUND_SCREAM_DIR "./resource/sound/scream.wav"

// Gameplay, Stage
#define NUMBER_OF_LINES 4
#define OBJECTS_PER_LINE 3
#define UNIT_SIZE 32
#define MOVE_STEP (UNIT_SIZE / 2)
#define BOARD_WIDTH (UNIT_SIZE * 9)
#define CONSOLE_WIDTH (UNIT_SIZE * 18)
#define CONSOLE_HEIGH (UNIT_SIZE * 8 + TITLE_HEIGH + 16)
#define TITLE_HEIGH (4 * UNIT_SIZE)
#define START_LEFT (UNIT_SIZE)
#define START_RIGHT (BOARD_WIDTH)
#define START_PLAYER_X (BOARD_WIDTH / 2 + UNIT_SIZE / 2)
#define START_PLAYER_Y (UNIT_SIZE * NUMBER_OF_LINES + TITLE_HEIGH + UNIT_SIZE)
const int LINES_SPD[10] = { 1,2,3,4,5,6,7,8,9,10 };

// Save & Load
#define SAVE1_DIR "./game/save/save1.bin"
#define SAVE2_DIR "./game/save/save2.bin"
#define SAVE3_DIR "./game/save/save3.bin"
#define SAVE4_DIR "./game/save/save4.bin"
#define SAVE5_DIR "./game/save/save5.bin"

// Image
	// Menu
#define IMG_MENU_DIR "./resource/img/menu/menu.bmp"
#define IMG_SELECT_DIR "./resource/img/menu/select.bmp"
#define IMG_UNSELECT_DIR "./resource/img/menu/unselect.bmp"
#define IMG_1_DIR "./resource/img/menu/1.bmp"
#define IMG_2_DIR "./resource/img/menu/2.bmp"
#define IMG_3_DIR "./resource/img/menu/3.bmp"
#define IMG_4_DIR "./resource/img/menu/4.bmp"
	// Player
#define IMG_PLAYER_DIRU "./resource/img/player/playerU.bmp"
#define IMG_PLAYER_DIRD "./resource/img/player/playerD.bmp"
#define IMG_PLAYER_DIRL "./resource/img/player/playerL.bmp"
#define IMG_PLAYER_DIRR "./resource/img/player/playerR.bmp"
	// Forest & Animal
#define IMG_FOREST_DIR "./resource/img/forest/forest.bmp"
#define IMG_DINOSAUR1_DIR "./resource/img/forest/dinosaur1.bmp"
#define IMG_DINOSAUR2_DIR "./resource/img/forest/dinosaur2.bmp"
#define IMG_BIRD1_DIR "./resource/img/forest/bird1.bmp"
#define IMG_BIRD2_DIR "./resource/img/forest/bird2.bmp"
#define IMG_TORNADO1_DIR "./resource/img/forest/tornado1.bmp"
#define IMG_TORNADO2_DIR "./resource/img/forest/tornado2.bmp"
#define IMG_YASUO_DIR "./resource/img/yasuo.bmp"
#define IMG_HASAGI_DIR "./resource/img/hasagi.bmp"
	// Road & Vechicle & Traffic light
#define IMG_ROAD_DIR "./resource/img/road/road.bmp"
#define IMG_REDL_DIR "./resource/img/road/redL.bmp"
#define IMG_GREENL_DIR "./resource/img/road/greenL.bmp"
#define IMG_YELLOWL_DIR "./resource/img/road/yellowL.bmp"
#define IMG_REDR_DIR "./resource/img/road/redR.bmp"
#define IMG_GREENR_DIR "./resource/img/road/greenR.bmp"
#define IMG_YELLOWR_DIR "./resource/img/road/yellowR.bmp"
#define IMG_TFLIGHTL_DIR "./resource/img/road/traficlightL.bmp"
#define IMG_TFLIGHTR_DIR "./resource/img/road/traficlightR.bmp"
#define IMG_CAR_DIR "./resource/img/road/car.bmp"
#define IMG_TRUCK_DIR "./resource/img/road/truck.bmp"
	// Orther
#define IMG_UNITBACKGROUND_DIR "./resource/img/unitbackground.bmp"
#define IMG_BACKGROUND_DIR "./resource/img/background.bmp"
#define IMG_FINISHLINE_DIR "./resource/img/finishline.bmp"
#define IMG_WIN_DIR "./resource/img/win.bmp"
#define IMG_LOSE_DIR "./resource/img/lose.bmp"
#endif // !CONFIG_H