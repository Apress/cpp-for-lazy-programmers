//Deck class
//  -- from C++ for Lazy Programmers

#include "stdafx.h"
#include <cstdlib> //for rand
#define IM_COMPILING_MY_CARD_LIBRARY_RIGHT_NOW  
                   //see setup.h. Must come before card 
                   // related includes, after "stdafx.h" if any
#include "deck.h"

using namespace std;

namespace Cards
{
	DECLSPEC Deck::Deck()
	{
		for (int s = HEARTS; s <= SPADES; ++s)
			for (int r = ACE; r <= KING; ++r)
				addCard(Card(Rank(r), Suit(s)));
	}

	DECLSPEC void Deck::shuffle()
	{
		/* WSB: give an explanation -- or omit!*/

		for (int j = size() - 1; j > 0; --j)
		{
			int newLoc = rand() % (j + 1);
			swap((*this)[j], (*this)[newLoc]);
		}
	}
}

