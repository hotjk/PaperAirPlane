#pragma once
#include "state.h"

class CStateEnding :
	public CState
{
public:
	void InitV()
	{
		fAlphaCurrent = 0.0f;
		nLogoState = 0;
		nWidth = 200;
		nHeight = 200;
		nLogoPause = 20;
	}
	CStateEnding(void)
	{
		InitV();
	}
	~CStateEnding(void){}
	
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
