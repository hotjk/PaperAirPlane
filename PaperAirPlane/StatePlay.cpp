#include "StatePlay.h"
#include "Common.h"
#include "SDLFacade.h"
#include "Factory.h"
#include "algorithm"
#include <time.h>
class CEnemyIntFunc
{
public:
	bool operator() (const CEnemy& enemy)
	{
		return (enemy.NeedPaint == 0)?true:false;
	}
};

class CBulletIntFunc
{
public:
	bool operator() (const CBullet& bullet)
	{
		return (bullet.NeedPaint == 0)?true:false;
	}
};

bool CStatePlay::Init()
{
	listEnemyData.push_back(CEnemyData(100,0,100));
	listEnemyData.push_back(CEnemyData(100,0,380));

	listEnemyData.push_back(CEnemyData(250,1,100));
	listEnemyData.push_back(CEnemyData(255,1,100));
	listEnemyData.push_back(CEnemyData(250,2,380));
	listEnemyData.push_back(CEnemyData(255,2,380));

	listEnemyData.push_back(CEnemyData(400,3,240));

	listEnemyData.push_back(CEnemyData(500,4,100));

	listEnemyData.push_back(CEnemyData(550,1,100));
	listEnemyData.push_back(CEnemyData(555,1,100));
	listEnemyData.push_back(CEnemyData(560,1,100));
	listEnemyData.push_back(CEnemyData(565,1,100));

	listEnemyData.push_back(CEnemyData(600,2,380));
	listEnemyData.push_back(CEnemyData(605,2,380));
	listEnemyData.push_back(CEnemyData(610,2,380));
	listEnemyData.push_back(CEnemyData(615,2,380));

	listEnemyData.push_back(CEnemyData(700,0,120));
	listEnemyData.push_back(CEnemyData(700,0,240));
	listEnemyData.push_back(CEnemyData(700,0,360));

	listEnemyData.push_back(CEnemyData(800,5,80));
	listEnemyData.push_back(CEnemyData(810,5,160));
	listEnemyData.push_back(CEnemyData(820,5,240));
	listEnemyData.push_back(CEnemyData(830,5,320));
	listEnemyData.push_back(CEnemyData(840,5,400));
	listEnemyData.push_back(CEnemyData(850,5,320));
	listEnemyData.push_back(CEnemyData(860,5,240));
	listEnemyData.push_back(CEnemyData(870,5,160));
	listEnemyData.push_back(CEnemyData(880,5,80));

	listEnemyData.push_back(CEnemyData(920,6,240));

	listEnemyData.push_back(CEnemyData(950,6,100));
	listEnemyData.push_back(CEnemyData(950,6,380));

	listEnemyData.push_back(CEnemyData(1000,1,100));
	listEnemyData.push_back(CEnemyData(1005,1,100));
	listEnemyData.push_back(CEnemyData(1010,1,100));
	listEnemyData.push_back(CEnemyData(1015,1,100));

	listEnemyData.push_back(CEnemyData(1020,2,380));
	listEnemyData.push_back(CEnemyData(1025,2,380));
	listEnemyData.push_back(CEnemyData(1030,2,380));
	listEnemyData.push_back(CEnemyData(1035,2,380));

	listEnemyData.push_back(CEnemyData(1050,3,100));

	listEnemyData.push_back(CEnemyData(1200,3,380));

	listEnemyData.push_back(CEnemyData(1250,4,50));
	listEnemyData.push_back(CEnemyData(1300,4,150));

	listEnemyData.push_back(CEnemyData(1400,0,100));
	listEnemyData.push_back(CEnemyData(1400,0,380));

	listEnemyData.push_back(CEnemyData(1500,8,240));

	listEnemyData.push_back(CEnemyData(2000,7,240));

	listEnemyData.push_back(CEnemyData(2800,1,20));
	listEnemyData.push_back(CEnemyData(2805,1,20));
	listEnemyData.push_back(CEnemyData(2810,1,20));
	listEnemyData.push_back(CEnemyData(2815,1,20));
	return true;
}
void CStatePlay::Update()
{
	frame++;

	// 更新玩家
	m_player.Update();

	// 更新敌人
	for(
		std::list<CEnemy>::iterator iter = listEnemy.begin()
		;iter!=listEnemy.end()
		;++iter)
	{
		iter->Update();
	}
	std::list<CEnemy>::iterator iter = std::remove_if(listEnemy.begin(),listEnemy.end(),CEnemyIntFunc());
	listEnemy.erase(iter,listEnemy.end());

	// 更新敌人子弹
	for(
		std::list<CBullet>::iterator iter = listEnemyBullet.begin()
		;iter!=listEnemyBullet.end()
		;++iter)
	{
		iter->Update();
	}
	std::list<CBullet>::iterator iter2 = std::remove_if(listEnemyBullet.begin(),listEnemyBullet.end(),CBulletIntFunc());
	listEnemyBullet.erase(iter2,listEnemyBullet.end());

	// 更新玩家子弹
	for(
		std::list<CBullet>::iterator iter = listPlayerBullet.begin()
		;iter!=listPlayerBullet.end()
		;++iter)
	{
		iter->Update();
	}
	std::list<CBullet>::iterator iter3 = std::remove_if(listPlayerBullet.begin(),listPlayerBullet.end(),CBulletIntFunc());
	listPlayerBullet.erase(iter3,listPlayerBullet.end());

	// 更新敌人位置
	for(
		std::list<CEnemyData>::iterator iter = listEnemyData.begin()
		;iter!=listEnemyData.end()
		;++iter)
	{
		//if( == frame);
		if(iter->_f ==  frame)
		{
			listEnemy.push_back(CFactory::NewEnemy(iter->_t,iter->_x,iter->_y));
		}
	}

	// 更新玩家子弹是否击中敌人
	for(
		std::list<CBullet>::iterator bullet = listPlayerBullet.begin()
		;bullet!=listPlayerBullet.end()
		;++bullet )
	{
		if(bullet->NeedPaint == 0) continue;
		int x = bullet->X;// + bullet->W/2;
		int y = bullet->Y;// + bullet->H/2;
		if(!(x > 2 && y > 2 && x < SCREEN_WIDTH -2 && y < SCREEN_HEIGHT -2))
		{
			continue; // 子弹飞出画面无效 
		}

		for(
			std::list<CEnemy>::iterator enemy = listEnemy.begin()
			;enemy!=listEnemy.end()
			;++enemy)
		{
			if(enemy->IsDead == 1) continue;

			int l = enemy->X - enemy->W/2;
			int t = enemy->Y - enemy->H/2;
			int r = enemy->X + enemy->W/2;
			int b = enemy->Y + enemy->H/2;
			if( x > l && x < r && y > t && y < b)
			{
				enemy->Power -= bullet->Power;
				if(enemy->Power<=0) enemy->IsDead = 1;
				bullet->NeedPaint = 0;
				break;
			}
		}
	}
	// 更新敌人是否撞击到玩家

	int P_L = m_player.X-m_player.W/2;
	int P_T = m_player.Y-m_player.H/2;
	int P_R = m_player.X+m_player.W/2;
	int P_B = m_player.Y+m_player.H/2;
	P_L = P_L + 5; // 缩小有效范围
	P_T = P_T + 5;
	P_R = P_R - 5;
	P_B = P_B - 5;

	if(m_player.HasInitFrame == m_player.InitFrame)
	{
		for(
			std::list<CEnemy>::iterator enemy = listEnemy.begin()
			;enemy!=listEnemy.end()
			;++enemy)
		{
			if(enemy->NeedPaint == 0) continue;
			int l = enemy->X - enemy->W/2;
			int t = enemy->Y - enemy->H/2;
			int r = enemy->X + enemy->W/2;
			int b = enemy->Y + enemy->H/2;

			if(CSDLFacade::Intersect(l,t,r,b
				,P_L
				,P_T
				,P_R
				,P_B))
			{
				this->m_player.ShowFog = 1;
				this->m_player.Power--;
				m_player.HasInitFrame = 0;
				break;
			}
		}

		// 更新敌人子弹是否击中玩家
		for(
			std::list<CBullet>::iterator bullet = listEnemyBullet.begin()
			;bullet!=listEnemyBullet.end()
			;++bullet )
		{
			if(bullet->NeedPaint == 0) continue;
			if(CSDLFacade::PtInRect(bullet->X,bullet->Y,P_L,P_T,P_R,P_B))
			{
				this->m_player.ShowFog = 1;
				this->m_player.Power-=bullet->Power;
				m_player.HasInitFrame = 0;
				bullet->NeedPaint = 0;
				break;
			}
		}
	}
	else
	{
		m_player.HasInitFrame++;
	}

	if(frame > 2000 && listEnemy.size() == 0) // win
	{
		gState = &gStateEnding;
	}

	if(m_player.Power <= 0 ) //lost
	{
		gState = &gStateEnding;
	}

}
void CStatePlay::Show()
{
	CSDLFacade::DrawRect(gScreen,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,COLOR_WHITE);

	for(int i=0;i<m_player.Power;i++)
	{
		CSDLFacade::DrawRect(gScreen,20 + i*10 ,20,4,10,0x000000);
	}

	m_player.Show();

	for(
		std::list<CEnemy>::iterator iter = listEnemy.begin()
		;iter!=listEnemy.end()
		;++iter)
	{
		iter->Show();
	}

	for(
		std::list<CBullet>::iterator iter = listEnemyBullet.begin()
		;iter!=listEnemyBullet.end()
		;++iter)
	{
		iter->Show();
	}

	for(
		std::list<CBullet>::iterator iter = listPlayerBullet.begin()
		;iter!=listPlayerBullet.end()
		;++iter)
	{
		iter->Show();
	}


}