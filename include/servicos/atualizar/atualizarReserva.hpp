/**
 * @file atualizarReserva.hpp
 * @brief Serviço de atualização de dados de reservas
 */

#ifndef ATUALIZAR_RESERVA_HPP_INCLUDED
#define ATUALIZAR_RESERVA_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "../cadastro/cadastro.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"

using namespace std;

/**
 * @class AtualizarReserva
 * @brief Atualiza dados de reservas cadastradas
 * @extends Cadastro
 * 
 * **Permite alterar:** Data Inicial, Data Final  
 * **NÃO permite alterar:** Código da Reserva (chave primária), Quarto, Hóspede  
 * **Processo:** Pergunta campo por campo se deseja alterar
 * 
 * **Regras de Negócio:**
 * - Data inicial deve ser anterior à data final
 * - Datas devem estar em formato válido
 * - Período deve ser válido conforme disponibilidade do quarto
 */
class AtualizarReserva : public Cadastro
{
private:
    /**
     * @brief Solicita e valida nova data inicial da reserva
     * @return Data Nova data inicial validada
     * 
     * Continua solicitando até receber data válida.
     */
    Data atualizar_data_inicial();
    
    /**
     * @brief Solicita e valida nova data final da reserva
     * @return Data Nova data final validada
     * 
     * Continua solicitando até receber data válida.
     */
    Data atualizar_data_final();
    
    /**
     * @brief Valida consistência entre datas inicial e final
     * @param inicial Data de início da reserva
     * @param final Data de término da reserva
     * @return true se data inicial < data final, false caso contrário
     * 
     * Garante que o período da reserva seja válido.
     */
    bool validar_datas(const Data &inicial, const Data &final);

public:
    /**
     * @brief Modifica dados da reserva conforme escolhas do usuário
     * @param reserva Ponteiro para a reserva a ser modificada
     * @param numero_quarto Número do quarto associado à reserva
     * @return Reserva* Ponteiro para a reserva modificada
     * 
     * Pergunta ao usuário campo por campo se deseja alterar:
     * - Data Inicial (sim/não)
     * - Data Final (sim/não)
     * 
     * Valida consistência das datas após modificação.
     * Mantém valores originais dos campos não alterados.
     */
    Reserva *modificar_reserva(Reserva *, int numero_quarto);
    
    /**
     * @brief Atualiza reserva no container
     * @param reserva Ponteiro para a reserva atualizada
     * @param numero_quarto Número do quarto para atualização no container
     * @return true se atualizado com sucesso, false caso contrário
     * 
     * Atualiza a reserva mantendo a consistência com o quarto associado.
     */
    bool atualizar_reserva(Reserva *, int numero_quarto);
    
    /**
     * @brief Valida resposta sim/não do usuário
     * @return true se resposta foi "sim", false se "nao"
     * 
     * Repete pergunta até receber "sim" ou "nao".
     */
    bool validar_resposta();
};

#endif // ATUALIZAR_RESERVA_HPP_INCLUDED
