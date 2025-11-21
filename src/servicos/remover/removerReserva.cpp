#include "remover/removerReserva.hpp"

using namespace std;

bool RemoverReserva::remover_reserva(Reserva* reserva)
{
    if (reserva == nullptr)
    {
        return false;
    }

    string codigo_reserva = reserva->getCodigo().getValor();

    // Remover apenas a reserva (sem cascata)
    return CentralContainers::getContainerReservas().remover(codigo_reserva);
}

