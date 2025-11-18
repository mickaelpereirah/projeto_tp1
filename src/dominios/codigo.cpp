//#include "../include/dominios/DOMINIOS.hpp"
#include "codigo.hpp"
#include <cctype>
#include <string>
#include <stdexcept>

using namespace std;

bool checar_caracteres(string caracteres){

    for(int i = 0; i < caracteres.size(); i++){
        if(!isalnum(caracteres[i])){
            return false;
        }
    }
    return true;
}

bool Codigo::validar(string caracteres){
    if(caracteres.size() != 10)
        return false;
    return checar_caracteres(caracteres);
}

void Codigo::setValor(string caracteres){
    if(!validar(caracteres)){
        throw invalid_argument("Codigo invalido");
    }
    this->caracteres = caracteres;
}
