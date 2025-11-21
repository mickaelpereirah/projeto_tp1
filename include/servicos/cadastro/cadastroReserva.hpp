#ifndef CADASTRO_RESERVA_HPP_INCLUDED
#define CADASTRO_RESERVA_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "cadastro.hpp"
#include "reserva.hpp"
#include "centralContainers.hpp"

using namespace std;

class CadastroReserva : public Cadastro
{
private:
    Data criar_data_inicial();
    Data criar_data_final();
    bool validar_datas(const Data &inicial, const Data &final);

public:
    Reserva *criar_reserva();
    bool nova_reserva();
};

#endif