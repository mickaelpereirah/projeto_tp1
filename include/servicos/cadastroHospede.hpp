
#ifndef CADASTRO_GERENTE_HPP_INCLUDED
#define CADASTRO_GERENTE_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "cadastro.hpp"
#include "hospede.hpp"
#include "containerHospedes.hpp"

using namespace std;

class CadastroHospede : public Cadastro
{
public:
    static ContainerHospede container;
    Hospede *criar_hospede();
    bool novo_hospede();
};

#endif