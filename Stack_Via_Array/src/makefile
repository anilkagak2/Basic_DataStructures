myPrg: stack.o main.o
	g++ -W $(CFLAGS) ../obj/stack.o ../obj/main.o -o ../bin/myPrg

stack.o: ../include/stack.h
	g++ -W -c $(CFLAGS) stack.cpp -o ../obj/stack.o

main.o: ../include/stack.h
	g++ -W -c $(CFLAGS) main.cpp -o ../obj/main.o

clean:
	rm ../obj/*.* ../bin/*
