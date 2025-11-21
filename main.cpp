#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "DOMINIOS.hpp"
#include "cadastroGerente.hpp"
#include "centralContainers.hpp"
#include "atualizarGerente.hpp"

using namespace std;

int main()
{
    CadastroGerente cadastro_gerente;
    AtualizarGerente atualizar_gerente;

    Gerente *g = CentralContainers::getContainerGerentes().pesquisar("luisa@gmail.com");
    if (g)
    {
        cout << g->getNome().getValor() << endl;
        cout << g->getEmail().getValor() << endl;
        cout << g->getSenha().getValor() << endl;
        cout << g->getRamal().getValor() << endl;
    }
    else
    {
        cout << "Gerente nao existe" << endl;
    }

    cadastro_gerente.novo_gerente();
    cout << "--------------------" << endl;
    g = CentralContainers::getContainerGerentes().pesquisar("luisa@gmail.com");
    if (g)
    {
        cout << g->getNome().getValor() << endl;
        cout << g->getEmail().getValor() << endl;
        cout << g->getSenha().getValor() << endl;
        cout << g->getRamal().getValor() << endl;
    }
    else
    {
        cout << "Gerente nao existe" << endl;
    }

    atualizar_gerente.atualizar_gerente(g); 
    cout << "--------------------" << endl;
    g = CentralContainers::getContainerGerentes().pesquisar("luisa@gmail.com");
    if (g)
    {
        cout << g->getNome().getValor() << endl;
        cout << g->getEmail().getValor() << endl;
        cout << g->getSenha().getValor() << endl;
        cout << g->getRamal().getValor() << endl;
    }
    else
    {
        cout << "Gerente nao existe" << endl;
    }
}
