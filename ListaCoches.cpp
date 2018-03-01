#include "ListaCoches.hpp"


        //Crea una nueva lista
        ListaCoche::ListaCoche(){

        }
        //Añade nuevo
        void ListaCoche::anyadirCoche(const Coche &c){
            this->listCoche.push_back(c);
        }
        //Calcular ruta proxima
        void ListaCoche::calcularMasCercano(Ruta r, int i){
            Coche* min = &(this->listCoche.front());
            int distMin = min->tiempoRestante()+ r.obtenerOrigen().distancia(min->destinoActual())  -r.obtenerMinComienzo();
            int otraDist;
            int max = 0;
            Coche* cocheMax = min;
            bool hayMax = false;
            bool hayCoche = false;
            int minPeor = abs(distMin);
            Coche* peorCoche = min;
            for(Coche& c: this->listCoche){
                  otraDist = c.tiempoRestante()+ r.obtenerOrigen().distancia(c.destinoActual())-r.obtenerMinComienzo();
                  if(otraDist == 0){
                  	     min = &c;
                  	     hayMax = true;
                  	     hayCoche = true;
                    	break;
                  }else if(otraDist < 0 && otraDist > distMin){
                  		min = &c;
                  		distMin = otraDist;
                  		hayCoche = true;
                  }else if((c.tiempoRestante()+ r.obtenerOrigen().distancia(c.destinoActual())) < r.obtenerMaxFinal()){
                  		if(max < c.tiempoRestante()+ r.obtenerOrigen().distancia(c.destinoActual())){
		             		cocheMax = &c;
		             		max = c.tiempoRestante()+ r.obtenerOrigen().distancia(c.destinoActual());
		             		hayMax = true;
		             		hayCoche = true;
		             	}
                  }else{
                  	if(abs(c.tiempoRestante()+ r.obtenerOrigen().distancia(c.destinoActual())  -r.obtenerMinComienzo()) >= minPeor){
                  		minPeor = abs(c.tiempoRestante()+ r.obtenerOrigen().distancia(c.destinoActual())  -r.obtenerMinComienzo());
                  		peorCoche = &c;
                  	}
                  }
//                if(otraDist = (abs(c.tiempoRestante()+ r.obtenerOrigen().distancia(c.destinoActual())  -r.obtenerMinComienzo())) < distMin){
//                    min = &c;
//                    distMin = otraDist;
//                }
                
            }
            if(hayCoche && hayMax){
            	cocheMax->anyadirRuta(r,i);
            }else if(hayCoche){
            	min->anyadirRuta(r, i);
            }else{
            	peorCoche->anyadirRuta(r,i);
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
