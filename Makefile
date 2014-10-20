# Makefile para aplicacion "lista"
CFLAGS	=
CC	= gcc
OBJS	= ordenArchivo-p.o   

ordenArchivo-p: $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $@

main:	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $@

main.o:	main.c quickSort.h mergeSort.h  
		$(CC) $(CFLAGS) -c main.c

clean:
		/bin/rm *.o main ordenArchivo-p
