//Pedro

#pragma once
#include "Punto.hpp"
#include <string>

class Ruta{

	private:
		Punto inicio;
		Punto destino;
		int minInicio;
		int maxFinal;
		int id;
	public:
		Ruta();

		Ruta(Punto inicio, Punto destino, int minInicio, int maxFinal, int i);

		bool operator<(Ruta dos);
		
		bool operator<(const Ruta dos) const;

		int idRuta();

		int maxTrayecto();
		
		Punto obtenerOrigen();
		
		Punto obtenerDestino();
		
		int obtenerMinComienzo();
		
		int obtenerMaxFinal();
		std::string to_string();
};
