#ifndef HOSPEDE_HPP_INCLUDED
#define HOSPEDE_HPP_INCLUDED
#include "DOMINIOS.hpp"

class Hospede
{
private:
    Endereco endereco;
    Cartao numero;

public:
    void setEndereco(Endereco);
    Endereco getEndereco();
    void setCartao(Cartao);
    Cartao getCartao();
};

inline void Hospede::setEndereco(Endereco endereco)
{
    this->endereco = endereco;
}

inline Endereco Hospede::getEndereco()
{
    return endereco;
}

inline void Hospede::setCartao(Cartao Numero)
{
    this->numero = numero;
}

inline Cartao Hospede::getCartao()
{
    return numero;
}

#endif