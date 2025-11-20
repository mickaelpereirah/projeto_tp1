#include "containerHoteis.hpp"
#include <iostream>

using namespace std;

bool ContainerHotel::incluir(Hotel *hotel)
{
    string codigo = hotel->getCodigo().getValor();
    Hotel *hotel_encontrado = pesquisar(codigo);

    if (hotel_encontrado != nullptr)
    {

        return false;
    }

    container.insert({codigo, hotel});
    return true;
}

bool ContainerHotel::remover(string codigo)
{
    return container.erase(codigo);
}

Hotel *ContainerHotel::pesquisar(string codigo)
{
    if (container.count(codigo))
    {
        return container.at(codigo);
    }

    return nullptr;
}

bool ContainerHotel::atualizar(Hotel *hotel)
{
    string codigo = hotel->getCodigo().getValor();
    container[codigo] = hotel;

    return true;
}