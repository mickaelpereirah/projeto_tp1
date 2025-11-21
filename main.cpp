#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "DOMINIOS.hpp"
<<<<<<< HEAD
#include "cadastroGerente.hpp"
=======
#include "cadastro/cadastroHotel.hpp"
#include "hotel.hpp"
>>>>>>> origin/main
#include "centralContainers.hpp"
#include "atualizarGerente.hpp"

using namespace std;

int main()
{
<<<<<<< HEAD
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
=======
    CadastroHotel cadastro_hotel;

    Hotel *h = CentralContainers::getContainerHoteis().pesquisar("AAAAA00000");
    if (h)
    {
        cout << h->getNome().getValor() << endl;
        cout << h->getEndereco().getValor() << endl;
        cout << h->getTelefone().getValor() << endl;
        cout << h->getCodigo().getValor() << endl;
    }
    else
    {
        cout << "Hotel nao existe" << endl;
    }

    cadastro_hotel.novo_hotel();
    cout << "--------------------" << endl;
    h = CentralContainers::getContainerHoteis().pesquisar("AAAAA00000");
    if (h)
    {
        cout << h->getNome().getValor() << endl;
        cout << h->getEndereco().getValor() << endl;
        cout << h->getTelefone().getValor() << endl;
        cout << h->getCodigo().getValor() << endl;
    }
    else
    {
        cout << "Hotel nao existe" << endl;
>>>>>>> origin/main
    }
}
