//Program to show, and move, the Olympics symbol
//It uses Circle, and a subclass of Shape called Text
//      -- from _C++ for Lazy Programmers_

#include <vector>
#include <memory> //for unique_ptr
#include "circle.h"
#include "text.h"

//Used to test move ctor/=
Text makeTextToTestMoveCtor()     { Text t ("t");        return t; }
Circle makeCircleToTestMoveCtor() { Circle c(1,1,5,"c"); return c; }

int main (int argc, char** argv) 
{
    Text   t; t = makeTextToTestMoveCtor  (); //Test move ctors, =
    Circle c; c = makeCircleToTestMoveCtor();
    Text t2(t);                               //Test copy ctors
    Circle c2(c);

    SSDL_SetWindowSize (500, 300); //make smaller window

    //Create Olympics symbol
    std::vector<std::unique_ptr<Shape>> olympicSymbol;  
    enum {RADIUS = 50};

    olympicSymbol.push_back
        (std::make_unique<Circle>( 50,  50, RADIUS));
    olympicSymbol.push_back
        (std::make_unique<Circle>(150,  50, RADIUS)); 
    olympicSymbol.push_back
        (std::make_unique<Circle>(250,  50, RADIUS));
    olympicSymbol.push_back
        (std::make_unique<Circle>(100, 100, RADIUS));
    olympicSymbol.push_back
        (std::make_unique<Circle>(200, 100, RADIUS));

    //plus a label
    olympicSymbol.push_back
        (std::make_unique<Text>(150,150,"Games of the Olympiad"));

    //color those circles (and the label)
    SSDL_Color olympicColors[] = { BLUE,
                   SSDL_CreateColor (0, 255, 255) /*yellow*/,
                   BLACK, GREEN, RED, BLACK };
    for (unsigned int i = 0; i < olympicSymbol.size(); ++i)
        olympicSymbol[i]->setColor (olympicColors [i]);

    //do a game loop
    while (SSDL_IsNextFrame ())
    {
        SSDL_DefaultEventHandler ();

        SSDL_RenderClear (WHITE);   //clear the screen

        //draw all those shapes
        for (const auto& i : olympicSymbol) i->draw ();
                                   //ranged-based for-loops ftw!
        //move all those shapes
        for (const auto& i : olympicSymbol) i->moveBy (1, 1);
    }

    //No longer needed:
    //for (auto i : olympicSymbol) delete i;

    return 0;
}
