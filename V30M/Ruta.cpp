//Pedro

#include "Ruta.hpp"	
#include "Punto.hpp"

Ruta::Ruta(){
	
}
bool Ruta::operator<(Ruta dos){
	if(this->obtenerMinComienzo() < dos.obtenerMinComienzo()){
		return true;
	}else if(this->obtenerMinComienzo() == dos.obtenerMinComienzo()){
		if(this->obtenerMaxFinal() < dos.obtenerMaxFinal()){
			return true;
		}else{
			return this->idRuta() < dos.idRuta();
		}
	}else{
		return false;
	}
}

bool Ruta::operator<(const Ruta dos) const{
	if(this->obtenerMinComienzo() < dos.obtenerMinComienzo()){
		return true;
	}else if(this->obtenerMinComienzo() == dos.obtenerMinComienzo()){
		if(this->obtenerMaxFinal() < dos.obtenerMaxFinal()){
			return true;
		}else{
			return this->idRuta() < dos.idRuta();
		}
	}else{
		return false;
	}
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
