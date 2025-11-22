/**
 * @file cartao.hpp
 * @brief Definição da classe Cartao para números de cartão de crédito
 */

#ifndef CARTAO_HPP_INCLUDED
#define CARTAO_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Cartao
 * @brief Representa um número de cartão de crédito válido
 * 
 * A classe Cartao armazena e valida números de cartão de crédito utilizando
 * o algoritmo de Luhn para garantir a integridade do dígito verificador.
 * 
 * **FORMATO VÁLIDO:**
 * - Exatamente 16 dígitos (0-9)
 * - Presença de dígito verificador calculado segundo o algoritmo de Luhn
 * 
 * **REGRAS DE VALIDAÇÃO:**
 * 1. O número deve conter exatamente 16 caracteres
 * 2. Todos os caracteres devem ser dígitos numéricos (0-9)
 * 3. O dígito verificador deve ser válido segundo o algoritmo de Luhn
 * 
 * **ALGORITMO DE LUHN:**
 * 1. Da direita para esquerda, duplique cada segundo dígito
 * 2. Se o resultado for maior que 9, subtraia 9
 * 3. Some todos os dígitos (duplicados e não duplicados)
 * 4. Se a soma for múltiplo de 10, o cartão é válido
 * 
 * **EXEMPLOS:**
 * - ✅ Válido: 4556737586899855 (cartão Visa de teste)
 * - ✅ Válido: 4111111111111111 (número de teste válido)
 * - ✅ Válido: 5555555555554444 (Mastercard de teste)
 * - ❌ Inválido: 1234567890123456 (falha no algoritmo de Luhn)
 * - ❌ Inválido: 411111111111111 (apenas 15 dígitos)
 * - ❌ Inválido: 4111-1111-1111-1111 (contém hífens)
 * - ❌ Inválido: 4111 1111 1111 1111 (contém espaços)
 * 
 * O método setValor() realiza a validação completa e lança exceção se inválido.
 */
class Cartao{
    private:
        /**
         * @brief Número do cartão armazenado como string (16 dígitos)
         */
        string digitos;

        /**
         * @brief Valida o número do cartão
         * @param digitos Número do cartão a ser validado
         * @return true se o número for válido, false caso contrário
         * 
         * Executa as seguintes validações:
         * 1. Verifica se tem exatamente 16 caracteres
         * 2. Verifica se todos os caracteres são dígitos (0-9)
         * 3. Aplica o algoritmo de Luhn para validar o dígito verificador
         * 
         * @see https://en.wikipedia.org/wiki/Luhn_algorithm
         */
        bool validar(string);
    
    public:
        /**
         * @brief Define o número do cartão
         * @param digitos Número do cartão em formato string (16 dígitos)
         * @throw invalid_argument Se o número for inválido
         * 
         * Realiza a validação completa antes de armazenar o valor.
         * Se o número não passar em qualquer validação (tamanho, formato ou Luhn),
         * lança exceção e o estado do objeto permanece inalterado.
         * 
         * Exemplo de uso:
         * @code
         * Cartao cartao;
         * try {
         *     cartao.setValor("4556737586899855");
         *     cout << "Cartão válido: " << cartao.getValor();
         * } catch (invalid_argument& e) {
         *     cout << "Cartão inválido: " << e.what();
         * }
         * @endcode
         */
        void setValor(string);

        /**
         * @brief Obtém o número do cartão armazenado
         * @return string Número do cartão (16 dígitos)
         */
        string getValor();
};

/**
 * @brief Implementação inline do método getValor()
 * @return string Número do cartão armazenado
 */
inline string Cartao::getValor(){
    return digitos;
}

#endif // CARTAO_HPP_INCLUDED
