//Program to demonstrate factorials
//     -- from _C++ for Lazy Programmers_

#include <iostream>

using namespace std;

unsigned long long factorial (unsigned n) 
{
    if (n == 0) return 1;
    else return n * factorial (n-1);
}

int main ()
{
    cout << "The factorial of 3 is " << factorial (3) << endl;

    return 0;
}
