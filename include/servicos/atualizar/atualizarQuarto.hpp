/**
 * @file atualizarQuarto.hpp
 * @brief Serviço de atualização de dados de quartos
 */

#ifndef ATUALIZAR_QUARTO_HPP_INCLUDED
#define ATUALIZAR_QUARTO_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "../cadastro/cadastro.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"

using namespace std;

/**
 * @class AtualizarQuarto
 * @brief Atualiza dados de quartos cadastrados
 * @extends Cadastro
 * 
 * **Permite alterar:** Capacidade, Diária, Estado  
 * **NÃO permite alterar:** Número do Quarto (chave primária), Hotel (relacionamento)  
 * **Processo:** Pergunta campo por campo se deseja alterar
 */
class AtualizarQuarto : public Cadastro
{
public:
    /**
     * @brief Modifica dados do quarto conforme escolhas do usuário
     * @param quarto Ponteiro para o quarto a ser modificado
     * @return Quarto* Ponteiro para o quarto modificado
     * 
     * Pergunta ao usuário campo por campo se deseja alterar:
     * - Capacidade (sim/não) - número de hóspedes
     * - Diária (sim/não) - valor por dia
     * - Estado (sim/não) - disponível/ocupado/manutenção
     * 
     * Mantém valores originais dos campos não alterados.
     */
    Quarto *modificar_quarto(Quarto *);
    
    /**
     * @brief Atualiza quarto no container
     * @param quarto Ponteiro para o quarto atualizado
     * @return true se atualizado com sucesso, false caso contrário
     */
    bool atualizar_quarto(Quarto *);
    
    /**
     * @brief Valida resposta sim/não do usuário
     * @return true se resposta foi "sim", false se "nao"
     * 
     * Repete pergunta até receber "sim" ou "nao".
     */
    bool validar_resposta();
};

#endif // ATUALIZAR_QUARTO_HPP_INCLUDED
