#include "listar/listarHotel.hpp"

using namespace std;

vector<Hotel*> ListarHotel::listar_hoteis(Gerente* gerente)
{
    // Obter o email do gerente
    string email_gerente = gerente->getEmail().getValor();

    // Buscar todos os hotéis do gerente no container
    return CentralContainers::getContainerHoteis().pesquisar(email_gerente);
}
