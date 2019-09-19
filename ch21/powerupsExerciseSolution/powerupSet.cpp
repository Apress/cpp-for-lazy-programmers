//PowerupSet class: a Shape that is a vector of Powerup*
//	-- from _C++ for Lazy Programmers_

#include "powerupSet.h"

void PowerupSet::animate()
{
    for (unsigned int i = 0; i < size(); ++i)
        (*(*this)[i]).animate();
}

void PowerupSet::drawAux() const 
{
    for (unsigned int i = 0; i < size(); ++i)
        (*(*this)[i]).drawAux();
}
