
#ifndef CADASTRO_GERENTE_HPP_INCLUDED
#define CADASTRO_GERENTE_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "cadastro.hpp"
#include "gerente.hpp"
#include "containerGerentes.hpp"

using namespace std;

class CadastroGerente : Cadastro
{
private:
    static ContainerGerente container;
    Gerente *criar_gerente();

public:
    bool novo_gerente();
};

#endif