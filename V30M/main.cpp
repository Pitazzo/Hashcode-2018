//Iñigo

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <set>
#include "Punto.hpp"
#include "Ruta.hpp"
#include "ListaCoches.hpp"
#include "Coche.hpp"

using namespace std;

list<string> fichero;
string nombreFicheroEntrada = "c_no_hurry.in";
string nobreFicheroA = "";
string nombreFicheroSalida = "a_output.op";

int numFilas;
int numColumnas;
int numVehiculos;
int numViajes;
int bonus;
int pasosSimulacion;


void escribirFichero(ListaCoche& l){
	ofstream f;
	f.open(nombreFicheroSalida);
	if(f.is_open()){
		f << l.to_string();
	}else{
		cout << "Error en la apertura del fichero de escritura" << endl;
	}
	nombreFicheroSalida[0]++;
}

void crearCoches(ListaCoche& l){
	Punto p(0, 0);
	for(int i = 0; i < numVehiculos; i++){
		Coche c(p);
		l.anyadirCoche(c);
	}
}

void leerFichero(string s){
	ifstream f;
	f.open(s);
	ListaCoche l;
	set<Ruta, less<Ruta> > setRutas;
	int fueraTiempo = 0;
	int noLlegan = 0;
	int anteriorTearly = 0;
	int anteriorTfin = 0;
	if(f.is_open()){
		f >> numFilas; f >> numColumnas; f >> numVehiculos; f >> numViajes;
		f >> bonus; f >> pasosSimulacion;
		crearCoches(l);
		int filaComienzo;
		int columnaComienzo;
		int filaFinal;
		int columnaFinal;
		int comienzoMasTemprano;
		int ultimoFinalPosible;
		int i = 0;
		int enTiempo = 0;

		while(!f.eof()){
			f >> filaComienzo; 
			if(!f.eof()){
				f >> columnaComienzo; f >> filaFinal;
				f >> columnaFinal; f >> comienzoMasTemprano; f >> ultimoFinalPosible;
				//cout << filaComienzo << " " << columnaComienzo << " " << filaFinal <<
				//" " << columnaFinal << " " << comienzoMasTemprano << " "
				//<< ultimoFinalPosible << endl;
				// if(anteriorTearly > comienzoMasTemprano){
					// cout << "SIN ORDEN EN EARLY\n";
					// //exit(1);
				// }else{
					// anteriorTearly = comienzoMasTemprano;
				// }
				// if(anteriorTfin > ultimoFinalPosible){
					// cout << "SIN ORDEN EN FIN\n";
					// exit(1);
				// }else{
					// anteriorTfin = ultimoFinalPosible;
				// }
				Punto inicio(filaComienzo, columnaComienzo);
				Punto llegada(filaFinal, columnaFinal);
				Ruta ruta(inicio, llegada, comienzoMasTemprano, ultimoFinalPosible, i);
				setRutas.insert(ruta);
				i++;
			}
		}
		i = fueraTiempo = noLlegan = anteriorTearly = anteriorTfin = 0;
		for(Ruta r: setRutas){
			if(l.calcularMasCercano(r, r.idRuta(), noLlegan)){
					enTiempo++;
				}else{
					fueraTiempo++;
				}
				//cout << "\033[33m" + l.to_stringo() + "\033[0m";
		}
		cout << "\033[32m\t" + nombreFicheroSalida + "\033[33m\nRutas: " << numViajes << " Coches: "
			<< numVehiculos << "\nEn tiempo: " << enTiempo << " Tarde: " << fueraTiempo <<
			"\n\tImposible Llegar a destino: " << noLlegan  << "\033[0m\n";
		f.close();
	}else{
		cout << "Error en la lectura del fichero" << endl;
	}
	escribirFichero(l);
}

int main(){
	fichero.push_back("a_example.in");
	fichero.push_back("b_should_be_easy.in");
	fichero.push_back("c_no_hurry.in");
	fichero.push_back("d_metropolis.in");
	fichero.push_back("e_high_bonus.in");
	for(string& s: fichero){
		leerFichero(s);
	}
//	leerFichero();
//	escribirFichero();
	
	return 0;
}
