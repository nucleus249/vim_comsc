
PROGS = HeightConvert

CC = g++`

CFLAGS = pedantic -wall -g

OUTPUT = $(PROGS:=.out)



%.out : %
	./$< > $@


.PHONY : all clean

all : $(PROGS) $(OUTPUT)

$(PROGS): $(PROGS).cpp
	$(CC) $(CFLAGS) -o $(PROGS) $(PROGS).cpp

clean : 
	@rm -fv $(PROGS)
	@rm -fv $(OUTPUT)
	@rm -fv *.buildlog
