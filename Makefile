CXXFLAGS= -Wall -pedantic


main: main.o Funkcje.o Grafy.o
	g++ -Wall -o main main.o Grafy.o Funkcje.o

main.o: main.cpp Funkcje.h Grafy.h
	g++ -c ${CXXFLAGS} -o main.o main.cpp

Grafy.o: Grafy.cpp Grafy.h 
	g++ -c ${CXXFLAGS} -o Grafy.o Grafy.cpp

Funkcje.o: Funkcje.cpp Funkcje.h Grafy.h
	g++ -c ${CXXFLAGS} -o Funkcje.o Funkcje.cpp