#pragma once
#include "state.h"

class CStateMenu :
	public CState
{
public:
	void InitV()
	{
		nWidth = 200;
		nHeight = 100;
		nUserSelect = 0;
		fAlphaCurrent = 0;
	}
	CStateMenu(void)
	{
		InitV();
	}
	
	~CStateMenu(void){}

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
	int nUserSelect;
};
