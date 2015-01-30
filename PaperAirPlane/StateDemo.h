#pragma once
#include "state.h"

class CStateDemo :
	public CState
{
public:
	CStateDemo(void)
	{
		fAlphaCurrent = 0.0f;
		nLogoState = 0;
		nWidth = 200;
		nHeight = 200;
		nLogoPause = 100;
	}
	~CStateDemo(void){}
public:
	bool Init();
	void Update();
	void Show();
public:
	int nWidth;
	int nHeight;
private:
	float fAlphaCurrent;
	int nLogoState;
	int nLogoPause;
};
