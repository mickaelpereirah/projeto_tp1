#include "containerHoteis.hpp"
#include <iostream>

using namespace std;

bool ContainerHotel::incluir(Hotel *hotel, string email_gerente)
{
    // Verificar se o hotel já existe (por código)
    string codigo = hotel->getCodigo().getValor();
    Hotel *hotel_encontrado = pesquisarPorCodigo(codigo);

    if (hotel_encontrado != nullptr)
    {
        return false;  // Hotel já existe
    }

    // Adicionar ao vector do gerente
    container[email_gerente].push_back(hotel);
    return true;
}

bool ContainerHotel::remover(string codigo)
{
    // Iterar sobre todos os gerentes para encontrar o hotel
    for (auto& par : container)
    {
        vector<Hotel*>& hoteis = par.second;
        for (auto it = hoteis.begin(); it != hoteis.end(); ++it)
        {
            if ((*it)->getCodigo().getValor() == codigo)
            {
                hoteis.erase(it);
                return true;
            }
        }
    }
    return false;
}

bool ContainerHotel::removerTodosPorGerente(string email_gerente)
{
    if (container.count(email_gerente))
    {
        container.erase(email_gerente);  // Remove todos os hotéis do gerente
        return true;
    }
    return false;
}

vector<Hotel*> ContainerHotel::pesquisar(string email_gerente)
{
    if (container.count(email_gerente))
    {
        return container.at(email_gerente);
    }
    return vector<Hotel*>();  // Retorna vector vazio
}

Hotel* ContainerHotel::pesquisarPorCodigo(string codigo)
{
    // Iterar sobre todos os gerentes para encontrar o hotel
    for (auto& par : container)
    {
        vector<Hotel*>& hoteis = par.second;
        for (Hotel* hotel : hoteis)
        {
            if (hotel->getCodigo().getValor() == codigo)
            {
                return hotel;
            }
        }
    }
    return nullptr;
}

bool ContainerHotel::atualizar(Hotel *hotel)
{
    string codigo = hotel->getCodigo().getValor();
    
    // Encontrar e atualizar o hotel
    for (auto& par : container)
    {
        vector<Hotel*>& hoteis = par.second;
        for (Hotel*& h : hoteis)
        {
            if (h->getCodigo().getValor() == codigo)
            {
                h = hotel;  // Atualiza o ponteiro
                return true;
            }
        }
    }
    return false;
}