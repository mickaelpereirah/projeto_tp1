#include <iostream>

#include "atualizarHotel.hpp"

using namespace std;

bool AtualizarHotel::validar_resposta() {
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

Hotel *AtualizarHotel::modificar_hotel(Hotel *hotel)
{
    cout << "ATUALIZAR HOTEL" << endl;

    cout << "Deseja atualizar o nome (sim / nao): ";
    if (validar_resposta()) {
        Nome nome = criar_nome();
        hotel->setNome(nome);
    }
    cout << "Deseja atualizar o endereço (sim / nao): ";
    if (validar_resposta()) {
        Endereco endereco = criar_endereco();
        hotel->setEndereco(endereco);
    }
    cout << "Deseja atualizar o telefone (sim / nao): ";
    if (validar_resposta()) {
        Telefone telefone = criar_telefone();
        hotel->setTelefone(telefone);
    }

    return hotel;
}

bool AtualizarHotel::atualizar_hotel(Hotel *hotel)
{
    modificar_hotel(hotel);
    return CentralContainers::getContainerHoteis().atualizar(hotel);
}
