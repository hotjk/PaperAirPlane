#include "StateMenu.h"
#include "Common.h"
#include "SDLFacade.h"

bool CStateMenu::Init()
{
	return true;
}
void CStateMenu::Update()
{
	if(nLogoState == 0) // logo µ­Èë
	{
		fAlphaCurrent += 25;
		if(fAlphaCurrent>255)
		{
			fAlphaCurrent = 255;
			nLogoState++; 
		}
	}
	else if(nLogoState == 1) // logo ¾²Ö¹
	{
		if(gKeyState.nDown == 1)
		{
			nUserSelect = 1;
		}
		if(gKeyState.nUp == 1)
		{
			nUserSelect = 0;
		}
		if(gKeyState.nFire == 1 || gKeyState.nEnter == 1)
		{
			if(nUserSelect == 1)
			{
				exit(1);
				//gState = &gStateEnding;
			}
			if(nUserSelect == 0)
			{
				gState = &gStatePlay;
				InitV();
			}
		}
	}
}
void CStateMenu::Show()
{
	
	if(nLogoState == 0)
	{
		CSDLFacade::AlphaSurface(gSurfaceMenu,(int)fAlphaCurrent);
	}
	CSDLFacade::DrawRect(gScreen,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,COLOR_WHITE);

	SDL_Rect rect;
	rect.x = 0 + (nUserSelect==0?nWidth:0);
	rect.y = 0 * nHeight ;
	rect.w = nWidth;
	rect.h = nHeight;

	CSDLFacade::ApplySurface((int)SCREEN_WIDTH/2-nWidth/2
		,(int)SCREEN_HEIGHT/2-nHeight
		,gSurfaceMenu
		,gScreen
		,&rect);

	rect.x = 0 + (nUserSelect==1?nWidth:0);
	rect.y = 1 * nHeight ;
	rect.w = nWidth;
	rect.h = nHeight;
	CSDLFacade::ApplySurface((int)SCREEN_WIDTH/2-nWidth/2
		,(int)SCREEN_HEIGHT/2
		,gSurfaceMenu
		,gScreen
		,&rect);
}
