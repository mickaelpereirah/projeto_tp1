
#ifndef ATUALIZAR_HOSPEDE_HPP_INCLUDED
#define ATUALIZAR_HOSPEDE_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "../cadastro/cadastro.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"

using namespace std;

class AtualizarReserva : public Cadastro
{
private:
    Data atualizar_data_inicial();
    Data atualizar_data_final();
    bool validar_datas(const Data &inicial, const Data &final);

public:
    Reserva *modificar_reserva(Reserva *);
    bool atualizar_reserva(Reserva *);
    bool validar_resposta();
};

#endif