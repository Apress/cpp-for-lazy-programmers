//class List:  a linked list class
//  from _C++ for Lazy Programmers_

#ifndef LIST_H
#define LIST_H

template <typename T>
class List
{
public:
    class Underflow {};                     //Exceptions
    class BadPointer{};

    List() { createEmptyList(); }
    List(const List <T>& other) : List() { copy(other); }
	List(List&&      other);                  //move ctor
	~List() { eraseAllElements(); delete start_; }
                                    //the elements, then the caboose

	const List& operator= (List&&      other); //move =
    const List <T>& operator= (const List <T>& other)
    {
        eraseAllElements(); createEmptyList(); copy(other);
        return *this;
    }

    bool operator== (const List <T>& other) const; //left as exercise earlier

    int  size () const { return size_;       }     //left as exercise earlier
    bool empty() const { return size() == 0; }

    void push_front(const T& newElement);  //add newElement at front
    void pop_front();                      //take one off the front
    const T& front() const                 //left as exercise earlier
    { 
        if (empty()) throw Underflow(); else return  (*start_).data_; 
    }

    void print(std::ostream&) const;       //left as exercise earlier
private:
    struct Entry
    {
        Entry() { next_ = nullptr;  }      //a good default
        T      data_;
        Entry* next_;
    };

    int    size_;
    Entry* start_;                         //Points to first element
    Entry* end_;                           //...and the caboose

    void copy(const List <T>& other);      //copies other's entries
                                           //  into this List

    void eraseAllElements();               //empties the list
    void createEmptyList()
    {
        start_ = end_ = new Entry; size_=0;//the list is...nothing
    }


public:
    class iterator                         //An iterator for List
    {
    public:
        iterator(const iterator& other)  : where_(other.where_) {}
        iterator(Entry* where = nullptr) : where_(where)        {}

        const iterator& operator= (const iterator& other)
        {
            where_ = other.where_;
        }

        bool operator== (const iterator& other) const
        {
            return where_ == other.where_;
        }
        bool operator!= (const iterator& other) const
        {
            return !((*this) == other);
        }

        const iterator& operator++()    //pre-increment, as in ++i
        {
            if (where_->next_ == nullptr) throw BadPointer();
            else where_ = where_->next_;
            return *this;
        }
        iterator operator++ (int)       //post-increment, as in i++
        {
            iterator result = *this; ++(*this); return result;
        }

        T& operator* ()
        {
            if (where_->next_ == nullptr) throw BadPointer();
            return where_->data_;
        }

        T* operator->()  //Yes, this really is how you do it.  It works!
        {
            if (where_->next_ == nullptr) throw BadPointer();
            return &(where_->data_);
        }
    private:
        Entry* where_;
    };

    iterator       begin() { return iterator(start_); }
    iterator       end  () { return iterator(end_  ); }
};

template <typename T>
inline
std::ostream& operator<< (std::ostream& out, const List <T>& foo)
{
    foo.print(out); return out;
}

template <typename T>
List<T>::List(List&& other)                   //move ctor
{
	start_ = other.start_; end_ = other.end_;  size_ = other.size_;
	other.createEmptyList();
}

template <typename T>
const List<T>& List<T>::operator= (List&& other) //move =
{
	eraseAllElements(); delete start_; //erase all, incl. caboose
	start_ = other.start_; end_ = other.end_;  size_ = other.size_;
	other.createEmptyList();
	return *this;
}

template <typename T>
void List<T>::eraseAllElements() { while (!empty()) pop_front(); }

template <typename T>
void List<T>::push_front(const T& newElement)
{
    Entry* newEntry = new Entry; //create an entry
    newEntry->data_ = newElement;//set its data_ field to newElement
    newEntry->next_ = start_;    //set its next_ field to start_

    start_ = newEntry;  //make start_ point to new entry
    ++size_;
}

template <typename T>
void List<T>::pop_front()
{
    if (empty()) throw Underflow();

    Entry* temp = start_;   //store location of thing to delete
    start_ = start_->next_; //let start_ = next thing after start_

    delete temp;            //delete the item
    --size_;
}

template <typename T>
void List<T>::copy(const List <T>& other)
{
    size_ = 0; //it shoudl be...
    Entry* lastEntry = nullptr;   //last thing we added to this list,
                                  //  as we go thru other list
    Entry* otherP = other.start_; //where are we in the other list?

    //while not done with other list... 
    //   copy its next item into this list
    while (otherP->next_) //while it's not a caboose...
    {
        //Make a new entry with current element from other;
        // put it at end of our list (so far)
        Entry* newEntry = new Entry;
        newEntry->data_ = otherP->data_;
        newEntry->next_ = nullptr;

        //If list is empty, make it start_ with this new entry
        //If not, make its previous Entry recognize new entry 
        //  as what comes next
        if (empty()) start_ = newEntry;
        else         lastEntry->next_ = newEntry;

        lastEntry = newEntry;  //Keep pointer for lastEntry updated
        otherP = otherP->next_;//Go on to next item in other list       
        ++size_;
    }

    lastEntry->next_ = end_ = new Entry;  //attach caboose
}

///Things that were exercises earlier...

template <typename T>
bool List<T>::operator== (const List <T>& other) const
{
    if (size_ != other.size_) return false;//diff sizes? not equal
    Entry* otherp = other.start_;
    for (Entry* thisp = start_;
        thisp != end_;
        thisp = thisp->next_, otherp = otherp->next_)
        if (thisp->data_ != otherp->data_) //diff data? not equal
            return false;

    return true;                           //otherwise, equal
}

template <typename T>
void List<T>::print(std::ostream& out) const
{
    out << '[';
    for (Entry* thisp = start_; thisp != end_; thisp = (*thisp).next_)
        out << (*thisp).data_ << ' ';
    out << ']';
}


#endif //LIST_H

