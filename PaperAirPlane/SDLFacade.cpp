#include "SDLFacade.h"
#include <math.h>
#include "Common.h"

SDL_Surface * 
CSDLFacade::LoadImage( std::string filename ) 
{
	SDL_Surface* loadedImage = NULL;
	loadedImage = SDL_LoadBMP( filename.c_str() );
	SDL_SetColorKey( loadedImage, SDL_RLEACCEL | SDL_SRCCOLORKEY, SDL_MapRGB( loadedImage->format, 0xFF, 0x00, 0xFF ) );
	return loadedImage;
}

void CSDLFacade::FreeImage(SDL_Surface * image)
{
	SDL_FreeSurface(image);
}

void CSDLFacade::ApplySurface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
	SDL_Rect offset;

	offset.x = x;
	offset.y = y;

	SDL_BlitSurface( source, clip, destination, &offset );
}

void CSDLFacade::AlphaSurface(SDL_Surface* surface,Uint8 alpha)
{
	SDL_SetAlpha( surface, SDL_SRCALPHA | SDL_RLEACCEL, alpha );
}
void CSDLFacade::DrawRect(SDL_Surface* screen,int x, int y, int width, int height, int c)
{
	int i, j;
	for (i = 0; i < height; i++)
	{
		if ((y + i) >= 0 && (y + i) < SCREEN_HEIGHT)
		{
			int len = width;
			int xofs = x;

			if (xofs < 0)
			{
				len += xofs;
				xofs = 0;
			}

			if (xofs + len >= SCREEN_WIDTH)
			{
				len -= (xofs + len) - SCREEN_WIDTH;
			}
			int ofs = (i + y) * PITCH + xofs;

			for (j = 0; j < len; j++)
				((unsigned int*)screen->pixels)[ofs + j] = c;
		}
	}
}

void CSDLFacade::DrawCircle(SDL_Surface* screen,int x, int y, int r, int c)
{
  int i, j;
  for (i = 0; i < 2 * r; i++)
  {
    // vertical clipping: (top and bottom)
    if ((y - r + i) >= 0 && (y - r + i) < SCREEN_HEIGHT)
    {
      int len = (int)sqrt((float)(r * r - (r - i) * (r - i))) * 2;
      int xofs = x - len / 2;

      // left border
      if (xofs < 0)
      {
        len += xofs;
        xofs = 0;
      }

      // right border
      if (xofs + len >= SCREEN_WIDTH)
      {
        len -= (xofs + len) - SCREEN_WIDTH;
      }
      int ofs = (y - r + i) * PITCH + xofs;
      
      // note that len may be 0 at this point, 
      // and no pixels get drawn!
      for (j = 0; j < len; j++)
        ((unsigned int*)screen->pixels)[ofs + j] = c;
    }
  }
}
bool CSDLFacade::Intersect(int l1,int t1,int r1,int b1,int l2,int t2,int r2,int b2)
{
	//if(l1<l2 && t1<t2 && r1>r2 && b1>b2) return true; // 2在1内部
	//if(l2<l1 && t2<t1 && r2>r1 && b2>b1) return true; // 1在2内部
	if(l1>=l2 && t1>=t2 && l1<=r2 && t1<=b2) return true; // 1左上在2内部
	if(r1>=l2 && t1>=t2 && r1<=r2 && t1<=b2) return true; // 1右上在2内部
	if(r1>=l2 && b1>=t2 && r1<=r2 && b1<=b2) return true; // 1右下在2内部
	if(l1>=l2 && b1>=t2 && l1<=r2 && b1<=b2) return true; // 1左下在2内部

	if(l2>=l1 && t2>=t1 && l2<=r1 && t2<=b1) return true; // 2左上在1内部
	if(r2>=l1 && t2>=t1 && r2<=r1 && t2<=b1) return true; // 2右上在1内部
	if(r2>=l1 && b2>=t1 && r2<=r1 && b2<=b1) return true; // 2右下在1内部
	if(l2>=l1 && b2>=t1 && l2<=r1 && b2<=b1) return true; // 2左下在1内部
	return false;
}
bool CSDLFacade::PtInRect(int x,int y,int l,int t,int r,int b)
{
	if(x > l && y > t && x < r && y < b) return true;
	return false;
}