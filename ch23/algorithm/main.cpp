//Program to use find, copy, sort, copy_if
//       -- from _C++ for Lazy Programmers_

#include <vector>
#include <list>
#include <algorithm>
#include <cassert>
#include <iterator> //for ostream_iterator
#include <iostream>

using namespace std;

bool isEven (int i) { return i % 2 == 0; }

int main()
{
    //Try out find
    vector<int> digits  = { 9,2,1,7,4,3,8,6,5 };
    auto i = find(digits.begin(), digits.end(), 7);
    assert(i != digits.end()); //7 should be there!

    //Now copy
    vector<int> newContainer;
    copy(digits.begin(), digits.end(), back_inserter(newContainer));
    assert(digits == newContainer);

    //Now sort
    sort(digits.begin(), digits.end());

    //Now copy_if. Moving between containers is fine.
    list<int> evens;
    copy_if(digits.begin(), digits.end(), back_inserter(evens), isEven);

    //Now copy for print
    cout << "This should be 2 4 6 8: ";
    copy(evens.begin(), evens.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //This is a Bad Idea:
    
    //for (auto i = digits.begin(); i != digits.end(); ++i)
    //    if (isEven(*i))
    //        digits.erase (i);           //erase element referenced by i

    //But this isn't:
    //for (auto i = digits.begin(); i != digits.end(); ) //no ++ here!
    //   if (isEven(*i))
    //      i = digits.erase (i);     //erase *i, and let i go on to the next
    //   else
    //      ++i;
      
    //Nor this:
    digits.erase (remove_if (digits.begin(), digits.end(), isEven), digits.end());

	cout << "This should be 1 3 5 7 9: ";
	copy(digits.begin(), digits.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
    return 0;
}
