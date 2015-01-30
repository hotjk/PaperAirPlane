#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include "Common.h"

class CSDLFacade
{
public:
	static SDL_Surface *LoadImage( std::string filename ) ;
	static void FreeImage(SDL_Surface * image);
	static void ApplySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);
	static void AlphaSurface(SDL_Surface* surface,Uint8 alpha);
	static void DrawRect(SDL_Surface* screen,int x, int y, int width, int height, int color);
	static void DrawCircle(SDL_Surface* screen,int x, int y, int r, int c);
	static bool Intersect(int l1,int t1,int r1,int b1,int l2,int t2,int r2,int b2);
	static bool PtInRect(int x,int y,int l,int t,int r,int b);
};
