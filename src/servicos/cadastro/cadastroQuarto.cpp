#include <iostream>
#include <stdexcept>

#include "cadastroQuarto.hpp"

using namespace std;

Quarto *CadastroQuarto::criar_quarto()
{
    Quarto *q = new Quarto();

    cout << "CRIAR QUARTO" << endl;
    Numero numero = criar_numero();
    Capacidade capacidade = criar_capacidade();
    Dinheiro dinheiro = criar_dinheiro();
    Ramal ramal = criar_ramal();

    q->setNumero(numero);
    q->setCapacidade(capacidade);
    q->setDinheiro(dinheiro);
    q->setRamal(ramal);

    return q;
}

bool CadastroQuarto::novo_quarto()
{
    Quarto *quarto = criar_quarto();
    
    // Solicitar código do hotel
    cout << "Digite o código do hotel: ";
    Codigo codigo_hotel_obj = criar_codigo();
    string codigo_hotel = codigo_hotel_obj.getValor();
    
    return CentralContainers::getContainerQuartos().incluir(quarto, codigo_hotel);
}