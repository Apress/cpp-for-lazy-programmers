//Driver program to test the String class
//  -- from _C++ for Lazy Programmers_

#include <iostream>
#include <cassert>  //for assert, a function which crashes 
                        //  if the condition you give is false
                    //used for debugging
#include <cstring>
#include "string.h"

using namespace std;

bool isPalindrome(const char* a) //Is it same backwards as forwards?
{
    int len = strlen(a);

    for (int i = 0, j = strlen(a) - 1; i < j; ++i, --j)
        if (a[i] != a[j])
            return false;

    return true;
}

int main ()
{
    //Testing that cast operator
    String M = "madam", N = "neon";
    assert(isPalindrome((const char*)M)); assert(!isPalindrome((const char*)N));

    String empty;   
    String abc ("abc");
    String str1 ("def");
    String str2 ("def");

    //Testing default ctor, conversion ctor from char*, ==, and != ...
    if (str1 == "END")
        cout << "Looks like we've reached the END.\n";

    assert (empty == "");   
    assert (! empty);   
    assert (! (empty != ""));
    assert (abc != "");     assert (! (abc == ""));
                            //assert (abc) calls (and negates) the ! operator
    //Testing c_str, size ...
    assert (strcmp (abc.c_str(), "abc") == 0);
    assert (abc.size() == 3);

    //Test >, >=, <, <=, !=,  
    //Note that we're doing lots of automatic calls 
    // to conversion ctor from const char*
    // so that's tested too
    assert (abc <  "abd");  assert (! (abc >= "abd"));  
    assert (abc <= "abd");  assert (! (abc >  "abd"));
    assert (abc >  "abb");  assert (! (abc <= "abb"));
    assert (abc >= "abb");  assert (! (abc <  "abb"));
    assert (abc <= abc);    assert (abc >= abc);

    //Test both versions of []...
    assert (abc[1] == 'b');
    abc[1] = 'B';
    assert (abc[1] == 'B');
    abc[1] = 'b';

    //Testing copy ctor  ...
    String abcAlso (abc);
    assert (abc == abcAlso);

    //Testing + (and thereby +=); =; and the () operator for substrings
    String abcdef = "Initialized, but we're about to change it.";
    abcdef = abc+"def";
    assert (abcdef == "abcdef");
    assert (abcdef(1,4) == "bcde");

    //Testing << and >>
    String input;
    cout << "Enter a string:\t"; cin >> input;
    cout << "You entered:\t" << input << endl;

    cout << "If no errors were reported, "
         << "class String seems to be working!\n";

    return 0;
}

