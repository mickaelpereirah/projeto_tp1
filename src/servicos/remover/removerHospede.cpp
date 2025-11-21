#include "remover/removerHospede.hpp"

using namespace std;

bool RemoverHospede::remover_hospede(Hospede* hospede)
{
    if (hospede == nullptr)
    {
        return false;
    }

    string email_hospede = hospede->getEmail().getValor();

    // 1. Remover todas as reservas do hóspede
    CentralContainers::getContainerReservas().removerTodasPorHospede(email_hospede);

    // 2. Remover o hóspede
    return CentralContainers::getContainerHospedes().remover(email_hospede);
}

