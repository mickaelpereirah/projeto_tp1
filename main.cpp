#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "DOMINIOS.hpp"
#include "cadastro/cadastroHotel.hpp"
#include "centralContainers.hpp"
#include "atualizar/atualizarHotel.hpp"

using namespace std;

int main()
{
    CadastroHotel cadastro_hotel;
    AtualizarHotel atualizar_hotel;

    Hotel *h = CentralContainers::getContainerHoteis().pesquisar("AAAAA00000");
    if (h)
    {
        cout << h->getNome().getValor() << endl;
        cout << h->getEndereco().getValor() << endl;
        cout << h->getTelefone().getValor() << endl;
        cout << h->getCodigo().getValor() << endl;
    }
    else
    {
        cout << "Hotel nao existe" << endl;
    }

    cadastro_hotel.novo_hotel();
    cout << "--------------------" << endl;
    h = CentralContainers::getContainerHoteis().pesquisar("AAAAA00000");
    if (h)
    {
        cout << h->getNome().getValor() << endl;
        cout << h->getEndereco().getValor() << endl;
        cout << h->getTelefone().getValor() << endl;
        cout << h->getCodigo().getValor() << endl;
    }
    else
    {
        cout << "Hotel nao existe" << endl;
    }

    atualizar_hotel.atualizar_hotel(h); 
    cout << "--------------------" << endl;
    h = CentralContainers::getContainerHoteis().pesquisar("AAAAA00000");
    if (h)
    {
        cout << h->getNome().getValor() << endl;
        cout << h->getEndereco().getValor() << endl;
        cout << h->getTelefone().getValor() << endl;
        cout << h->getCodigo().getValor() << endl;
    }
    else
    {
        cout << "Hotel nao existe" << endl;
    }
}
