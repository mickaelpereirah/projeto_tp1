/**
 * @file cadastroQuarto.hpp  
 * @brief Serviço de cadastro de quartos
 */

#ifndef CADASTRO_QUARTO_HPP_INCLUDED
#define CADASTRO_QUARTO_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "cadastro.hpp"
#include "quarto.hpp"
#include "centralContainers.hpp"

using namespace std;

/**
 * @class CadastroQuarto
 * @brief Cadastra quartos em um hotel
 * @extends Cadastro
 * 
 * **Dados:** Número (PK, 001-999), Capacidade (1-4), Diária, Ramal (00-50)  
 * **Validação:** Número único no sistema
 */
class CadastroQuarto : public Cadastro
{
public:
    /** @brief Cria objeto Quarto com dados do usuário */
    Quarto *criar_quarto();
    
    /** @brief Cadastra quarto no sistema (retorna true se sucesso) */
    bool novo_quarto();
};

#endif
