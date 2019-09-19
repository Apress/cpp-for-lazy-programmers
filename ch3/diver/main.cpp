//Program to draw the path of a diver
//		-- from _C++ for Lazy Programmers_

#include "SSDL.h"

int main(int argc, char** argv)
{
	SSDL_SetWindowTitle("Sploosh!  Hit a key to end");

	//Stuff about the board
	enum {BOARD_WIDTH = 60, BOARD_THICKNESS = 8, BOARD_INIT_Y =20};
	SSDL_RenderDrawRect(0, BOARD_INIT_Y,
		BOARD_WIDTH, BOARD_THICKNESS);

	//...the water
	enum { SKY_HEIGHT = 440 };
	SSDL_SetRenderDrawColor(BLUE);
	SSDL_RenderFillRect(0, SKY_HEIGHT,
		SSDL_GetWindowWidth(),
		SSDL_GetWindowHeight() - SKY_HEIGHT);
						  //height is 
						  //  window height - sky height

	//...the diver
	enum {WIDTH = 10, HEIGHT = 10};//Dimensions of the "diver"
	enum {DISTANCE_TO_TRAVEL = 20};//How far to go right each time
	enum {FACTOR_TO_INCREASE =  2};//Increase Y this much each time

	enum { INIT_X = 50, INIT_Y = 10 };
	int x = INIT_X;		  //Move diver to end of board
	int y = INIT_Y;		  //and just on top of it		

	const SSDL_Color DIVER_COLOR = SSDL_CreateColor(200, 150, 90);
	SSDL_SetRenderDrawColor(DIVER_COLOR);

	//Now draw several images, going down as if falling, and right
	//Remember x+=DISTANCE_TO_TRAVEL means x=x+DISTANCE_TO_TRAVEL
	//	...and so on

	SSDL_RenderFillRect(x, y, WIDTH, HEIGHT);
	x += DISTANCE_TO_TRAVEL;  //go right the same amount each time,
	y *= FACTOR_TO_INCREASE;  // down by an ever-increasing amount

					//Same thing repeated several times
	SSDL_RenderFillRect(x, y, WIDTH, HEIGHT);
	x += DISTANCE_TO_TRAVEL; y *= FACTOR_TO_INCREASE;

	SSDL_RenderFillRect(x, y, WIDTH, HEIGHT);
	x += DISTANCE_TO_TRAVEL; y *= FACTOR_TO_INCREASE;

	SSDL_RenderFillRect(x, y, WIDTH, HEIGHT);
	x += DISTANCE_TO_TRAVEL; y *= FACTOR_TO_INCREASE;

	SSDL_RenderFillRect(x, y, WIDTH, HEIGHT);
	x += DISTANCE_TO_TRAVEL; y *= FACTOR_TO_INCREASE;

	SSDL_RenderFillRect(x, y, WIDTH, HEIGHT);
	x += DISTANCE_TO_TRAVEL; y *= FACTOR_TO_INCREASE;

	//end program
	SSDL_WaitKey();
	return 0;
}
