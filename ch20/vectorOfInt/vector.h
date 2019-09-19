//Vector class:  a variable-length array of ints
//  -- from _C++ for Lazy Programmers_

#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
public:
    class OutOfRange {};    //exception, for [] operators

    Vector () { contents_ = new int[0]; howMany_ = 0; }
    Vector (const Vector& other) { copy (other);      }
	Vector (Vector&& other);                       //move ctor
    ~Vector() { if (contents_) delete [] contents_;   }

	const Vector& operator= (const Vector& other);
	const Vector& operator= (Vector&&      other); //move =

    bool operator== (const Vector& other) const;
    bool operator!= (const Vector& other) const
    {
        return !((*this) == other);
    }

    unsigned int size () const { return howMany_;      }

    int  operator[] (unsigned int index) const;
    int& operator[] (unsigned int index);

    void push_back  (int newElement); //add newElement at the back
    
    void print (std::ostream&) const;
private:
    int* contents_;
    unsigned int howMany_;

    void copy (const Vector& other);
};

inline
std::ostream& operator<< (std::ostream& out, const Vector& foo)
{
    foo.print(out); return out;
}

#endif //VECTOR_H
