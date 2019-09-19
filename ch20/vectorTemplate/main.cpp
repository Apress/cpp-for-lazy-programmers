//Example with a Vector of string
//      -- from _C++ for Lazy Programmers_

#include <iostream>
#include <cassert>
#include <string>
#include "vector.h"

using namespace std;

//Used to test move ctor/=
template<typename T>
Vector<T> makeVectorToTestMoveCtor(const T& e) 
{ 
	Vector<T> V; V.push_back(e); return V; 
}

int main ()
{
    //Setting up the band...
    Vector<string> FabFour; 
    string names[] = { "John","Paul","George","Ringo" };
    enum { NUM_BEATLES = 4 };

    for (int i = 0; i < NUM_BEATLES; ++i) 
		FabFour.push_back(names[i]);

    cout << "The Fab Four: " << FabFour << endl;

    //Trying other base types...
    Vector<int> V; for (int i = 1; i < 11; ++i) V.push_back(i);
    Vector<Vector<double>> Grid;

    //Still some testing code
    Vector<int> W (V); assert (W==V);
    V[0] = 10;         assert (W!=V); assert(V[0]==10);
    V = W;             assert (W==V); 

	V = makeVectorToTestMoveCtor(5);
	    //test by tracing in debugger, that it really calls it

    return 0;
}

