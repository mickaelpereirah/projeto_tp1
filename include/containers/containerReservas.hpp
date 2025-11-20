#ifndef CONTAINER_RESERVAS_HPP_INCLUDED
#define CONTAINER_RESERVAS_HPP_INCLUDED

#include <unordered_map>
#include <string>
#include "reserva.hpp"

using namespace std;

class ContainerReserva {
    private:
        unordered_map<string, Reserva*> container;
    public: 
        bool incluir(Reserva*);
        bool remover(string);
        Reserva *pesquisar(string);
        bool atualizar(Reserva*);

};


#endif