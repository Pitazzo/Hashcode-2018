/* Autor Victor*/

#pragma once

#include <list>
#include <string>
#include <stdlib.h>
#include "Coche.hpp"
#include "Ruta.hpp"
class ListaCoche{
    private:
        list<Coche> listCoche;

    public:
        //Crea una nueva lista
        ListaCoche();
        //Añade nuevo
        void anyadirCoche(const Coche &c);
        //Calcular ruta proxima
        void calcularMasCercano(Ruta r, int i);
        //
        string to_string();

};
