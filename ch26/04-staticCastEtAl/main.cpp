//Program to test built-in cast operators
//        -- from _C++ for Lazy Programmers_

#include <iostream>
#include <string>
#include <vector>

//For some game, a class of cards...
class Card 
{
public:
    Card ()            = default;
    Card (const Card&) = default;
    Card(const std::string& s) : front_(s) {};
    
    virtual void print (std::ostream&) const;
private:
    std::string front_;
};

inline std::ostream& operator<< (std::ostream& out, const Card& foo)
{
    foo.print(out); return out;
}

void Card::print(std::ostream& out) const { out << front_;  }

//...some of which have a flip side
class GridCard: public Card
{
public:
    GridCard() : isFaceUp_(true) {}
    GridCard(const GridCard&) = default;
    GridCard(const std::string& f, const std::string& b) :
        Card(f), back_(b), isFaceUp_(true)
        {
        }

    void flip    ()       { isFaceUp_ = ! isFaceUp_; }
    bool isFaceUp() const { return isFaceUp_; }
    void print   (std::ostream&)const;
private:
    bool isFaceUp_;
    std::string back_;
};

void GridCard::print(std::ostream& out) const
{
	if (isFaceUp_) out << back_; else Card::print(out);
}

void display    (const std::vector<Card*> cards); //display the cards
void setFaceDown(const GridCard* c);              //set c face down
         //really should be a member; looking for ways to screw up const_cast

using namespace std;

int main ()
{
    vector<Card*> spaceRace;
    spaceRace.push_back(new     Card("1956"));
    spaceRace.push_back(new GridCard("1957","Sputnik launched"));
    spaceRace.push_back(new     Card("1958"));
    spaceRace.push_back(new GridCard("1959","First photo of far side of moon"));
    spaceRace.push_back(new     Card("1960"));

    //Fun with static_cast
    double myDouble = 0.0;
    int x = static_cast<int> (myDouble); //not req'd, but makes things clearer
    
    GridCard* c = static_cast<GridCard*> (spaceRace[1]); //no problem
    c->flip ();
    static_cast<GridCard*>(spaceRace[3])->flip ();       //no problem
    //static_cast<GridCard*>(spaceRace[0])->flip ();     //yes, problem
    //paceRace[0] isn't a GridCard
    // the compiler won't detect this -- *we* have to
    
	//float floatArray[20];
	//int* intArray = static_cast<int*>(floatArray);     //absolutely no way!

    cout << "Here's the cards: ";
    display(spaceRace);                  //function uses static_cast

    //Fun with const_cast

    cout << "Prints 1957 twice: ";
    const_cast<const GridCard*> (c)->print(cout);   //adds constness
    cout << ' ';
    c->print(cout);         // ...but this line shows it's not needed
    cout << '\n';

    const GridCard anotherGridCard("1969", "One small step for man...");
    //const_cast<GridCard*> (&anotherGridCard)->flip(); //"undefined behavior"
          //...because anotherGridCard is constant and can't be altered

    return 0;
}

void display (const vector<Card*> cards)
{
    for (auto c: cards)
        cout << *c << ' ';
    
    cout << '\n';
}

void setFaceDown(const GridCard* c)
{
    //if (c->isFaceUp()) c->flip();     //Can't: c is const
    //if (c->isFaceUp()) const_cast<GridCard>(*c)->flip();
                      //Can't cast ordinary variable -- pointer would work

    if (c->isFaceUp()) const_cast<GridCard*>(c)->flip();
                     //Yes, that'll work. But a better solution
                     //is to pass c in without the const qualifier!
}
