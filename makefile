play: main.o move.o pokemon.o 
	g++ pokemon.o move.o main.o -lncurses -o play
main.o: main.cpp pokemon.h move.h
	g++ -c main.cpp
move.o: move.cpp move.h 
	g++ -c move.cpp
pokemon.o: pokemon.cpp pokemon.h move.h
	g++ -c pokemon.cpp 