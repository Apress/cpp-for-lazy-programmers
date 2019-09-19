//Program which takes you through successive angles
//		in 30-degree increments
//		-- from _C++ for Lazy Programmers_

#include <cmath> //for sin, cos
#include "SSDL.h"

enum { LINE_LENGTH = 200};
enum { CENTER_X = 320, CENTER_Y = 240 };

const float PI = 3.14159F;

double degrees2Radians (double angle); //conversion
void   drawAngle       (double angle); //draw 2 lines, 
                                       //given angle between

int main (int argc, char** argv)
{
    SSDL_SetWindowTitle ("See some angles.  "
                         "Hit a key to go between frames.");

    double currentAngle = 0.0;
 
    while (! SSDL_IsQuitMessage () && currentAngle < 360.0)
    {
        static const double ANGLE_INCREMENT = 30.0;

        SSDL_RenderClear();        //clear screen
		
        SSDL_SetCursor (0, 0);     //draw angle
        sout << "Angle:  " << currentAngle << "\n";
        drawAngle (currentAngle); 
	
        SSDL_WaitKey ();           //wait for user
	
        currentAngle += ANGLE_INCREMENT;
                                  //go on to next angle
    }

    return 0;
}

//converts degrees to radians -- since 180 degrees = PI radians
double degrees2Radians (double angle) {	return angle * PI / 180; }

void drawAngle (double angle)
{
    //length of base of a right triangle is hypotenuse * cos(angle)
    //length of vertical is hypotenuse * sin (angle)
    //sin and cos expect radians, so we must convert
    int base     = int (LINE_LENGTH*cos(degrees2Radians (angle)));
    int vertical = int (LINE_LENGTH*sin(degrees2Radians (angle)));

    //draw horizontal line...
    SSDL_RenderDrawLine (CENTER_X, CENTER_Y, 
                         CENTER_X+LINE_LENGTH, CENTER_Y); 

    //then we'll add the base to the center X, to get the ending X
    //and we'll add the vertical to center Y, to get the ending Y

    //draw line elevated by given angle
    SSDL_RenderDrawLine (CENTER_X, CENTER_Y, 
                         CENTER_X+base, CENTER_Y-vertical);
    //Why -vertical, not +vertical?  Because positive y is down 
}
