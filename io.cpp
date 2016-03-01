
// 'unistd.h' is a POSIX header, which might not be available on MS Windows.
#include <unistd.h> // for isatty()

#include <cstdio>   // for stdout, fileno()
#include <iostream> // cerr, cin, cout, flush

#include "io.hpp"

using namespace std;

/// Determine whether standard output be a tty. If so, then print the prompt to
/// the standard output. Otherwise, print the prompt to the standard error. In
/// any event return a non-zero value only if the standard output be a tty.
int prompt_user(string const &prompt)
{
   int const is_term = isatty(fileno(stdout));
   if (is_term) {
      // Standard output goes to the terminal. So prompt the user by writing to
      // standard output.
      cout << prompt << flush;
   } else {
      // Standard output has been redirected to a file. So prompt the user by
      // writing to standard error.
      cerr << prompt << flush;
   }
   return is_term;
}

/// If the standard output be a tty, then do nothing, for the standard output
/// is not being redirected to a log file. Otherwise, print both the prompt and
/// the user's input to the standard output; that is, to the log file.
template<typename TT>
void log_input(int is_term, string const &prompt, TT const& input)
{
   if (!is_term) {
      // Standard output has been redirected to a file, and so write to that
      // file the prompt along with the input collected from the prompt. In
      // this way, the contents of the output file appear exactly as the lines
      // on the terminal appear.
      cout << prompt << input << endl;
   }
}

int read_input(string const &prompt)
{
   int const is_term = prompt_user(prompt);
   int input;
   cin >> input;
   log_input(is_term, prompt, input);
   return input;
}

string read_input_line(string const &prompt)
{
   int const is_term = prompt_user(prompt);
   string input;
   getline(cin, input);
   log_input(is_term, prompt, input);
   return input;
}

void write_output(string const& output)
{
   int const is_term = isatty(fileno(stdout));
   cout << output << endl;
   if (!is_term) {
      cerr << output << endl;
   }
}

