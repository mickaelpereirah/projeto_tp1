#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "DOMINIOS.hpp"
#include "cadastroReserva.hpp"
#include "quarto.hpp"
#include "centralContainers.hpp"

#include "reserva.hpp"

using namespace std;

int main()
{
    CadastroReserva cadastro_reserva;

    Reserva *r = CentralContainers::getContainerReservas().pesquisar("AAAAA00000");
    if (r)
    {
        cout << r->getChegada().getValor() << endl;
        cout << r->getPartida().getValor() << endl;
        cout << r->getCodigo().getValor() << endl;
        cout << r->getDinheiro().getValor() << endl;
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
        cout << r->getCodigo().getValor() << endl;
        cout << r->getDinheiro().getValor() << endl;
    }
    else
    {
        cout << "Reserva nao existe" << endl;
    }
}
