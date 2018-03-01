//Iñigo

#include <iostream>
#include <fstream>
#include <string>
#include "Punto.hpp"
#include "Ruta.hpp"

using namespace std;

string nombreFichero = "e_high_bonus.in";
int numFilas;
int numColumnas;
int numVehiculos;
int numViajes;
int bonus;
int pasosSimulacion;

void leerFichero(){
	ifstream f;
	f.open(nombreFichero);
	if(f.is_open()){
		f >> numFilas; f >> numColumnas; f >> numVehiculos; f >> numViajes;
		f >> bonus; f >> pasosSimulacion;
		int filaComienzo;
		int columnaComienzo;
		int filaFinal;
		int columnaFinal;
		int comienzoMasTemprano;
		int ultimoFinalPosible;
		while(!f.eof()){
			f >> filaComienzo; 
			if(!f.eof()){
				f >> columnaComienzo; f >> filaFinal;
				f >> columnaFinal; f >> comienzoMasTemprano; f >> ultimoFinalPosible;
				cout << filaComienzo << " " << columnaComienzo << " " << filaFinal <<
				" " << columnaFinal << " " << comienzoMasTemprano << " "
				<< ultimoFinalPosible << endl;
				Punto inicio = new Punto(filaComienzo, columnaComienzo);
				Punto llegada = new Punto(filaFinal, columnaFinal);
				Ruta r = new Ruta(inicio, llegada, comienzoMasTemprano, ultimoFinalPosible);
			}
		}
		f.close();
	}else{
		cout << "Error en la lectura del fichero" << endl;
	}
}

int main(){
	leerFichero();
	return 0;
}
