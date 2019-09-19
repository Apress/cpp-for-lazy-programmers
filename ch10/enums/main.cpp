//Program to do some things with enum and enum class
//              -- from _C++ for Lazy Programmers_

#include "SSDL.h"

enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES }; //Playing card suit
enum Rank { ACE = 1, JACK = 11, QUEEN, KING }; //Playing card rank

void print(Suit);

int main (int argc, char** argv)
{
    Suit firstCardSuit = HEARTS, secondCardSuit = Suit::SPADES;
                                    //"Suit::" is optional for enum values
    Rank myRank = Rank (8);
    myRank = Rank(myRank + 1);

    sout << "All possible cards:\n";
                                          //for all possible cards, do...
    for (int s = CLUBS; s <= SPADES; ++s) //can't declare s as Suit; ++s
    {                                     // wouldn't compile.
        for (int r = ACE; r <= KING; ++r) //Same for declaring r as Rank
        {
            //prints rank as 1, 2, ... 13 -- clunky
            //But Exercise 3 fixes that
            sout << r;
            print(Suit(s));
            sout << "...";
        }
        sout << '\n';
    }
    
    int daysLeftTillVacation = QUEEN;   //weird, but C++ won't complain

    myRank = Rank(14);                  //way weird, but C++ won't complain

    SSDL_WaitKey ();

    return 0;
} 

void print(Suit suit) //prints a Suit
{
    switch (suit)
    {
    case CLUBS  :  sout << 'C'; break; 
    case DIAMONDS: sout << 'D'; break; 
    case HEARTS :  sout << 'H'; break;
    case SPADES :  sout << 'S'; break;
    default     :  sout << '?'; break; 
    }
}
