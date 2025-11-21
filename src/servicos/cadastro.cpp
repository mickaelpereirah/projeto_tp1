#include <iostream>>
#include <stdexcept>

#include "cadastro.hpp"
#include "DOMINIOS.hpp"

using namespace std;


Capacidade Cadastro::criar_capacidade() {
    Capacidade c;
    string input;
    int capacidade;
    while (true) {
        cout << "Digite a capacidade:";
        getline(cin, input);
        try
        {
            capacidade = stoi(input);
            c.setValor(capacidade);
            break;
        }
        catch (const invalid_argument &e)
        {
            cout << "[Capacidade Invalida:" << capacidade << "] Deve ser um numero inteiro entre [1,4]" << endl;
        }
    }
    return c;
}

Cartao criar_cartao();
Codigo criar_codigo();
Data criar_data();
Dinheiro criar_dinheiro();

Email criar_email() {
    Email e;
    string email;
    while (true) {
        cout << "Digite o email:";
        getline(cin, email);
        try
        {
            e.setValor(email);
            break;
        }
        catch (const invalid_argument &e)
        {
            cout << "[Email Invalido:" << email << "] Modelo de email: nome@dominio.extensao (Ex: gerente@gmail.com)" << endl;
        }
    }
    return e;
}


Endereco criar_endereco();
Nome criar_nome() {
    Nome n;
    string nome;
    while (true) {
        cout << "Digite o email:";
        getline(cin, nome);
        try
        {
            n.setValor(nome);
            break;
        }
        catch (const invalid_argument &e)
        {
            cout << "[Nome Invalido:" << nome << "] O nome deve ter, ao menos, 5 carateres e letras iniciais maiusculas" << endl;
        }
    }
    return n;

}

Numero criar_numero();
Ramal criar_ramal();
Senha criar_senha();
Telefone criar_telefone();