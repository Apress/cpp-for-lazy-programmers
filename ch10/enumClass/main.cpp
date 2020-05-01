//Program to do some things with enum and enum class
//              -- from _C++ for Lazy Programmers_

#include "SSDL.h"

enum class Suit { CLUBS, DIAMONDS, HEARTS, SPADES }; //Playing card suit
enum class Rank { ACE = 1, JACK = 11, QUEEN, KING }; //Playing card rank

void print(Suit);

int main (int argc, char** argv)
{
    //using enum class Suit;
    //using enum class Rank;

    Suit firstCardSuit = Suit::HEARTS, secondCardSuit = Suit::SPADES;
                                          //Specifying "Suit::" is required
                                          // for enum class type
    Rank myRank = Rank (8);
    myRank = Rank(int(myRank) + 1);

    sout << "All possible cards:\n";
                                          //for all possible cards, do...
    for (int s = int(Suit::CLUBS); s <= int(Suit::SPADES); ++s) 
    {                                     //can't declare s as Suit; ++s
	                                  // wouldn't compile.
	                                  //Also, must cast to int explicitly
	for (int r = int(Rank::ACE); r <= int(Rank::KING); ++r)
	                                  //Same for declaring r as Rank
	{
	    //prints rank as 1, 2, ... 13 -- clunky
	    //But Exercise 3 fixes that
	    sout << r;
	    print(Suit(s));
	    sout << "...";
	}
	sout << '\n';
    }
                                
    int daysLeftTillVacation = int(Rank::QUEEN);
                                         //if you want to do this weird thing,
                                         //you must insist (by casting)

    myRank = Rank(14);                   //way weird, but C++ won't complain

    SSDL_WaitKey ();

    return 0;
} 

void print(Suit suit)
{
    switch (suit)
    {
    case Suit::CLUBS  :  sout << 'C'; break; 
    case Suit::DIAMONDS: sout << 'D'; break; 
    case Suit::HEARTS :  sout << 'H'; break;
    case Suit::SPADES :  sout << 'S'; break;
    default           :  sout << '?'; break; 
    }
}
