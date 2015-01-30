#pragma once
#include "state.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"

#include <list>

class CEnemyData
{
public:
	CEnemyData(int f,int t,int x,int y):_f(f),_t(t),_x(x),_y(y) {}
	CEnemyData(int f,int t,int x):_f(f),_t(t),_x(x),_y(-128) {}
	int _f;
	int _t;
	int _x;
	int _y;
};

class CStatePlay :
	public CState
{
public:
	CStatePlay(void):frame(0) {}
	~CStatePlay(void){}
public:
	bool Init();
	void Update();
	void Show();
public:
	std::list<CBullet> listPlayerBullet;
	std::list<CBullet> listEnemyBullet;
	std::list<CEnemy> listEnemy;
	std::list<CEnemyData> listEnemyData;
	CPlayer m_player;
private:
	int frame;
};
