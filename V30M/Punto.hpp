//Pedro
#pragma once

class Punto{
	private:
		int x;
		int y;
	public:
		
		//Constructor por defecto
		Punto();
		
		Punto(int x, int y);
		
		int obtenerX();
		
		int obtenerY();
		
		int distancia(Punto destino);
		
};
