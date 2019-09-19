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

//#include <SDL.h>
//#include <SDL_ttf.h>
//#include <SDL_image.h>
#include <string>
#include "SSDL.h"

int main (int argc, char** argv)
{
	try
	{   
		SSDL_SetFont (SSDL_OpenSystemFont("cour.ttf", 32));  //Courier New
								//If this font is not found, you can change it, or (on Unix) install 
								//Microsoft's Core Fonts for the Web
 
			//Screen 1:  some console interaction, and fonts

		SSDL_SetRenderDrawColor (WHITE);
		SSDL_SetRenderEraseColor (BLUE);

		sout << "Black screen, but blue color if\nyou backspace over an area.\n\n";
								//Backspacing won't work neatly for variable-width fonts -- not supported
		int X = 2;
		std::string S;

		sout << "Enter a string:  ";
		ssin >> S;
		sout << "You entered " << S << std::endl;

		sout << "Enter an int:  ";
		ssin >> X;
		sout << "You entered " << X << std::endl;

		sout << "Click to continue.\n";
		SSDL_WaitMouse ();

			//Screen 1:  showing some images

		SSDL_SetRenderEraseColor(RED);
		SSDL_RenderClear ();
		SSDL_SetRenderDrawColor (WHITE);

		SSDL_Image image = SSDL_LoadImage("../test/egore911-Pointer-small.png");
		{
			const SSDL_Image COPY = image;			//test copy ctor, non-const to const
			SSDL_Image secondCopy = COPY;			// and back
			secondCopy = COPY;						// and operator =
			SSDL_RenderImage (COPY, 0, 0);			//Show an image
			SSDL_RenderImage (secondCopy, 0, 0);	// (and same, at same location)
		}

		//Will destructing images in order not created will cause havoc?
		SSDL_Image yo;
		{
			SSDL_Image funkyTown = SSDL_LoadImage("../test/egore911-Pointer-small.png");
			yo = funkyTown;
		}
		//If you got this far, it didn't.  

		SSDL_RenderImage (yo,     40,  40);			//Show 2 more images
		SSDL_RenderImage (image, 100, 100); 

		SSDL_RenderText ("Red screen; click to continue.\nMusic will start...", 0, 50); 
		SSDL_WaitMouse();

				//Screen 3:  sound

		SSDL_RenderClear (BLACK);
		SSDL_SetCursor (0, 0);

		sout << "Black screen.\n\ntab\tthen slash-n\nthen slash-r\rthen nothing.\n";

		SSDL_Music music;
		music = SSDL_LoadMUS ("../test/457729__razor5__boss-battle-2-0.wav");
		SSDL_PlayMusic (music);

		sout << "Click mouse to continue";

		SSDL_WaitMouse();

			//Screen 4:  end the program; test some polling

		SSDL_RenderClear();

		bool mouseClicked = false;

		while (SSDL_IsNextFrame ())
		{
			SDL_Event event;
			while (SSDL_PollEvent (event))
			{
				switch (event.type)
				{
				case SDL_QUIT:			  SSDL_DeclareQuit(); break;
				case SDL_KEYDOWN:		  if (SSDL_IsKeyPressed (SDLK_ESCAPE)) SSDL_DeclareQuit(); break;
				case SDL_MOUSEBUTTONDOWN: mouseClicked = true; break;
				}
			}

			SSDL_RenderClear ();				//Show end of program essage
			SSDL_SetRenderDrawColor (WHITE);
			SSDL_SetCursor(0, 0);
			sout << "Hit Esc or kill window to quit.\n";

			if (mouseClicked)
				sout << "I didn't say click the mouse,\nbut OK!\n";
		}
	}
	catch(const SSDL_Exception&)				//Did anything go wrong?  If so, report
	{
		const char* errorString = SDL_GetError ();
		if (errorString[0] != '\0') //if there's an error
					SDL_ShowSimpleMessageBox (SDL_MESSAGEBOX_ERROR, "SDL Error", SDL_GetError (), NULL);
	}

	return 0;
}