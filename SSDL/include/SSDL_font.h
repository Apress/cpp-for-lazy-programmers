/*Simple SDL, a wrapper library for SDL.
  
  Copyright (C) 2019 Will Briggs.

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution. */

//This is SSDL_Font.
//Since it's a wrapper, it is essentially TTF_Font*, only it has memory management.

#ifndef SSDL_FONT_H
#define SSDL_FONT_H

#include <memory>
#include <SDL_ttf.h>

class SSDL_Font
{
public:
	SSDL_Font(TTF_Font* font = NULL) : ttfFont_(NULL) //WSB: took out SSDL_Font:: for MinGW compile
	{
		ttfFont_.reset(font, TTF_CloseFont);
	}
	SSDL_Font(const SSDL_Font& f) { *this = f; }

	const SSDL_Font& operator= (const SSDL_Font& f) { ttfFont_ = f.ttfFont_; return *this; }
	operator       TTF_Font* ()       { return ttfFont_.get(); }
	operator       TTF_Font* () const { return ttfFont_.get(); }

private:
	std::shared_ptr<TTF_Font> ttfFont_;
};

TTF_Font* SSDL_OpenFont		  (const char* filename, int point);
        //This bit all relates to where to get fonts found on the system
        //WSB: get something that'll work on Mac too...
#ifdef _WIN32
#define FONT_PATH "C:\\Windows\\Fonts\\"
#elif __unix__
#define FONT_PATH "/usr/share/fonts/truetype/msttcorefonts/"
#endif

inline
TTF_Font* SSDL_OpenSystemFont (const char* filename, int point)
{
	std::string newPath (FONT_PATH); newPath += filename; filename = newPath.c_str();
	return SSDL_OpenFont (filename, point);
}

	//What font is current?
TTF_Font* SSDL_GetCurrentFont(); //WSB: should it return const TTF_Font*?
void      SSDL_SetFont(TTF_Font* newFont); //WSB: test with const pointer too?

#endif
