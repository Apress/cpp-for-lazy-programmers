//Program to make a 5-point star in center of screen
//		-- from _C++ for Lazy Programmers_

#include <cmath>
#include "SSDL.h"							

int main(int argc, char** argv)
{
	const double PI = 3.14159;

	//Starting out with some generally useful numbers...

				//Can't initialize enums with functions or
				// calculations -- so must use const here
	const int CENTER_X = SSDL_GetWindowWidth() / 2; //center of screen
	const int CENTER_Y = SSDL_GetWindowHeight() / 2;
	enum { RADIUS = 200 };
	enum { NUMBER_OF_POINTS = 5 };

	//angle information...
	double angle = 0;			//angle starts at 0
	//const double ANGLE_INCREMENT = (2 / NUMBER_OF_POINTS) * PI;			//wrong!
	const double ANGLE_INCREMENT = (2 / double(NUMBER_OF_POINTS)) * PI;//right
								//increases by whole circle/5 each time

	//...now we make the successive lines
	int x, y;			//endpt of line (other endpt is center)

	x = CENTER_X + int(RADIUS * cos(angle));		//calc endpoint
	y = CENTER_Y + int(RADIUS * sin(angle));
	SSDL_RenderDrawLine(CENTER_X, CENTER_Y, x, y);	//draw line
	angle += ANGLE_INCREMENT;						//go on to next

	x = CENTER_X + int(RADIUS * cos(angle));		//calc endpoint
	y = CENTER_Y + int(RADIUS * sin(angle));
	SSDL_RenderDrawLine(CENTER_X, CENTER_Y, x, y);	//draw line
	angle += ANGLE_INCREMENT;						//go on to next

	x = CENTER_X + int(RADIUS * cos(angle));		//calc endpoint
	y = CENTER_Y + int(RADIUS * sin(angle));
	SSDL_RenderDrawLine(CENTER_X, CENTER_Y, x, y);	//draw line
	angle += ANGLE_INCREMENT;						//go on to next

	x = CENTER_X + int(RADIUS * cos(angle));		//calc endpoint
	y = CENTER_Y + int(RADIUS * sin(angle));
	SSDL_RenderDrawLine(CENTER_X, CENTER_Y, x, y);	//draw line
	angle += ANGLE_INCREMENT;						//go on to next

	x = CENTER_X + int(RADIUS * cos(angle));		//calc endpoint
	y = CENTER_Y + int(RADIUS * sin(angle));
	SSDL_RenderDrawLine(CENTER_X, CENTER_Y, x, y);	//draw line
	angle += ANGLE_INCREMENT;						//go on to next

	//end program
	SSDL_WaitKey();
	return 0;
}
