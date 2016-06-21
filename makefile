play: main.o move.o pokemon.o ataque.o proteccion.o recover.o
	g++ pokemon.o move.o ataque.o proteccion.o recover.o main.o -lncurses -o play
main.o: main.cpp pokemon.h move.h ataque.h proteccion.h recover.h
	g++ -c main.cpp
move.o: move.cpp move.h 
	g++ -c move.cpp
ataque.o: ataque.cpp move.h ataque.h
	g++ -c ataque.cpp
proteccion.o: proteccion.cpp move.h proteccion.h
	g++ -c proteccion.cpp
recover.o: recover.cpp move.h recover.h
	g++ -c recover.cpp
pokemon.o: pokemon.cpp pokemon.h move.h
	g++ -c pokemon.cpp 