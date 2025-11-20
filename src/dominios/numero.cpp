#include "numero.hpp"
#include <stdexcept>

using namespace std;

bool Numero::validar(int valor) {
    return (valor >= 1 && valor <= 999);
}

void Numero::setValor(int valor) {
    if (!validar(valor)) {
        throw invalid_argument("Valor invalido");
    }
    this->valor = valor;
}
