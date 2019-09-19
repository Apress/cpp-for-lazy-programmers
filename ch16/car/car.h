//Class Car, and a program to use it
//  -- from _C++ for Lazy Programmers_

#ifndef CAR_H
#define CAR_H

#include <iostream>

class Car
{
public:
    enum { MAX_NAME_SIZE = 50 };

    Car();
    Car(const Car &);
    Car(int theYear, const char* theMake, const char* theModel);

    void print(std::ostream&) const;

    const char* make () const { return make_;   }
    const char* model() const { return model_;  }
    int         year () const { return year_;   }

    static int  numCars()     { return numCars_;}
    void        buy    ()     { ++numCars_;     }
    void        sell   ()     { --numCars_;     }

private:
    char make_[MAX_NAME_SIZE], model_[MAX_NAME_SIZE];
    int  year_;

    static int numCars_;
};

#endif //CAR_H
