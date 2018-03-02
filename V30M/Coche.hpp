//*****************************************************************
// File:   Coche.hpp
// Author: Enrique Torres Sanchez
// Date:   Marzo 1
//*****************************************************************
#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
#include "Punto.hpp"
#include <list>
#include "Ruta.hpp"
using namespace std;

class Coche {
private:
	Punto pFinal;
	list<int> rutasAsignadas;
    int tiempoHastaAcabar;
    int numRutas;
public:
	//Crea el coche dado el punto inicial
    Coche(Punto inicial);

    //Devuelve el numero de pasos hasta su destino si esta en ruta. Si no
    //devuelve 0.
    int tiempoRestante();

    //Devuelve una string con el formato necesario para imprimirlo en el
    //fichero de salida
    string toString();

    //Si esta en ruta, devuelve el punto al que se dirige el coche actualmente.
    //Si no, devuelve el punto en el que se encuentre actualmente.
    Punto destinoActual();

    //Devuelve el numero de rutas que han sido asignadas historicamente a este coche
    int numeroRutas();

    //Poner un nuevo punto destino al coche
    void nuevoDestino(Punto nuevo);

    //Anyade una nueva ruta a las rutas asignadas a este coche
    void anyadirRuta(Ruta r, int id, int delay);
};