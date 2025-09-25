#include <string>
#include <cctype>
#include "dominios.hpp"

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

//--------------------------------------------------------------------------------------------------------------------------------------------------//
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

bool checar_caracteres(string caracteres){

    for(int i = 0; i < caracteres.size(); i++){
        if(!isalnum(caracteres[i])){
            return false;
        }
    }
    return true;
}

bool Caracteres::validar(string caracteres){
    if(caracteres.size() != 10)
        return false;
    return checar_caracteres(caracteres);
}

bool Caracteres::setValor(string caracteres){
    if(validar(caracteres)){
        this->caracteres = caracteres;
        return true;
    }
    return false;
}
