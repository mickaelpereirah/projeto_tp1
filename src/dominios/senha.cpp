#include "senha.hpp"
#include <cctype>
#include <string>
#include <stdexcept>

bool Senha::validar(string texto) {
    int tamanho = texto.length();

    if (tamanho != 5){
        return false;
    }

    bool temMaiuscula = false;
    bool temMinuscula = false;
    bool temDigito = false;
    bool temEspecial = false;
    string especiais = "!\"#$%&?";

    for (int i = 0; i < tamanho; i++) {
        char atual = texto[i];
        
        if (isupper(atual)) temMaiuscula = true;
        else if (islower(atual)) temMinuscula = true;
        else if (isdigit(atual)) temDigito = true;
        else if (especiais.find(atual) != string::npos) temEspecial = true;
        else return false;

        if (i < tamanho - 1) {
            char proximo = texto[i + 1];

            if (isalpha(atual) && isalpha(proximo)) {
            return false;
            }
            if (isdigit(atual) && isdigit(proximo)) {
            return false;
            }

        }
    }

    if (!temMinuscula || !temMaiuscula || !temDigito || !temEspecial) {
        return false;
    }

    return true;
}

void Senha::setValor(string texto) {
    if (!validar(texto)) {
        throw invalid_argument("Senha invalida");
    }
    this->texto = texto;
}