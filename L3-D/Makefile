CXX=g++
CXXFLAGS=-std=c++17 -Wall
LDFLAGS=-fsanitize=address,leak

.PHONY: all clean

main.o: main.cpp SongDuration.hpp Song.hpp
	${CXX} ${CXXFLAGS} main.cpp -o main.o



clean:
	rm -f *.o l3
