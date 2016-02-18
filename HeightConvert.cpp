
// Program assignment: 1
// Program name: HeightConvert.cpp
// Author name: Nicholas Vaughan
// Date: 2/2/2016
// Course: COMSC 1450-A  

// 'unistd.h' is a POSIX header, which might not be available on MS Windows.
#include <unistd.h>  // for isatty()

#include <cstdio>    // for stdout, fileno()
#include <iostream>  // for cin, cout, cerr, flush, endl
#include <string>

using namespace std;

float read_input(int is_term, string const& prompt)
{
   if (is_term) {
      cout << prompt << flush;
   } else {
      // Standard output has been redirected to a file, and so send to the
      // standard-error channel the prompt asking for input.
      cerr << prompt << flush;
   }
   int input;
   cin >> input;
   if (!is_term) {
      // Standard output has been redirected to a file, and so write to that
      // file the prompt along with the input collected from the prompt. In
      // this way, the contents of the output file appear exactly as the lines
      // on the terminal appear.
      cout << prompt << input << endl;
   }
   return input;
}

int main()
{
    // Non-zero (true) if standard output be a terminal (and be not redirected
    // to a file).  'stdout', defined in 'cstdio', is a pointer to the
    // C-standard-library (not C++-standard-library) FILE structure for
    // standard output.  fileno() converts such a pointer into the
    // file-descriptor number that isatty() needs.
    int const is_term = isatty(fileno(stdout));
    
    // Ask for input.
    int const ft = read_input(is_term, "integer feet in height: ");
    int const in = read_input(is_term, "integer inches in height: ");
    
    // Calculate centimeters with given input.
    float const cm = (12 * ft + in) * 2.54;
    
    // Print result.
    cout << "You are " << cm << " centimeters tall." << endl;
    if (!is_term) {
        cerr << "You are " << cm << " centimeters tall." << endl;
    }
}
