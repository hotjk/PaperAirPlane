#include <stdlib.h>
#include <string.h>

#include "Common.h"
#include "SDLFacade.h"


// ########################################
SDL_Surface *gScreen;
int gLastTick;

CKeyState gKeyState;

CState *gState;
CStateDemo gStateDemo;
CStateMenu gStateMenu;
CStatePlay gStatePlay;
CStatePause gStatePause;
CStateEnding gStateEnding;

SDL_Surface *gSurfacePlayer;
SDL_Surface *gSurfaceDemo;
SDL_Surface *gSurfaceMenu;
SDL_Surface *gSurfaceEnemy;
SDL_Surface *gSurfaceBullet;
SDL_Surface *gSurfaceFog;
SDL_Surface *gSurfaceEnding;
// ########################################
void render()
{   
	int tick = SDL_GetTicks();
	if (tick <= gLastTick) 
	{
		SDL_Delay(1);
		return;
	}

	while (gLastTick < tick)
	{
		// 计算业务逻辑
		gState->Update();
		gLastTick += 1000 / PHYSICSFPS;
	}

	if (SDL_MUSTLOCK(gScreen))
		if (SDL_LockSurface(gScreen) < 0) 
			return;

	// 更新图像
	gState->Show();
	
	if (SDL_MUSTLOCK(gScreen)) 
		SDL_UnlockSurface(gScreen);

	SDL_UpdateRect(gScreen, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);    
}

bool init()
{
	gSurfacePlayer = CSDLFacade::LoadImage(".\\Res\\Player.bmp");
	if( gSurfacePlayer == NULL ) return false;
	gSurfaceDemo = CSDLFacade::LoadImage(".\\Res\\Demo.bmp");
	if( gSurfaceDemo == NULL ) return false;
	gSurfaceMenu = CSDLFacade::LoadImage(".\\Res\\Menu.bmp");
	if( gSurfaceMenu == NULL ) return false;
	gSurfaceEnemy = CSDLFacade::LoadImage(".\\Res\\Enemy.bmp");
	if( gSurfaceEnemy == NULL ) return false;
	gSurfaceBullet = CSDLFacade::LoadImage(".\\Res\\Bullet.bmp");
	if( gSurfaceBullet == NULL ) return false;
	gSurfaceFog = CSDLFacade::LoadImage(".\\Res\\Fog.bmp");
	if( gSurfaceFog == NULL ) return false;
	gSurfaceEnding = CSDLFacade::LoadImage(".\\Res\\Ending.bmp");
	if( gSurfaceEnding == NULL ) return false;
	
	if(!gStateDemo.Init()) return false;
	if(!gStateMenu.Init()) return false;
	if(!gStatePlay.Init()) return false;
	if(!gStatePause.Init()) return false;
	if(!gStateEnding.Init()) return false;
	gState = &gStateDemo;
	//gState = &gStatePlay;
	return true;
}
void destory()
{
	CSDLFacade::FreeImage(gSurfacePlayer);
	CSDLFacade::FreeImage(gSurfaceDemo);
	CSDLFacade::FreeImage(gSurfaceMenu);
	CSDLFacade::FreeImage(gSurfaceEnemy);
	CSDLFacade::FreeImage(gSurfaceBullet);
	CSDLFacade::FreeImage(gSurfaceFog);
	CSDLFacade::FreeImage(gSurfaceEnding);
}

int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) exit(1);
	atexit(SDL_Quit);
	gScreen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE);
	if (gScreen == NULL) exit(1);
	SDL_WM_SetCaption( "Paper Airplane", NULL );

	if(!init()) exit(1);
	while (1)
	{
		render();
		SDL_Event event;
		while (SDL_PollEvent(&event)) 
		{
			switch (event.type) 
			{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_LEFT:
				case SDLK_a:
					gKeyState.nLeft = 1;
					break;
				case SDLK_RIGHT:
				case SDLK_d:
					gKeyState.nRight = 1;
					break;
				case SDLK_UP:
				case SDLK_w:
					gKeyState.nUp = 1;
					break;
				case SDLK_DOWN:
				case SDLK_s:
					gKeyState.nDown = 1;
					break;
				case SDLK_n:
				case SDLK_SPACE:
					gKeyState.nFire = 1;
					break;
					case SDLK_RETURN:
						gKeyState.nEnter = 1;
					break;
				}
				break;

			case SDL_KEYUP:                    
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					return 0;
				case SDLK_LEFT:
				case SDLK_a:
					gKeyState.nLeft = 0;
					break;
				case SDLK_RIGHT:
				case SDLK_d:
					gKeyState.nRight = 0;
					break;
				case SDLK_UP:
				case SDLK_w:
					gKeyState.nUp = 0;
					break;
				case SDLK_DOWN:
				case SDLK_s:
					gKeyState.nDown = 0;
					break;
				case SDLK_n:
				case SDLK_SPACE:
					gKeyState.nFire = 0;
					break;
					case SDLK_RETURN:
						gKeyState.nEnter = 0;
					break;
				}

				break;
			case SDL_QUIT:
				destory();
				return(0);
			}
		}
	}
	return 0;
}

