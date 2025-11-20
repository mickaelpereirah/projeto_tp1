#ifndef CONTAINER_HOTEIS_HPP_INCLUDED
#define CONTAINER_HOTEIS_HPP_INCLUDED 

#include <unordered_map>
#include <string>
#include "hotel.hpp"

using namespace std;

class ContainerHotel {
    private:
        unordered_map<string, Hotel*> container;
    public: 
        bool incluir(Hotel*);
        bool remover(string);
        Hotel *pesquisar(string);
        bool atualizar(Hotel*);

};


#endif