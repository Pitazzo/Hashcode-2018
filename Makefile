CPPFLAGS=-I. -O2 -std=c++11
CC = g++

main: main.o Punto.o Ruta.o Coche.o ListaCoches.o
	$(CC) main.o Punto.o Ruta.o Coche.o ListaCoches.o -o main
	
main.o: main.cpp
	${CC} -c main.cpp ${CPPFLAGS}

ListaCoches.o: ListaCoches.hpp ListaCoches.cpp
	${CC} -c ListaCoches.cpp ${CPPFLAGS}

Ruta.o: Ruta.hpp Ruta.cpp
	${CC} -c Ruta.cpp ${CPPFLAGS}

Punto.o: Punto.hpp Punto.cpp
	${CC} -c Punto.cpp ${CPPFLAGS}

Coche.o: Coche.hpp Coche.cpp
	${CC} -c Coche.cpp ${CPPFLAGS}
