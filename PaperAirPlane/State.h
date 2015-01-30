#pragma once

class CState
{
public:
	CState(void);
	~CState(void);
public:
	virtual bool Init() = 0;
	virtual void Update() = 0;
	virtual void Show() = 0;
	
};

