
# Programs that read the standard input or otherwise require interaction at run
# time.
INTERACTIVE_PROGS = HeightConvert test14

# Programs that do not read the standard input and do not otherwise require
# interaction at run time.
NONINTERACTIVE_PROGS =

PROGS = $(INTERACTIVE_PROGS) $(NONINTERACTIVE_PROGS)

# GNU 'make' uses these and does not require a build rule when one wishes only
# to build an executable from a single C++ source file of the same name.
CXX      = g++
CXXFLAGS = -Wall -g

INTERACTIVE_OUTPUT   = $(INTERACTIVE_PROGS:=.out)
NONINTERACIVE_OUTPUT = $(NONINTERACTIVE_PROGS:=.out)

# Run a program, and redirect its standard output to a file.
%.out : %
	./$< > $@

.PHONY : all clean interactive

all : $(PROGS) $(NONINTERACTIVE_OUTPUT)

interactive : $(INTERACTIVE_OUTPUT)

clean : 
	@rm -fv $(PROGS)
	@rm -fv $(OUTPUT)

