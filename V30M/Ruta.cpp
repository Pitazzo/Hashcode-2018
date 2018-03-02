//Pedro

#include "Ruta.hpp"	
#include "Punto.hpp"

Ruta::Ruta(){
	
}


bool Ruta::operator<(const Ruta dos) const{

	if(this->obtenerMaxFinal() < dos.obtenerMaxFinal()|| this->obtenerMinComienzo() < dos.obtenerMinComienzo()){
		return true;
	}else if(this->obtenerMaxFinal() == dos.obtenerMaxFinal() || this->obtenerMinComienzo() == dos.obtenerMinComienzo()){
			return this->idRuta() < dos.idRuta();
/*	}else if(){
		return true;
	}else if(){
		return this->idRuta() < dos.idRuta();*/
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

std::string Ruta::to_string(){
	return "ID: " + std::to_string(this->idRuta()) +
			+"\tInicial: [" + std::to_string(this->obtenerOrigen().obtenerX()) + "," + std::to_string(this->obtenerOrigen().obtenerY())
			+ "]\tFinal: [" + std::to_string(this->obtenerDestino().obtenerX()) + "," + std::to_string(this->obtenerDestino().obtenerY())
			+ "] \tEarly: " + std::to_string(this->obtenerMinComienzo()) + "\tFin: " + std::to_string(this->obtenerMaxFinal());
}
