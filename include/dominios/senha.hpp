/**
 * @file senha.hpp
 * @brief Definição da classe Senha para senhas seguras válidas
 */

#ifndef SENHA_HPP_INCLUDED
#define SENHA_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Senha
 * @brief Representa uma senha segura de exatamente 5 caracteres
 * 
 * A classe Senha é responsável por armazenar e validar senhas seguras
 * conforme regras rigorosas de segurança. A validação inclui:
 * - Comprimento fixo de exatamente 5 caracteres
 * - Caracteres permitidos: letras (a-z, A-Z), dígitos (0-9) e caracteres especiais (!"#$%&?)
 * - Pelo menos uma letra minúscula (a-z)
 * - Pelo menos uma letra maiúscula (A-Z)
 * - Pelo menos um dígito (0-9)
 * - Pelo menos um caractere especial (!"#$%&?)
 * - Letra não pode ser seguida por letra
 * - Dígito não pode ser seguido por dígito
 * 
 * Exemplos de senhas válidas:
 * - A1b#2
 * - p@Q3r
 * - X9!y8
 */
class Senha {
private:
    string texto; ///< Senha armazenada como string

    /**
     * @brief Valida a senha conforme regras rigorosas de segurança
     * @param texto Senha a ser validada
     * @return true se a senha for válida, false caso contrário
     * 
     * Implementa a validação completa da senha, incluindo:
     * - Verificação de comprimento exato (5 caracteres)
     * - Validação de caracteres permitidos
     * - Verificação de presença de pelo menos: uma minúscula, uma maiúscula, um dígito, um especial
     * - Restrições de sequência: letra não seguida por letra, dígito não seguido por dígito
     * - Garantia de complexidade e segurança da senha
     */
    bool validar(string);

public:
    /**
     * @brief Define a senha
     * @param texto Senha em formato string
     * @throw invalid_argument Se a senha for inválida
     * 
     * Realiza a validação completa antes de armazenar o valor.
     * Senhas que não atendem às regras rigorosas de segurança
     * resultam em exceção com mensagem descritiva do erro.
     * 
     * @note A senha é armazenada em texto claro. Em sistemas
     * de produção, considere implementar criptografia adicional.
     */
    void setValor(string);

    /**
     * @brief Obtém a senha armazenada
     * @return string Senha armazenada
     * 
     * @note Em sistemas de produção, evite expor senhas
     * através deste método. Considere implementar métodos
     * de verificação sem expor o valor completo.
     */
    string getValor();
};

/**
 * @brief Implementação inline do método getValor
 * @return string Senha armazenada
 * 
 * Retorna a senha armazenada internamente.
 * 
 * @warning Em ambientes de produção, o retorno de senhas
 * em texto claro deve ser evitado por questões de segurança.
 */
inline string Senha::getValor() {
    return texto;
}

#endif // SENHA_HPP_INCLUDED