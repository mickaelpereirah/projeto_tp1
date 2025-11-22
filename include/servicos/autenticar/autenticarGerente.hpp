/**
 * @file autenticarGerente.hpp
 * @brief Serviço de autenticação de gerentes
 */

#ifndef AUTENTICAR_GERENTE_HPP_INCLUDED
#define AUTENTICAR_GERENTE_HPP_INCLUDED

#include <string>
#include "gerente.hpp"
#include "centralContainers.hpp"

using namespace std;

/**
 * @class AutenticarGerente
 * @brief Autentica gerentes no sistema
 * 
 * **Processo de Autenticação:**
 * 1. Recebe email e senha
 * 2. Busca gerente no container por email
 * 3. Verifica se senha corresponde
 * 4. Retorna gerente autenticado ou nullptr
 * 
 * **Segurança:**
 * - Comparação direta de senha (sem criptografia no MVP)
 * - Email como identificador único
 * - Retorna nullptr em caso de falha (não expõe motivo)
 * 
 * **Casos de Uso:**
 * - Login na camada de apresentação
 * - Validação de permissões de acesso
 * - Início de sessão do gerente
 */
class AutenticarGerente
{
public:
    /**
     * @brief Autentica gerente no sistema
     * @param email Email do gerente (identificador único)
     * @param senha Senha cadastrada do gerente
     * @return Gerente* Ponteiro para gerente autenticado, nullptr se credenciais inválidas
     * 
     * **Fluxo:**
     * 1. Busca gerente por email no container
     * 2. Se não encontrado → retorna nullptr
     * 3. Se encontrado → compara senha
     * 4. Se senha correta → retorna ponteiro do gerente
     * 5. Se senha incorreta → retorna nullptr
     * 
     * **Exemplo de uso:**
     * @code
     * Gerente* g = AutenticarGerente::login("joao@hotel.com", "senha123");
     * if (g != nullptr) {
     *     cout << "Login realizado com sucesso!" << endl;
     * } else {
     *     cout << "Email ou senha incorretos!" << endl;
     * }
     * @endcode
     */
    static Gerente* login(string email, string senha);
};

#endif // AUTENTICAR_GERENTE_HPP_INCLUDED
