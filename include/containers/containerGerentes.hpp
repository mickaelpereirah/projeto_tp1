#ifndef CONTAINER_GERENTES_HPP_INCLUDED
#define CONTAINER_GERENTES_HPP_INCLUDED 

#include <unordered_map>
#include <string>
#include "gerente.hpp"

using namespace std;

class ContainerGerente {
    private:
        unordered_map<string, Gerente*> container;
    public: 
        bool incluir(Gerente*);
        bool remover(string);
        Gerente *pesquisar(string);
        bool atualizar(Gerente*);

};


#endif