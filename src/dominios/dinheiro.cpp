#include "dinheiro.hpp"

bool Dinheiro::validar(double valor)
{
    if (valor >= 1 && valor <= 100000000)
        return true;
    return false;
}

bool Dinheiro::setValor(double valor)
{
    valor *= 100;
    if (validar(valor))
    {
        this->valor = static_cast<int>(valor);
        return true;
    }
    return false;
}
