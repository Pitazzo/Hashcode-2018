//Pedro

#include "Ruta.hpp"	
#include "Punto.hpp"

Ruta::Ruta(Punto inicio, Punto destino, int minInicio, int maxFinal){
	this->inicio = inicio;
	this->destino = destino;
	this->minInicio = minInicio;
	this->maxFinal = maxFinal;
}

int Ruta::maxTrayecto(){
	return this->maxFinal - this->minInicio;
}

Punto Ruta::obtenerOrigen(){
	return this->inicio;
}

Punto Ruta::obtenerDestino(){
	return this->destino;
}

int Ruta::obtenerMinComienzo(){
	return this->minInicio;
}

int Ruta::obtenerMaxFinal(){
	return this->maxFinal;
}
