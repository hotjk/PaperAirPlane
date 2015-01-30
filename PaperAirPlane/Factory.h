#pragma once
#include "Bullet.h"
#include "Enemy.h"

class CFactory
{
public:
	static CEnemy NewEnemy(int EnemyType,int x,int y);
	static CBullet NewBullet(int BulletType,int x,int y);
};
