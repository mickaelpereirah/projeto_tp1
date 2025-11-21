#include "remover/removerQuarto.hpp"

using namespace std;

bool RemoverQuarto::remover_quarto(Quarto* quarto)
{
    if (quarto == nullptr)
    {
        return false;
    }

    int numero_quarto = quarto->getNumero().getValor();

    // 1. Remover todas as reservas do quarto
    CentralContainers::getContainerReservas().removerTodasPorQuarto(numero_quarto);

    // 2. Remover o quarto
    return CentralContainers::getContainerQuartos().remover(numero_quarto);
}

