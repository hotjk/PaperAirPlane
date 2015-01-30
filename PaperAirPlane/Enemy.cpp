#include "Enemy.h"
#include "Common.h"
#include "SDLFacade.h"
#include "Factory.h"

void CEnemy::Show()
{
	SDL_Rect rect;
	rect.x = W * (int)xIndex;
	rect.y = H * yIndex;;
	rect.w = W;
	rect.h = H;
	CSDLFacade::ApplySurface((int)X - W/2
		,(int)Y - H/2
		,gSurfaceEnemy
		,gScreen
		,&rect);

	//CSDLFacade::DrawRect(gScreen,X-2,Y-2,4,4,COLOR_BLACK);
}
void CEnemy::Update()
{
	if(this->NeedPaint == 0) return;

	frame++;

	if(this->IsDead == 0)
	{
		this->xIndex += this->xIndexStep;
		if(this->xIndex == IndexCount) this->xIndex = 0;

		for(
		std::list<CMoveRule>::iterator iter = listMoveRule.begin()
		;iter!=listMoveRule.end()
		;++iter)
		{
			if(frame < (iter->nFrame))
			{
				this->X += iter->fX;
				this->Y += iter->fY;
				break;
			}
		}

		if(this->Y > SCREEN_HEIGHT || (this->Y) < (-300))
		{
			this->NeedPaint = 0;
		}

		for(
		std::list<CBulletRule>::iterator iter = listBulletRule.begin()
		;iter!=listBulletRule.end()
		;++iter)
		{
			if(frame == (iter->nFrame))
			{
				CStatePlay* s = (CStatePlay*)gState;
				s->listEnemyBullet.push_back(CFactory::NewBullet(iter->nT,this->X,this->Y));
			}
		}

	}
	else
	{
		if(this->xIndex < IndexCount)
		{
			this->xIndex = IndexCount;
		}
		else
			this->xIndex+=xDeadIndexStep;
		if(this->xIndex >= DeadIndexCount)
		{
			this->NeedPaint = 0;
		}
	}
}