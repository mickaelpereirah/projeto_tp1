#include <iostream>
#include <stdexcept>

#include "cadastroHotel.hpp"

using namespace std;

Hotel *CadastroHotel::criar_hotel()
{
    Hotel *h = new Hotel();

    cout << "CRIAR HOTEL" << endl;
    Nome nome = criar_nome();
    Endereco endereco = criar_endereco();
    Telefone telefone = criar_telefone();
    Codigo codigo = criar_codigo();

    h->setNome(nome);
    h->setEndereco(endereco);
    h->setTelefone(telefone);
    h->setCodigo(codigo);

    return h;
}

bool CadastroHotel::novo_hotel()
{
    Hotel *hotel = criar_hotel();
    return CentralContainers::getContainerHoteis().incluir(hotel);
}