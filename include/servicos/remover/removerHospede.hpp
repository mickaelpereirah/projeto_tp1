#ifndef REMOVER_HOSPEDE_HPP_INCLUDED
#define REMOVER_HOSPEDE_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"
#include "listar/listarReserva.hpp"

using namespace std;

class RemoverHospede
{
public:
    static bool remover_hospede(Hospede* hospede);
};

#endif

