#ifndef CONTAINER_QUARTOS_HPP_INCLUDED
#define CONTAINER_QUARTOS_HPP_INCLUDED 

#include <unordered_map>
#include <string>
#include "quarto.hpp"

using namespace std;

class ContainerQuarto {
    private:
        unordered_map<int, Quarto*> container;
    public: 
        bool incluir(Quarto*);
        bool remover(int);
        Quarto *pesquisar(int);
        bool atualizar(Quarto*);

};


#endif