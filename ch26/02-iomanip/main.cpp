//Program to print temp, pressure for Venus and Earth
//      -- from _C++ for Lazy Programmers_

#include <iostream>
#include <iomanip>  //for setw and setprecision

using namespace std;

int main ()
{
    //constants related to spacing on the page
    const int      PLANET_SPACE =    10;
    const int        TEMP_SPACE =    15;
    const int    PRESSURE_SPACE =    15;

    //planetary temperature and pressure
    const double     VENUS_TEMP =   464;
    const double VENUS_PRESSURE = 92000;
    const double     EARTH_TEMP =    15;
    const double EARTH_PRESSURE =  1000;

    //Right-justify, and use 1 (fixed) decimal point precision
    cout << right << fixed << setprecision (1);

    //Print the headers
    cout    << setw (PLANET_SPACE)  << " " 
            << setw (TEMP_SPACE  )  << "Average"
            << setw (PRESSURE_SPACE)<< "Surface"    << endl;
    cout    << setw (PLANET_SPACE)  << " " 
            << setw (TEMP_SPACE  )  << "temperature"
            << setw (PRESSURE_SPACE)<< "pressure"   << endl;
    cout    << setw (PLANET_SPACE)  << "Planet" 
            << setw (TEMP_SPACE  )  << "(degrees C)"
            << setw (PRESSURE_SPACE)<< "millibars" << endl;
    cout    << endl;

    //Print the data
    cout    << setw (PLANET_SPACE)  << "Venus" 
            << setw (TEMP_SPACE  )  << VENUS_TEMP
            << setw (PRESSURE_SPACE)<< VENUS_PRESSURE << endl;
    cout    << setw (PLANET_SPACE)  << "Earth" 
            << setw (TEMP_SPACE  )  << EARTH_TEMP
            << setw (PRESSURE_SPACE)<< EARTH_PRESSURE << endl;

    cout    << "\n...I think I'll just stay home.\n\n";

    return 0;
}
