
// Program assignment: 2
// Program name: HeightConvert.cpp
// Author name: Nicholas Vaughan
// Date: 2/2/2016
// Course: COMSC 1450-A  

#include <iostream>

using namespace std;

int main()
{
    int feet;
    float inches;
    float cm;
    
    // Ask for input
    cerr << "Enter the foot dimension of your height: " << flush;
    cin >> feet;
    cout << "Foot dimenion of height is " << feet << "." << endl;
    
    cerr << "Enter the inch dimension of your height: " << flush;
    cin >> inches;
    cout << "Inch dimension of height is " << inches << "." << endl;
    
    // Calculate centimeters with given input
    cm = (12 * feet + inches) * 2.54;
    
    // Print result
    cerr << "You are " << cm << " centimeters tall." << endl;
    cout << "You are " << cm << " centimeters tall." << endl;
}
