#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "DOMINIOS.hpp"
#include "cadastroHospede.hpp"
#include "quarto.hpp"
#include "containerQuartos.hpp"

#include "reserva.hpp"
#include "containerReservas.hpp"

using namespace std;

int main()
{
    CadastroHospede cadastro_hospede;

    Hospede *h = CadastroHospede::container.pesquisar("luisa@gmail.com");
    if (h)
    {
        cout << h->getNome().getValor() << endl;
        cout << h->getEmail().getValor() << endl;
        cout << h->getCartao().getValor() << endl;
        cout << h->getEndereco().getValor() << endl;
    }
    else
    {
        cout << "Hospede nao existe" << endl;
    }

    cadastro_hospede.novo_hospede();
    cout << "--------------------" << endl;
    h = CadastroHospede::container.pesquisar("luisa@gmail.com");
    if (h)
    {
        cout << h->getNome().getValor() << endl;
        cout << h->getEmail().getValor() << endl;
        cout << h->getCartao().getValor() << endl;
        cout << h->getEndereco().getValor() << endl;
    }
    else
    {
        cout << "Hospede nao existe" << endl;
    }
}
