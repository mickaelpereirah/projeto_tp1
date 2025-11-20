#ifndef CONTAINER_HOSPEDES_HPP_INCLUDED
#define CONTAINER_HOSPEDES_HPP_INCLUDED 

#include <unordered_map>
#include <string>
#include "hospede.hpp"

using namespace std;

class ContainerHospede {
    private:
        unordered_map<string, Hospede*> container;
    public: 
        bool incluir(Hospede*);
        bool remover(string);
        Hospede *pesquisar(string);
        bool atualizar(Hospede*);

};


#endif