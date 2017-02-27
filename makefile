all: map

map: map.o
		g++ -std=c++11 -g map.o -o map

map.o: map.hpp map.cpp
		g++ -std=c++11 -g -c map.cpp

clean:
		rm *.o *~ map
