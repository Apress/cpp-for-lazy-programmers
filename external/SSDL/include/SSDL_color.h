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

//This is SSDL_Color.h, which provides SSDL_Color:  just like SDL_Color, except that it has constructors

#ifndef SSDL_COLOR_H
#define SSDL_COLOR_H

#include "SDL.h"

struct SSDL_Color : public SDL_Color
{
public:
	SSDL_Color (const SDL_Color& other) { r = other.r; g = other.g; b = other.b; a = other.a; }
	SSDL_Color (int rIn = 0, int gIn = 0, int bIn = 0, int alpha = 255)
	{
		r = rIn; g = gIn; b = bIn; a = alpha;
	}
	SSDL_Color            (const SSDL_Color& other) = default;
	SSDL_Color& operator= (const SSDL_Color& other) = default;
	
	bool operator== (const SSDL_Color& other) const
	{
		return r == other.r && g == other.g&& b == other.b && a == other.a;
	}
};

extern const SSDL_Color BLACK, WHITE, RED, GREEN, BLUE;

inline SSDL_Color SSDL_CreateColor (int r, int g, int b, int a=255) { return SSDL_Color (r, g, b, a); }
#endif

