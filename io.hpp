
/// \file io.hpp
/// 
/// The present file provides an input-output (IO) interface by which an
/// interactive program can be run either directly from the command line or by
/// way of the Makefile, which logs the interaction to a different file for
/// each program. The problems solved by the interface here are
///
///    1. that when the standard output be redirected to a log file, the user
///       would not be able to see a prompt issued by the program and
///
///    2. that when the standard output be redirected to a log file, what the
///       user types on the standard input in response to the prompt would not
///       be visible in the log file.
///
/// Each of read_input() and write_output() determines whether the standard
/// output is a terminal and then takes action so that, whether or not the
/// standard output be redirected, the user's experience on the terminal is the
/// same and so that, if the standard output be redirected to a log file, the
/// log file's contents are exactly what the user saw in his interactive
/// session.
///
/// The Makefile by default builds every executable and runs every
/// non-interactive executable. By default, the Makefile does not run any of
/// the interactive executables.
///
/// An interactive executable can be run either by hand from the command line,
/// or every interactive executable will be run in sequence if 'make
/// interactive' be issued from the command line.

#include <string> // for string

// Read integer from standard input.
//
// If standard output be a (teletype, tty) terminal, then send the prompt to
// the standard output before reading from standard input; otherwise, send the
// prompt to the standard error before reading from standard input.
//
// If the standard input be not a terminal, then print both the prompt and the
// user's input to the standard output.
int read_input(std::string const &prompt);

// Read line of text from standard input.
//
// If standard output be a (teletype, tty) terminal, then send the prompt to
// the standard output before reading from standard input; otherwise, send the
// prompt to the standard error before reading from standard input.
//
// If the standard input be not a terminal, then print both the prompt and the
// user's input to the standard output.
std::string read_input_line(std::string const &prompt);

// Write string to standard output and, if the standard output be not a
// (teletype, tty) terminal, then write the string also to the standard error.
void write_output(std::string const& output);

