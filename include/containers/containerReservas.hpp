#ifndef CONTAINER_RESERVAS_HPP_INCLUDED
#define CONTAINER_RESERVAS_HPP_INCLUDED

#include <unordered_map>
#include <vector>
#include <string>
#include "reserva.hpp"

using namespace std;

class ContainerReserva {
    private:
        unordered_map<int, unordered_map<string, vector<Reserva*>>> container;
        // Chave externa: numero_quarto
        // Chave interna: email_hospede
        // Valor: vector de Reserva*
    public: 
        bool incluir(Reserva*, int numero_quarto, string email_hospede);
        bool remover(string codigo);
        Reserva* pesquisar(string codigo);  // Busca por código da reserva
        vector<Reserva*> pesquisar(int numero_quarto, string email_hospede);  // Busca por quarto + hóspede
        vector<Reserva*> pesquisarPorQuarto(int numero_quarto);  // Todas reservas do quarto
        vector<Reserva*> pesquisarPorHospede(string email);  // Todas reservas do hóspede
        bool atualizar(Reserva*);

};


#endif