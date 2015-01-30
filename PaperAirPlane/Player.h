#pragma once


class CPlayer
{
public:
	/**/
	CPlayer(void);

	~CPlayer(void){}

public:
	float X;         // ����x
	float Y;         // ����y
	int W;         // ���
	int H;         // �߶�

	float XMov;    // x���ƶ�����
	float YMov;    // y���ƶ�����

	int NeedPaint;  // ��Ҫ����
	int IsDead;     // ׹����

	float xIndex; // ͼ������
	int yIndex; // ͼ������
	float xIndexStep; // ͼ���л�����

	float Thrust;		// ����
	float Slowdown; // ����

	int Colddown;
	int HasColddown;

	int ShowFog;
	float IndexFog;
	float IndexFogStep;

	int Power;
	int InitFrame; // �޵�ʱ��
	int HasInitFrame;

public:
	void Show();
	void Update();
};
