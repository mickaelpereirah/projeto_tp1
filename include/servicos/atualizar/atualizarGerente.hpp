/**
 * @file atualizarGerente.hpp
 * @brief Serviço de atualização de dados de gerentes
 */

#ifndef ATUALIZAR_GERENTE_HPP_INCLUDED
#define ATUALIZAR_GERENTE_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "../cadastro/cadastro.hpp"
#include "gerente.hpp"
#include "centralContainers.hpp"

using namespace std;

/**
 * @class AtualizarGerente
 * @brief Atualiza dados de gerentes cadastrados
 * @extends Cadastro
 * 
 * **Permite alterar:** Nome, Ramal, Senha  
 * **NÃO permite alterar:** Email (chave primária)  
 * **Processo:** Pergunta campo por campo se deseja alterar
 */
class AtualizarGerente : public Cadastro
{
public:
    /** @brief Modifica dados do gerente conforme escolhas do usuário */
    Gerente *modificar_gerente(Gerente *);
    
    /** @brief Atualiza gerente no container */
    bool atualizar_gerente(Gerente *);
    
    /** @brief Valida resposta sim/não do usuário */
    bool validar_resposta();
};

#endif
