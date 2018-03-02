#include "Coche.hpp"
#include "Punto.hpp"
#include "Ruta.hpp"
Coche::Coche(Punto inicial){
    tiempoHastaAcabar = 0;
    pFinal = inicial;
    numRutas = 0;
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
void Coche::nuevoDestino(Punto nuevo){
    Punto actual = this->pFinal;
    this->tiempoHastaAcabar += actual.distancia(nuevo);
    this->pFinal = nuevo;
    this->numRutas++;
}
void Coche::anyadirRuta(Ruta r, int id, int delay){
    this->tiempoHastaAcabar = r.obtenerMinComienzo()+delay;
    nuevoDestino(r.obtenerDestino());
    this->rutasAsignadas.push_back(id);
}
