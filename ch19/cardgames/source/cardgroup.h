//CardGroup class (for playing cards)
//  -- from C++ for Lazy Programmers

#ifndef CARDGROUP_H
#define CARDGROUP_H

#include <iostream>

#include "card.h"

class OutOfRange  {};         //Exception classes
class IllegalMove {};   

class CardGroup
{
public:
    enum {MAX_SIZE = 208};    //if anybody wants to play a game
                              //  w/ more than 4 decks, change this.
    CardGroup ()                      { howMany_ = 0;              }
    CardGroup (const CardGroup& other){ *this    = other;          }
    CardGroup (const Card& other)     
    { 
        howMany_ = 0; addCard (other); 
    }

    const CardGroup& operator= (const CardGroup&);
    bool operator== (const CardGroup& other) const;
    bool operator!= (const CardGroup& other) const 
    {
        return !(*this == other);
    }

    Card& operator[] (unsigned int index);
    Card  operator[] (unsigned int index) const;

    Card remove         (unsigned int index);
    Card top            () const { return (*this)[size()-1];  }
    Card removeTop      ()       { return remove (size()-1);  }

    unsigned int size   () const { return howMany_;           }
    bool         isEmpty() const { return size() == 0;        }
    bool         isFull () const { return size() >= MAX_SIZE; }

    //addCard does NOT check that it's legal to add a card.
    //We need this for creating CardGroups during the deal. 
    void addCard (const Card&); 

    //makes sure the addition of the card is legal, then adds it
    void addCardLegally (const Card& other) 
    { 
        if (isFull ()) throw IllegalMove();
        addCard (other); 
    }
    
    void print (std::ostream&) const;

private:
    unsigned int howMany_;
    Card contents_ [MAX_SIZE];
};

inline
std::ostream& operator<< (std::ostream& out, const CardGroup& foo)
{ 
    foo.print(out); return out; 
}

using Hand = CardGroup;

#endif //CARDGROUP_H
