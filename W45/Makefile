CXX=g++ -std=c++17

.PHONY: all clean

all: zadanie

zadanie: main.o
	${CXX} main.o -o zadanie

main.o: main.cpp  Movie.hpp
	${CXX} -c main.cpp -o main.o

