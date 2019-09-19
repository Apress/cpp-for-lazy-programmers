//Program that uses stringstream and
// reports what it got
//      -- from _C++ for Lazy Programmers_

#include <sstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int points  = 3200;      //Some arbitrary data to test
    double time = 30.2;      // printing to HUD
    char mood[] = "Annoyed";

    stringstream out;
    out << "Points: " << points << "   /   Time left: "
        << time << "   /   Mood: " << mood;
    
    cout << "\"" << out.str() << "\"\nhas " 
         << out.str().size () << " characters.\n";

    return 0;
}
