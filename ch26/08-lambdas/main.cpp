//Program that uses lambda functions to order cities
//  by different criteria
//      -- from _C++ for Lazy Programmers_

#include <iostream>
#include <cmath>  //for sin, cos, asin, sqrt
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

    //constexprs
constexpr double PI = 3.14159;

    //...including user-defined literal operators
constexpr
long double operator"" _deg(unsigned long long deg)
{ 
    return deg * PI / 180; 
}
constexpr
long double operator"" _mi(long double  mi)        
{ 
    return mi * 1609.344;    //1 mi = 1609.344 m
}                                                      

    //types
struct PointLatLong
{
    long double latitude_, longitude_;
};

class City
{
public:
    City(const std::string& n, int pop, const PointLatLong& l) :
        name_ (n), population_ (pop), location_(l)
    {
    }
    City            (const City&) = default;
    City& operator= (const City&) = default;
    const std::string& name     () const { return name_;       }
    int population              () const { return population_; }
    const PointLatLong& location() const { return location_;   }
private:
    std::string  name_;
    int          population_;
    PointLatLong location_;
};

    //function protoypes
double distance(const PointLatLong&, const PointLatLong&);

inline 
double distance(const City& xCity, const City& yCity)
{
    return distance(xCity.location(), yCity.location());
}

////Functions for use without lambdas:
//bool lessThanByName(const City& a, const City& b)
//{
//  return a.name() < b.name();
//}
//bool lessThanByPop(const City& a, const City& b)
//{
//  return a.population() < b.population();
//}

int main()
{
    //Some prominent party spots
    vector<City> cities =
    {
        {"London",         10'313'000, { 51_deg,  -5_deg}},
        {"Hamburg",         1'739'000, { 53_deg,  10_deg}},
        {"Paris",          10'843'000, { 49_deg,   2_deg}},
        {"Rome",            3'718'000, { 42_deg,  12_deg}},
        {"Rio de Janiero", 12'902'000, {-22_deg, -43_deg}},
        {"Hong Kong",       7'314'000, { 20_deg, 114_deg}},
        {"Tokyo",          38'001'000, { 36_deg, 140_deg}}
    };

    //Without lambdas:
    //sort(cities.begin(), cities.end(), lessThanByName);
    //sort(cities.begin(), cities.end(), lessThanByPop);

        //Print those cities in different orderings:
        
    cout << "Some major cities, in alpha order :      ";
    sort(cities.begin(), cities.end(), 
         [](const City& a, const City& b) 
         { 
             return a.name() < b.name(); 
         });
    for (const auto& i : cities) cout << i.name() << " / ";
    cout << endl;

    
    cout << "Ordered by population:                   "; 
    sort(cities.begin(), cities.end(), 
         [](const City& a, const City& b) 
         {
            return a.population() < b.population();
         });
    for (const auto& i : cities) cout << i.name() << " / "; 
    cout << endl;

    
    cout << "Ordered by how far they are from Delhi:  ";
    const City DELHI("Delhi", 25'703'000, { 28_deg, 77_deg });

    sort(cities.begin(), cities.end(), 
         [&DELHI](const City& a, const City& b)
         {
             return distance(DELHI, a) < distance(DELHI, b);
         });
    for (const auto& i : cities) cout << i.name() << " / "; 
    cout << endl;

    
    cout << "Ordered by how far they are from LA:     ";
    const City LA ( "Los Angeles", 3'900'000, {34_deg, -118_deg} );

    //& will work here -- but &LA would be a little more secure
    sort(cities.begin(), cities.end(), 
	     [&](const City& a, const City& b)
         { 
             return distance(LA, a) < distance(LA, b); 
         });
    for (const auto& i : cities) cout << i.name() << " / "; 
    cout << endl; 

    
    //And something to illustrate the use of lambda capture by value:
    //Does Los Angeles have an 'x' in it?
    char badLetter = 'x';
    assert(find_if(LA.name().begin(), LA.name().end(),
        [badLetter](char ch) { return ch == badLetter; })
        == LA.name().end());

     return 0;
}

template<typename T>
inline T sqr(const T& thing) { return thing * thing; }

//Uses the Haversine formula to get distances
double distance(const PointLatLong& x, const PointLatLong& y)
{
    constexpr double EARTH_RADIUS = 3958.8_mi;

    double a = sqr(sin((x.latitude_ - y.latitude_) / 2.0))
        + cos(x.latitude_)*cos(y.latitude_)*
           sqr(sin((x.longitude_ - y.longitude_) / 2.0));

    return EARTH_RADIUS * 2 * asin(sqrt(a));
}

