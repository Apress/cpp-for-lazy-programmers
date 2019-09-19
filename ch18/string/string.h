//String class
//      -- from _C++ for Lazy Programmers_

#ifndef STRING_H
#define STRING_H

#include <cstring> //uses cstring functions all over

#ifdef _MSC_VER
#pragma warning (disable:4996) //Disable a warning about strcpy, etc.,
#endif                         //  in Visual Studio

class String 
{
public:
    enum {BIGGEST_READABLE_STRING_PLUS_ONE   = 256};
                              //biggest string we can read, incl '\0'

    String (const char* other="") 
    { 
        copy(other);             
    }
    String (const String &other) : String (other.c_str())   {}
                              //a "delegated" ctor
    ~String()                 {  if (contents_) delete [] contents_; }
    String (String&& other)   //move ctor
    {
        contents_ = other.contents_; 
        other.contents_ = nullptr;
    }
     
    //access function
    
    const char* c_str() const { return contents_;         }  

    //other functions, not operators
    
    int       size () const   { return (int) strlen (c_str()); }
                              //Inefficient! Is there a better way?
    bool operator! () const   { return ! size();               } 

    //comparison operators

    bool operator< (const String& other) const
    {
        return strcmp (c_str(), other.c_str()) <  0;
    }
    bool operator> (const String& other) const
    {
        return strcmp (c_str(), other.c_str()) >  0;
    }
    bool operator<= (const String& other) const
    {
        return strcmp (c_str(), other.c_str()) <= 0;
    }
    bool operator>= (const String& other) const
    {
        return strcmp (c_str(), other.c_str()) >= 0;
    }
    bool operator== (const String& other) const
    {
        return strcmp (c_str(), other.c_str()) == 0;
    }
    bool operator!= (const String& other) const 
    { 
        return ! (*this == other); 
    }

    //assignment and concatenation

    const String& operator=  (const String& other);
    const String& operator=  (String&&      other); //move =
    const String& operator+= (const String& other);
    String        operator+  (const String& other) const
    {
        String result = *this; 
        result += other; 
        return result;
    }

    //[] and substring
    
    char  operator[] (int index) const { return contents_[index]; }
    char& operator[] (int index)       { return contents_[index]; }

    String operator () (int start, int finish) const;

    //I/O functions
    void read  (std::istream& in ); 
    void print (std::ostream& out) const{ out << c_str();        }
private:
    char* contents_;
    void copy(const char* str);
};

inline
std::istream& operator>> (std::istream& in, String& foo)
{
    foo.read (in); return in;
}

inline
std::ostream& operator<< (std::ostream& out, const String& foo)
{
    foo.print(out); return out;
}
#endif //STRING_H
