//Card class
//  -- from C++ for Lazy Programmers

#ifndef CARD_H
#define CARD_H

#include <iostream>

//Rank and Suit:  integral parts of Card

//I make these global so that I don't have to forget
// "Card::" over and over when I use them.
enum Rank {ACE=1, JACK=11, QUEEN, KING};
enum Suit {HEARTS, DIAMONDS, CLUBS, SPADES};
enum Color{BLACK, RED};

std::ostream& operator<< (std::ostream& out, Rank r);
std::ostream& operator<< (std::ostream& out, Suit s); 
std::istream& operator>> (std::istream& in, Rank& r);
std::istream& operator>> (std::istream& in, Suit& s);

class BadRankException {};  //used if a Rank is out of range
class BadSuitException {};  //used if a Suit is out of range

inline 
constexpr Color toColor(Suit s) 
{ 
    if (s == HEARTS || s == DIAMONDS) return RED; else return BLACK; 
} 

//...and class Card.

class Card
{
public:
    constexpr Card(Rank r=Rank(0), Suit s=Suit(0)) : rank_(r), suit_(s) {} 
                           //can't =default this; there IS no default for it
    constexpr Card            (const Card& other) = default;
    constexpr Card& operator= (const Card& other) = default;
    
    constexpr bool operator== (const Card& other) const
    { 
        return rank() == other.rank () && suit() == other.suit(); 
    }
    constexpr bool operator!= (const Card& other) const 
    { 
        return !(*this == other);
    }

    constexpr Suit  suit () const { return suit_; }
    constexpr Rank  rank () const { return rank_; }
    constexpr Color color() const
    { 
        return toColor(suit());
    }

    void print (std::ostream &out) const { out << rank() << suit(); }
    void read  (std::istream &in );
private:
    Suit suit_;
    Rank rank_;
};

inline std::ostream& operator<< (std::ostream& out, const Card& foo)
{
    foo.print (out); return out;
}

inline std::istream& operator>> (std::istream& in,        Card& foo)
{
    foo.read  (in);  return in;
}

inline 
constexpr Card JOKER(Rank(-1), Suit(-1));
                             //works in later implementations of C++17

#endif //CARD_H
