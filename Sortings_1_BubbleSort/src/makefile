CC = g++
CFLAGS = -Wall
BIN = ../bin/
INCLUDE = ../include/
OBJ = ../obj/

bubbleSort: bubbleSort.o main.o
	$(CC) $(CFLAGS) $(OBJ)bubbleSort.o $(OBJ)main.o -o $(BIN)bubbleSort

bubbleSort.o: $(INCLUDE)bubbleSort.h
		$(CC) -c $(CFLAGS) bubbleSort.cpp  -o $(OBJ)bubbleSort.o

main.o: $(INCLUDE)bubbleSort.h
		$(CC) -c $(CFLAGS) main.cpp  -o $(OBJ)main.o

clean:
	rm -rf $(OBJ)*.o $(BIN)/*
