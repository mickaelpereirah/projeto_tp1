#include "containerReservas.hpp"
#include <iostream>

using namespace std;

bool ContainerReserva::incluir(Reserva *reserva)
{
    string codigo_reserva = reserva->getCodigo().getValor();
    Reserva *reserva_encontrada = pesquisar(codigo_reserva);

    if (reserva_encontrada != nullptr)
    {
        return false;
    }
    else
    {
        container.insert({codigo_reserva, reserva});
        return true;
    }
}

bool ContainerReserva::remover(string codigo)
{
    return container.erase(codigo);
}

Reserva *ContainerReserva::pesquisar(string codigo)
{
    if (container.count(codigo))
    { // retorna 0 se não existir e 1 se existir
        return container.at(codigo);
    }
    return nullptr;
}

bool ContainerReserva::atualizar(Reserva *reserva_atualizada)
{
    string codigo_reserva = reserva_atualizada->getCodigo().getValor();
    container[codigo_reserva] = reserva_atualizada;

    return true;
}