#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "DOMINIOS.hpp"
#include "cadastroQuarto.hpp"
#include "centralContainers.hpp"
#include "atualizarQuarto.hpp"

using namespace std;

int main()
{
    CadastroQuarto cadastro_quarto;
    AtualizarQuarto atualizar_quarto;

    Quarto *q = CentralContainers::getContainerQuartos().pesquisar(1);
    if (q)
    {
        cout << q->getNumero().getValor() << endl;
        cout << q->getCapacidade().getValor() << endl;
        cout << q->getDinheiro().getValor() << endl;
        cout << q->getRamal().getValor() << endl;
    }
    else
    {
        cout << "Quarto nao existe" << endl;
    }

    cadastro_quarto.novo_quarto();
    cout << "--------------------" << endl;
    q = CentralContainers::getContainerQuartos().pesquisar(1);
    if (q)
    {
        cout << q->getNumero().getValor() << endl;
        cout << q->getCapacidade().getValor() << endl;
        cout << q->getDinheiro().getValor() << endl;
        cout << q->getRamal().getValor() << endl;
    }
    else
    {
        cout << "Quarto nao existe" << endl;
    }

    atualizar_quarto.atualizar_quarto(q);
    cout << "--------------------" << endl;
    q = CentralContainers::getContainerQuartos().pesquisar(1);
    if (q)
    {
        cout << q->getNumero().getValor() << endl;
        cout << q->getCapacidade().getValor() << endl;
        cout << q->getDinheiro().getValor() << endl;
        cout << q->getRamal().getValor() << endl;
    }
    else
    {
        cout << "Quarto nao existe" << endl;
    }
}
