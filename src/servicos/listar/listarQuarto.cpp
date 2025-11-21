#include "listar/listarQuarto.hpp"

using namespace std;

vector<Quarto*> ListarQuarto::listar_quartos(Hotel* hotel)
{
    // Obter o código do hotel
    string codigo_hotel = hotel->getCodigo().getValor();

    // Buscar todos os quartos do hotel no container
    return CentralContainers::getContainerQuartos().pesquisar(codigo_hotel);
}

