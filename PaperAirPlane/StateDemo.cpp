#include "StateDemo.h"
#include "Common.h"
#include "SDLFacade.h"

bool CStateDemo::Init()
{
	return true;
}
void CStateDemo::Update()
{
	if(nLogoState == 0) // logo 淡入
	{
		fAlphaCurrent += 5;
		if(fAlphaCurrent>255)
		{
			fAlphaCurrent = 255;
			nLogoState++; 
		}
	}
	else if(nLogoState == 1) // logo 静止
	{
		nLogoPause--;
		if(gKeyState.nFire == 1 || gKeyState.nEnter == 1)
		{
			nLogoState++;
		}
		else
		{
			if(nLogoPause==0)
			{
				nLogoState++;
			}
		}
	}
	else if(nLogoState == 2) // logo 淡出
	{
		fAlphaCurrent -= 10;
		if(fAlphaCurrent<0)
		{
			fAlphaCurrent = 0;
			nLogoState++; 
		}
	}
	else // 进入菜单
	{
		gState = &gStateMenu;
	}
}
void CStateDemo::Show()
{
	if(fAlphaCurrent<255)
	{
		CSDLFacade::AlphaSurface(gSurfaceDemo,(int)fAlphaCurrent);
	}
	CSDLFacade::DrawRect(gScreen,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,COLOR_WHITE);

	SDL_Rect rect;
	rect.x = 0 ;
	rect.y = 0 ;
	rect.w = nWidth;
	rect.h = nHeight;

	CSDLFacade::ApplySurface((int)SCREEN_WIDTH/2-nWidth/2
		,(int)SCREEN_HEIGHT/2-nHeight/2
		,gSurfaceDemo
		,gScreen
		,&rect);
}
