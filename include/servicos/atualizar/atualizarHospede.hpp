
#ifndef ATUALIZAR_HOSPEDE_HPP_INCLUDED
#define ATUALIZAR_HOSPEDE_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "../cadastro/cadastro.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"

using namespace std;

class AtualizarHospede : public Cadastro
{
public:
    Hospede *modificar_hospede(Hospede *);
    bool atualizar_hospede(Hospede *);
    bool validar_resposta();
};

#endif