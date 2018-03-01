#include "Punto.hpp"
#include <stdlib.h> 

Punto::Punto(int x, int y){
	this->x = x;
	this->y = y;
}

int Punto::obtenerX(){
	return this->x;
}

int Punto::obtenerY(){
	return this->y;
}

int Punto::distancia(Punto destino){
	return abs(this->x - destino.x ) + abs(this->y - destino.y);
 }
