CC = g++
CFLAGS = -Wall
OBJ = ../obj/
BIN = ../bin/
INCLUDE = ../include/

#make rule for queue
queue: sll.o queue.o main.o
	$(CC) $(CFLAGS) $(OBJ)sll.o $(OBJ)queue.o $(OBJ)main.o -o $(BIN)queue

sll.o:
	$(CC) $(CFLAGS) -c sll.cpp -o $(OBJ)sll.o

queue.o: $(INCLUDE)sll.h $(INCLUDE)queue.h
	$(CC) $(CFLAGS) -c queue.cpp -o $(OBJ)queue.o

main.o:  $(INCLUDE)sll.h $(INCLUDE)queue.h
	$(CC) $(CFLAGS) -c main.cpp -o $(OBJ)main.o

clean:
	rm $(OBJ)*.o $(BIN)*
