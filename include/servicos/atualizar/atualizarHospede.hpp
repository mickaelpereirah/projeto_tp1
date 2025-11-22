/**
 * @file atualizarHospede.hpp
 * @brief Serviço de atualização de dados de hóspedes
 */

#ifndef ATUALIZAR_HOSPEDE_HPP_INCLUDED
#define ATUALIZAR_HOSPEDE_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "../cadastro/cadastro.hpp"
#include "hospede.hpp"
#include "centralContainers.hpp"

using namespace std;

/**
 * @class AtualizarHospede
 * @brief Atualiza dados de hóspedes cadastrados
 * @extends Cadastro
 * 
 * **Permite alterar:** Nome, Endereço, Cartão de Crédito  
 * **NÃO permite alterar:** Email (chave primária)  
 * **Processo:** Pergunta campo por campo se deseja alterar
 */
class AtualizarHospede : public Cadastro
{
public:
    /**
     * @brief Modifica dados do hóspede conforme escolhas do usuário
     * @param hospede Ponteiro para o hóspede a ser modificado
     * @return Hospede* Ponteiro para o hóspede modificado
     * 
     * Pergunta ao usuário campo por campo se deseja alterar:
     * - Nome (sim/não)
     * - Endereço (sim/não)
     * - Cartão de Crédito (sim/não)
     * 
     * Mantém valores originais dos campos não alterados.
     */
    Hospede *modificar_hospede(Hospede *);
    
    /**
     * @brief Atualiza hóspede no container
     * @param hospede Ponteiro para o hóspede atualizado
     * @return true se atualizado com sucesso, false caso contrário
     */
    bool atualizar_hospede(Hospede *);
    
    /**
     * @brief Valida resposta sim/não do usuário
     * @return true se resposta foi "sim", false se "nao"
     * 
     * Repete pergunta até receber "sim" ou "nao".
     */
    bool validar_resposta();
};

#endif // ATUALIZAR_HOSPEDE_HPP_INCLUDED
