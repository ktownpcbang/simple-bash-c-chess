CC = gcc 
CFLAGS = -g -Wall
EXE = ajedrez
$(EXE):main.o ajedrez.o
	$(CC) $(CFLAGS) -o ajedrez main.o ajedrez.o
main.o:main.c ajedrez.h
	$(CC) $(CFLAGS) -c main.c 
ajedrez.o:ajedrez.c ajedrez.h
	$(CC) $(CFLAGS) -c ajedrez.c
clean :
	rm -f *.o core $(EXE) secuencia_movimientos.txt
