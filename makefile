all: main

main: main.cpp Board.hpp 
	g++ main.cpp -lncurses -o main