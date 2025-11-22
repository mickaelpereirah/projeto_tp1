#include "telefone.hpp"
#include <cctype>
#include <stdexcept>

bool Telefone::validar(string texto)
{
    int tamanho = texto.length();

    if (tamanho != 14)
    {
        return false;
    }

    if (texto[0] != '+')
    {
        return false;
    }

    for (int i = 1; i < tamanho; i++)
    {
        if (!isdigit(texto[i]))
        {
            return false;
        }
    }

    return true;
}

void Telefone::setValor(string texto)
{
    if (!validar(texto))
    {
        throw std::invalid_argument("Telefone invalido");
    }
    this->numero = texto;
}
