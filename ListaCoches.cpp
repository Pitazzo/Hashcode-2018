#include "ListaCoches.hpp"


        //Crea una nueva lista
        ListaCoche::ListaCoche(){

        }
        //Añade nuevo
        void ListaCoche::AnyadirCoche(const Coche &c){
            this->listCoche.push_back(c);
        }
        //Calcular ruta proxima
        Coche ListaCoche::CalcularMasCercano(Ruta r){
            for(Coche& c: this->listCoche){
                if(!c.estaEnRuta() && (c.tiempoRestante()+ r.obtenerOrigen().distancia(c.destinoActual())  -r.obtenerMinComienzo())){

                }
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
