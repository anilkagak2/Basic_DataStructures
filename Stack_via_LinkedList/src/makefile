myPrg: Stack.o main.o
	g++ -W $(CFLAGS) ../obj/Stack.o ../obj/main.o -o ../bin/myPrg

Stack.o: ../include/Stack.h
	g++ -W -c $(CFLAGS) Stack.cpp -o ../obj/Stack.o

main.o: ../include/Stack.h
	g++ -W -c $(CFLAGS) main.cpp -o ../obj/main.o

clean:
	rm ../obj/*.* ../bin/*
