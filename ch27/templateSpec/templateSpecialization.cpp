//Program to print a list of super-heroes
//      -- from _C++ for Lazy Programmers_

#include <iostream>
#include <string>
#include "vector.h"

using namespace std;

class Superhero
{
public:
    Superhero (const char* theName = "") : name_ (theName) {}

    void print (ostream& out ) const { out << name_; }
private:
    string name_;
};

inline
ostream& operator<< (ostream& out, const Superhero& foo)
{
    foo.print (out); return out;
}


template<>
void Vector<Superhero*>::print (ostream& out) const
{
    for (unsigned int i = 0; i < size(); ++i)
        out << *((*this)[i]) << '/';
}

int main ()
{
        //Can still print Vector<int> normally
    Vector<int> intVector; for (int i = 0; i < 10; ++i) intVector.push_back(i);
    cout << "Some #'s: " << intVector << endl;

        //Set up the superhero list
    Vector<Superhero*> superheroes;
    superheroes.push_back (new Superhero ("Somewhat Competent Boy"));
    superheroes.push_back (new Superhero ("Amazing Girl"));
    superheroes.push_back (new Superhero ("Superpolite Man"));
    superheroes.push_back (new Superhero ("Wunderkind"));

        //Print the superhero list
    cout << "The superheroes of Yokohama:  " << superheroes << endl;

        //Clean up memory
    for (unsigned int i = 0; i < superheroes.size(); ++i)
        delete superheroes[i];

    return 0;
}
