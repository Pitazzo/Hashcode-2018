CPPFLAGS=-I. -O2 -std=c++11
CC = g++



Punto.o: Punto.hpp Punto.cpp
	${CC} -c Punto.cpp ${CPPFLAGS}
