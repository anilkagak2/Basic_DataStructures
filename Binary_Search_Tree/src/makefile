CC = g++
CFLAGS = -Wall
INCLUDE = ../include/
OBJ = ../obj/
BIN = ../bin/

bst: bst.o main.o
	$(CC) $(CFLAGS) $(OBJ)bst.o $(OBJ)main.o -o $(BIN)bst

bst.o: $(INCLUDE)bst.h bst.cpp
	$(CC) -c $(CFLAGS) bst.cpp -o $(OBJ)bst.o

main.o: $(INCLUDE)bst.h main.cpp
	$(CC) -c $(CFLAGS) main.cpp -o $(OBJ)main.o

clean:
	rm -rf $(BIN)bst $(OBJ)*.o
