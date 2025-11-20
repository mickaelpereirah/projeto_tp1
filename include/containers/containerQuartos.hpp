#ifndef CONTAINER_QUARTOS_HPP_INCLUDED
#define CONTAINER_QUARTOS_HPP_INCLUDED 

#include <unordered_map>
#include <string>
#include "quarto.hpp"

using namespace std;

class ContainerQuarto {
    private:
        unordered_map<string, Quarto*> container;
    public: 
        bool incluir(Quarto*);
        bool remover(string);
        Quarto *pesquisar(string);
        bool atualizar(Quarto*);

};


#endif