
#ifndef CADASTRO_GERENTE_HPP_INCLUDED
#define CADASTRO_GERENTE_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "cadastro.hpp"
#include "gerente.hpp"
#include "containerGerentes.hpp"

using namespace std;

class CadastroGerente : public Cadastro
{
private:
    int test;
public:
    static ContainerGerente container;
    Gerente *criar_gerente();
    bool novo_gerente();
};

#endif