/**
 * @file senha.hpp
 * @brief Definição da classe Senha para senhas de acesso
 */

#ifndef SENHA_HPP_INCLUDED
#define SENHA_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Senha
 * @brief Representa uma senha de acesso segura
 * 
 * A classe Senha armazena e valida senhas seguindo regras rigorosas
 * de segurança para garantir senhas fortes.
 * 
 * **FORMATO VÁLIDO:**
 * - Exatamente 5 caracteres
 * 
 * **CARACTERES PERMITIDOS:**
 * - Letra minúscula (a-z)
 * - Letra maiúscula (A-Z)
 * - Dígito (0-9)
 * - Caracter especial: ! " # $ % & ? 
 * 
 * **REGRAS DE COMPOSIÇÃO:**
 * - Letra NÃO pode ser seguida por letra
 * - Dígito NÃO pode ser seguido por dígito
 * - Deve existir pelo menos:
 *   - Uma letra minúscula (a-z)
 *   - Uma letra maiúscula (A-Z)
 *   - Um dígito (0-9)
 *   - Um caracter especial (! " # $ % & ?)
 * 
 * **EXEMPLOS:**
 * - ✅ Válido: "aA1#b" (tem tudo: minúscula, maiúscula, dígito, especial, alternados)
 * - ✅ Válido: "1aB%2" (dígito, letra, letra, especial, dígito)
 * - ✅ Válido: "A1b!C" (alterna tipos)
 * - ✅ Válido: "9#Aa8" (todos os requisitos atendidos)
 * - ❌ Inválido: "aA1#" (apenas 4 caracteres, precisa de 5)
 * - ❌ Inválido: "aA1#bc" (6 caracteres, precisa de exatamente 5)
 * - ❌ Inválido: "aB1#2" (dígito seguido de dígito: "1#2")
 * - ❌ Inválido: "ab1#2" (letra seguida de letra: "ab")
 * - ❌ Inválido: "AB1#2" (letra seguida de letra: "AB")
 * - ❌ Inválido: "1#2$3" (falta letra minúscula)
 * - ❌ Inválido: "a1#2$" (falta letra maiúscula)
 * - ❌ Inválido: "aA#$%" (falta dígito)
 * - ❌ Inválido: "aA123" (falta caracter especial)
 * - ❌ Inválido: "aA1@2" (@ não é caracter especial permitido)
 * 
 * **DETALHES DAS REGRAS:**
 * 
 * 1. **Alternância obrigatória:**
 *    - Após letra (a-z ou A-Z): deve vir dígito ou especial
 *    - Após dígito (0-9): deve vir letra ou especial
 *    - Após especial: pode vir qualquer tipo
 * 
 * 2. **Requisitos de presença:**
 *    - Pelo menos 1 de cada categoria é obrigatório
 *    - Não basta ter apenas 3 das 4 categorias
 * 
 * 3. **Caracteres especiais válidos (7 no total):**
 *    - ! (exclamação)
 *    - " (aspas duplas)
 *    - # (cerquilha/hash)
 *    - $ (cifrão)
 *    - % (porcentagem)
 *    - & (e comercial)
 *    - ? (interrogação)
 */
class Senha
{
private:
    /**
     * @brief Senha armazenada (5 caracteres)
     */
    string senha;

    /**
     * @brief Valida a senha
     * @param senha Senha a ser validada
     * @return true se a senha for válida, false caso contrário
     * 
     * Executa as seguintes validações:
     * 1. Verifica se tem exatamente 5 caracteres
     * 2. Valida caracteres permitidos (a-z, A-Z, 0-9, ! " # $ % & ?)
     * 3. Verifica alternância:
     *    - Letra não seguida de letra
     *    - Dígito não seguido de dígito
     * 4. Verifica presença de pelo menos:
     *    - Uma letra minúscula
     *    - Uma letra maiúscula
     *    - Um dígito
     *    - Um caracter especial
     */
    bool validar(string);

public:
    /**
     * @brief Define a senha
     * @param senha Senha em formato string (5 caracteres)
     * @throw invalid_argument Se a senha for inválida
     * 
     * Realiza a validação completa antes de armazenar.
     * 
     * Exemplo de uso:
     * @code
     * Senha senhaGerente;
     * try {
     *     senhaGerente.setValor("aA1#b");
     *     cout << "Senha válida e forte!";
     * } catch (invalid_argument& e) {
     *     cout << "Senha inválida: " << e.what();
     * }
     * @endcode
     */
    void setValor(string);

    /**
     * @brief Obtém a senha armazenada
     * @return string Senha (5 caracteres)
     * 
     * **ATENÇÃO DE SEGURANÇA:**
     * Em sistemas reais, senhas nunca devem ser retornadas em texto claro.
     * Este método existe apenas para fins educacionais e de validação.
     * Em produção, use hashing (bcrypt, argon2, etc.).
     */
    string getValor();
};

/**
 * @brief Implementação inline do método getValor
 * @return string Senha armazenada
 */
inline string Senha::getValor()
{
    return senha;
}

#endif // SENHA_HPP_INCLUDED
