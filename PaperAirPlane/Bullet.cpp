#include "Bullet.h"
#include "Common.h"
#include "SDLFacade.h"

void CBullet::Show()
{
	SDL_Rect rect;
	rect.x = W * (int)xIndex;
	rect.y = H * yIndex;;
	rect.w = W;
	rect.h = H;
	CSDLFacade::ApplySurface((int)X - W/2
		,(int)Y - H/2
		,gSurfaceBullet
		,gScreen
		,&rect);
	//CSDLFacade::DrawRect(gScreen,X-2,Y-2,4,4,COLOR_BLACK);
}
void CBullet::Update()
{
	if(this->NeedPaint == 0) return;

	this->xIndex += this->xIndexStep;
	if(this->xIndex >= IndexCount) this->xIndex = 0;

	this->X += XMov;
	this->Y += YMov;


	if(this->Y > SCREEN_HEIGHT + 128 || this->Y < -128)
	{
		this->NeedPaint = 0;
	}


}