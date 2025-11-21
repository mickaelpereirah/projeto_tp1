#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "DOMINIOS.hpp"
#include "cadastro/cadastroReserva.hpp"
#include "centralContainers.hpp"
#include "atualizar/atualizarReserva.hpp"

using namespace std;

int main()
{
    CadastroReserva cadastro_reserva;
    AtualizarReserva atualizar_reserva;

    Reserva *r = CentralContainers::getContainerReservas().pesquisar("AAAAA00000");
    if (r)
    {
        cout << r->getChegada().getValor() << endl;
        cout << r->getPartida().getValor() << endl;
        cout << r->getDinheiro().getValor() << endl;
        cout << r->getCodigo().getValor() << endl;
    }
    else
    {
        cout << "Reserva nao existe" << endl;
    }

    cadastro_reserva.nova_reserva();
    cout << "--------------------" << endl;
    r = CentralContainers::getContainerReservas().pesquisar("AAAAA00000");
    if (r)
    {
        cout << r->getChegada().getValor() << endl;
        cout << r->getPartida().getValor() << endl;
        cout << r->getDinheiro().getValor() << endl;
        cout << r->getCodigo().getValor() << endl;
    }
    else
    {
        cout << "Reserva nao existe" << endl;
    }

    atualizar_reserva.atualizar_reserva(r);
    cout << "--------------------" << endl;
    r = CentralContainers::getContainerReservas().pesquisar("AAAAA00000");
    if (r)
    {
        cout << r->getChegada().getValor() << endl;
        cout << r->getPartida().getValor() << endl;
        cout << r->getDinheiro().getValor() << endl;
        cout << r->getCodigo().getValor() << endl;
    }
    else
    {
        cout << "Reserva nao existe" << endl;
    }
}
