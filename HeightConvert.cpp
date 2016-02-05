
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
    cout << "Enter the foot dimension of your height: ";
	cin >> feet;
    cout << endl;
    
    cout << "Enter the inch dimension of your height: ";
    cin >> inches;
    cout << endl;
    
    // Calculate centimeters with given input
    cm = (12 * feet + inches) * 2.54;
    
    // Print result
    cout << "You are " << cm << " centimeters tall." endl;
}
