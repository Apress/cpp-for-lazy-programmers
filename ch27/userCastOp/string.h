//String class
//  -- from _C++ for Lazy Programmers_

#ifndef STRING_H
#define STRING_H

class String 
{
public:
    enum {BIGGEST_READABLE_STRING                = 255};
                                            //biggest we allow to be read in
    enum {BIGGEST_READABLE_STRING_PLUS_ONE   = 256};
                                            //... plus one (used in read (istream&)

    String ()  { contents_ = new char[1]; contents_ [0] = '\0';     }
    String (const String &other)    { copy (other.contents_);   }
    String (const char* other)  { copy (other);                 }
    ~String ()                          { delete [] contents_;          }

    int size () const;

    const char* c_str() const       { return contents_;         }  
    explicit operator const char* () const  { return c_str ();          }

    bool operator! () const { return ! size(); } 
  
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

    const String& operator= (const String& other)
    {
        delete [] contents_; copy (other.c_str()); return *this;
    }
    const String& operator+= (const String& other);
    String operator+ (const String& other) const
    {
        String result = *this; result += other; return result;
    }

    //[] and substring
    char  operator[] (int index) const;
    char& operator[] (int index);

    String operator () (int start, int finish);

    //I/O functions
    void read  (std::istream& in)
    {
        char buffer [BIGGEST_READABLE_STRING_PLUS_ONE];

        in >> buffer;

        *this = buffer;
    }

    void print (std::ostream& out) const
    {
        out << c_str();
    }
private:
    char* contents_;

    void copy (const char* other);
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
