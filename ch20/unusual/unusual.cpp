//A little unusual use of class templates
//      -- from _C++ for Lazy Programmers_

#include <iostream>
#include <utility> 
#include <string>

using namespace std;

template <int SIZE>
class Stack		//Stack of chars with at most SIZE elements
{
public:
	//...
	bool full() const { return howMany_ >= SIZE; }
private:
	char contents_[SIZE];
	int  howMany_;
};

int main()
{
	pair<int, string> P (1, "C++ for Lazy Programmers");
	cout << "The number " << P.first << " C++ text EVER is " << P.second << "!\n";

	Stack<30> Stack;

	return 0;
}

