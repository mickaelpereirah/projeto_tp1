#include <iostream>
#include <stdexcept>

#include "cadastro.hpp"
#include "DOMINIOS.hpp"

using namespace std;

Capacidade Cadastro::criar_capacidade()
{
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

Cartao Cadastro::criar_cartao() {
    Cartao c;
    return c;
}

Codigo Cadastro::criar_codigo() {
    Codigo c;
    return c;
}

Data Cadastro::criar_data() {
    Data d;
    return d;
}

Dinheiro Cadastro::criar_dinheiro() {
    Dinheiro d;
    return d;
}

Email Cadastro::criar_email() {
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


Endereco Cadastro::criar_endereco()
{
    Endereco e;
    string endereco;
    while (true)
    {
        cout << "Digite o endereco:";
        getline(cin, endereco);
        try
        {
            e.setValor(endereco);
            break;
        }
        catch (const invalid_argument &)
        {
            cout << "[Endereco Invalido:" << endereco << "]" << endl;
        }
    }
    return e;
}

Nome Cadastro::criar_nome() {
    Nome n;
    string nome;
    while (true) {
        cout << "Digite o nome:";
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

Numero Cadastro::criar_numero() {
    Numero n;
    return n;
}

Ramal Cadastro::criar_ramal() {
    Ramal r;
    string input;
    int ramal;
    while (true) {
        cout << "Digite o Ramal: ";
        getline(cin, input);
        try
        {
            ramal = stoi(input);
            r.setValor(ramal);
            break;
        }
        catch (const invalid_argument &e)
        {
            cout << "[Ramal Invalido:" << ramal << "] Deve ser um numero inteiro entre [0, 50]" << endl;
        }
    }
    return r;
}

Senha Cadastro::criar_senha()
{
    Senha s;
    string senha;
    while (true)
    {
        cout << "Digite uma senha:";
        cin >> senha;
        try
        {
            s.setValor(senha);
            break;
        }
        catch (const invalid_argument &e)
        {
            cout << "[Senha Invalida:" << senha << "]" << endl;
            cout << "- Caracter pode ser letra (a-z, A-Z), digito (0-9) ou especial (! \" # $ % & ?)" << endl;
            cout << "- Letra nao pode ser seguida por outra letra" << endl;
            cout << "- Digito nao pode ser seguido por outro digito" << endl;
            cout << "- Deve conter pelo menos uma letra minuscula (a-z)" << endl;
            cout << "- Deve conter pelo menos uma letra maiuscula (A-Z)" << endl;
            cout << "- Deve conter pelo menos um digito (0-9)" << endl;
            cout << "- Deve conter pelo menos um caractere especial (! \" # $ % & ?)" << endl;
        }
    }
    return s;
}
Telefone Cadastro::criar_telefone()
{
    Telefone t;
    string telefone;
    while (true)
    {
        cout << "Digite o telefone:";
        getline(cin, telefone);
        try
        {
            t.setValor(telefone);
            break;
        }
        catch (const invalid_argument &)
        {
            cout << "[Telefone Invalido:" << telefone << "]" << endl;
        }
    }
    return t;
}