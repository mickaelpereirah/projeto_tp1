/**
 * @file email.hpp
 * @brief Definição da classe Email para endereços de email válidos
 */

#ifndef EMAIL_HPP_INCLUDED
#define EMAIL_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Email
 * @brief Representa um endereço de email válido conforme padrões RFC
 * 
 * A classe Email é responsável por armazenar e validar endereços de email
 * de acordo com as especificações RFC 5322. A validação inclui:
 * - Verificação da estrutura básica (parte local @ domínio)
 * - Validação de caracteres permitidos em cada parte
 * - Verificação do comprimento máximo (até 254 caracteres)
 * - Validação do domínio (extensão, pontos, etc.)
 * 
 * Exemplos de emails válidos:
 * - usuario@exemplo.com
 * - nome.sobrenome@empresa.com.br
 * - user+tag@domain.org
 */
class Email
{
private:
    string email; ///< Endereço de email armazenado

    /**
     * @brief Valida o endereço de email conforme padrões RFC
     * @param email Endereço de email a ser validado
     * @return true se o email for válido, false caso contrário
     * 
     * Implementa a validação completa do email, incluindo:
     * - Presença do caractere '@' separando partes local e domínio
     * - Comprimento máximo de 254 caracteres
     * - Caracteres permitidos na parte local (antes do @)
     * - Validação da parte do domínio (após o @)
     * - Extensões de domínio válidas
     */
    bool validar(string email);

public:
    /**
     * @brief Define o endereço de email
     * @param email Endereço de email em formato string
     * @throw invalid_argument Se o email for inválido
     * 
     * Realiza a validação completa antes de armazenar o valor.
     * Emails que não atendem aos padrões RFC resultam em exceção
     * com mensagem descritiva do erro de validação.
     */
    void setValor(string email);

    /**
     * @brief Obtém o endereço de email armazenado
     * @return string Endereço de email no formato válido
     */
    string getValor();
};

/**
 * @brief Implementação inline do método getValor
 * @return string Endereço de email armazenado
 */
inline string Email::getValor()
{
    return email;
}

#endif // EMAIL_HPP_INCLUDED