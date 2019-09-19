//Vector class:  a variable-length array
//      -- from _C++ for Lazy Programmers_

#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector
{
public:
    class OutOfRange {};    //exception, for [] operators

    Vector ()   { contents_ = new T[0]; howMany_ = 0; }
    Vector (const Vector& other) { copy (other);      }
    Vector (Vector&&      other);                  //move ctor

    ~Vector ()  { if (contents_) delete [] contents_; }

    const Vector& operator= (const Vector& other);
    const Vector& operator= (Vector&&      other); //move =

    bool operator== (const Vector& other) const;
    bool operator!= (const Vector& other) const
    {
        return !((*this) == other);
    }

    unsigned int size () const { return howMany_;     }

    const T& operator[] (unsigned int index) const;
          T& operator[] (unsigned int index);

    void push_back  (const T& newElement); //add newElement at the back
    
    void print (std::ostream&) const;
private:
    T* contents_;
    unsigned int howMany_;

    void copy (const Vector& other);
};

template <typename T>
inline
std::ostream& operator<< (std::ostream& out, const Vector<T>& foo)
{
    foo.print(out); return out;
}

template <typename T>
Vector<T>::Vector(Vector&& other)                   //move ctor
{
    contents_ = other.contents_;howMany_ = other.howMany_; 
    other.contents_ = nullptr;
}

template <typename T>
const Vector<T>& Vector<T>::operator= (Vector&& other) //move =
{
    if (contents_) delete[] contents_;
    contents_ = other.contents_; howMany_ = other.howMany_;
    other.contents_ = nullptr;
    return *this;
}

template <typename T>
bool Vector<T>::operator==(const Vector& other) const
{
    bool noDifferences = true;

    //quit if you find a difference or run out of elements
    for (unsigned int i = 0; i < size() && noDifferences; ++i)
        if ((*this)[i] != other[i]) noDifferences = false;

    return noDifferences;
}

template <typename T>
const Vector<T>& Vector<T>::operator= (const Vector& other)
{
    if (this == &other) return *this;
    if (contents_) delete[] contents_; copy(other);
    return *this;
}

template <typename T>
const T&  Vector<T>::operator[] (unsigned int index) const
{
    if (index >= size()) throw OutOfRange();
    else return contents_[index];
}

template <typename T>
      T&  Vector<T>::operator[] (unsigned int index)
{
    if (index >= size()) throw OutOfRange();
    else return contents_[index];
}

//add newElement at the back
template <typename T>
void Vector<T>::push_back(const T& newElement)
{
    T* newContents = new T[howMany_ + 1];     //make room for 1 more... 

    for (unsigned int i = 0; i < size(); ++i) //copy existing elements
                                              // into new array... 
        newContents[i] = contents_[i];

    newContents[howMany_] = newElement;       //add the new element... 

    ++howMany_;                               //remember we have one more... 

    delete[] contents_;                       //throw out old contents_
    contents_ = newContents;                  // and keep new version
}

//print Vector with []'s around it, spaces between
template <typename T>
void Vector<T>::print(std::ostream& out) const
{
    for (unsigned int i = 0; i < size(); ++i)
        out << (*this)[i] << '/';
}

template <typename T>
void Vector<T>::copy(const Vector& other)
{
    //set howMany to other's size; allocate that much memory
    contents_ = new int[howMany_ = other.size()];
    
    //then copy the elements over
    for (unsigned int i = 0; i < size(); ++i)
        contents_[i] = other[i];
}

#endif //VECTOR_H
