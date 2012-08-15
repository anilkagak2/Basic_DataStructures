CC = g++
CFLAGS = -Wall
OBJ = ../obj/
BIN = ../bin/
INCLUDE = ../include/

############### stack commands ##########################
#make the stack executable
stack: stack.o main.o sll.o
	$(CC) $(CFLAGS) $(OBJ)sll.o $(OBJ)stack.o $(OBJ)main.o -o $(BIN)stack

#make the object file out of stack.cpp
stack.o: $(INCLUDE)stack.h $(INCLUDE)sll.h
	$(CC) $(CFLAGS) -c stack.cpp -o $(OBJ)stack.o

#make the object file out of main.cpp
main.o: $(INCLUDE)stack.h $(INCLUDE)sll.h
	$(CC) $(CFLAGS) -c main.cpp -o $(OBJ)main.o

################ end stack commands ##########################

################# sll commands ##################
# make the singly linked list executable
sll: sll.o main_sll.o
	$(CC) $(CFLAGS) $(OBJ)sll.o $(OBJ)main_sll.o -o $(BIN)sll

# make the object file out of sll.cpp
sll.o: $(INCLUDE)sll.h
	$(CC) $(CFLAGS) -c sll.cpp -o $(OBJ)sll.o

#make the object file out of main_sll.cpp
main_sll.o: $(INCLUDE)sll.h
	$(CC) $(CFLAGS) -c main_sll.cpp -o $(OBJ)main_sll.o

################# end sll commands ##################

clean:
	rm $(OBJ)*.* $(BIN)*.*
