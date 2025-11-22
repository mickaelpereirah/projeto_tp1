/**
 * @file cadastroReserva.hpp
 * @brief Serviço de cadastro de reservas
 */

#ifndef CADASTRO_RESERVA_HPP_INCLUDED
#define CADASTRO_RESERVA_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "cadastro.hpp"
#include "reserva.hpp"
#include "centralContainers.hpp"

using namespace std;

/**
 * @class CadastroReserva
 * @brief Cadastra reservas no sistema
 * @extends Cadastro
 * 
 * **Dados:** Código (PK), Data chegada, Data partida, Valor total  
 * **Validações:** Código único, Partida > Chegada, Sem conflito de datas no quarto
 */
class CadastroReserva : public Cadastro
{
public:
    /** @brief Cria objeto Reserva com dados do usuário */
    Reserva *criar_reserva();
    
    /** @brief Cadastra reserva no sistema (retorna true se sucesso) */
    bool nova_reserva();
};

#endif
