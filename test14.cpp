
#include <iostream> // for cout, endl
#include <sstream>  // for istringstream, ostringstream
#include <string>   // for string, getline()
#include <iomanip>  // for setw(), setfill(), left

#include "io.hpp" // for read_input(), write_output()

using namespace std;

// Extract total width from command-line argument. If no argument be given to
// the command, set the default total width.
int get_width(int argc, char **argv)
{
   if (argc == 1) {
      // The only word on the command line is the name of the executable.
      enum {
         // Number of characters within which string is to be centered.
         DEFAULT_WIDTH = 40
      };
      return DEFAULT_WIDTH;
   }
   if (argc == 2) {
      // Exactly one word follows the name of the executable on the command
      // line.
      istringstream iss(argv[1]);
      int width;
      iss >> width;
      return width;
   }
   throw "more than one argument to command";
   return 0;
}

int main(int argc, char **argv)
{
   try {
      int const total_width = get_width(argc, argv);
      ostringstream oss1;
      oss1 << "Total width is " << total_width << ".";
      write_output(oss1.str());
      string const text = read_input_line("Enter text to be centered: ");
      int const margin = (total_width - text.length()) / 2;
      ostringstream oss2;
      oss2 << setw(margin) << setfill('-') << "-";
      oss2 << left << setw(total_width - margin) << text << endl;
      write_output(oss2.str());
   } catch (char const *e) {
      cerr << "ERROR: " << e << endl;
   }
}

