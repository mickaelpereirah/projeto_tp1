#ifndef PESSOA_HPP_INCLUDED
#define PESSOA_HPP_INCLUDED
#include "DOMINIOS.hpp"

class Pessoa
{
private:
    Nome nome;
    Email email;

public:
    void setNome(Nome);
    Nome getNome();
    void setEmail(Email);
    Email getEmail();
};

inline void Pessoa::setNome(Nome nome)
{
    this->nome = nome;
}

inline Nome Pessoa::getNome()
{
    return nome;
}

inline void Pessoa::setEmail(Email email)
{
    this->email = email;
}

inline Email Pessoa::getEmail()
{
    return email;
}

#endif