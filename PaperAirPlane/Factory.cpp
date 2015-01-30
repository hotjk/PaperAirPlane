#include "Factory.h"

CEnemy CFactory::NewEnemy(int EnemyType,int x,int y)
{
	CEnemy enemy;
	enemy.X = x;
	enemy.Y = y;
	enemy.Type = EnemyType;
	enemy.XMov = 0;
	enemy.YMov = 3;
	enemy.NeedPaint = 1;
	enemy.IsDead = 0;
	enemy.W = 64;
	enemy.H = 64;
	enemy.Power = 3;
	enemy.Score = 10;
	enemy.xIndex = 0.0f;
	enemy.yIndex = 0;
	enemy.xIndexStep = 0.5f;
	enemy.xDeadIndexStep = 0.5f;
	enemy.IndexCount = 5;
	enemy.DeadIndexCount = 10;
	switch(EnemyType)
	{
	case 0: // 发3发子弹的直升机
		enemy.yIndex = 0;
		enemy.listMoveRule.push_back(CMoveRule(50,0,5));
		enemy.listMoveRule.push_back(CMoveRule(100,0,0));
		enemy.listMoveRule.push_back(CMoveRule(1000,0,10));

		enemy.listBulletRule.push_back(CBulletRule(80,1));
		enemy.listBulletRule.push_back(CBulletRule(85,1));
		enemy.listBulletRule.push_back(CBulletRule(90,1));
		enemy.Power = 3;
		break;
	case 1: // 右俯冲
		enemy.yIndex = 1;
		enemy.listMoveRule.push_back(CMoveRule(1000,2,12));
		enemy.Power = 1;
		break;
	case 2: // 左俯冲
		enemy.yIndex = 1;
		enemy.listMoveRule.push_back(CMoveRule(1000,-2,12));
		enemy.Power = 1;
		break;
	case 3: // 2轮扇形子弹大轰炸机
		enemy.W = 128;
		enemy.H = 128;
		enemy.yIndex = 1;
		enemy.IndexCount = 2;
		enemy.xDeadIndexStep = 0.1f;
		enemy.DeadIndexCount = 5;
		enemy.listMoveRule.push_back(CMoveRule(50,0,5));
		enemy.listMoveRule.push_back(CMoveRule(100,0,0));
		enemy.listMoveRule.push_back(CMoveRule(1000,0,3));

		//enemy.listBulletRule.push_back(CBulletRule(80,1));
		enemy.listBulletRule.push_back(CBulletRule(80,2));
		enemy.listBulletRule.push_back(CBulletRule(80,3));
		enemy.listBulletRule.push_back(CBulletRule(80,4));
		enemy.listBulletRule.push_back(CBulletRule(80,5));
		enemy.listBulletRule.push_back(CBulletRule(80,6));
		enemy.listBulletRule.push_back(CBulletRule(80,7));
		enemy.listBulletRule.push_back(CBulletRule(80,8));
		enemy.listBulletRule.push_back(CBulletRule(80,9));

		//enemy.listBulletRule.push_back(CBulletRule(90,1));
		enemy.listBulletRule.push_back(CBulletRule(90,2));
		enemy.listBulletRule.push_back(CBulletRule(90,3));
		enemy.listBulletRule.push_back(CBulletRule(90,4));
		enemy.listBulletRule.push_back(CBulletRule(90,5));
		enemy.listBulletRule.push_back(CBulletRule(90,6));
		enemy.listBulletRule.push_back(CBulletRule(90,7));
		enemy.listBulletRule.push_back(CBulletRule(90,8));
		enemy.listBulletRule.push_back(CBulletRule(90,9));
		enemy.Power = 20;
		break;
	case 4: // 4发子弹双螺旋浆直升机
		enemy.yIndex = 4;
		enemy.Power = 5;
		enemy.listMoveRule.push_back(CMoveRule(50,0,5));
		enemy.listMoveRule.push_back(CMoveRule(150,1,1));
		enemy.listMoveRule.push_back(CMoveRule(250,1,-1));
		enemy.listMoveRule.push_back(CMoveRule(1000,1,-5));

		enemy.listBulletRule.push_back(CBulletRule(160,1));
		enemy.listBulletRule.push_back(CBulletRule(170,1));
		enemy.listBulletRule.push_back(CBulletRule(230,1));
		enemy.listBulletRule.push_back(CBulletRule(240,1));
		break;
	case 5: // 不发子弹的直升机
		enemy.yIndex = 0;
		enemy.listMoveRule.push_back(CMoveRule(1000,0,8));
		enemy.Power = 3;
		break;
	case 6: // 左右发弹的直升机
		enemy.yIndex = 0;
		enemy.listMoveRule.push_back(CMoveRule(50,0,5));
		enemy.listMoveRule.push_back(CMoveRule(100,0,0));
		enemy.listMoveRule.push_back(CMoveRule(1000,0,10));
		enemy.listBulletRule.push_back(CBulletRule(60,6));
		enemy.listBulletRule.push_back(CBulletRule(60,7));
		enemy.listBulletRule.push_back(CBulletRule(70,6));
		enemy.listBulletRule.push_back(CBulletRule(70,7));
		enemy.Power = 3;
		break;
	case 8: // 强
		enemy.yIndex = 5;
		enemy.xIndexStep = 0.25f;
		enemy.listMoveRule.push_back(CMoveRule(60,0,5));
		enemy.listMoveRule.push_back(CMoveRule(400,0,0));
		enemy.listMoveRule.push_back(CMoveRule(1000,0,10));

		enemy.listBulletRule.push_back(CBulletRule(60,2));
		enemy.listBulletRule.push_back(CBulletRule(60,3));
		enemy.listBulletRule.push_back(CBulletRule(60,6));
		enemy.listBulletRule.push_back(CBulletRule(60,7));
		enemy.listBulletRule.push_back(CBulletRule(70,6));
		enemy.listBulletRule.push_back(CBulletRule(70,7));
		enemy.listBulletRule.push_back(CBulletRule(80,6));
		enemy.listBulletRule.push_back(CBulletRule(80,7));
		enemy.listBulletRule.push_back(CBulletRule(90,6));
		enemy.listBulletRule.push_back(CBulletRule(90,7));

		enemy.listBulletRule.push_back(CBulletRule(160,6));
		enemy.listBulletRule.push_back(CBulletRule(160,7));
		enemy.listBulletRule.push_back(CBulletRule(170,6));
		enemy.listBulletRule.push_back(CBulletRule(170,7));
		enemy.listBulletRule.push_back(CBulletRule(180,2));
		enemy.listBulletRule.push_back(CBulletRule(180,3));
		enemy.listBulletRule.push_back(CBulletRule(180,6));
		enemy.listBulletRule.push_back(CBulletRule(180,7));
		enemy.listBulletRule.push_back(CBulletRule(190,6));
		enemy.listBulletRule.push_back(CBulletRule(190,7));

		enemy.listBulletRule.push_back(CBulletRule(260,6));
		enemy.listBulletRule.push_back(CBulletRule(260,7));
		enemy.listBulletRule.push_back(CBulletRule(270,6));
		enemy.listBulletRule.push_back(CBulletRule(270,7));
		enemy.listBulletRule.push_back(CBulletRule(280,6));
		enemy.listBulletRule.push_back(CBulletRule(280,7));
		enemy.listBulletRule.push_back(CBulletRule(290,6));
		enemy.listBulletRule.push_back(CBulletRule(290,7));

		enemy.listBulletRule.push_back(CBulletRule(360,2));
		enemy.listBulletRule.push_back(CBulletRule(360,3));
		enemy.listBulletRule.push_back(CBulletRule(360,6));
		enemy.listBulletRule.push_back(CBulletRule(360,7));
		enemy.listBulletRule.push_back(CBulletRule(370,8));
		enemy.listBulletRule.push_back(CBulletRule(370,9));
		enemy.listBulletRule.push_back(CBulletRule(380,4));
		enemy.listBulletRule.push_back(CBulletRule(380,5));
		enemy.listBulletRule.push_back(CBulletRule(390,6));
		enemy.listBulletRule.push_back(CBulletRule(390,7));
		enemy.Power = 30;
		break;
	case 7: // 可怕的大轰炸机
		enemy.W = 128;
		enemy.H = 128;
		enemy.yIndex = 3;
		enemy.IndexCount = 2;
		enemy.xDeadIndexStep = 0.1f;
		enemy.DeadIndexCount = 5;
		enemy.listMoveRule.push_back(CMoveRule(50,0,5));
		enemy.listMoveRule.push_back(CMoveRule(150,0,0));
		enemy.listMoveRule.push_back(CMoveRule(200,2,0));
		enemy.listMoveRule.push_back(CMoveRule(300,-2,0));
		enemy.listMoveRule.push_back(CMoveRule(400,2,0));
		enemy.listMoveRule.push_back(CMoveRule(500,-2,0));
		enemy.listMoveRule.push_back(CMoveRule(600,2,0));
		enemy.listMoveRule.push_back(CMoveRule(650,-2,0)); // center

		enemy.listMoveRule.push_back(CMoveRule(700,0,1));
		enemy.listMoveRule.push_back(CMoveRule(750,0,0));
		enemy.listMoveRule.push_back(CMoveRule(800,2,0));
		enemy.listMoveRule.push_back(CMoveRule(900,-2,0));
		enemy.listMoveRule.push_back(CMoveRule(1000,2,0));
		enemy.listMoveRule.push_back(CMoveRule(1100,-2,0));
		enemy.listMoveRule.push_back(CMoveRule(1200,2,0));
		enemy.listMoveRule.push_back(CMoveRule(1250,-2,0)); //center

		enemy.listMoveRule.push_back(CMoveRule(1300,0,-1));
		enemy.listMoveRule.push_back(CMoveRule(1350,0,0));
		enemy.listMoveRule.push_back(CMoveRule(1400,2,0));
		enemy.listMoveRule.push_back(CMoveRule(1500,-2,0));
		enemy.listMoveRule.push_back(CMoveRule(1600,2,0));
		enemy.listMoveRule.push_back(CMoveRule(1700,-2,0));
		enemy.listMoveRule.push_back(CMoveRule(1800,2,0));
		enemy.listMoveRule.push_back(CMoveRule(1850,-2,0)); //center

		enemy.listBulletRule.push_back(CBulletRule(80,2));
		enemy.listBulletRule.push_back(CBulletRule(80,3));
		enemy.listBulletRule.push_back(CBulletRule(80,4));
		enemy.listBulletRule.push_back(CBulletRule(80,5));
		enemy.listBulletRule.push_back(CBulletRule(80,6));
		enemy.listBulletRule.push_back(CBulletRule(80,7));
		enemy.listBulletRule.push_back(CBulletRule(80,8));
		enemy.listBulletRule.push_back(CBulletRule(80,9));

		enemy.listBulletRule.push_back(CBulletRule(90,2));
		enemy.listBulletRule.push_back(CBulletRule(90,3));
		enemy.listBulletRule.push_back(CBulletRule(90,4));
		enemy.listBulletRule.push_back(CBulletRule(90,5));
		enemy.listBulletRule.push_back(CBulletRule(90,6));
		enemy.listBulletRule.push_back(CBulletRule(90,7));
		enemy.listBulletRule.push_back(CBulletRule(90,8));
		enemy.listBulletRule.push_back(CBulletRule(90,9));

		enemy.listBulletRule.push_back(CBulletRule(200,2));
		enemy.listBulletRule.push_back(CBulletRule(200,3));
		enemy.listBulletRule.push_back(CBulletRule(200,4));
		enemy.listBulletRule.push_back(CBulletRule(200,5));
		enemy.listBulletRule.push_back(CBulletRule(200,6));
		enemy.listBulletRule.push_back(CBulletRule(200,7));
		enemy.listBulletRule.push_back(CBulletRule(200,8));
		enemy.listBulletRule.push_back(CBulletRule(200,9));

		enemy.listBulletRule.push_back(CBulletRule(300,2));
		enemy.listBulletRule.push_back(CBulletRule(300,3));
		enemy.listBulletRule.push_back(CBulletRule(300,4));
		enemy.listBulletRule.push_back(CBulletRule(300,5));
		enemy.listBulletRule.push_back(CBulletRule(300,6));
		enemy.listBulletRule.push_back(CBulletRule(300,7));
		enemy.listBulletRule.push_back(CBulletRule(300,8));
		enemy.listBulletRule.push_back(CBulletRule(300,9));

		enemy.listBulletRule.push_back(CBulletRule(350,1));
		enemy.listBulletRule.push_back(CBulletRule(355,1));
		enemy.listBulletRule.push_back(CBulletRule(360,1));
		enemy.listBulletRule.push_back(CBulletRule(365,1));

		enemy.listBulletRule.push_back(CBulletRule(400,1));
		enemy.listBulletRule.push_back(CBulletRule(405,1));
		enemy.listBulletRule.push_back(CBulletRule(410,1));
		enemy.listBulletRule.push_back(CBulletRule(415,1));

		enemy.listBulletRule.push_back(CBulletRule(500,2));
		enemy.listBulletRule.push_back(CBulletRule(500,3));
		enemy.listBulletRule.push_back(CBulletRule(500,4));
		enemy.listBulletRule.push_back(CBulletRule(500,5));
		enemy.listBulletRule.push_back(CBulletRule(500,6));
		enemy.listBulletRule.push_back(CBulletRule(500,7));
		enemy.listBulletRule.push_back(CBulletRule(500,8));
		enemy.listBulletRule.push_back(CBulletRule(500,9));

		enemy.listBulletRule.push_back(CBulletRule(510,2));
		enemy.listBulletRule.push_back(CBulletRule(510,3));
		enemy.listBulletRule.push_back(CBulletRule(510,4));
		enemy.listBulletRule.push_back(CBulletRule(510,5));
		enemy.listBulletRule.push_back(CBulletRule(510,6));
		enemy.listBulletRule.push_back(CBulletRule(510,7));
		enemy.listBulletRule.push_back(CBulletRule(510,8));
		enemy.listBulletRule.push_back(CBulletRule(510,9));

		enemy.listBulletRule.push_back(CBulletRule(520,2));
		enemy.listBulletRule.push_back(CBulletRule(520,3));
		enemy.listBulletRule.push_back(CBulletRule(520,4));
		enemy.listBulletRule.push_back(CBulletRule(520,5));
		enemy.listBulletRule.push_back(CBulletRule(520,6));
		enemy.listBulletRule.push_back(CBulletRule(520,7));
		enemy.listBulletRule.push_back(CBulletRule(520,8));
		enemy.listBulletRule.push_back(CBulletRule(520,9));

		enemy.listBulletRule.push_back(CBulletRule(530,2));
		enemy.listBulletRule.push_back(CBulletRule(530,3));
		enemy.listBulletRule.push_back(CBulletRule(530,4));
		enemy.listBulletRule.push_back(CBulletRule(530,5));
		enemy.listBulletRule.push_back(CBulletRule(530,6));
		enemy.listBulletRule.push_back(CBulletRule(530,7));
		enemy.listBulletRule.push_back(CBulletRule(530,8));
		enemy.listBulletRule.push_back(CBulletRule(530,9));

		enemy.listBulletRule.push_back(CBulletRule(600,10));
		enemy.listBulletRule.push_back(CBulletRule(610,10));
		enemy.listBulletRule.push_back(CBulletRule(620,10));
		enemy.listBulletRule.push_back(CBulletRule(630,10));

		enemy.listBulletRule.push_back(CBulletRule(700,10));
		enemy.listBulletRule.push_back(CBulletRule(710,10));
		enemy.listBulletRule.push_back(CBulletRule(720,10));
		enemy.listBulletRule.push_back(CBulletRule(730,10));

		enemy.listBulletRule.push_back(CBulletRule(800,2));
		enemy.listBulletRule.push_back(CBulletRule(800,3));
		enemy.listBulletRule.push_back(CBulletRule(800,4));
		enemy.listBulletRule.push_back(CBulletRule(800,5));
		enemy.listBulletRule.push_back(CBulletRule(800,6));
		enemy.listBulletRule.push_back(CBulletRule(800,7));
		enemy.listBulletRule.push_back(CBulletRule(800,8));
		enemy.listBulletRule.push_back(CBulletRule(800,9));

		enemy.listBulletRule.push_back(CBulletRule(810,2));
		enemy.listBulletRule.push_back(CBulletRule(810,3));
		enemy.listBulletRule.push_back(CBulletRule(810,4));
		enemy.listBulletRule.push_back(CBulletRule(810,5));
		enemy.listBulletRule.push_back(CBulletRule(810,6));
		enemy.listBulletRule.push_back(CBulletRule(810,7));
		enemy.listBulletRule.push_back(CBulletRule(810,8));
		enemy.listBulletRule.push_back(CBulletRule(810,9));

		enemy.listBulletRule.push_back(CBulletRule(900,2));
		enemy.listBulletRule.push_back(CBulletRule(900,3));
		enemy.listBulletRule.push_back(CBulletRule(900,4));
		enemy.listBulletRule.push_back(CBulletRule(900,5));
		enemy.listBulletRule.push_back(CBulletRule(900,6));
		enemy.listBulletRule.push_back(CBulletRule(900,7));
		enemy.listBulletRule.push_back(CBulletRule(900,8));
		enemy.listBulletRule.push_back(CBulletRule(900,9));

		enemy.listBulletRule.push_back(CBulletRule(910,2));
		enemy.listBulletRule.push_back(CBulletRule(910,3));
		enemy.listBulletRule.push_back(CBulletRule(910,4));
		enemy.listBulletRule.push_back(CBulletRule(910,5));
		enemy.listBulletRule.push_back(CBulletRule(910,6));
		enemy.listBulletRule.push_back(CBulletRule(910,7));
		enemy.listBulletRule.push_back(CBulletRule(910,8));
		enemy.listBulletRule.push_back(CBulletRule(910,9));

		enemy.listBulletRule.push_back(CBulletRule(1100,11));
		enemy.listBulletRule.push_back(CBulletRule(1105,11));
		enemy.listBulletRule.push_back(CBulletRule(1110,11));
		enemy.listBulletRule.push_back(CBulletRule(1115,11));

		enemy.listBulletRule.push_back(CBulletRule(1150,11));
		enemy.listBulletRule.push_back(CBulletRule(1155,11));
		enemy.listBulletRule.push_back(CBulletRule(1160,11));
		enemy.listBulletRule.push_back(CBulletRule(1165,11));

		enemy.listBulletRule.push_back(CBulletRule(1220,2));
		enemy.listBulletRule.push_back(CBulletRule(1220,3));
		enemy.listBulletRule.push_back(CBulletRule(1220,4));
		enemy.listBulletRule.push_back(CBulletRule(1220,5));
		enemy.listBulletRule.push_back(CBulletRule(1220,6));
		enemy.listBulletRule.push_back(CBulletRule(1220,7));
		enemy.listBulletRule.push_back(CBulletRule(1220,8));
		enemy.listBulletRule.push_back(CBulletRule(1220,9));

		enemy.listBulletRule.push_back(CBulletRule(1230,2));
		enemy.listBulletRule.push_back(CBulletRule(1230,3));
		enemy.listBulletRule.push_back(CBulletRule(1230,4));
		enemy.listBulletRule.push_back(CBulletRule(1230,5));
		enemy.listBulletRule.push_back(CBulletRule(1230,6));
		enemy.listBulletRule.push_back(CBulletRule(1230,7));
		enemy.listBulletRule.push_back(CBulletRule(1230,8));
		enemy.listBulletRule.push_back(CBulletRule(1230,9));

		enemy.listBulletRule.push_back(CBulletRule(1240,2));
		enemy.listBulletRule.push_back(CBulletRule(1240,3));
		enemy.listBulletRule.push_back(CBulletRule(1240,4));
		enemy.listBulletRule.push_back(CBulletRule(1240,5));
		enemy.listBulletRule.push_back(CBulletRule(1240,6));
		enemy.listBulletRule.push_back(CBulletRule(1240,7));
		enemy.listBulletRule.push_back(CBulletRule(1240,8));
		enemy.listBulletRule.push_back(CBulletRule(1240,9));

		enemy.listBulletRule.push_back(CBulletRule(1250,2));
		enemy.listBulletRule.push_back(CBulletRule(1250,3));
		enemy.listBulletRule.push_back(CBulletRule(1250,4));
		enemy.listBulletRule.push_back(CBulletRule(1250,5));
		enemy.listBulletRule.push_back(CBulletRule(1250,6));
		enemy.listBulletRule.push_back(CBulletRule(1250,7));
		enemy.listBulletRule.push_back(CBulletRule(1250,8));
		enemy.listBulletRule.push_back(CBulletRule(1250,9));

		enemy.listBulletRule.push_back(CBulletRule(1400,11));
		enemy.listBulletRule.push_back(CBulletRule(1405,11));
		enemy.listBulletRule.push_back(CBulletRule(1410,11));
		enemy.listBulletRule.push_back(CBulletRule(1415,11));

		enemy.listBulletRule.push_back(CBulletRule(1450,11));
		enemy.listBulletRule.push_back(CBulletRule(1455,11));
		enemy.listBulletRule.push_back(CBulletRule(1460,11));
		enemy.listBulletRule.push_back(CBulletRule(1465,11));

		enemy.listBulletRule.push_back(CBulletRule(1520,2));
		enemy.listBulletRule.push_back(CBulletRule(1520,3));
		enemy.listBulletRule.push_back(CBulletRule(1520,4));
		enemy.listBulletRule.push_back(CBulletRule(1520,5));
		enemy.listBulletRule.push_back(CBulletRule(1520,6));
		enemy.listBulletRule.push_back(CBulletRule(1520,7));
		enemy.listBulletRule.push_back(CBulletRule(1520,8));
		enemy.listBulletRule.push_back(CBulletRule(1520,9));

		enemy.listBulletRule.push_back(CBulletRule(1530,2));
		enemy.listBulletRule.push_back(CBulletRule(1530,3));
		enemy.listBulletRule.push_back(CBulletRule(1530,4));
		enemy.listBulletRule.push_back(CBulletRule(1530,5));
		enemy.listBulletRule.push_back(CBulletRule(1530,6));
		enemy.listBulletRule.push_back(CBulletRule(1530,7));
		enemy.listBulletRule.push_back(CBulletRule(1530,8));
		enemy.listBulletRule.push_back(CBulletRule(1530,9));

		enemy.Power = 200;
		break;

	}
	return enemy;
	

}

CBullet CFactory::NewBullet(int BulletType,int x,int y)
{
	CBullet bullet;
	bullet.W = 10;
	bullet.H = 10;
	bullet.X = x;
	bullet.Y = y;
	bullet.Type = BulletType;
	bullet.XMov = 0;
	bullet.YMov = 10;
	bullet.Power = 1;
	bullet.NeedPaint = 1;
	bullet.xIndex = 0;
	bullet.yIndex = 1;
	bullet.xIndexStep = 0.2;
	bullet.IndexCount = 1;
	switch(BulletType)
	{
	case 0:
		bullet.yIndex = 0;
		bullet.YMov = -15;
		break;
	case 1:
		break;
	case 2:
		bullet.XMov = -1.0f;
		break;
	case 3:
		bullet.XMov = +1.0f;
		break;
	case 4:
		bullet.XMov = -2.0f;
		break;
	case 5:
		bullet.XMov = +2.0f;
		break;
	case 6:
		bullet.XMov = -3.0f;
		break;
	case 7:
		bullet.XMov = +3.0f;
		break;
	case 8:
		bullet.XMov = -4.0f;
		break;
	case 9:
		bullet.XMov = +4.0f;
		break;
	case 10:
		bullet.YMov = 15;
	case 11:
		bullet.YMov = 20;
	}

	return bullet;
	
}