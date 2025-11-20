#include <iostream>>
#include <stdexcept>

#include "cadastro.hpp"
#include "DOMINIOS.hpp"

using namespace std;


Capacidade Cadastro::criar_capacidade() {
    Capacidade c;
    int capacidade;
    bool flag = false;
    while (!flag) {
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
Senha criar_senha();
Telefone criar_telefone();