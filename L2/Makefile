CXX=g++ -std=c++17
CXXFLAGS=-Wall # obiekty
LDFLAGS= # exe biblioteki

.PHONY: all clean

all: l2

l2: vector3.o main.o
	${CXX} ${LDFLAGS} $^ -o l2

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

vector3.o: vector3.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	rm -f l2
