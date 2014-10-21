
CC         = gcc
COPTS      = -Wall -g
LDLIBS     = pthread

execs      = prueba

%.o: %.c ; $(CC) $(COPTS) -c $<
%  : %.o ; $(CC) $(COPTS) -o $@ $^ $(LDLIBS:%=-l%)

.PHONY: all clean

all: $(execs)
clean: ; rm -f $(execs) ./*.o

prueba  : prueba.o
prueba.o: prueba.c

main  : main.o
main.o: main.c

ordenArchivo-p  : ordenArchivo-p.o
ordenArchivo-p.o: ordenArchivo-p.c
