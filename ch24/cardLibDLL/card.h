//Card class
//  -- from C++ for Lazy Programmers

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include "cardsSetup.h"

namespace Cards
{
    //Rank and Suit:  integral parts of Card

    //I make these global so that I don't have to forget
    // "Card::" over and over when I use them.
    enum Rank { ACE = 1, JACK = 11, QUEEN, KING };
    enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
    enum Color { BLACK, RED };

    inline
        Color toColor(Suit s)
    {
        if (s == HEARTS || s == DIAMONDS) return RED; else return BLACK;
    }

    DECLSPEC std::ostream& operator<< (std::ostream& out, Rank  r);
    DECLSPEC std::ostream& operator<< (std::ostream& out, Suit  s);
    DECLSPEC std::istream& operator>> (std::istream& in, Rank& r);
    DECLSPEC std::istream& operator>> (std::istream& in, Suit& s);

    class BadRankException {};  //used if a Rank is out of range
    class BadSuitException {};  //used if a Suit is out of range

    //...and class Card.

    class Card
    {
    public:
        Card(Rank r = Rank(0), Suit s = Suit(0)) :
            rank_(r), suit_(s)
        {
        }
        Card(const Card& other) { *this = other; }

        const Card& operator= (const Card& other)
        {
            rank_ = other.rank(); suit_ = other.suit(); return *this;
        }

        bool operator== (const Card& other) const
        {
            return rank() == other.rank() && suit() == other.suit();
        }
        bool operator!= (const Card& other) const
        {
            return !(*this == other);
        }

        Suit  suit() const { return suit_; }
        Rank  rank() const { return rank_; }
        Color color() const { return toColor(suit()); }

        void print(std::ostream &out) const { out << rank() << suit(); }
        DECLSPEC void read(std::istream &in);
    private:
        Suit suit_;
        Rank rank_;
    };

    inline std::ostream& operator<< (std::ostream& out, const Card& foo)
    {
        foo.print(out); return out;
    }

    inline std::istream& operator>> (std::istream& in, Card& foo)
    {
        foo.read(in);  return in;
    }
}
#endif //CARD_H
