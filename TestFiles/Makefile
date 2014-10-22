
CC         = gcc
COPTS      = -Wall -g
LDLIBS     = pthread

execs      = testFilesGenerator

%.o: %.c ; $(CC) $(COPTS) -c $<
%  : %.o ; $(CC) $(COPTS) -o $@ $^ $(LDLIBS:%=-l%)

.PHONY: all clean

all: $(execs)
clean: ; rm -f $(execs) ./*.o ./*.bin

testFilesGenerator r: testFilesGenerator.o
testFilesGenerator.o: testFilesGenerator.c
