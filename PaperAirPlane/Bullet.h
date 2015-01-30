#pragma once

class CBullet
{
public:
	CBullet(void) {}
	~CBullet(void) {}
public:
	int X;
	int Y;
	int W;
	int H;
	int Type;

	float XMov;
	float YMov;
	int Power;
	int NeedPaint;  // ��Ҫ����
	float xIndex; // ͼ������
	int yIndex; // ͼ������
	float xIndexStep; // ͼ���л�����
	int IndexCount;

	public:
	void Show();
	void Update();
};
