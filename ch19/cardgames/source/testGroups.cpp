//Test CardGroup, Waste, Cell, Deck
//  -- from C++ for Lazy Programmers

#include <iostream>
#include <cstdlib> //for srand
#include <ctime>   //for time
#include <cassert> //for assert
#include "deck.h"
#include "waste.h"
#include "cell.h"

using namespace std;

int main ()
{
    srand ((unsigned int) (time (nullptr)));

    //CardGroup
    //Test isFull, isEmpty
    CardGroup group1;
    assert (! group1.isFull()); assert (group1.isEmpty());
    for (int i = 0; i < CardGroup::MAX_SIZE; ++i)
        group1.addCardLegally (Card ());
    try
    {
        group1.addCardLegally (Card());
        cout << "addCardLegally's not finding an error.\n";
    }
    catch (const IllegalMove&) {}
    assert (group1.isFull()); assert (! group1.isEmpty());
    //Test copy ctor, =, ==, !=
    CardGroup group2 = group1; assert (group1 == group2); 
    assert (group1 != CardGroup());

    CardGroup CG1 (Card (ACE, SPADES));        //Test ctors, ==, and !=
    assert (CG1.top () == Card(ACE,SPADES));   
    Hand CG2 = CG1;                            //Hand == CardGroup
    assert (CG1 == CG2); assert (! (CG1 != CG2));

    CG1.addCardLegally (Card (ACE, DIAMONDS)); //Test size, =, ==, and !=
    assert(CG1.top () == Card(ACE,DIAMONDS));  //addCardLegally
    assert (CG1.size() == 2);   
    assert (! (CG1 == CG2));
    assert (CG1 != CG2);
    CG2 = CG1;
    assert (CG1 == CG2);
    assert (! (CG1 != CG2));

    //should I do this, or addCard, or add to top?      
    assert (CG1[1]     == Card(ACE, DIAMONDS));//Test +=, size, [], and top

    CG2.remove (0);                     //Test remove
    assert (CG2.top () == Card (ACE, DIAMONDS));

    CG1.removeTop ();                   //Test removeTop
    assert (CG1.top () == Card (ACE, SPADES));
    CG1.removeTop ();
    try 
    { 
        CG1.removeTop (); 
        cout << "Error: removeTop should've thrown an exception.\n";
    } 
    catch (const OutOfRange&) { }

    //Test waste
    Waste waste; 
    Waste w1 (waste);     assert (w1 == waste);
    
    //Test Cell
    Cell cell;
    cell.addCardLegally (Card (Rank(2), CLUBS));
    try
    {
        cell.addCardLegally (Card());
        cout << "Error: added a second card to a cell!\n";
    }
    catch (const IllegalMove&) {}

    Cell c1 = cell;      assert (c1 == cell);
    assert (c1.isFull ());
    assert (! c1.Waste::isFull ());
	cout << "This is 2 of clubs: " << cell << endl;;
    cell.removeTop ();
    try
    {
        cell.top ();
        cout << "Error: can't look at top of empty cell!\n";
    }
    catch (const OutOfRange&) {}
    
    //Test shuffle, printing
    Deck deck;

    cout << "An unshuffled deck:  " << deck << endl;
    deck.shuffle();
    cout << "A shuffled deck:     " << deck << endl;

    //Test dealing
    cout << "Now I'll take the top 3 cards and put them into the waste.\n";
    for (int i = 0; i < 3; ++i)
    {
        Card c = deck.deal (); cout << c << endl; waste.addCardLegally (c);
    }
    cout << "This is the waste:     " << waste << endl;
    cout << "And this is the deck:  " << deck  << endl;


    cout << "If no errors were reported, testGroups "
        "must have succeeded!\n";

    return 0;
}
