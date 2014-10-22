
CC         = gcc
COPTS      = -Wall -g
LDLIBS     = pthread

execs      = ordenArchivo-p

%.o: %.c ; $(CC) $(COPTS) -c $<
%  : %.o ; $(CC) $(COPTS) -o $@ $^ $(LDLIBS:%=-l%)

.PHONY: all clean

all: $(execs)
clean: ; rm -f $(execs) ./*.o ordenArchivo-p ordenArchivo-h

ordenArchivo-p  : ordenArchivo-p.o
ordenArchivo-p.o: ordenArchivo-p.c

ordenArchivo-p  : ordenArchivo-p.o
ordenArchivo-p.o: ordenArchivo-p.c
