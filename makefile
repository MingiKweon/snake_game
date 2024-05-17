all: main

main: main.cpp Board.hpp map.h
	g++ -o main main.cpp Board.cpp map.cpp -lncurses 