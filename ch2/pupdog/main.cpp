//Program that pastes two images onto a background
//		-- from _C++ for Lazy Programmers_

#include "SSDL.h"

int main(int argc, char **argv)
{
	//Set window parameters
	SSDL_SetWindowSize(400, 300);	//make a 400x300 window
	SSDL_SetWindowTitle("Pup dog and flamingo at the beach");

	//Load images
	const SSDL_Image BEACH		= SSDL_LoadImage("media/beach.jpg");
	const SSDL_Image FLAMINGO	= SSDL_LoadImage("media/flamingo.png");
	const SSDL_Image PUPPY		= SSDL_LoadImage("media/pupdog.png");

	//Paste in the background image, and the flamingo
	SSDL_RenderImage(BEACH, 0, 0);
	SSDL_RenderImage(FLAMINGO, 0, 175);	
							//I'll increase flamingo's size
							// from 81x100
							// to 81x120 -- make it taller
							// and move it a little (175->155)
							// just for grins
	SSDL_RenderImage(PUPPY, 320, 225, 50, 75); 
							//puppy goes on bottom right
							//She's bigger than I want, so I
							// make her 50x75. It's better to 
							// resize when making the image, but
							// this works too

	SSDL_WaitKey();

	return 0;
}

