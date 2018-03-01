CPPFLAGS=-I. -O2 -std=c++11
CC = g++

Ruta.o: Ruta.hpp Ruta.cpp
	${CC} -c Ruta.cpp ${CPPFLAGS}

Punto.o: Punto.hpp Punto.cpp
	${CC} -c Punto.cpp ${CPPFLAGS}

Main: main.cpp
	${CC} ${CPPFLAGS} main.cpp -o main

