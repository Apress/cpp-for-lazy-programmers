//Card class tester using constexpr and static_assert
//  -- from C++ for Lazy Programmers

#include <iostream>
#include <cassert> 
#include "card.h"

using namespace std;

int main ()
{
    constexpr double PI = 3.14159;

    //Test some Card functions...
    constexpr Card ACE_OF_SPADES(ACE, SPADES);
    constexpr Card COPY_OF_ACE_OF_SPADES(ACE_OF_SPADES);

    static_assert (ACE_OF_SPADES ==COPY_OF_ACE_OF_SPADES, 
                   "Copy ctor or == failed");
    static_assert (COPY_OF_ACE_OF_SPADES.rank() == ACE && 
                   COPY_OF_ACE_OF_SPADES.suit() == SPADES,
                   "Copy ctor or access functions failed");
    static_assert (toColor(SPADES) == BLACK,
                   "toColor failed");
    static_assert (COPY_OF_ACE_OF_SPADES.color() == BLACK,
                   "Card::color failed");

    static_assert (JOKER.rank() == Rank(-1) && JOKER.suit() == Suit(-1),
                   "JOKER access functions or initializations failed");

    //Now without things being constexpr
    Card someCard;
    assert(someCard == Card(Rank(0), Suit(0)));
    assert(someCard != ACE_OF_SPADES);
    someCard         = ACE_OF_SPADES;
    assert(someCard == ACE_OF_SPADES);

    cout << "Enter 3 cards, using S for spades, H for hearts, etc.\n"
         << "E.g. KS, 10H, 2C.  You can enter bogus ones like 12H or 5X.\n"
         << "Use 0 for 10.\n";

    //Test I/O, and exception throwing
    enum { INPUT_TRIALS = 3 };
    for (int i = 0; i < INPUT_TRIALS; ++i)
        try
        {
            Card inputCard;
            cout << "? ";
            cin >> inputCard;
            cout << "You entered " << inputCard << endl;
        }
        catch (const BadRankException&)
        {
            cout << "The rank is invalid.\n";
        }
        catch (const BadSuitException&)
        {
            cout << "The suit is invalid; rank may be bad too.\n";
        }

    cout << "\nIf there are no unexpected error messages, "
         << "it looks like class Card is working!\n";

    return 0;
}
