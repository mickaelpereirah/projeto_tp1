#include <iostream>
#include <stdexcept>

#include "cadastroHospede.hpp"

using namespace std;


Hospede *CadastroHospede::criar_hospede()
{
    Hospede *h = new Hospede();

    cout << "CRIAR HOSPEDE" << endl;
    Nome nome = criar_nome();
    Cartao cartao = criar_cartao();
    Email email = criar_email();
    Endereco endereco = criar_endereco();

    h->setNome(nome);
    h->setCartao(cartao);
    h->setEmail(email);
    h->setEndereco(endereco);

    return h;
}

bool CadastroHospede::novo_hospede()
{
    Hospede *hospede = criar_hospede();
    return CentralContainers::getContainerHospedes().incluir(hospede);
}
