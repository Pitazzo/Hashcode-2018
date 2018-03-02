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
        ~ListaCoche();
        void anyadirCoche(const Coche &c);
        //Calcular ruta proxima
        bool calcularMasCercano(Ruta r, int i, int& noLlegan);
        //
        string to_string();
        string to_stringo();
};
