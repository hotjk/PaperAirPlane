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
	float X;         // ����x
	float Y;         // ����y
	int W;         // ���
	int H;         // �߶�
	int Type;      // ����

	float XMov;    // x���ƶ�����
	float YMov;    // y���ƶ�����

	int Power;
	int Score;

	int NeedPaint;  // ��Ҫ����
	int IsDead;     // ׹����

	float xIndex; // ͼ������
	int yIndex; // ͼ������
	float xIndexStep; // ͼ���л�����
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
