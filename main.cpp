#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "DOMINIOS.hpp"
#include "hospede.hpp"
#include "containerHospedes.hpp"

#include "hotel.hpp"
#include "containerHoteis.hpp"

using namespace std;

int main()
{
    /*ContainerHospede container;

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
    }*/

    ContainerHotel container_h;

    Nome n_hotel;
    string nome_hotel;

    cout << "Digite o nome: ";
    getline(cin, nome_hotel);
    n_hotel.setValor(nome_hotel);

    Endereco en_hotel;
    string endereco_hotel;

    cout << "Digite o endereco: ";
    getline(cin >> ws, endereco_hotel); // ws elimina espaços em branco pendentes
    en_hotel.setValor(endereco_hotel);

    Telefone tel_hotel;
    string telefone_hotel;

    cout << "Digite o telefone: ";
    getline(cin >> ws, telefone_hotel); // ws elimina espaços em branco pendentes
    tel_hotel.setValor(telefone_hotel);

    Codigo co_hotel;
    string codigo_hotel;

    cout << "Digite um codigo: ";
    getline(cin >> ws, codigo_hotel); // ws elimina espaços em branco pendentes
    co_hotel.setValor(codigo_hotel);

    Hotel *hotel = new Hotel();
    hotel->setNome(n_hotel);
    hotel->setEndereco(en_hotel);
    hotel->setTelefone(tel_hotel);
    hotel->setCodigo(co_hotel);

    Hotel *hotel_encontrado = container_h.pesquisar(codigo_hotel);
    if (hotel_encontrado)
    {
        cout << "Hotel existe" << endl;
        cout << hotel_encontrado->getNome().getValor() << endl;
        cout << hotel_encontrado->getEndereco().getValor() << endl;
        cout << hotel_encontrado->getTelefone().getValor() << endl;
        cout << hotel_encontrado->getCodigo().getValor() << endl;
    }
    else
    {
        cout << "Hotel inexistente" << endl; // ESPERADO
    }

    container_h.incluir(hotel);

    hotel_encontrado = container_h.pesquisar(codigo_hotel);
    if (hotel_encontrado)
    {
        cout << "Hotel existe" << endl; // ESPERADO
        cout << hotel_encontrado->getNome().getValor() << endl;
        cout << hotel_encontrado->getEndereco().getValor() << endl;
        cout << hotel_encontrado->getTelefone().getValor() << endl;
        cout << hotel_encontrado->getCodigo().getValor() << endl;
    }
    else
    {
        cout << "Hotel inexistente" << endl;
    }

    Nome nh_novo;
    nh_novo.setValor("Hotel Da Loura");
    Endereco enh_novo;
    enh_novo.setValor("Rua das Flores, 123");
    Telefone tel_novo;
    tel_novo.setValor("+5561999999999");
    Codigo codigo_novo;
    codigo_novo.setValor("AAAAA00000");
    hotel_encontrado->setNome(nh_novo);
    hotel_encontrado->setEndereco(enh_novo);
    hotel_encontrado->setTelefone(tel_novo);
    hotel_encontrado->setCodigo(codigo_novo);

    container_h.atualizar(hotel_encontrado);
    if (hotel_encontrado)
    {
        cout << "Hotel existe" << endl; // ESPERADO ATUALIZADO
        cout << hotel->getNome().getValor() << endl;
        cout << hotel->getEndereco().getValor() << endl;
        cout << hotel->getTelefone().getValor() << endl;
        cout << hotel->getCodigo().getValor() << endl;
    }
    else
    {
        cout << "Hotel inexistente" << endl;
    }

    container_h.remover(codigo_hotel);

    hotel_encontrado = container_h.pesquisar(codigo_hotel);
    if (hotel_encontrado)
    {
        cout << "Hotel existente" << endl;
        cout << hotel_encontrado->getNome().getValor() << endl;
        cout << hotel_encontrado->getEndereco().getValor() << endl;
        cout << hotel_encontrado->getTelefone().getValor() << endl;
        cout << hotel_encontrado->getCodigo().getValor() << endl;
    }
    else
    {
        cout << "Hotel inexistente" << endl; // ESPERADO
    }
}
