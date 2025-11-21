#include "listar/listarReserva.hpp"

using namespace std;

vector<Reserva*> ListarReserva::listar_reservas_por_quarto(Quarto* quarto)
{
    // Obter o número do quarto
    int numero_quarto = quarto->getNumero().getValor();

    // Buscar todas as reservas do quarto no container
    return CentralContainers::getContainerReservas().pesquisarPorQuarto(numero_quarto);
}

vector<Reserva*> ListarReserva::listar_reservas_por_hospede(Hospede* hospede)
{
    // Obter o email do hóspede
    string email_hospede = hospede->getEmail().getValor();

    // Buscar todas as reservas do hóspede no container
    return CentralContainers::getContainerReservas().pesquisarPorHospede(email_hospede);
}

