
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
     string name;
     int width;

     cout << "What is your name? ";
     getline (cin, name);

     width = (30 - name.length())/2;

     cout << setw(width) << setfill('-') << "-";
     cout << left << setw(30 - width) << name << endl;
}

