
// 'unistd.h' is a POSIX header, which might not be available on MS Windows.
#include <unistd.h> // for isatty()

#include <cstdio>   // for stdout, fileno()
#include <iostream> // cerr, cin, cout, flush
#include <string>   // for string

// Never put 'using namespace' at global scope in header file.

// Read integer from standard input.
//
// If standard output be a (teletype, tty) terminal, then send the prompt to
// the standard output before reading from standard input; otherwise, send the
// prompt to the standard error, which will be visible to the user even if the
// standard output have been redirected to a file.
//
// Finally, if the standard input be not a terminal, then print both the prompt
// and the user's input to the standard output, which is redirected to a file.
//
// read_input() allows for the user's experience to be identical, regardless of
// whether redirection be used to record a transcript of the session in a file.
inline int read_input(std::string const &prompt)
{
   int const is_term = isatty(fileno(stdout));
   if (is_term) {
      std::cout << prompt << std::flush;
   } else {
      // Standard output has been redirected to a file, and so send to the
      // standard-error channel the prompt asking for input.
      std::cerr << prompt << std::flush;
   }
   int input;
   std::cin >> input;
   if (!is_term) {
      // Standard output has been redirected to a file, and so write to that
      // file the prompt along with the input collected from the prompt. In
      // this way, the contents of the output file appear exactly as the lines
      // on the terminal appear.
      std::cout << prompt << input << std::endl;
   }
   return input;
}

inline std::string read_input_line(std::string const &prompt)
{
   int const is_term = isatty(fileno(stdout));
   if (is_term) {
      std::cout << prompt << std::flush;
   } else {
      // Standard output has been redirected to a file, and so send to the
      // standard-error channel the prompt asking for input.
      std::cerr << prompt << std::flush;
   }
   std::string input;
   getline(std::cin, input);
   if (!is_term) {
      // Standard output has been redirected to a file, and so write to that
      // file the prompt along with the input collected from the prompt. In
      // this way, the contents of the output file appear exactly as the lines
      // on the terminal appear.
      std::cout << prompt << input << std::endl;
   }
   return input;
}

// Write string to standard output and, if the standard output be not a
// (teletype, tty) terminal, then write the string also to the standard error.
//
// write_output() allows for the user's experience to be identical, regardless
// of whether redirection be used to record a transcript of the session in a
// file.
inline void write_output(std::string const& output)
{
   int const is_term = isatty(fileno(stdout));
   std::cout << output << std::endl;
   if (!is_term) {
      std::cerr << output << std::endl;
   }
}

