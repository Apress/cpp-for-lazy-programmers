//Program to do some things with ranged loops
//      -- from _C++ for Lazy Programmers_

#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

int main ()
{
    //printing sequences using range-based for-loops
    cout << "Just going to print some sequences:\n";

    vector<string> myVector = { "Somewhat Competent Boy", "Amazing Girl",
                                "Superpolite Man", "Wunderkind" };
    for (vector<string>::const_iterator i = myVector.begin();
        i != myVector.end();
        ++i)
        cout << *i << ' ';
    cout << endl;

    for (const string& i : myVector)   //a "range-based" for-loop
        cout << i << ' ';
    cout << endl;
    int myArray[] = { 0,1,2,3 };
    for (int  i : myArray)  cout << i << ' '; cout << endl;
    for (auto i : myVector) cout << i << ' '; cout << endl;
                                       //calls copy ctors needlessly
    for (auto i : myArray)  cout << i << ' '; cout << endl;

    cout << "Let's see that doubled:\n";
    for (auto& i : myArray)  i *= 2; 
    for (auto  i : myArray)  cout << i << ' '; cout << endl;
    for (const auto& i : myVector) cout << i << ' '; cout << endl;

    //Brings Somewhat Competent Boy to the front
    list<string> myList = {"Amazing Girl", "Superpolite Man",
                           "Somewhat Competent Boy", "Wunderkind" };
    for (auto i = myList.begin(); i != myList.end(); ++i) 
    {
        auto result = i->size();
        if (result > myList.front().size()) //if more than first item
            std::swap(*i, myList.front());  // move *i to front
    }
    cout << "This should be Somewhat Competent Boy, the longest name: "
        << myList.front() << endl;

    std::swap(myList.front(), myList.back());

    //Same thing again, but with ranged-based for-loop
    for (auto& item : myList)
        if (item.size() > myList.front().size())
            std::swap(item, myList.front());
    cout << "And again: " << myList.front() << endl;

    return 0;
}
