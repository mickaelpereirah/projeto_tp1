#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "DOMINIOS.hpp"
#include "hospede.hpp"
#include "containerHospedes.hpp"

using namespace std;

int main()
{
    ContainerHospede container;

    Nome n;
    string nome;

    cout << "Digite o nome: ";
    getline(cin, nome);
    n.setValor(nome);

    Email e;
    string email;
    cout << "Digite o email: ";
    cin >> email;
    cin.ignore();
    e.setValor(email);

    Endereco en;
    string endereco;

    cout << "Digite o endereco: ";
    getline(cin >> ws, endereco); // ws elimina espaços em branco pendentes
    en.setValor(endereco);

    Cartao c;
    string cartao;

    cout << "Digite o número do cartão: ";
    getline(cin, cartao);
    c.setValor(cartao);

    Hospede *hospede = new Hospede();
    hospede->setNome(n);
    hospede->setEmail(e);
    hospede->setEndereco(en);
    hospede->setCartao(c);

    Hospede *hospede_encontrado = container.pesquisar(email);
    if (hospede_encontrado)
    {
        cout << "Hospede existe" << endl;
        cout << hospede_encontrado->getNome().getValor() << endl;
        cout << hospede_encontrado->getEmail().getValor() << endl;
        cout << hospede_encontrado->getEndereco().getValor() << endl;
        cout << hospede_encontrado->getCartao().getValor() << endl;
    }
    else
    {
        cout << "Hospede inexistente" << endl; // ESPERADO
    }

    container.incluir(hospede);

    hospede_encontrado = container.pesquisar(email);
    if (hospede_encontrado)
    {
        cout << "Hospede existe" << endl; // ESPERADO
        cout << hospede_encontrado->getNome().getValor() << endl;
        cout << hospede_encontrado->getEmail().getValor() << endl;
        cout << hospede_encontrado->getEndereco().getValor() << endl;
        cout << hospede_encontrado->getCartao().getValor() << endl;
    }
    else
    {
        cout << "Hospede inexistente" << endl;
    }

    Nome n_novo;
    n_novo.setValor("Roberto");
    Endereco en_novo;
    en_novo.setValor("Rua das Flores, 123");
    Cartao c_novo;
    c_novo.setValor("4556737586899855");
    hospede_encontrado->setNome(n_novo);
    hospede_encontrado->setEndereco(en_novo);
    hospede_encontrado->setCartao(c_novo);

    container.atualizar(hospede_encontrado);
    if (hospede_encontrado)
    {
        cout << "Hospede existe" << endl; // ESPERADO ATUALIZADO
        cout << hospede_encontrado->getNome().getValor() << endl;
        cout << hospede_encontrado->getEmail().getValor() << endl;
        cout << hospede_encontrado->getEndereco().getValor() << endl;
        cout << hospede_encontrado->getCartao().getValor() << endl;
    }
    else
    {
        cout << "Hospede inexistente" << endl;
    }

    container.remover(email);

    hospede_encontrado = container.pesquisar(email);
    if (hospede_encontrado)
    {
        cout << "Hospede existe" << endl;
        cout << hospede_encontrado->getNome().getValor() << endl;
        cout << hospede_encontrado->getEmail().getValor() << endl;
        cout << hospede_encontrado->getEndereco().getValor() << endl;
        cout << hospede_encontrado->getCartao().getValor() << endl;
    }
    else
    {
        cout << "Hospede inexistente" << endl; // ESPERADO
    }
}
