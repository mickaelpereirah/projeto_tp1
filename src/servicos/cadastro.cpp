#include <iostream>>
#include <stdexcept>

#include "cadastro.hpp"
#include "DOMINIOS.hpp"

using namespace std;

Capacidade Cadastro::criar_capacidade()
{
    Capacidade c;
    int capacidade;
    bool flag = false;
    while (!flag)
    {
        cout << "Digite a capacidade:";
        cin >> capacidade;
        try
        {
            c.setValor(capacidade);
            flag = true;
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
Email criar_email();
Endereco criar_endereco();
Nome criar_nome();
Numero criar_numero();
Ramal criar_ramal();
Senha criar_senha()
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
Telefone criar_telefone();