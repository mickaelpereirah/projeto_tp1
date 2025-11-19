/**
 * @file endereco.hpp
 * @brief Definição da classe Endereco para endereços textuais válidos
 */

#ifndef ENDERECO_HPP_INCLUDED
#define ENDERECO_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Endereco
 * @brief Representa um endereço textual válido de 5 a 30 caracteres
 * 
 * A classe Endereco é responsável por armazenar e validar endereços
 * textuais conforme regras específicas de formatação. A validação inclui:
 * - Comprimento entre 5 e 30 caracteres
 * - Caracteres permitidos: letras (a-z, A-Z), dígitos (0-9), vírgula, ponto e espaço
 * - Restrições de sequência de caracteres
 * - Restrições para primeiro e último caractere
 * 
 * Exemplos de endereços válidos:
 * - Rua das Flores, 123
 * - Av. Principal, 1000
 * - Praça da Sé, 25
 */
class Endereco{
private:
    string texto; ///< Texto do endereço armazenado

    /**
     * @brief Valida o endereço textual conforme regras do domínio
     * @param texto Endereço a ser validado
     * @return true se o endereço for válido, false caso contrário
     * 
     * Implementa a validação completa do endereço, incluindo:
     * - Verificação de comprimento (5-30 caracteres)
     * - Validação de caracteres permitidos
     * - Restrições de sequência: vírgula não pode ser seguida por vírgula ou ponto
     * - Restrições de sequência: ponto não pode ser seguido por vírgula ou ponto
     * - Espaço em branco deve ser seguido por letra ou dígito
     * - Primeiro e último caractere não podem ser vírgula, ponto ou espaço
     */
    bool validar(string);

public:
    /**
     * @brief Define o endereço textual
     * @param texto Endereço em formato string
     * @throw invalid_argument Se o endereço for inválido
     * 
     * Realiza a validação completa antes de armazenar o valor.
     * Endereços que não atendem às regras de validação resultam
     * em exceção com mensagem descritiva do erro.
     */
    void setValor(string);

    /**
     * @brief Obtém o endereço armazenado
     * @return string Endereço no formato válido
     */
    string getValor();
};

/**
 * @brief Implementação inline do método getValor
 * @return string Endereço armazenado
 */
inline string Endereco::getValor(){
    return texto; 
}

#endif // ENDERECO_HPP_INCLUDED