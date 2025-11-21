#ifndef CONTAINER_HOTEIS_HPP_INCLUDED
#define CONTAINER_HOTEIS_HPP_INCLUDED 

#include <unordered_map>
#include <vector>
#include <string>
#include "hotel.hpp"

using namespace std;

class ContainerHotel {
    private:
        unordered_map<string, vector<Hotel*>> container;  // Chave: email_gerente
    public: 
        bool incluir(Hotel*, string email_gerente);
        bool remover(string codigo);
        bool removerTodosPorGerente(string email_gerente);  // Remove todos os hotéis de um gerente
        vector<Hotel*> pesquisar(string email_gerente);  // Retorna todos os hotéis do gerente
        Hotel* pesquisarPorCodigo(string codigo);  // Busca por código do hotel
        bool atualizar(Hotel*);

};


#endif