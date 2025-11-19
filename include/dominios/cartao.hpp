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
 * A classe Cartao implementa a validação de números de cartão de crédito
 * utilizando o algoritmo de Luhn. A validaçãoo inclui:
 * - Verificação do tamanho (16 dígitos)
 * - Verificação de que todos os caracteres são dígitos 
 * - Aplicação do algoritmo de Luhn para validar o número 
 * 
 * Exemplos de números válidos para teste:
 * - 4556737586899855
 * - 4111111111111111
 */

class Cartao{
    private:
        string digitos; ///< Número do cartão armazenado como string

        /**
         * @brief Valida o número do cartão
         * @param digitos Número do cartão a ser validado 
         * @return true se o número for válido, false caso contrário
         * 
         * A validação inclui: 
         * - Verificação de tamnanho (16 dígitos)
         * - Verifcação de que todos são dígitos
         * - Aplicação do algoritmo de Luhn
         */
        bool validar(string);
    
    public:
        /**
         * @brief Define o número do cartão
         * @param digitos Número do cartão em formato string
         * @throw invalid_argument se o número for inválido
         * 
         * Realiza a validação completa antes de armazenar o valor.
         * Números inválidos lançam uma exceção.
         */
        void setValor(string);

        /**
         * @brief Obtém o númmero do cartão armazenado
         * @return string Número do cartão
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