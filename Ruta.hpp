//Pedro

#pragma once
#include "Punto.hpp"

class Ruta{

	private:
		Punto inicio;
		Punto destino;
		int minInicio;
		int maxFinal;
		
	public:
		
		Ruta(Punto inicio, Punto destino, int minInicio, int maxFinal);
		
		int maxTrayecto();
		
		Punto obtenerOrigen();
		
		Punto obtenerDestino();
		
		int obtenerMinComienzo();
		
		int obtenerMaxFinal();
};
