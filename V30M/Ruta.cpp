//Pedro

#include "Ruta.hpp"	
#include "Punto.hpp"

Ruta::Ruta(){
	
}
bool Ruta::operator<(Ruta dos){
	return this->obtenerMinComienzo() < dos.obtenerMaxFinal();
}

bool Ruta::operator<(const Ruta dos) const{
	return this->obtenerMinComienzo() < dos.obtenerMaxFinal();
}
Ruta::Ruta(Punto inicio, Punto destino, int minInicio, int maxFinal, int i){
	this->inicio = inicio;
	this->destino = destino;
	this->minInicio = minInicio;
	this->maxFinal = maxFinal;
	this->id = i;
}
int Ruta::idRuta(){
	return this->id;
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
