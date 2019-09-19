//Program to print temp, pressure for Venus and Earth
//      -- from _C++ for Lazy Programmers_

#include <iostream>
#include <memory>  //for unique_ptr
#include <cassert> //for assert
#include <cstring>
#include "date.h"

#ifdef _MSC_VER
#pragma warning (disable:4996) //Disable a warning about strcpy, etc.,
#endif                         //  in Visual Studio

using namespace std;

int main ()
{
    //Argument to make unique is initial value or ctor arguments
    std::unique_ptr<int >    p1 = std::make_unique<int>(27);
    //new int ptr, value 27
    std::unique_ptr<Date> pDate = std::make_unique<Date>(1, 1, 2000);
    //Put the arguments for Date's constructor in  
    //   and make_unique will take care of it

    //When it's a dynamic array, the argument is the size you want
    std::unique_ptr<char[]> myChars = std::make_unique<char[]>(100);

    //Some printing and testing

    *p1 = 2; cout <<"Printing 2: " << *p1 << endl;
    myChars[5] = 'A';
    assert(myChars[5] == 'A');

    cout << "Printing 1-1-2000: ";
    pDate->print(cout);
    cout << endl;

    strcpy(       myChars.get(), "totally unique");
    assert(strcmp(myChars.get(), "totally unique") == 0);

    //Test reset ()
    p1.reset(); //the memory is deleted, and p1 now thinks it's nullptr
    assert(p1.get() == nullptr);
    int* p = new int; *p = 27;
    p1.reset(p); 
    assert(*p1 = 27);
 
    return 0;
}
