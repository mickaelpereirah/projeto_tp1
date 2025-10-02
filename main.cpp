#include <iostream>
#include <string>
#include "capacidade.hpp"
#include "codigo.hpp"
#include "cartao.hpp"

using namespace std;

int main()
{
    Capacidade c;
    int v;

    cout << "Digite a capacidadeeeeeeeeeeeeeeeeeeee: ";
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


    Codigo cr;
    string caracteres;
    cin >> caracteres;

    cout << cr.setValor(caracteres)<< endl;
    cout <<cr.getValor()<<endl;


    return 0;
}
