CC = g++
CFLAGS = -Wall
OBJ = ../obj/
BIN = ../bin/
INCLUDE = ../include/

#make rule for queue
queue: queue.o main.o
	$(CC) $(CFLAGS) $(OBJ)queue.o $(OBJ)main.o -o $(BIN)queue

queue.o: $(INCLUDE)queue.h
	$(CC) $(CFLAGS) -c queue.cpp -o $(OBJ)queue.o

main.o: $(INCLUDE)queue.h
	$(CC) $(CFLAGS) -c main.cpp -o $(OBJ)main.o

clean:
	rm $(OBJ)*.o $(BIN)*
