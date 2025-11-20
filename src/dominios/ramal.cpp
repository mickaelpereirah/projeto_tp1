#include "ramal.hpp"
#include <stdexcept>

using namespace std;


bool Ramal::validar(int valor) {
    return (valor >= 0 && valor <= 50);
}

void Ramal::setValor(int valor) {
    if (!validar(valor)) {
        throw invalid_argument("Valor invalido");
    }
    this->valor = valor;
}