#include <iostream>

#include "atualizarHospede.hpp"

using namespace std;

bool AtualizarHospede::validar_resposta()
{
    string resposta;
    while (true)
    {
        getline(cin, resposta);
        if (resposta == "sim")
        {
            return true;
        }
        else if (resposta == "nao")
        {
            return false;
        }
        else
        {
            cout << "Responda apenas 'sim' ou 'nao'." << endl;
        }
    }
}

Hospede *AtualizarHospede::modificar_hospede(Hospede *hospede)
{
    cout << "ATUALIZAR HOSPEDE" << endl;

    cout << "Deseja atualizar o nome (sim / nao): ";
    if (validar_resposta())
    {
        Nome nome = criar_nome();
        hospede->setNome(nome);
    }
    cout << "Deseja atualizar o endereço (sim / nao): ";
    if (validar_resposta())
    {
        Endereco endereco = criar_endereco();
        hospede->setEndereco(endereco);
    }
    cout << "Deseja atualizar o cartao (sim / nao): ";
    if (validar_resposta())
    {
        Cartao cartao = criar_cartao();
        hospede->setCartao(cartao);
    }

    return hospede;
}

bool AtualizarHospede::atualizar_hospede(Hospede *hospede)
{
    modificar_hospede(hospede);
    return CentralContainers::getContainerHospedes().atualizar(hospede);
}