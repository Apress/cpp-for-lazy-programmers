//class List:  a linked list class
//	from _C++ for Lazy Programmers_

#ifndef LIST_H
#define LIST_H

template <typename T>
class List
{
public:
	class Underflow  {};		//Exception

	List ()                                 { createEmptyList();  }
	List (const List <T>& other) : List ()	{ copy(other);        }
	~List()                                 { eraseAllElements(); }

	const List <T>& operator= (const List <T>& other)
	{
		eraseAllElements(); createEmptyList(); copy(other); 
        return *this;
	}

	bool operator== (const List <T>& other) const;

	int  size() const { return size_; }
	bool empty() const { return size() == 0; }

	void push_front(const T& newElement);	//add newElement at front
	void pop_front();                      //take one off the front
	const T& front() const { if (empty()) throw Underflow(); else return  (*start_).data_; }

	void print(std::ostream&) const;
private:
	struct Entry
	{
		T      data_;
		Entry* next_;
	};

	Entry* start_;                         //Points to first element 
	int    size_;

	void copy(const List <T>& other);      //copies other's entries
										   //  into this List

	void eraseAllElements ();              //empties the list
	void createEmptyList  ()
	{
		start_ = nullptr;                  //the list is...nothing
		size_ = 0;
	}
};

template <typename T>
inline
std::ostream& operator<< (std::ostream& out, const List <T>& foo)
{
	foo.print(out); return out;
}

template <typename T>
void List<T>::eraseAllElements () {	while (!empty()) pop_front();	}

template <typename T>
void List<T>::push_front (const T& newElement)
{
    Entry* newEntry = new Entry; //create an entry
    newEntry->data_ = newElement;//set its data_ field to newElement
    newEntry->next_ = start_;    //set its next_ field to start_

    start_          = newEntry;  //make start_ point to new entry
    ++size_;
}

template <typename T>
void List<T>::pop_front()
{
    if (empty()) throw Underflow();

    Entry* temp = start_;   //store location of thing to delete
    start_ = start_->next_; //set start_ = next thing after start_

    delete temp;            //delete the item

    --size_;
}

template <typename T>
bool List<T>::operator== (const List <T>& other) const
{
	if (size_ != other.size_) return false;//diff sizes? not equal
	Entry* otherp = other.start_;
	for (Entry* thisp = start_;
		thisp != nullptr;
		thisp = thisp->next_, otherp = otherp->next_)
		if (thisp->data_ != otherp->data_) //diff data? not equal
			return false;

	return true;                           //otherwise, equal
}

template <typename T>
void List<T>::print(std::ostream& out) const
{
	out << '[';
	for (Entry* thisp = start_; thisp != nullptr; thisp = (*thisp).next_)
		out << (*thisp).data_ << ' ';
	out << ']';
}

template <typename T>
void List<T>::copy(const List <T>& other)
{
    Entry* lastEntry = nullptr;   //last thing we added to this list,
                                  //  as we go thru other list
    Entry* otherP = other.start_; //where are we in the other list?

	//while not done with other list... 
	//   copy its next item into this list
    while (otherP)
    {
        //Make a new entry with current element from other;
        // put it at end of our list (so far)
        Entry* newEntry = new Entry;
        newEntry->data_ = otherP->data_;
        newEntry->next_ = nullptr;
	
        //If list is empty, make it start_ with this new entry
        //If not, make its previous Entry recognize new entry as what comes next
        if (empty()) start_           = newEntry;
        else         lastEntry->next_ = newEntry;

        lastEntry = newEntry;  //Keep our pointer for lastEntry updated
        otherP = otherP->next_;//Go on to next item in other list

        ++size_;               //One more thing added...
    }
}

#endif
