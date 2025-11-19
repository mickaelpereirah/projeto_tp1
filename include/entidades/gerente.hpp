#ifndef GERENTE_HPP_INCLUDED
#define GERENTE_HPP_INCLUDED
#include "DOMINIOS.hpp"

class Gerente
{
private:
    Ramal ramal;
    Senha senha;

public:
    void setRamal(Ramal);
    Ramal getRamal();
    void setSenha(Senha);
    Senha getSenha();
};

inline void Gerente::setRamal(Ramal ramal)
{
    this->ramal = ramal;
}

inline Ramal Gerente::getRamal()
{
    return ramal;
}

inline void Gerente::setSenha(Senha senha)
{
    this->senha = senha;
}

inline Senha Gerente::getSenha()
{
    return senha;
}

#endif