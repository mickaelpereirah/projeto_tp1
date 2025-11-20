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
    ContainerQuarto container;

    Numero n;
    int numero;

    cout << "Digite o numero: ";
    cin >> numero;
    n.setValor(numero);

    Capacidade c;
    int capacidade;
    cout << "Digite a capacidade: ";
    cin >> capacidade;
    c.setValor(capacidade);

    Dinheiro d;
    double diaria;

    cout << "Digite o valor da diária: ";
    cin >> diaria;
    d.setValor(diaria);

    Ramal r;
    int ramal;

    cout << "Digite o ramal: ";
    cin >> ramal;
    r.setValor(ramal);

    Quarto *quarto = new Quarto();
    quarto->setNumero(n);
    quarto->setCapacidade(c);
    quarto->setDinheiro(d);
    quarto->setRamal(r);

    Quarto *quarto_encontrado = container.pesquisar(numero);
    if (quarto_encontrado)
    {
        cout << "Quarto existe" << endl;
        cout << quarto_encontrado->getNumero().getValor() << endl;
        cout << quarto_encontrado->getCapacidade().getValor() << endl;
        cout << quarto_encontrado->getDinheiro().getValor() << endl;
        cout << quarto_encontrado->getRamal().getValor() << endl;
    }
    else
    {
        cout << "Quarto inexistente" << endl; // ESPERADO
    }

    container.incluir(quarto);

    quarto_encontrado = container.pesquisar(numero);
    if (quarto_encontrado)
    {
        cout << "Quarto existe" << endl; // ESPERADO
        cout << quarto_encontrado->getNumero().getValor() << endl;
        cout << quarto_encontrado->getCapacidade().getValor() << endl;
        cout << quarto_encontrado->getDinheiro().getValor() << endl;
        cout << quarto_encontrado->getRamal().getValor() << endl;
    }
    else
    {
        cout << "Quarto inexistente" << endl;
    }

    Ramal r_novo;
    r_novo.setValor(23);
    Capacidade c_nova;
    c_nova.setValor(3);
    Dinheiro d_novo;
    d_novo.setValor(1.00);
    quarto_encontrado->setRamal(r_novo);
    quarto_encontrado->setCapacidade(c_nova);
    quarto_encontrado->setDinheiro(d_novo);

    container.atualizar(quarto_encontrado);
    if (quarto_encontrado)
    {
        cout << "Quarto existe" << endl; // ESPERADO ATUALIZADO
        cout << quarto_encontrado->getNumero().getValor() << endl;
        cout << quarto_encontrado->getCapacidade().getValor() << endl;
        cout << quarto_encontrado->getDinheiro().getValor() << endl;
        cout << quarto_encontrado->getRamal().getValor() << endl;
    }
    else
    {
        cout << "Quarto inexistente" << endl;
    }

    container.remover(numero);

    quarto_encontrado = container.pesquisar(numero);
    if (quarto_encontrado)
    {
        cout << "Quarto existe" << endl;
        cout << quarto_encontrado->getNumero().getValor() << endl;
        cout << quarto_encontrado->getCapacidade().getValor() << endl;
        cout << quarto_encontrado->getDinheiro().getValor() << endl;
        cout << quarto_encontrado->getRamal().getValor() << endl;
    }
    else
    {
        cout << "Quarto inexistente" << endl; // ESPERADO
    }

    ////////////////////////////////////////////////////////
}
