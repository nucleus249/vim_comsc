
# Programs that read the standard input and write to the standard output.
STDIN_STDOUT_PROGS = HeightConvert test14

# Programs that do not read the standard input but do write to the standard
# output.
STDOUT_PROGS =

# Programs that neither read from the standard input nor write to the standard
# output.
NO_STDIO_PROGS = meanCalc

PROGS = $(STDIN_STDOUT_PROGS) $(STDOUT_PROGS) $(NO_STDIO_PROGS)

# Various output files.
STDIN_STDOUT_OUTPUT = $(STDIN_STDOUT_PROGS:=.out)
STDOUT_OUTPUT       = $(STDOUT_PROGS:=.out)
NO_STDIO_OUTPUT     = meanCalcOutput.txt

# This is used by the clean target to remove all output files.
OUTPUT = $(STDIN_STDOUT_OUTPUT) $(STDOUT_OUTPUT) $(NO_STDIO_OUTPUT)

WARN_FLAGS =\
 -W\
 -Wall\
 -Wconversion\
 -Wshadow\
 -Wcast-align\
 -Wwrite-strings\
 -Wpointer-arith

CTAGS = /usr/bin/ctags

CXX      = g++
CXXFLAGS = $(WARN_FLAGS) -g

# By default, GNU make uses $(CC) to link a program from object files. We need,
# however, the C++ compiler to do the final linking because we have C++ object
# files.
CC = $(CXX)

# See <http://mad-scientist.net/make/autodep.html>.
DEPDIR = .dep
SRC    = $(wildcard *.cpp)

# See <http://mad-scientist.net/make/autodep.html>.
%.o : %.cpp Makefile
	$(CXX) -MD $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<
	@mkdir -p $(DEPDIR)
	@cp $*.d $(DEPDIR)/$*.P
	@sed                 \
	  -e 's/#.*//'       \
	  -e 's/^[^:]*: *//' \
	  -e 's/ *\\$$//'    \
	  -e '/^$$/ d'       \
	  -e 's/$$/ :/'      \
	  < $*.d >> $(DEPDIR)/$*.P
	@rm -f $*.d

# Run a program, and redirect its standard output to a log file.
%.out : %
	./$< > $@

.PHONY : all clean interactive

all : $(PROGS) $(STDOUT_OUTPUT) $(NO_STDIO_OUTPUT) tags

interactive : $(STDIN_STDOUT_OUTPUT)

HeightConvert : HeightConvert.o io.o

test14 : test14.o io.o

meanCalcOutput.txt : meanCalc meanCalcInput.txt
	./meanCalc

tags : $(SRC) $(wildcard *.hpp)
	if test -x $(CTAGS); then ctags -R; fi

clean : 
	@rm -frv .dep
	@rm -fv *.o
	@rm -fv $(OUTPUT)
	@rm -fv $(PROGS)
	@rm -fv tags

# Must be last line.  See <http://mad-scientist.net/make/autodep.html>.
-include $(SRC:%.cpp=$(DEPDIR)/%.P)
