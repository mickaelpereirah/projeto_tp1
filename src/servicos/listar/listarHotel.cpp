#include <iostream>

#include "atualizarGerente.hpp"

using namespace std;

bool AtualizarGerente::validar_resposta() {
    string resposta;
    while (true) {
        getline(cin, resposta);
        if (resposta == "sim") {
            return true;
        }
        else if (resposta == "nao") {
            return false;
        }
        else {
            cout << "Responda apenas 'sim' ou 'nao'." << endl;
        }
    }
}

Gerente *AtualizarGerente::modificar_gerente(Gerente *gerente)
{
    cout << "ATUALIZAR GERENTE" << endl;
    
    cout << "Deseja atualizar o nome (sim / nao): ";
    if (validar_resposta()) {
        Nome nome = criar_nome();
        gerente->setNome(nome);
    }
    cout << "Deseja atualizar o ramal (sim / nao): ";
    if (validar_resposta()) {
        Ramal ramal = criar_ramal();
        gerente->setRamal(ramal);
    }
    cout << "Deseja atualizar a senha (sim / nao): ";
    if (validar_resposta()) {
        Senha senha = criar_senha();
        gerente->setSenha(senha);
    }
    
    return gerente;
}

bool AtualizarGerente::atualizar_gerente(Gerente *gerente)
{
    modificar_gerente(gerente);
    return CentralContainers::getContainerGerentes().atualizar(gerente);
}