//Deck class
//  -- from C++ for Lazy Programmers

#ifndef DECK_H
#define DECK_H

#include "cardgroup.h"

namespace Cards
{
	class Deck : private CardGroup
	{
	public:
		enum { MAX_SIZE = 52 };

		Deck();
		Deck(const Deck& other) = delete;

		Card deal() { return removeTop(); }

		void shuffle();

		void print(std::ostream& out) const { CardGroup::print(out); }

		int  size() const { return CardGroup::size(); }
		bool isEmpty() const { return CardGroup::isEmpty(); }
		bool isFull() const { return CardGroup::isFull(); }
		void addCard(const Card& c) { CardGroup::addCard(c); }
	};

	inline
		std::ostream& operator<< (std::ostream& out, const Deck& foo)
	{
		foo.print(out); return out;
	}
}
#endif //DECK_H
