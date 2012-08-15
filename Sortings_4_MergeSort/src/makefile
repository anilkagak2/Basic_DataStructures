CC = g++
CFLAGS = -Wall
BIN = ../bin/
INCLUDE = ../include/
OBJ = ../obj/

MergeSort: MergeSort.o main.o
	$(CC) $(CFLAGS) $(OBJ)MergeSort.o $(OBJ)main.o -o $(BIN)MergeSort

MergeSort.o: $(INCLUDE)MergeSort.h
		$(CC) -c $(CFLAGS) MergeSort.cpp  -o $(OBJ)MergeSort.o

main.o: $(INCLUDE)MergeSort.h
		$(CC) -c $(CFLAGS) main.cpp  -o $(OBJ)main.o

clean:
	rm -rf $(OBJ)*.o $(BIN)*.*
