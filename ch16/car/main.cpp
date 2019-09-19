//A program that uses the Car class
//  -- from _C++ for Lazy Programmers_

#include "car.h"

using namespace std;

int main ()
{
    Car banzai (2020, "Ford",   "GT40");
    Car mudbug (1987, "Jeep",   "Wrangler");
    Car sport  (2000, "Toyota", "Corolla");

    cout << "Looks like we have " 
         << Car::numCars () << " cars in stock!" << endl;

    return 0;
}
