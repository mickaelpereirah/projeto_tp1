/**
 * @file data.hpp
 * @brief Definição da classe Data para datas válidas
 */

#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Data
 * @brief Representa uma data válida no sistema
 *
 * A classe Data é responsável por armazenar e validar datas
 * conformes as regras do domínio. A validação inclui:
 * - Formato específico (ex: DD/MM/AAAA, DD-MM-AAAA)
 * - Verificação de dias válidos para cada mês
 * - Consideração de anos bissextos
 * - Validação de datas futuras/passadas conforme regras de negócio
 *
 * A implementação garante que apenas datas válidas podem sejam armazenadas.
 */

class Data
{
private:
    string data; ///< Data armazenada em formato string

    /**
     * @brief Valida a data conforme as regras do domínio
     * @param data Data a ser validada em formato string
     * @return true se a data for válida, false caso contrário
     *
     * Implementa a validação completa da data, incluindo:
     * - Verificação de formato
     * - Validação de dia, mês e ano
     * - Consideração de anos bissextos
     * - Limites temporais conforme regras de negócio
     */
    bool validar(string);

public:
    /**
     * @brief Define a data
     *  @param data Data em formato string
     * @throw invalid_argument Se a data for inválida
     *
     * Realiza a validação completa antes de armazenar o valor.
     * Datas que não atendem às regras de validação resultam
     * em exceção com mensagem descritiva.
     */

    void setValor(string);

    /**
     * @brief Obtém a data armazenada
     * @return string Data armazenada em formato string
     */
    string getValor() const;
};

/**
 * @brief Implementação inline do método getValor()
 * @return string Data armazenada
 */
inline string Data::getValor() const
{
    return data;
}

#endif // DATA_HPP_INCLUDED