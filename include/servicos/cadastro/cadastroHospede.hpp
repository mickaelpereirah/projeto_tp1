/**
 * @file cadastroHospede.hpp
 * @brief Definição da classe CadastroHospede para cadastro de hóspedes
 */

#ifndef CADASTRO_HOSPEDE_HPP_INCLUDED
#define CADASTRO_HOSPEDE_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "cadastro.hpp"
#include "hospede.hpp"
#include "centralContainers.hpp"

using namespace std;

/**
 * @class CadastroHospede
 * @brief Serviço responsável pelo cadastro de hóspedes no sistema
 * @extends Cadastro
 * 
 * Gerencia o cadastro de hóspedes, coletando dados pessoais e de pagamento.
 * 
 * **DADOS COLETADOS:**
 * - Nome (5-20 caracteres)
 * - Email (único, chave primária)
 * - Endereço (5-30 caracteres)
 * - Cartão (16 dígitos + Luhn)
 * 
 * **VALIDAÇÕES:**
 * - Email único no sistema
 * - Cartão com dígito verificador válido (Luhn)
 * - Todos os domínios validados individualmente
 */
class CadastroHospede : public Cadastro
{
public:
    /**
     * @brief Cria novo objeto Hospede com dados do usuário
     * @return Hospede* Ponteiro para o hóspede criado
     */
    Hospede *criar_hospede();
    
    /**
     * @brief Cadastra novo hóspede no sistema
     * @return true se cadastrado, false se email já existe
     */
    bool novo_hospede();
};

#endif
