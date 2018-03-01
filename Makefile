CPPFLAGS=-I. -O2 -std=c++11
CC = g++

main: main.o Punto.o Ruta.o
	$(CC) main.o Punto.o Ruta.o -o main
	
main.o: main.cpp
	${CC} -c main.cpp ${CPPFLAGS}

Ruta.o: Ruta.hpp Ruta.cpp
	${CC} -c Ruta.cpp ${CPPFLAGS}

Punto.o: Punto.hpp Punto.cpp
	${CC} -c Punto.cpp ${CPPFLAGS}

