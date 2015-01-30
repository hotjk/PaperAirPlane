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
	int NeedPaint;  // 需要绘制
	float xIndex; // 图像索引
	int yIndex; // 图像索引
	float xIndexStep; // 图像切换步长
	int IndexCount;

	public:
	void Show();
	void Update();
};
