#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "DOMINIOS.hpp"
#include "cadastroHospede.hpp"
#include "centralContainers.hpp"
#include "atualizarHospede.hpp"

using namespace std;

int main()
{
    CadastroHospede cadastro_hospede;
    AtualizarHospede atualizar_hospede;

    Hospede *h = CentralContainers::getContainerHospedes().pesquisar("luisa@gmail.com");
    if (h)
    {
        cout << h->getNome().getValor() << endl;
        cout << h->getEndereco().getValor() << endl;
        cout << h->getCartao().getValor() << endl;
    }
    else
    {
        cout << "Hospede nao existe" << endl;
    }

    cadastro_hospede.novo_hospede();
    cout << "--------------------" << endl;
    h = CentralContainers::getContainerHospedes().pesquisar("luisa@gmail.com");
    if (h)
    {
        cout << h->getNome().getValor() << endl;
        cout << h->getEndereco().getValor() << endl;
        cout << h->getCartao().getValor() << endl;
    }
    else
    {
        cout << "Hospede nao existe" << endl;
    }

    atualizar_hospede.atualizar_hospede(h);
    cout << "--------------------" << endl;
    h = CentralContainers::getContainerHospedes().pesquisar("luisa@gmail.com");
    if (h)
    {
        cout << h->getNome().getValor() << endl;
        cout << h->getEndereco().getValor() << endl;
        cout << h->getCartao().getValor() << endl;
    }
    else
    {
        cout << "Hospede nao existe" << endl;
    }
}
