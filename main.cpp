#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "DOMINIOS.hpp"
#include "quarto.hpp"
#include "containerQuartos.hpp"

#include "reserva.hpp"
#include "containerReservas.hpp"

using namespace std;

int main()
{
    ContainerReserva container;

    Codigo c;
    string codigo;

    cout << "Digite o codigo: ";
    cin >> codigo;
    c.setValor(codigo);

    Data ch;
    string chegada;

    cout << "Digite a data de chegada: ";
    cin >> chegada;
    ch.setValor(chegada);

    Data p;
    string partida;

    cout << "Digite a data da partida: ";
    cin >> partida;
    p.setValor(partida);

    Dinheiro d;
    int total_reserva;

    cout << "Digite o valor total da reserva: ";
    cin >> total_reserva;
    d.setValor(total_reserva);

    Reserva *reserva = new Reserva();
    reserva->setCodigo(c);
    reserva->setChegada(ch);
    reserva->setPartida(p);
    reserva->setDinheiro(d);

    Reserva *reserva_encontrada = container.pesquisar(codigo);
    if (reserva_encontrada)
    {
        cout << "Reserva existe" << endl;
        cout << reserva_encontrada->getCodigo().getValor() << endl;
        cout << reserva_encontrada->getChegada().getValor() << endl;
        cout << reserva_encontrada->getPartida().getValor() << endl;
        cout << reserva_encontrada->getDinheiro().getValor() << endl;
    }
    else
    {
        cout << "Reserva inexistente" << endl; // ESPERADO
    }

    container.incluir(reserva);

    reserva_encontrada = container.pesquisar(codigo);
    if (reserva_encontrada)
    {
        cout << "Reserva existe" << endl; // ESPERADO
        cout << reserva_encontrada->getCodigo().getValor() << endl;
        cout << reserva_encontrada->getChegada().getValor() << endl;
        cout << reserva_encontrada->getPartida().getValor() << endl;
        cout << reserva_encontrada->getDinheiro().getValor() << endl;
    }
    else
    {
        cout << "Reserva inexistente" << endl;
    }

    Data ch_nova;
    ch_nova.setValor("14-MAI-2001");
    Data p_nova;
    p_nova.setValor("24-MAI-2001");
    Dinheiro d_novo;
    d_novo.setValor(15.99);
    reserva_encontrada->setChegada(ch_nova);
    reserva_encontrada->setPartida(p_nova);
    reserva_encontrada->setDinheiro(d_novo);

    container.atualizar(reserva_encontrada);
    if (reserva_encontrada)
    {
        cout << "reserva existe" << endl; // ESPERADO ATUALIZADO
        cout << reserva_encontrada->getCodigo().getValor() << endl;
        cout << reserva_encontrada->getChegada().getValor() << endl;
        cout << reserva_encontrada->getPartida().getValor() << endl;
        cout << reserva_encontrada->getDinheiro().getValor() << endl;
    }
    else
    {
        cout << "Reserva inexistente" << endl;
    }

    container.remover(codigo);

    reserva_encontrada = container.pesquisar(codigo);
    if (reserva_encontrada)
    {
        cout << "reserva existe" << endl;
        cout << reserva_encontrada->getCodigo().getValor() << endl;
        cout << reserva_encontrada->getChegada().getValor() << endl;
        cout << reserva_encontrada->getPartida().getValor() << endl;
        cout << reserva_encontrada->getDinheiro().getValor() << endl;
    }
    else
    {
        cout << "Reserva inexistente" << endl; // ESPERADO
    }

    ////////////////////////////////////////////////////////
}
