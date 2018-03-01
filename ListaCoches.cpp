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
            int distMin = abs(min->tiempoRestante()+ r.obtenerOrigen().distancia(min->destinoActual())  -r.obtenerMinComienzo());
            int otraDist;
            for(Coche& c: this->listCoche){
                if(otraDist = (abs(c.tiempoRestante()+ r.obtenerOrigen().distancia(c.destinoActual())  -r.obtenerMinComienzo())) < distMin){
                    min = &c;
                    distMin = otraDist;
                }
                
            }
            min->anyadirRuta(r, i);
        }
        //
        string ListaCoche::to_string(){
            string rutasCoches;
            for(Coche& c: this->listCoche){
                rutasCoches = rutasCoches + c.toString() + "\n";
            }
            return rutasCoches;
        }
