#include <iostream>
#include <string>
#include <iomanip>
// #include "capacidade.hpp"
// #include "codigo.hpp"
// #include "cartao.hpp"
#include "DOMINIOS.hpp"
#include <stdexcept>

using namespace std;

int main()
{
    Capacidade c;
    int v;

    cout << "Digite a capacidade(valorize interiros de 1 a 4): ";
    cin >> v;
    cin.ignore();

    try {
        c.setValor(v);
        cout << "Valor = " << c.getValor() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Valor invalido: " << e.what() << endl;
    }

    Cartao d;
    string digitos;
    cout << "Digite o numero do cartao: ";
    cin >> digitos;
    cin.ignore();

    try {
        d.setValor(digitos);
        cout << "Digitos sao: = " << d.getValor() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Digitos invalidos: " << e.what() << endl;
    }

    Codigo co;
    string codigo;
    cout << "Digite o codigo: ";
    cin >> codigo;
    cin.ignore();

    try {
        co.setValor(codigo);
        cout << "Codigo: " << co.getValor() << endl;
     }
     catch (const invalid_argument& e) {
        cout << "Codigo invalido: " << e.what() << endl;
     }

    Data da;
    string data;
    cout << "Digite a data: ";
    cin >> data;
    cin.ignore();

    try {
        da.setValor(data);
        cout << "Data: " << da.getValor() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Data invalida: " << e.what() << endl;
    }

    Dinheiro di;
    double dinheiro;
    cout << "Digite o dinheiro: ";
    cin >> dinheiro;
    cin.ignore();

    try {
        di.setValor(dinheiro);
        cout << fixed << setprecision(2);
        cout << "Dinheiro: " << di.getValor() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Dinheiro invalido: " << e.what() << endl;
    }

    Endereco end;
    string endereco;

    cout << "Digite o endereco: ";
    getline(cin, endereco);

    try {
        end.setValor(endereco);
        cout << "Endereco valido: " << end.getValor() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Endereco invalido: " << e.what() << endl;
    }

    Nome n;
    string textoN;

    cout << "Digite o nome: ";
    getline(cin, textoN);

    try {
        n.setValor(textoN);
        cout << "Nome valido: " << n.getValor() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Nome invalido: " << e.what() << endl;
    }

    Numero nu;
    int numero;

    cout << "Digite o numero (1-999): ";
    cin >> numero;
    cin.ignore();

    try {
        nu.setValor(numero);
        cout << "Numero valido: " << nu.getValor() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Numero invalido: " << e.what() << endl;
    }

    Ramal r;
    int valor;

    cout << "Digite o ramal (0-50): ";
    cin >> valor;
    cin.ignore();

    try {
        r.setValor(valor);
        cout << "Ramal valido: " << r.getValor() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Ramal invalido: " << e.what() << endl;
    }

    Senha s;
    string textoS;

    cout << "Digite a senha (5 caracteres): ";
    getline(cin, textoS);

    try {
        s.setValor(textoS);
        cout << "Senha valida: " << s.getValor() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Senha invalida: " << e.what() << endl;
    }

    Telefone t;
    string textoT;

    cout << "Digite o telefone (+ seguindo de 13 digitos): ";
    getline(cin, textoT);

    try {
        t.setValor(textoT);
        cout << "Telefone valido: " << t.getValor() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Telefone invalido: " << e.what() << endl;
    }

}
