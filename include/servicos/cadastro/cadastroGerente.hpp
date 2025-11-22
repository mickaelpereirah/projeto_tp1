/**
 * @file cadastroGerente.hpp
 * @brief Definição da classe CadastroGerente para cadastro de gerentes
 */

#ifndef CADASTRO_GERENTE_HPP_INCLUDED
#define CADASTRO_GERENTE_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "cadastro.hpp"
#include "gerente.hpp"
#include "centralContainers.hpp"

using namespace std;

/**
 * @class CadastroGerente
 * @brief Serviço responsável pelo cadastro de gerentes no sistema
 * @extends Cadastro
 * 
 * Esta classe gerencia o processo completo de cadastro de um novo gerente,
 * incluindo coleta de dados, validação e armazenamento no container.
 * 
 * **DADOS COLETADOS:**
 * - Nome (5-20 caracteres, capitalizado)
 * - Email (único no sistema, usado como chave)
 * - Ramal (00-50)
 * - Senha (5 caracteres com requisitos de segurança)
 * 
 * **VALIDAÇÕES:**
 * - Email não pode estar duplicado no sistema
 * - Todos os domínios são validados individualmente
 * - Dados são validados antes de criar o objeto Gerente
 * 
 * **FLUXO DE CADASTRO:**
 * 1. Solicita dados via métodos herdados de Cadastro
 * 2. Cria objeto Gerente com dados validados
 * 3. Verifica se email já existe no container
 * 4. Inclui no ContainerGerente via CentralContainers
 * 5. Retorna sucesso ou falha
 */
class CadastroGerente : public Cadastro
{
public:
    /**
     * @brief Cria um novo objeto Gerente com dados coletados do usuário
     * @return Gerente* Ponteiro para o gerente criado
     * 
     * Solicita todos os dados necessários via terminal:
     * - Nome (usando criar_nome())
     * - Email (usando criar_email())
     * - Ramal (usando criar_ramal())
     * - Senha (usando criar_senha())
     * 
     * Cria e retorna um ponteiro para o objeto Gerente.
     * NÃO inclui no container - isso é feito por novo_gerente().
     * 
     * Exemplo de uso:
     * @code
     * CadastroGerente cadastro;
     * Gerente* g = cadastro.criar_gerente();
     * @endcode
     */
    Gerente *criar_gerente();
    
    /**
     * @brief Cadastra um novo gerente no sistema
     * @return true se cadastrado com sucesso, false se email já existe
     * 
     * Fluxo completo:
     * 1. Chama criar_gerente() para coletar dados
     * 2. Valida se email já existe (pesquisa no container)
     * 3. Se email único, inclui no ContainerGerente
     * 4. Retorna resultado da operação
     * 
     * Exemplo de uso:
     * @code
     * CadastroGerente cadastro;
     * if(cadastro.novo_gerente()) {
     *     cout << "Gerente cadastrado com sucesso!";
     * } else {
     *     cout << "Email já existe no sistema.";
     * }
     * @endcode
     */
    bool novo_gerente();
};

#endif // CADASTRO_GERENTE_HPP_INCLUDED
