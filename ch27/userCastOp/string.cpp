//class String, for char arrays
//  -- from _C++ for Lazy Programmers_

#include <cstring>
#include <iostream>
#include "string.h"

#pragma warning (disable:4996)  //prevent deprecation warnings 
                                //about strcpy, strcat, strlen
using namespace std;

void String::copy (const char* other) 
{
    contents_ = new char [strlen(other)+1]; 
        //The "+1" is room for final '\0'
    strcpy (contents_, other);
}

int String::size () const   { return strlen (contents_);}

const String& String::operator+= (const String& other)
{
    char* temp = contents_;

    contents_ = new char [size() + other.size() + 1]; 
            //1 extra space at the end for the null char

    strcpy (contents_, temp);
    strcat (contents_, other.c_str());

    delete [] temp;

    return *this;
}

char String::operator[] (int index) const
{
    if (index >= size ())
    {
        cout    << "Error in operator[]:  index " 
                << index << "is out of range.  It should be under "
                << size () << ".\n";
        return contents_[0]; //We gotta return something
    }
    else return contents_[index];
}

char& String::operator[] (int index)
{
    if (index >= size ())
    {
        cout    << "Error in operator[]:  index " 
                << index << "is out of range.  It should be under "
                << size () << ".\n";
        return contents_[0]; //We gotta return something
    }
    else return contents_[index];
}

String String::operator () (int start, int finish) 
{
    if (start >= size())
    {
        cout    << "Error in String::operator (int start, int finish):  "
                << "start (" << start << ") is out of range.  "
                << "It should be under "
                << size () << ".\n";
        return ""; //We gotta return something
    }

    if (finish >= size())
    {
        cout    << "Error in String::operator (int start, int finish):  " 
                << "finish (" << finish << ") is out of range.  "
                << "It should be under "
                << size () << ".\n";
        return ""; //We gotta return something
    }

    //This constructs the substring
    String result = *this;
    strcpy (result.contents_, contents_+start);
                //contents_+start is the char array that is "start"
                //  characters after contents_ begins
    result.contents_[finish-start+1] = '\0'; 
                //the number of chars in this sequence 
                //  is the difference plus 1

    return result;
}

