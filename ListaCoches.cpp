#include "ListaCoches.hpp"


        //Crea una nueva lista
        ListaCoches::ListaCoche(){

        }
        //Añade nuevo
        void ListaCoches::AnyadirCoche(const Coche &c){
            this->listCoche.push_back(c);
        }
        //Calcular ruta proxima
        Coche ListaCoches::CalcularMasCercano(Ruta r){
            for(Coche& c: this->listCoche){
                if(!c.estaEnRuta() && (c.tiempoRestante()+   -r.obtobtenerMinComienzo)){

                }
            }
        }
        //
        string ListaCoches::to_string(){

        }
