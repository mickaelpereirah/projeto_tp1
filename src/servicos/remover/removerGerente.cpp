#include "remover/removerGerente.hpp"

using namespace std;

bool RemoverGerente::remover_gerente(Gerente* gerente)
{
    if (gerente == nullptr)
    {
        return false;
    }

    string email_gerente = gerente->getEmail().getValor();

    // 1. Obter todos os hotéis do gerente
    vector<Hotel*> hoteis = ListarHotel::listar_hoteis(gerente);

    // 2. Para cada hotel, remover usando o serviço RemoverHotel (que já remove quartos e reservas)
    for (Hotel* hotel : hoteis)
    {
        RemoverHotel::remover_hotel(hotel);
    }

    // 3. Remover o gerente
    return CentralContainers::getContainerGerentes().remover(email_gerente);
}

