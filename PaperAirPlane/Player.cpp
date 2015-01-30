#include "Player.h"
#include "SDLFacade.h"
#include "Factory.h"

CPlayer::CPlayer(void)
	{
		W = 64;
		H = 64;
		X = SCREEN_WIDTH / 2;
		Y = SCREEN_HEIGHT - H;
		
		XMov = 0;
		YMov = 0;
		NeedPaint = 1;
		IsDead = 0;
		xIndex = 0;
		yIndex = 0;
		xIndexStep = 2.0f;
		Thrust = 4.0f;
		Slowdown = 0.7f;

		Colddown = 5;
		HasColddown = 0;

		ShowFog=0;
		IndexFog = 0;
		IndexFogStep = 0.5f;
		Power = 3;
		InitFrame = 30;
		HasInitFrame = 0;
	}

void CPlayer::Show()
{
	SDL_Rect rect;
	rect.x = W * (int)xIndex;
	rect.y = 0;
	rect.w = W;
	rect.h = H;
	CSDLFacade::ApplySurface((int)X - W/2
		,(int)Y -H/2
		,gSurfacePlayer
		,gScreen
		,&rect);
	//CSDLFacade::DrawRect(gScreen,X-2,Y-2,4,4,COLOR_BLACK);
	if(ShowFog == 1)
	{
		rect.x = W * (int)IndexFog;
	rect.y = 0;
	rect.w = W;
	rect.h = H;
		CSDLFacade::ApplySurface((int)X - W/2
		,(int)Y -H/2
		,gSurfaceFog
		,gScreen
		,&rect);
	}
}

void CPlayer::Update()
{
	if(gKeyState.nUp)
		YMov -= Thrust;
	if(gKeyState.nDown)
		YMov += Thrust;
	if(gKeyState.nLeft)
	{
		XMov -= Thrust;
		if(xIndex>0) xIndex -= xIndexStep;
	}
	else
	{
		if(xIndex<2) xIndex += xIndexStep;
	}
	if(gKeyState.nRight)
	{
		XMov += Thrust;
		if(xIndex<4) xIndex += xIndexStep;
	}
	else
	{
		if(xIndex>2) xIndex -= xIndexStep;
	}

	XMov *= Slowdown;
	YMov *= Slowdown;

	X += XMov;
	Y += YMov;

	if(X<=0)
	{
		X = 0;
	}
	else if(X >= SCREEN_WIDTH)
	{
		X = SCREEN_WIDTH;
	}
	if(Y <= 0)
	{
		Y = 0;
	}
	else if(Y >= SCREEN_HEIGHT)
	{
		Y = SCREEN_HEIGHT;
	}

	if(HasColddown < Colddown) HasColddown++;

	if(gKeyState.nFire && HasColddown == Colddown)
	{
		CStatePlay* s = (CStatePlay*)gState;
		s->listPlayerBullet.push_back(CFactory::NewBullet(0,X,Y - H/2 + 10));
		HasColddown = 0;
	}



	if(ShowFog == 1)
	{
		IndexFog+=IndexFogStep;
		if((int)IndexFog>=10)
		{
			IndexFog = 0;
			ShowFog = 0;
		}
	}
}
