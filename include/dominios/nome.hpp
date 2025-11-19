/**
 * @file nome.hpp
 * @brief Definição da classe Nome para nomes pessoais válidos
 */

#ifndef NOME_HPP_INCLUDED
#define NOME_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Nome
 * @brief Representa um nome pessoal válido de 5 a 20 caracteres
 * 
 * A classe Nome é responsável por armazenar e validar nomes pessoais
 * conforme regras específicas de formatação. A validação inclui:
 * - Comprimento entre 5 e 20 caracteres
 * - Caracteres permitidos: apenas letras (a-z, A-Z) e espaços em branco
 * - Primeira letra de cada termo deve ser maiúscula (A-Z)
 * - Espaço em branco deve ser seguido por letra
 * - Último caractere não pode ser espaço em branco
 * 
 * Exemplos de nomes válidos:
 * - Joao Silva
 * - Maria Santos
 * - Carlos Alberto
 * - Ana Claudia
 */
class Nome {
private:
    string texto; ///< Texto do nome armazenado

    /**
     * @brief Valida o nome pessoal conforme regras do domínio
     * @param texto Nome a ser validado
     * @return true se o nome for válido, false caso contrário
     * 
     * Implementa a validação completa do nome, incluindo:
     * - Verificação de comprimento (5-20 caracteres)
     * - Validação de caracteres permitidos (apenas letras e espaços)
     * - Primeira letra de cada termo deve ser maiúscula
     * - Espaço em branco deve ser seguido por letra
     * - Último caractere não pode ser espaço
     * - Não permite espaços consecutivos
     */
    bool validar(string);

public:
    /**
     * @brief Define o nome pessoal
     * @param texto Nome em formato string
     * @throw invalid_argument Se o nome for inválido
     * 
     * Realiza a validação completa antes de armazenar o valor.
     * Nomes que não atendem às regras de validação resultam
     * em exceção com mensagem descritiva do erro.
     */
    void setValor(string);

    /**
     * @brief Obtém o nome armazenado
     * @return string Nome no formato válido
     */
    string getValor();
};

/**
 * @brief Implementação inline do método getValor
 * @return string Nome armazenado
 */
inline string Nome::getValor(){
    return texto; 
}

#endif // NOME_HPP_INCLUDED