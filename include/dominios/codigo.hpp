/**
 * @file codigo.hpp
 * @brief Definição da classe Codigo para códigos identificadores
 */

#ifndef CODIGO_HPP_INCLUDED
#define CODIGO_HPP_INCLUDED
#include <string>

using namespace std;

/**
 * @class Codigo
 * @brief Representa um código identificador válido
 * 
 * A classe Codigo armazena e valida códigos alfanuméricos utilizados para
 * identificar entidades no sistema (hotéis, reservas, etc.).
 * 
 * **FORMATO VÁLIDO:**
 * - Exatamente 10 caracteres
 * - Cada caracter é letra (a-z) ou dígito (0-9)
 * 
 * **REGRAS DE VALIDAÇÃO:**
 * 1. O código deve conter exatamente 10 caracteres
 * 2. Cada caractere deve ser:
 *    - Letra minúscula (a-z) OU
 *    - Dígito (0-9)
 * 3. Não são permitidos:
 *    - Letras maiúsculas (devem ser convertidas antes)
 *    - Caracteres especiais (-, _, @, etc.)
 *    - Espaços em branco
 * 
 * **EXEMPLOS:**
 * - ✅ Válido: "htl0001abc" (10 caracteres alfanuméricos)
 * - ✅ Válido: "abc1234567" (mix de letras e números)
 * - ✅ Válido: "0123456789" (apenas números)
 * - ✅ Válido: "abcdefghij" (apenas letras)
 * - ❌ Inválido: "HTL0001ABC" (contém letras maiúsculas)
 * - ❌ Inválido: "abc123" (apenas 6 caracteres)
 * - ❌ Inválido: "abc-123-456" (contém hífen)
 * - ❌ Inválido: "abc 123 456" (contém espaços)
 * 
 * **NOTA DE IMPLEMENTAÇÃO:**
 * O sistema pode internamente converter letras maiúsculas para minúsculas
 * ou exigir que o usuário forneça já em minúsculas.
 */
class Codigo{
    private:
        /**
         * @brief Sequência de caracteres do código armazenado (10 caracteres)
         */
        string caracteres;

        /**
         * @brief Valida o código conforme as regras do domínio
         * @param caracteres Código a ser validado
         * @return true se o código for válido, false caso contrário
         * 
         * Implementa as regras de validação:
         * - Verifica se tem exatamente 10 caracteres
         * - Verifica se cada caractere é letra (a-z) ou dígito (0-9)
         * 
         * Utiliza isalnum() para verificar se é alfanumérico.
         */
        bool validar(string);
    
    public:
        /**
         * @brief Define o código
         * @param caracteres Código em formato string (10 caracteres alfanuméricos)
         * @throw invalid_argument Se o código for inválido
         * 
         * Realiza a validação completa antes de armazenar o valor.
         * Códigos que não atendem às regras de validação resultam em exceção.
         * 
         * Exemplo de uso:
         * @code
         * Codigo cod;
         * try {
         *     cod.setValor("htl0001abc");
         *     cout << "Código válido: " << cod.getValor();
         * } catch (invalid_argument& e) {
         *     cout << "Código inválido: " << e.what();
         * }
         * @endcode
         */
        void setValor(string);

        /**
         * @brief Obtém o código armazenado
         * @return string Código armazenado (10 caracteres)
         */
        string getValor();
};

/**
 * @brief Implementação inline do método getValor()
 * @return string Código armazenado
 */
inline string Codigo::getValor(){
    return caracteres;
}

#endif // CODIGO_HPP_INCLUDED
