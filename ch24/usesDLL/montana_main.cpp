//A game of Montana solitaire
//  -- from C++ for Lazy Programmers

#include <cstdio>       //for srand, rand
#include <ctime>        //for time
#include "io.h"         //for bool getAnswerYorN (const char[]);
#include "montana.h"

int main ()
{
	srand ((unsigned int) time (nullptr)); //start rand# generator

    Montana montanaGame;

    do
        montanaGame.play ();
    while (getYorNAnswer ("Play again (Y/N)? "));

    return 0;
}

