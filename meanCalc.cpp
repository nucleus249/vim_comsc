
#include <cmath>   // for pow()
#include <fstream> // for ifstream, ofstream
#include <iomanip> // for setprecision(), setw()

using namespace std;

int main()
{
   // Set the input and output files.
   ofstream out("meanCalcOutput.txt");
   ifstream in("meanCalcInput.txt");

   // Take three numbers from input file, and store each in a variable. Ignore
   // between the numbers in the input stream up to 100 characters of input in
   // searching for the first comma, which is ignored.
   double a, b, c;
   in >> a;
   in.ignore(100, ',');
   in >> b;
   in.ignore(100, ',');
   in >> c;

   // Calculate the different means.
   double const amean = (a + b + c) / 3.0;
   double const gmean = pow((a * b * c), (1.0 / 3.0));
   double const hmean = 3.0 / (1.0 / a + 1.0 / b + 1.0 / c);

   // Put calculated output into output file.
   out << setprecision(4) << setw(10) << amean << ", ";  //
   out << setprecision(4) << setw(10) << gmean << ", ";  // First line
   out << setprecision(4) << setw(10) << hmean << ",\n"; //

   out << setprecision(6) << setw(10) << amean << ", ";  //
   out << setprecision(6) << setw(10) << gmean << ", ";  // Second line
   out << setprecision(6) << setw(10) << hmean << ",\n"; //

   out << scientific;
   out << setprecision(2) << setw(10) << amean << ", "; //
   out << setprecision(2) << setw(10) << gmean << ", "; //  Third line
   out << setprecision(2) << setw(10) << hmean << endl; //

   return 0;
}

