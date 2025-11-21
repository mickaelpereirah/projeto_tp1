#ifndef CADASTRO_HOSPEDE_HPP_INCLUDED
#define CADASTRO_HOSPEDE_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "../cadastro.hpp"
#include "hospede.hpp"
#include "centralContainers.hpp"

using namespace std;

class CadastroHospede : public Cadastro
{
public:
    Hospede *criar_hospede();
    bool novo_hospede();
};

#endif