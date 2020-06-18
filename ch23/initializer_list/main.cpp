//Test initializer_list ctor/= for Vector
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
    Vector<string> FabFour = { "John","Paul","George","Ringo" };
    cout << "The Fab Four: " << FabFour << endl;

    //Try another base type, and test initializer_list ctor and =
    Vector<int> V = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    cout << "[1...10] I hope: " << V << endl;
	Vector<int> U; U = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	assert(V == U);

    return 0;
}

