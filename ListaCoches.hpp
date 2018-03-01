/* Autor Victor*/

#pragma once

#include <list>
#include <string>
#include "Coche.hpp"
#include "Ruta.hpp"
class ListaCoche{
    private:
        list<Coche> listCoche;
        list<surtidor>::iterator iterador;

    public:
        //Crea una nueva lista
        ListaCoche();
        //Añade nuevo
        void AnyadirCoche(Coche c);
        //Calcular ruta proxima
        Coche CalcularMasCercano(Ruta r);
        //
        string to_string();

};