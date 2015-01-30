#pragma once
#include <list>
#include "MoveRule.h"

class CEnemy
{
public:
	CEnemy(void)
	{
		frame = 0;
	}
	~CEnemy(void){}
public:
	float X;         // 中心x
	float Y;         // 中心y
	int W;         // 宽度
	int H;         // 高度
	int Type;      // 类型

	float XMov;    // x轴移动距离
	float YMov;    // y轴移动距离

	int Power;
	int Score;

	int NeedPaint;  // 需要绘制
	int IsDead;     // 坠机中

	float xIndex; // 图像索引
	int yIndex; // 图像索引
	float xIndexStep; // 图像切换步长
	float xDeadIndexStep;

	int IndexCount;
	int DeadIndexCount;
	std::list<CMoveRule> listMoveRule;
	std::list<CBulletRule> listBulletRule;
public:
	void Show();
	void Update();
private:
	int frame;
};
