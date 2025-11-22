#include "nome.hpp"
#include <cctype>
#include <stdexcept>

bool Nome::validar(string texto)
{
    int tamanho = texto.length();

    if (tamanho < 5 || tamanho > 20)
    {
        return false;
    }

    if (texto[tamanho - 1] == ' ')
    {
        return false;
    }

    bool proximoDeveSerMaiusculo = true;

    for (int i = 0; i < tamanho; i++)
    {
        char atual = texto[i];

        if (!isalpha(atual) && atual != ' ')
        {
            return false;
        }

        if (proximoDeveSerMaiusculo)
        {
            if (!isupper(atual))
            {
                return false;
            }
            proximoDeveSerMaiusculo = false;
        }

        if (atual == ' ')
        {
            if (i < tamanho - 1 && !isalpha(texto[i + 1]))
            {
                return false;
            }
            proximoDeveSerMaiusculo = true;
        }
    }
    return true;
}

void Nome::setValor(string texto)
{
    if (!validar(texto))
    {
        throw std::invalid_argument("Nome invalido");
    }
    this->texto = texto;
}
