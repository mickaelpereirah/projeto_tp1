#include <iostream>
#include <string>
#include <iomanip>
// #include "capacidade.hpp"
// #include "codigo.hpp"
// #include "cartao.hpp"
#include "DOMINIOS.hpp"

using namespace std;

int main()
{
    Capacidade c;
    int v;

    cout << "Digite a capacidade: ";
    cin >> v;

    if (c.setValor(v))
        cout << "Valor = " << c.getValor() << endl;
    else
        cout << "Valor invalido: " << v << endl;

    Cartao d;
    string digitos;
    cout << "Digite o numero do cartao: ";
    cin >> digitos;

    if (d.setValor(digitos))
        cout << "Digitos sao: " << d.getValor() << endl;
    else
        cout << "Digitos invalidos: " << digitos << endl;

    Codigo co;
    string codigo;
    cout << "Digite o codigo: ";
    cin >> codigo;

    if (co.setValor(codigo))
        cout << "Codigo: " << co.getValor() << endl;
    else
        cout << "Codigo invalido: " << codigo << endl;

    Data da;
    string data;
    cout << "Digite a data: ";
    cin >> data;

    if (da.setValor(data))
        cout << "Data: " << da.getValor() << endl;
    else
        cout << "Data invalido: " << data << endl;

    Dinheiro di;
    double dinheiro;
    cout << "Digite o dinheiro: ";
    cin >> dinheiro;

    if (di.setValor(dinheiro))
    {
        cout << fixed << setprecision(2);
        cout << "Dinheiro: " << di.getValor() << endl;
    }
    else
        cout << "Dinheiro invalido: " << dinheiro << endl;

    return 0;
}
