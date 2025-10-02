//#include "../include/dominios/DOMINIOS.hpp"
#include "capacidade.hpp"

bool Capacidade::validar(int valor) {
    if (valor >= 1 && valor <= 4)
        return true;
    return false;
}

bool Capacidade::setValor(int valor) {
    if (validar(valor)) {
        this->valor = valor;
        return true;
    }
    return false;
}
