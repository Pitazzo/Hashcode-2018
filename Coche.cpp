#include "Coche.hpp"
#include "Punto.hpp"
Coche::Coche(Punto inicial){
    enRuta = false;
    tiempoHastaAcabar = 0;
    pFinal = inicial;
    numRutas = 0;
}

bool Coche::estaEnRuta(){
    return this->enRuta;
}

int Coche::tiempoRestante(){
    return this->tiempoHastaAcabar;
}

string Coche::toString(){
    string toReturn = to_string(this->numRutas);
    for (int& ruta: this->rutasAsignadas){
        toReturn = toReturn + " " + to_string(ruta);
    }
    return toReturn;
}

Punto Coche::destinoActual(){
    return this->pFinal;
}

int Coche::numeroRutas(){
    return this->numRutas;
}
