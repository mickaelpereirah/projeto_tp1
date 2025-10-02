//#include "../include/dominios/DOMINIOS.hpp"
#include "cartao.hpp"
#include <string>

using namespace std;

bool verificarLuhn(string digitos){
    int total = 0;

    for(int i = 15; i >= 0; i--){
        int atual = digitos[i] - '0'; //8
        if(i % 2 == 0){
            atual *= 2;
            if (atual > 9)
                atual -= 9;
        }
        total += atual;
    }

    return total % 10 == 0;
}

bool Cartao::validar(string digitos){
    if (digitos.size() != 16)
        return false;
    return verificarLuhn(digitos);
}

bool Cartao::setValor(string digitos){
    if(validar(digitos)){
        this->digitos = digitos;
        return true;
    }
    return false;

}
