#pragma once

class CMoveRule
{
public:
	int nFrame;
	float fX;
	float fY;
public:
	CMoveRule(int f,float x,float y):nFrame(f),fX(x),fY(y)
	{
	}
};

class CBulletRule
{
	public:
	int nFrame;
	int nT;
	public:
	CBulletRule(int f,int t):nFrame(f),nT(t)
	{
	}
};