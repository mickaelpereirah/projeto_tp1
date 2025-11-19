#ifndef QUARTO_HPP_INCLUDED
#define QUARTO_HPP_INCLUDED
#include "DOMINIOS.hpp"

class Quarto
{
private:
    Numero numero;
    Capacidade capacidade;
    Dinheiro dinheiro;
    Ramal ramal;

public:
    void setNumero(Numero);
    Numero getNumero();
    void setCapacidade(Capacidade);
    Capacidade getCapacidade();
    void setDinheiro(Dinheiro);
    Dinheiro getDinheiro();
    void setRamal(Ramal);
    Ramal getRamal();
};

inline void Quarto::setNumero(Numero numero)
{
    this->numero = numero;
}

inline Numero Quarto::getNumero()
{
    return numero;
}

inline void Quarto::setCapacidade(Capacidade capacidade)
{
    this->capacidade = capacidade;
}

inline Capacidade Quarto::getCapacidade()
{
    return capacidade;
}

inline void Quarto::setDinheiro(Dinheiro dinheiro)
{
    this->dinheiro = dinheiro;
}

inline Dinheiro Quarto::getDinheiro()
{
    return dinheiro;
}

inline void Quarto::setRamal(Ramal ramal)
{
    this->ramal = ramal;
}

inline Ramal Quarto::getRamal()
{
    return ramal;
}

#endif