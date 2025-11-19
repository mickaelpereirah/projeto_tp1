/**
 * @file telefone.hpp
 * @brief Definição da classe Telefone para números telefônicos internacionais válidos
 */

#ifndef TELEFONE_HPP_INCLUDED
#define TELEFONE_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Telefone
 * @brief Representa um número de telefone internacional válido
 * 
 * A classe Telefone é responsável por armazenar e validar números
 * de telefone no formato internacional padrão. A validação inclui:
 * - Comprimento fixo de 14 caracteres total
 * - Formato: '+' seguido de 13 dígitos
 * - Primeiro caractere deve ser '+'
 * - Os 13 caracteres restantes devem ser apenas dígitos (0-9)
 * - Compatível com números internacionais reais
 * 
 * Exemplos de números válidos:
 * - +5561999999999 (Brasil: +55 61 99999-9999)
 * - +5511999999999 (Brasil: +55 11 99999-9999)
 * - +1234567890123 (Exemplo internacional)
 */
class Telefone {
private:
    string texto; ///< Número de telefone armazenado como string

    /**
     * @brief Valida o número de telefone conforme formato internacional
     * @param texto Número de telefone a ser validado
     * @return true se o telefone for válido, false caso contrário
     * 
     * Implementa a validação completa do telefone, incluindo:
     * - Verificação de comprimento total (14 caracteres)
     * - Primeiro caractere deve ser '+'
     * - Os 13 caracteres restantes devem ser dígitos (0-9)
     * - Validação de formato internacional padrão
     */
    bool validar(string);

public:
    /**
     * @brief Define o número de telefone
     * @param texto Número de telefone em formato string
     * @throw invalid_argument Se o telefone for inválido
     * 
     * Realiza a validação completa antes de armazenar o valor.
     * Números de telefone que não atendem ao formato internacional
     * padrão resultam em exceção com mensagem descritiva do erro.
     * 
     * @note O formato aceito é estritamente internacional:
     * '+' seguido de 13 dígitos, sem espaços, hífens ou parênteses.
     */
    void setValor(string);

    /**
     * @brief Obtém o número de telefone armazenado
     * @return string Número de telefone no formato internacional
     * 
     * Retorna o número no formato padrão internacional pronto
     * para uso em sistemas de telefonia ou exibição.
     */
    string getValor();
};

/**
 * @brief Implementação inline do método getValor
 * @return string Número de telefone armazenado
 * 
 * Retorna o número de telefone armazenado internamente
 * no formato internacional padrão.
 */
inline string Telefone::getValor() {
    return texto;
}

#endif // TELEFONE_HPP_INCLUDED