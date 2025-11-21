#include <iostream>

#include "atualizarQuarto.hpp"

using namespace std;

bool AtualizarQuarto::validar_resposta()
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

Quarto *AtualizarQuarto::modificar_quarto(Quarto *quarto)
{
    cout << "ATUALIZAR QUARTO" << endl;

    cout << "Deseja atualizar a capacidade (sim / nao): ";
    if (validar_resposta())
    {
        Capacidade capacidade = criar_capacidade();
        quarto->setCapacidade(capacidade);
    }
    cout << "Deseja atualizar a diaria (sim / nao): ";
    if (validar_resposta())
    {
        Dinheiro dinheiro = criar_dinheiro();
        quarto->setDinheiro(dinheiro);
    }

    cout << "Deseja atualizar o Ramal (sim / nao): ";
    if (validar_resposta())
    {
        Ramal ramal = criar_ramal();
        quarto->setRamal(ramal);
    }

    return quarto;
}

bool AtualizarQuarto::atualizar_quarto(Quarto *quarto)
{
    modificar_quarto(quarto);
    return CentralContainers::getContainerQuartos().atualizar(quarto);
}