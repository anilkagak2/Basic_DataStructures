CC = g++
CFLAGS = -Wall
BIN = ../bin/
INCLUDE = ../include/
OBJ = ../obj/

QuickSort: QuickSort.o main.o
	$(CC) $(CFLAGS) $(OBJ)QuickSort.o $(OBJ)main.o -o $(BIN)QuickSort

QuickSort.o: $(INCLUDE)QuickSort.h
		$(CC) -c $(CFLAGS) QuickSort.cpp  -o $(OBJ)QuickSort.o

main.o: $(INCLUDE)QuickSort.h
		$(CC) -c $(CFLAGS) main.cpp  -o $(OBJ)main.o

clean:
	rm -rf $(OBJ)*.o $(BIN)*
