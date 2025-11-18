//#include "../include/dominios/DOMINIOS.hpp"
#include "capacidade.hpp"
#include <stdexcept>

using namespace std;

bool Capacidade::validar(int valor) {
    if (valor >= 1 && valor <= 4)
        return true;
    return false;
}

void Capacidade::setValor(int valor) {
    if (!validar(valor)) {
        throw invalid_argument("Valor invalido");
    }
    this->valor = valor;
}