#ifndef COCHE_HPP
#define COCHE_HPP

//*****************************************************************
// File:   Coche.hpp
// Author: Enrique Torres Sanchez
// Date:   Marzo 1
//*****************************************************************

#include <iostream>
#include <fstream>
#include <ostream>
#include <Punto.hpp>
#include <list>
using namespace std;

class Coche {
private:
	Punto pFinal;
	list<int> rutasAsignadas;
    bool enRuta;
    int tiempoHastaAcabar;
public:
	//Crea el coche dado el punto inicial
    Coche(Punto inicial);

    //Devuelve true si el coche esta actualmente en ruta
    bool estaEnRuta();

    //Devuelve el numero de pasos hasta su destino si esta en ruta. Si no
    //devuelve 0.
    int tiempoRestante();

    //Devuelve una string con el formato necesario para imprimirlo en el
    //fichero de salida
    string to_string();

    //Si esta en ruta, devuelve el punto al que se dirige el coche actualmente.
    //Si no, devuelve el punto en el que se encuentre actualmente.
    Punto destinoActual();
};

#endif // COCHE_HPP