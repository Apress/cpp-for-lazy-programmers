//Program to produce an ALL CAPS version of a file
//      -- from _C++ for Lazy Programmers_

#include <iostream>
#include <cctype>             //for toupper

using namespace std;

int main ()
{
    while (cin)               //for each char in file
    {
                              //read in char and capitalize it
        char ch = cin.get(); ch = toupper (ch);
        //char ch;  cin >> ch; ch = toupper(ch); //nope -- skips whitespace
        if (cin) cout << ch;  //still no problems with cin? Then print
    }

    return 0;
}
