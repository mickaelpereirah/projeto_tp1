#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "DOMINIOS.hpp"
#include "cadastroQuarto.hpp"
#include "quarto.hpp"
#include "centralContainers.hpp"

#include "reserva.hpp"

using namespace std;

int main()
{
    CadastroQuarto cadastro_quarto;

    Quarto *q = CentralContainers::getContainerQuartos().pesquisar(2);
    if (q)
    {
        cout << q->getCapacidade().getValor() << endl;
        cout << q->getNumero().getValor() << endl;
        cout << q->getDinheiro().getValor() << endl;
        cout << q->getRamal().getValor() << endl;
    }
    else
    {
        cout << "Quarto nao existe" << endl;
    }

    cadastro_quarto.novo_quarto();
    cout << "--------------------" << endl;
    q = CentralContainers::getContainerQuartos().pesquisar(2);
    if (q)
    {
        cout << q->getCapacidade().getValor() << endl;
        cout << q->getNumero().getValor() << endl;
        cout << q->getDinheiro().getValor() << endl;
        cout << q->getRamal().getValor() << endl;
    }
    else
    {
        cout << "Quarto nao existe" << endl;
    }
}
