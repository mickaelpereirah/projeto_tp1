#include "endereco.hpp"
#include <stdexcept>
#include <cctype>

using  namespace std;

bool Endereco::validar(string texto)
{
    int tamanho = texto.length();

    if (tamanho < 5 || tamanho > 30) {
        return false;
    }

    char primeiro = texto[0];
    char ultimo = texto[tamanho - 1];

    if (primeiro == ',' ||primeiro == '.' || primeiro == ' ' ||
        ultimo == ',' || ultimo == '.' || ultimo == ' '){
        return false;
    }

    for (int i = 0; i < tamanho; i++) {
        char atual = texto[i];
        char proximo = (i < tamanho - 1) ? texto[i + 1] : '\0';

        if (!isalnum(atual) && atual != ',' && atual != '.' && atual != ' '){
            return false;
        }

        if (atual == ','){
            if (proximo == ',' || proximo == '.') {
                return false;
            }
        }
        else if (atual == '.') {
            if (proximo == ',' || proximo == '.') {
                return false;
            }
        }
        else if (atual == ' ') {
            if (proximo != '\0' && !isalnum(proximo)) {
                return false;
            }
        }
    }

    return true;
}

void Endereco::setValor(string texto)
{
    if (!validar(texto))
    {
        throw invalid_argument("Endereco invalido");
    }
    this->texto = texto;
}
