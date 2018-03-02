CPPFLAGS=-I. -O2 -std=c++11
CC = g++

main: main.o Punto.o Ruta.o Coche.o ListaCoches.o
	$(CC) main.o Punto.o Ruta.o Coche.o ListaCoches.o -g -o  main
	
main.o: main.cpp
	${CC} -c -g main.cpp ${CPPFLAGS}

ListaCoches.o: ListaCoches.hpp ListaCoches.cpp
	${CC} -c -g ListaCoches.cpp ${CPPFLAGS}

Ruta.o: Ruta.hpp Ruta.cpp
	${CC} -c -g -fpermissive Ruta.cpp ${CPPFLAGS}

Punto.o: Punto.hpp Punto.cpp
	${CC} -c -g Punto.cpp ${CPPFLAGS}

Coche.o: Coche.hpp Coche.cpp
	${CC} -c -g Coche.cpp ${CPPFLAGS}
