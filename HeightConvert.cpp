
// Program assignment: 1
// Program name: HeightConvert.cpp
// Author name: Nicholas Vaughan
// Date: 2/2/2016
// Course: COMSC 1450-A
//
// Modified by Thomas Vaughan on 2016 Mar 01.

#include <sstream> // for ostringstream
#include "io.hpp"  // for read_input(), write_output()

using namespace std;

int main()
{
    // Print prompt for input, and read input.
    int const ft = read_input("integer feet in height: ");
    int const in = read_input("integer inches in height: ");
    
    // Calculate centimeters with given input.
    float const cm = (12 * ft + in) * 2.54;
    
    // Print result.
    ostringstream oss;
    oss << "You are " << cm << " centimeters tall.";
    write_output(oss.str());
}

