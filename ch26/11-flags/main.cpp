//Program that controls a Super-Simple Demo Oven (SSDO) with flags
//      -- from _C++ for Lazy Programmers_

#include <iostream>
#include <cassert>

class SSDO  //A Super-Simple Demo Oven
{
public:
    enum FLAGS
    {
        RIGHT = 0b00000011,  //This is how to write in binary in C++:
        LEFT  = 0b00001100,  //  precede with 0b or 0B
        BAKE  = 0b00010000,
        BROIL = 0b00100000
        //Top two bits are unused
    };

    enum Condition
    {
        OFF = 0b00,
        LO  = 0b01,
        MD  = 0b10,
        HI  = 0b11,
    };

    enum 
    {
        RIGHT_BURNER_OFFSET=0,  //starts at right end of flags
        LEFT_BURNER_OFFSET = 2, //starts 2 bits left
        FIRE = 0b00111111
    };

    //ctors and =
    SSDO()            { flags_ = '\0'; }
    SSDO(const SSDO&)                   = delete;
    const SSDO& operator= (const SSDO&) = delete;

    //the controls
    void    setBake() { flags_ |= BAKE; }
    void  clearBake() { flags_ &= ~BAKE; }
    void   setBroil() { flags_ |= BROIL; }
    void clearBroil() { flags_ &= ~BROIL; }

    void    setRightBurner(Condition c) 
    { 
        flags_ &= ~RIGHT; 
        flags_ |= 
            static_cast<unsigned char>(c << RIGHT_BURNER_OFFSET); 
               //The static_cast makes it obvious I *know* I'm
              // changing between types Condition and unsigned char
    }
    void   setLeftBurner  (Condition c) 
    { 
        flags_ &= ~LEFT; 
        flags_ |= 
            static_cast<unsigned char> (c<< LEFT_BURNER_OFFSET); 
    }
    void clearRightBurner()            { setRightBurner(OFF);}
    void clearLeftBurner ()            { setLeftBurner(OFF); }

    //access functions
    unsigned char flags  () const      { return flags_;       }
    bool isSelfCleaning  () const
    {
        return (flags() & BAKE) && (flags() & BROIL);
    }
    bool isFireHazard    () const  //they're all on, high!
    {
        return  (flags() & FIRE) == FIRE;
    }
private:
    unsigned char flags_; //I only have a few bits; don't need a whole int
};

using namespace std;

int main ()
{
    SSDO myOven;

    //Turning the oven completely on; now it's in self-cleaning mode
    myOven.setBake();
    myOven.setBroil();
    assert(myOven.isSelfCleaning());
    assert(myOven.flags() == 0b00110000);

    //Playing with the right burner, checking the result...
    myOven.setRightBurner   (SSDO::LO);
    myOven.clearRightBurner (); 
    assert ((myOven.flags() & SSDO::RIGHT) == 0); //()'s needed!

    //I probably shouldn't do this...
    myOven.setRightBurner   (SSDO::HI);
    myOven.setLeftBurner    (SSDO::HI);
    if (myOven.isFireHazard()) 
        cout << "Cut the power and call the fire department!\n";

    return 0;
}
