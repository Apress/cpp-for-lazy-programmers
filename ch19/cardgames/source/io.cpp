//I/O functions
//  -- from _C++ for Lazy Programmers_

#include <iostream>
#include "io.h"

using namespace std;

bool getYorNAnswer (const char question [])
{
    char answer;

    do
    {
        cout << question;
        cin  >> answer;
        answer = toupper (answer);
    }
    while (answer != 'Y' && answer != 'N');

    return answer == 'Y';
}
