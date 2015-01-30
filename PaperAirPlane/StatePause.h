#pragma once
#include "state.h"

class CStatePause :
	public CState
{
public:
	CStatePause(void);
	~CStatePause(void);
public:
	bool Init();
	void Update();
	void Show();
};
