#include "dinheiro.hpp"
#include <stdexcept>

bool Dinheiro::validar(double valor)
{
    if (valor >= 1.00 && valor <= 1000000.00)
        return true;
    return false;
}

void Dinheiro::setValor(double valor)
{
    if (!validar(valor))
    {
        throw std::invalid_argument("Valor invalido");
    }
    this->valor = static_cast<int>(valor * 100);
}