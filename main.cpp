#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "DOMINIOS.hpp"
#include "cadastroGerente.hpp"
#include "quarto.hpp"
#include "containerQuartos.hpp"

#include "reserva.hpp"
#include "containerReservas.hpp"

using namespace std;

int main()
{
    CadastroGerente cadastro_gerente;

    Gerente *g = CadastroGerente::container.pesquisar("luisa@gmail.com");
    if (g) {
        cout << g->getNome().getValor() << endl;
        cout << g->getEmail().getValor() << endl;
        cout << g->getRamal().getValor() << endl;
        cout << g->getSenha().getValor() << endl;
    }
    else {
        cout << "Gerente nao existe" << endl;
    }

    cadastro_gerente.novo_gerente();
    cout << "--------------------" << endl;
    g = CadastroGerente::container.pesquisar("luisa@gmail.com");
    if (g) {
        cout << g->getNome().getValor() << endl;
        cout << g->getEmail().getValor() << endl;
        cout << g->getRamal().getValor() << endl;
        cout << g->getSenha().getValor() << endl;
    }
    else {
        cout << "Gerente nao existe" << endl;
    }
}
