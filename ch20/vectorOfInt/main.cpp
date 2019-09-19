//Example with a Vector of int
//      -- from _C++ for Lazy Programmers_

#include <iostream>
#include <cassert>
#include "vector.h"

using namespace std;

//Used to test move ctor/=
Vector makeVectorToTestMoveCtor(int e) 
{ 
	Vector V; V.push_back(e); return V; 
}

int main ()
{
    Vector V;

    for (int i = 1; i < 11; ++i) V.push_back (i);

    cout << "Can you count to 10?  The Count will be so proud!\n";
    
    cout << V << endl;

    Vector W (V); assert (W==V);
    V[0] = 10;    assert (W!=V); assert(V[0]==10);
    V = W;        assert (W==V);

	V = makeVectorToTestMoveCtor(5); 
	    //test by tracing in debugger, that it really calls it

    return 0;
}

