//Vector class:  a variable-length array of ints
//      -- from _C++ for Lazy Programmers_

#include <iostream>
#include "vector.h"

Vector::Vector(Vector&& other)                   //move ctor
{
	contents_ = other.contents_; howMany_ = other.howMany_;
	other.contents_ = nullptr; 
}

const Vector& Vector::operator= (Vector&& other) //move =
{
	if (contents_) delete[] contents_;
	contents_ = other.contents_; howMany_ = other.howMany_;
	other.contents_ = nullptr;
	return *this;
}

bool Vector::operator==(const Vector& other) const
{
    bool noDifferences = true;

    //quit if you find a difference or run out of elements
    for (unsigned int i = 0; i < size() && noDifferences; ++i)
        if ((*this)[i] != other[i]) noDifferences = false;

    return noDifferences;
}

const Vector& Vector::operator= (const Vector& other)
{
	if (this == &other) return *this;
	if (contents_) delete[] contents_; copy(other);
	return *this;
}

int  Vector::operator[] (unsigned int index) const
{
    if (index >= size ()) throw OutOfRange (); 
    else return contents_[index];
}

int& Vector::operator[] (unsigned int index) 
{
    if (index >= size()) throw OutOfRange();
    else return contents_[index];
}

//add newElement at the back
void Vector::push_back  (int newElement)      
{
    int* newContents = new int [howMany_+1];  //make room for 1 more... 

    for (unsigned int i = 0; i < size(); ++i) //copy existing elements
                                              // into new array... 
        newContents[i] = contents_[i];

    newContents[howMany_] = newElement;       //add the new element... 

    ++howMany_;                               //remember we have one more... 

    delete [] contents_;                      //throw out old contents_
    contents_ = newContents;                  // and keep new version
}

//print Vector with []'s around it, spaces between
void Vector::print (std::ostream& out) const  
{
    out << "[  ";

    for (unsigned int i = 0; i < size(); ++i)
        out << (*this)[i] << "  ";

    out << ']';
}

//Sort of like String::copy from Chapter 17, but w/o strcpy
void Vector::copy(const Vector& other)
{
    //set howMany to other's size; allocate that much memory
    contents_ = new int[howMany_ = other.size()];

    //then copy the elements over
    for (unsigned int i = 0; i < size(); ++i)
        contents_[i] = other[i];
}

