#pragma once


class CPlayer
{
public:
	/**/
	CPlayer(void);

	~CPlayer(void){}

public:
	float X;         // 中心x
	float Y;         // 中心y
	int W;         // 宽度
	int H;         // 高度

	float XMov;    // x轴移动距离
	float YMov;    // y轴移动距离

	int NeedPaint;  // 需要绘制
	int IsDead;     // 坠机中

	float xIndex; // 图像索引
	int yIndex; // 图像索引
	float xIndexStep; // 图像切换步长

	float Thrust;		// 推力
	float Slowdown; // 阻力

	int Colddown;
	int HasColddown;

	int ShowFog;
	float IndexFog;
	float IndexFogStep;

	int Power;
	int InitFrame; // 无敌时间
	int HasInitFrame;

public:
	void Show();
	void Update();
};
