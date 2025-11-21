#ifndef CONTAINER_QUARTOS_HPP_INCLUDED
#define CONTAINER_QUARTOS_HPP_INCLUDED 

#include <unordered_map>
#include <vector>
#include <string>
#include "quarto.hpp"

using namespace std;

class ContainerQuarto {
    private:
        unordered_map<string, vector<Quarto*>> container;  // Chave: codigo_hotel
    public: 
        bool incluir(Quarto*, string codigo_hotel);
        bool remover(int numero);
        vector<Quarto*> pesquisar(string codigo_hotel);  // Retorna todos os quartos do hotel
        Quarto* pesquisarPorNumero(int numero);  // Busca por número do quarto
        bool atualizar(Quarto*);

};


#endif