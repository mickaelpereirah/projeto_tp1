#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "DOMINIOS.hpp"
#include "gerente.hpp"
#include "containerGerentes.hpp"

using namespace std;

int main()
{
    ContainerGerente container;

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

    Ramal r;
    int ramal;

    cout << "Digite o ramal (0-50): ";
    cin >> ramal;
    cin.ignore();
    r.setValor(ramal);

    Senha s;
    string senha;

    cout << "Digite a senha (5 caracteres): ";
    getline(cin, senha);
    s.setValor(senha);

    Gerente *gerente = new Gerente();
    gerente->setNome(n);
    gerente->setEmail(e);
    gerente->setRamal(r);
    gerente->setSenha(s);

    Gerente *gerente_encontrado = container.pesquisar(email);
    if (gerente_encontrado)
    {
        cout << "Gerente existe" << endl;
        cout << gerente_encontrado->getNome().getValor() << endl;
        cout << gerente_encontrado->getEmail().getValor() << endl;
        cout << gerente_encontrado->getRamal().getValor() << endl;
        cout << gerente_encontrado->getSenha().getValor() << endl;
    }
    else
    {
        cout << "Gerente inexistente" << endl; // ESPERADO
    }

    container.incluir(gerente);

    gerente_encontrado = container.pesquisar(email);
    if (gerente_encontrado)
    {
        cout << "Gerente existe" << endl; // ESPERADO
        cout << gerente_encontrado->getNome().getValor() << endl;
        cout << gerente_encontrado->getEmail().getValor() << endl;
        cout << gerente_encontrado->getRamal().getValor() << endl;
        cout << gerente_encontrado->getSenha().getValor() << endl;
    }
    else
    {
        cout << "Gerente inexistente" << endl;
    }

    Nome n_novo;
    n_novo.setValor("Roberto");
    Ramal r_novo;
    r_novo.setValor(45);
    Senha s_nova;
    s_nova.setValor("A1b2!");
    gerente_encontrado->setNome(n_novo);
    gerente_encontrado->setRamal(r_novo);
    gerente_encontrado->setSenha(s_nova);

    container.atualizar(gerente_encontrado);
    if (gerente_encontrado)
    {
        cout << "Gerente existe" << endl; // ESPERADO ATUALIZADO
        cout << gerente_encontrado->getNome().getValor() << endl;
        cout << gerente_encontrado->getEmail().getValor() << endl;
        cout << gerente_encontrado->getRamal().getValor() << endl;
        cout << gerente_encontrado->getSenha().getValor() << endl;
    }
    else
    {
        cout << "Gerente inexistente" << endl;
    }

    container.remover(email);

    gerente_encontrado = container.pesquisar(email);
    if (gerente_encontrado)
    {
        cout << "Gerente existe" << endl;
        cout << gerente_encontrado->getNome().getValor() << endl;
        cout << gerente_encontrado->getEmail().getValor() << endl;
        cout << gerente_encontrado->getRamal().getValor() << endl;
        cout << gerente_encontrado->getSenha().getValor() << endl;
    }
    else
    {
        cout << "Gerente inexistente" << endl; // ESPERADO
    }
}
