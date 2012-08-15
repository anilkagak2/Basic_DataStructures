CC = g++
CFLAGS = -Wall
BIN = ../bin/
INCLUDE = ../include/
OBJ = ../obj/

insertionSort: insertionSort.o main.o
	$(CC) $(CFLAGS) $(OBJ)insertionSort.o $(OBJ)main.o -o $(BIN)insertionSort

insertionSort.o: $(INCLUDE)InsertionSort.h
		$(CC) -c $(CFLAGS) InsertionSort.cpp  -o $(OBJ)insertionSort.o

main.o: $(INCLUDE)InsertionSort.h
		$(CC) -c $(CFLAGS) main.cpp  -o $(OBJ)main.o

clean:
	rm -rf $(OBJ)*.o $(BIN)/*
