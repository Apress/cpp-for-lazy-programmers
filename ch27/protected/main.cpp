//Program to illustrate "protected" with 
// phones
//        -- from _C++ for Lazy Programmers_


#include <cassert>

class Phone
{
public:
    void call() { /*do some stuff, and then */ incNumCalls(); }
    static int numCalls() { return numCalls_; }
    
protected:
    void incNumCalls   () { ++numCalls_;      }
    
private:
    static int numCalls_;
};

class MobilePhone : protected Phone
{
public:
    //void call() { /* do stuff w cell towers, and */ incNumCalls(); }
    void secureCall() 
    { 
        /* do cell tower stuff */ 
        makeSecure ();
        incNumCalls(); 
    }
    
    void makeSecure() {} //however that's done
};

class SatellitePhone : public MobilePhone
{
public:
    void secureCall() 
    { 
        makeSecure ();      
        /* do satellite stuff */
        incNumCalls(); 
    }
    
    //makeSecure is inherited and public
};

int Phone::numCalls_ = 0;

int main ()
{
    Phone P;            P.call();
    MobilePhone MP;    MP.secureCall();
    SatellitePhone SP; SP.secureCall();

    assert(Phone::numCalls() == 3);

    return 0;
}
