#include "containerQuartos.hpp"
#include <iostream>

using namespace std;

bool ContainerQuarto::incluir(Quarto *quarto, string codigo_hotel)
{
    // Verificar se o quarto já existe (por número)
    int numero_quarto = quarto->getNumero().getValor();
    Quarto *quarto_encontrado = pesquisarPorNumero(numero_quarto);

    if (quarto_encontrado != nullptr)
    {
        return false;  // Quarto já existe
    }

    // Adicionar ao vector do hotel
    container[codigo_hotel].push_back(quarto);
    return true;
}

bool ContainerQuarto::remover(int numero)
{
    // Iterar sobre todos os hotéis para encontrar o quarto
    for (auto& par : container)
    {
        vector<Quarto*>& quartos = par.second;
        for (auto it = quartos.begin(); it != quartos.end(); ++it)
        {
            if ((*it)->getNumero().getValor() == numero)
            {
                quartos.erase(it);
                return true;
            }
        }
    }
    return false;
}

bool ContainerQuarto::removerTodosPorHotel(string codigo_hotel)
{
    if (container.count(codigo_hotel))
    {
        container.erase(codigo_hotel);  // Remove todos os quartos do hotel
        return true;
    }
    return false;
}

vector<Quarto*> ContainerQuarto::pesquisar(string codigo_hotel)
{
    if (container.count(codigo_hotel))
    {
        return container.at(codigo_hotel);
    }
    return vector<Quarto*>();  // Retorna vector vazio
}

Quarto* ContainerQuarto::pesquisarPorNumero(int numero)
{
    // Iterar sobre todos os hotéis para encontrar o quarto
    for (auto& par : container)
    {
        vector<Quarto*>& quartos = par.second;
        for (Quarto* quarto : quartos)
        {
            if (quarto->getNumero().getValor() == numero)
            {
                return quarto;
            }
        }
    }
    return nullptr;
}

bool ContainerQuarto::atualizar(Quarto *quarto_atualizado)
{
    int numero_quarto = quarto_atualizado->getNumero().getValor();
    
    // Encontrar e atualizar o quarto
    for (auto& par : container)
    {
        vector<Quarto*>& quartos = par.second;
        for (Quarto*& q : quartos)
        {
            if (q->getNumero().getValor() == numero_quarto)
            {
                q = quarto_atualizado;  // Atualiza o ponteiro
                return true;
            }
        }
    }
    return false;
}