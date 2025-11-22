/**
 * @file atualizarHotel.hpp
 * @brief Serviço de atualização de dados de hotéis
 */

#ifndef ATUALIZAR_HOTEL_HPP_INCLUDED
#define ATUALIZAR_HOTEL_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "../cadastro/cadastro.hpp"
#include "hotel.hpp"
#include "centralContainers.hpp"

using namespace std;

/**
 * @class AtualizarHotel
 * @brief Atualiza dados de hotéis cadastrados
 * @extends Cadastro
 * 
 * **Permite alterar:** Nome, Endereço, Telefone  
 * **NÃO permite alterar:** Código (chave primária)  
 * **Processo:** Pergunta campo por campo se deseja alterar
 */
class AtualizarHotel : public Cadastro
{
public:
    /**
     * @brief Modifica dados do hotel conforme escolhas do usuário
     * @param hotel Ponteiro para o hotel a ser modificado
     * @return Hotel* Ponteiro para o hotel modificado
     * 
     * Pergunta ao usuário campo por campo se deseja alterar:
     * - Nome (sim/não)
     * - Endereço (sim/não)
     * - Telefone (sim/não)
     * 
     * Mantém valores originais dos campos não alterados.
     */
    Hotel *modificar_hotel(Hotel *);
    
    /**
     * @brief Atualiza hotel no container
     * @param hotel Ponteiro para o hotel atualizado
     * @return true se atualizado com sucesso, false caso contrário
     */
    bool atualizar_hotel(Hotel *);
    
    /**
     * @brief Valida resposta sim/não do usuário
     * @return true se resposta foi "sim", false se "nao"
     * 
     * Repete pergunta até receber "sim" ou "nao".
     */
    bool validar_resposta();
};

#endif // ATUALIZAR_HOTEL_HPP_INCLUDED
