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

//This is SSDL_Font, a wrapper for TTF_Font

#include <string>
#include <cstring>
#include <sstream>
#include "SSDL_font.h"
#include "SSDL_exception.h"
#include "SSDL_display.h"

using namespace std;

class BooHoo
{
public:
	static BooHoo& Instance() { static BooHoo myBooHoo; return myBooHoo; }

	TTF_Font* currentFont() const { return currentFont_; }
	void setFont(TTF_Font* newFont) { currentFont_ = newFont; }
private:
	BooHoo()
	{
		currentFont_ = SSDL_OpenSystemFont("arial.ttf", 14);
		TTF_SetFontStyle(currentFont_, TTF_STYLE_BOLD);
	}
	TTF_Font* currentFont_;
};

//I should remember to TTF_CloseFont(newFont) in the dtor for SSDL_Font -- later.
//I'm so relieved it's no longer crashing on closing.


TTF_Font* SSDL_GetCurrentFont()
{
	return BooHoo::Instance().currentFont();
}
void SSDL_SetFont(TTF_Font* newFont) //WSB: test with const pointer too?
{
	BooHoo::Instance().setFont(newFont);
}

bool matchFromEnd (const char* str, const char* substr) //WSB 7-26-2016 not yet tested
{
    char* strEnd    = (char*) str+strlen(str)-1;
    char* substrEnd = (char*) substr+strlen(substr)-1;

    for (;;--strEnd, --substrEnd)
    {
        if (*substrEnd != *strEnd)  return false;

        if (substrEnd <= substr)    return true;
        else if (strEnd <= str)     return false;
    }
}

TTF_Font* SSDL_OpenFont (const char* filename, int point) //WSB: changed 7-26-2016 and not yet tested
{
	//WSB: How do I know that SDL has been opened?!  Better check!
	SSDL_Display::Instance();

    //We hope the filename ends in .ttf.  If not, and there's no extension, append it.
    //If not, and there is an (incorrect) extension, go ahead and append it, and watch it fail.

    string finalFilename = filename;
    if (! matchFromEnd (filename, ".ttf")) finalFilename += ".ttf";

	//SSDL_Display::Instance (); //be sure it's all set up BEFORE we try to load a font
	TTF_Font* result = TTF_OpenFont (finalFilename.c_str(), point);
	if (! result) throw SSDL_Exception ();
	return result;
}

/*TTF_Font* SSDL_OpenFont (const char* filename, int point)
{
	//WSB: How do I know that SDL has been opened?!  Better check!
	SSDL_Display::Instance();

	//Laura Mercy, what a lot of code just to check for file extension!
	enum {MAXLENGTH=5};
	char ext [5];
	if (_splitpath_s (filename, NULL, 0, NULL, 0, NULL, 0, ext, MAXLENGTH))
	{
		ostringstream os; os << "Could not extract extension from filename " << filename <<"; max length is " << MAXLENGTH-1;
		SDL_SetError (os.str().c_str());
		throw SSDL_Exception ();
	}

	//and if it's not there, add it.  I don't check for the WRONG one; SDL_TTF can do that
	string finalFilename = filename;
	if (strcmp (ext, "") ==0) finalFilename += ".ttf";

	//SSDL_Display::Instance (); //be sure it's all set up BEFORE we try to load a font
	TTF_Font* result = TTF_OpenFont (finalFilename.c_str(), point);
	if (! result) throw SSDL_Exception ();
	return result;
}*/


