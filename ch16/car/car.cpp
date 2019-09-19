//Class Car
//  -- from _C++ for Lazy Programmers_

#include <cstring>
#include "car.h"

#ifdef _MSC_VER                 //If using Microsoft Visual Studio, then
#pragma warning (disable:4996)  //disable "strcpy deprecated" warning
#endif

int Car::numCars_ = 0;              //initialize the number of Cars to 0

Car::Car(int theYear, const char* theMake, const char* theModel) :
    year_(theYear)
{
    strcpy(make_, theMake); strcpy(model_, theModel);buy();
}
