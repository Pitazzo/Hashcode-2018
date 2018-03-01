//Iñigo

#include <iostream>
#include <fstream>
#include <string>
#include "Punto.hpp"
#include "Ruta.hpp"
#include "ListaCoches.hpp"
#include "Coche.hpp"

using namespace std;

string nombreFicheroEntrada = "c_no_hurry.in";
string nombreFicheroSalida = "c_output.op";

int numFilas;
int numColumnas;
int numVehiculos;
int numViajes;
int bonus;
int pasosSimulacion;
ListaCoche l;

void escribirFichero(){
	ofstream f;
	f.open(nombreFicheroSalida);
	if(f.is_open()){
		f << l.to_string();
	}else{
		cout << "Error en la apertura del fichero de escritura" << endl;
	}
}

void crearCoches(){
	Punto p(0, 0);
	for(int i = 0; i < numVehiculos; i++){
		Coche c(p);
		l.anyadirCoche(c);
	}
}

void leerFichero(){
	ifstream f;
	f.open(nombreFicheroEntrada);
	if(f.is_open()){
		f >> numFilas; f >> numColumnas; f >> numVehiculos; f >> numViajes;
		f >> bonus; f >> pasosSimulacion;
		crearCoches();
		int filaComienzo;
		int columnaComienzo;
		int filaFinal;
		int columnaFinal;
		int comienzoMasTemprano;
		int ultimoFinalPosible;
		int i = 0;
		while(!f.eof()){
			f >> filaComienzo; 
			if(!f.eof()){
				f >> columnaComienzo; f >> filaFinal;
				f >> columnaFinal; f >> comienzoMasTemprano; f >> ultimoFinalPosible;
				cout << filaComienzo << " " << columnaComienzo << " " << filaFinal <<
				" " << columnaFinal << " " << comienzoMasTemprano << " "
				<< ultimoFinalPosible << endl;
				Punto inicio(filaComienzo, columnaComienzo);
				Punto llegada(filaFinal, columnaFinal);
				Ruta ruta(inicio, llegada, comienzoMasTemprano, ultimoFinalPosible);
				l.calcularMasCercano(ruta, i);
				i++;
			}
		}
		f.close();
	}else{
		cout << "Error en la lectura del fichero" << endl;
	}
}

int main(){
	leerFichero();
	escribirFichero();
	
	return 0;
}
