#pragma once
#include "SDL.h"
#include "State.h"
#include "StateDemo.h"
#include "StateMenu.h"
#include "StatePlay.h"
#include "StatePause.h"
#include "StateEnding.h"

class CKeyState;

extern SDL_Surface *gScreen;

extern SDL_Surface *gSurfacePlayer;
extern SDL_Surface *gSurfaceDemo;
extern SDL_Surface *gSurfaceMenu;
extern SDL_Surface *gSurfaceEnemy;
extern SDL_Surface *gSurfaceBullet;
extern SDL_Surface *gSurfaceFog;

extern CState *gState;
extern CStateDemo gStateDemo;
extern CStateMenu gStateMenu;
extern CStatePlay gStatePlay;
extern CStatePause gStatePause;
extern CStateEnding gStateEnding;
extern SDL_Surface *gSurfaceEnding;

extern CKeyState gKeyState;
// 常量定义
#define SCREEN_WIDTH  480
#define SCREEN_HEIGHT 640
#define PITCH (gScreen->pitch / 4)
#define PHYSICSFPS 30
#define COLOR_WHITE 0xffffff
#define COLOR_BLACK 0x000000


class CKeyState
{
public:
	int nLeft;
	int nRight;
	int nUp;
	int nDown;
	int nFire;
	int nEnter;
};


