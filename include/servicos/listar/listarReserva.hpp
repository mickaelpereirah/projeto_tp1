#ifndef LISTAR_RESERVA_HPP_INCLUDED
#define LISTAR_RESERVA_HPP_INCLUDED

#include <vector>
#include "DOMINIOS.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"

using namespace std;

class ListarReserva
{
public:
    static vector<Reserva*> listar_reservas_por_quarto(Quarto* quarto);
    static vector<Reserva*> listar_reservas_por_hospede(Hospede* hospede);
};

#endif

