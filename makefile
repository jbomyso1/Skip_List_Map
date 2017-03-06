all: main

main: main.o
		g++ -std=c++14 -g main.o -o main

main.o: map.hpp main.cpp
		g++ -std=c++14 -g -c main.cpp

clean:
		rm *.o *~ main
