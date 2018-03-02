#include "ListaCoches.hpp"


		//Crea una nueva lista
		ListaCoche::ListaCoche(){

		}
		ListaCoche::~ListaCoche(){
			
		}
		//Añade nuevo
		void ListaCoche::anyadirCoche(const Coche &c){
			this->listCoche.push_back(c);
		}
		//Calcular ruta proxima
		bool ListaCoche::calcularMasCercano(Ruta r, int i,int& noLlegan){
			Coche* min = &(this->listCoche.front());
			Coche* max = min;
			int distMin = min->tiempoRestante()+r.obtenerOrigen().distancia(min->destinoActual());
			int otraDist;
			int delay = 0;
			bool esPosible = (r.obtenerMaxFinal()-r.obtenerMinComienzo()) < r.obtenerOrigen().distancia(r.obtenerDestino());
			bool hayMax = false;
			for(Coche& c: this->listCoche){
				if((otraDist=(c.tiempoRestante()+r.obtenerOrigen().distancia(c.destinoActual()))) <= r.obtenerMinComienzo()){
					if(otraDist < distMin){
						hayMax = true;
						min = &c;
						distMin = otraDist;
						delay = 0;
					}
				}else{
					if(!hayMax){
						if(delay == 0){
							delay = otraDist - r.obtenerMinComienzo();
							max = &c;
						}else if(delay > otraDist - r.obtenerMinComienzo()){
							delay = otraDist - r.obtenerMinComienzo();
							max = &c;
						}
					}
				}
			}
			
			// int max = 0;
			// Coche* cocheMax = min;
			// 
			// bool hayCoche = false;
			// int minPeor = abs(distMin);
			// Coche* peorCoche = min;
			// for(Coche& c: this->listCoche){
			//       otraDist = c.tiempoRestante()+ r.obtenerOrigen().distancia(c.destinoActual())-r.obtenerMinComienzo();
			//       if(otraDist == 0){
			//       	     min = &c;
			//       	     hayMax = true;
			//       	     hayCoche = true;
			//         	break;
			//       }else if(otraDist < 0 && otraDist > distMin){
			//       		min = &c;
			//       		distMin = otraDist;
			//       		hayCoche = true;
			//       }else if((c.tiempoRestante()+ r.obtenerOrigen().distancia(c.destinoActual())) < r.obtenerMaxFinal()){
			//       		if(max < c.tiempoRestante()+ r.obtenerOrigen().distancia(c.destinoActual())){
			//          		cocheMax = &c;
			//          		max = c.tiempoRestante()+ r.obtenerOrigen().distancia(c.destinoActual());
			//          		hayMax = true;
			//          		hayCoche = true;
			//          	}
			//       }else{
			//       	if(abs(c.tiempoRestante()+ r.obtenerOrigen().distancia(c.destinoActual())  -r.obtenerMinComienzo()) >= minPeor){
			//       		minPeor = abs(c.tiempoRestante()+ r.obtenerOrigen().distancia(c.destinoActual())  -r.obtenerMinComienzo());
			//       		peorCoche = &c;
			//       	}
			//       }
//                if(otraDist = (abs(c.tiempoRestante()+ r.obtenerOrigen().distancia(c.destinoActual())  -r.obtenerMinComienzo())) < distMin){
//                    min = &c;
//                    distMin = otraDist;
//                }
				
			//}
			if(hayMax){
				min->anyadirRuta(r,i, 0);
				if (max->tiempoRestante() <= r.obtenerMaxFinal()){
					return true;
				}else{
					//cout << "NO LLEEGOOOO\n";
					noLlegan++;
					return false;
				}
			/*}else if(hayCoche){
				min->anyadirRuta(r, i);
			*/}else{
				max->anyadirRuta(r,i, delay);
				return (max->tiempoRestante() <= r.obtenerMaxFinal());
			}
		}
		//
		string ListaCoche::to_string(){
			string rutasCoches;
			for(Coche& c: this->listCoche){
				rutasCoches = rutasCoches + c.toString() + "\n";
			}
			return rutasCoches;
		}
		string ListaCoche::to_stringo(){	
			string rutasCoches;
			for(Coche& c: this->listCoche){
				string uno = c.toString();
				if(uno[0] != '0'){
					rutasCoches = rutasCoches + uno + "\n";
				}
			}
			return rutasCoches;
		}