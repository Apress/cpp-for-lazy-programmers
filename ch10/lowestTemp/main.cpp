//Program to read in and print back out numbers 
//              -- from _C++ for Lazy Programmers_

#include "SSDL.h"

enum { MAX_NUMBERS = 10 };
double lowestTemp(      double temperatures[MAX_NUMBERS]);
double minimum   (const double elements[], int arraySize);

int main (int argc, char** argv)
{
    sout << "Enter " << MAX_NUMBERS
         << " temperatures to make your report.\n\n"; 

    double temperatures[] = { 32.6, 32.6, 32.7, 32.7, 32.7,
                              32.7, 32.7, 32.7, 32.7, 32.7 };

    //Print the numbers
    sout << "The lowest temp in the initializer list is " 
         //<< lowestTemp(temperatures) << ".\n";
         << minimum   (temperatures, MAX_NUMBERS) << ".\n";
         //minimum: more versatile than lowestTemp; see Chapter 10

    sout << "\nHit any key to end.\n";

    SSDL_WaitKey ();

    return 0;
} 

double lowestTemp(double temperatures[MAX_NUMBERS])
//returns lowest entry in temperatures
{
    double result = temperatures[0];

    for (int i = 0; i < MAX_NUMBERS; ++i)
        if (temperatures[i] < result)
            result = temperatures[i];

    return result;
}

double minimum(const double elements[], int arraySize)
//returns lowest entry in elements
{
    double result = elements[0];

    for (int i = 0; i < arraySize; ++i)
        if (elements[i] < result)
            result = elements[i];

    return result;
}

