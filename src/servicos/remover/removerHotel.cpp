#include "remover/removerHotel.hpp"

using namespace std;

bool RemoverHotel::remover_hotel(Hotel* hotel)
{
    if (hotel == nullptr)
    {
        return false;
    }

    string codigo_hotel = hotel->getCodigo().getValor();

    // 1. Obter todos os quartos do hotel
    vector<Quarto*> quartos = ListarQuarto::listar_quartos(hotel);

    // 2. Para cada quarto, remover todas as reservas
    for (Quarto* quarto : quartos)
    {
        int numero_quarto = quarto->getNumero().getValor();
        CentralContainers::getContainerReservas().removerTodasPorQuarto(numero_quarto);
    }

    // 3. Remover todos os quartos do hotel
    CentralContainers::getContainerQuartos().removerTodosPorHotel(codigo_hotel);

    // 4. Remover o hotel
    return CentralContainers::getContainerHoteis().remover(codigo_hotel);
}

