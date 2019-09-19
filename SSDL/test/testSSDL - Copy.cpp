//Super-Simple DirectMedia Layer library:  a test program
//Tests some things with fonts, ssin, sout, mouse I/O
//Will Briggs
//Fall 2012
//Released under ? License

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string>
#include "SSDL.h"

int main (int argc, char** argv)
{
	try
	{   
		SSDL_Font  fo = SSDL_OpenSystemFont ("cour.ttf", 32); //Courier New
		SSDL_SetFont (fo);
 
		SSDL_SetRenderDrawColor (WHITE);
		SSDL_SetRenderEraseColor (BLUE);

		sout << "Black screen, but blue color if\nyou backspace over an area.\n\n";
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

		//The following had no effect!  WSB
		//SSDL_Display::Instance().scrollVertically (SSDL_StreamIOSystem::Instance().fontLineSkip ());
		//SSDL_WaitMouse ();

		//SSDL_ToggleEscapeIsQuit ();
		SSDL_SetRenderEraseColor(RED);
		SSDL_RenderClear ();
		SSDL_SetRenderDrawColor (WHITE);
		SSDL_Image image = SSDL_LoadImage("../test/egore911-Pointer-small.png");
		{
			const SSDL_Image COPY = image;	//test copy ctor, non-const to const
			SSDL_Image secondCopy = COPY;	// and back
			secondCopy = COPY;				// and operator =
			SSDL_RenderImage (COPY, 0, 0);
			SSDL_RenderImage (secondCopy, 0, 0);
		}
		//Now test whether deleting them in order not created will cause havoc
		SSDL_Image yo;
		{
			SSDL_Image funkyTown = SSDL_LoadImage("../test/egore911-Pointer-small.png");
			yo = funkyTown;
		}
		//It didn't!  

		SSDL_RenderImage(yo, 40, 40);
		//Will this interfere with my use of something like for each img display img?  Shd I use image indices like DarkGDK?
		// No, because I do arrays almost as soon as I do for-loops.  Make this an exercise!
		SSDL_RenderImage (image, 100, 100); //put it at 10, 10

		SSDL_RenderText ("Red screen; click to continue.\nMusic will start...", 0, 50); 
		SSDL_WaitMouse();

		SSDL_RenderClear (BLACK);
		SSDL_SetCursor (0, 0);

		sout << "Black screen.\n\ntab\tthen slash-n\nthen slash-r\rthen nothing.\n";

		SSDL_Music music;
		music = SSDL_LoadMUS ("../test/457729__razor5__boss-battle-2-0.wav");
		SSDL_PlayMusic (music);

		sout << "Click mouse to continue";
		//SSDL_RenderPresent ();

		SSDL_WaitMouse();
		SSDL_RenderClear();

		bool mouseClicked = false;

		while (SSDL_IsNextFrame ())
		{
			SDL_Event event;
			while (SSDL_PollEvent (event))
			{
				switch (event.type)
				{
				case SDL_QUIT:    SSDL_DeclareQuit(); break;
				case SDL_KEYDOWN: if (SSDL_IsKeyPressed (SDLK_ESCAPE)) SSDL_DeclareQuit(); break;
				case SDL_MOUSEBUTTONDOWN: mouseClicked = true; break;
				}
			}

			SSDL_RenderClear ();
			SSDL_SetRenderDrawColor (WHITE);
			SSDL_SetCursor(0, 0);
			sout << "Hit Esc or kill window to quit.\n";
			if (mouseClicked)
				sout << "I didn't say click the mouse,\nbut OK!\n";
		}
	}
	catch(const SSDL_Exception&)
	{
		const char* errorString = SDL_GetError ();
		if (errorString[0] != '\0') //if there's an error
					SDL_ShowSimpleMessageBox (SDL_MESSAGEBOX_ERROR, "SDL Error", SDL_GetError (), NULL);
	}

	return 0;
}