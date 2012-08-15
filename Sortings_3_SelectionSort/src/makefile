CC = g++
CFLAGS = -Wall
BIN = ../bin/
INCLUDE = ../include/
OBJ = ../obj/

SelectionSort: SelectionSort.o main.o
	$(CC) $(CFLAGS) $(OBJ)SelectionSort.o $(OBJ)main.o -o $(BIN)SelectionSort

SelectionSort.o: $(INCLUDE)SelectionSort.h
		$(CC) -c $(CFLAGS) SelectionSort.cpp  -o $(OBJ)SelectionSort.o

main.o: $(INCLUDE)SelectionSort.h
		$(CC) -c $(CFLAGS) main.cpp  -o $(OBJ)main.o

clean:
	rm -rf $(OBJ)*.o $(BIN)/*
