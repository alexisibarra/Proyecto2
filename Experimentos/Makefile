
CC         = gcc
COPTS      = -Wall -g
LDLIBS     = pthread

execs      = Archivos

%.o: %.c ; $(CC) $(COPTS) -c $<
%  : %.o ; $(CC) $(COPTS) -o $@ $^ $(LDLIBS:%=-l%)

.PHONY: all clean

all: $(execs)
clean: ; rm -f $(execs) ./*.o

Archivos  : Archivos.o
Archivos.o: Archivos.c

