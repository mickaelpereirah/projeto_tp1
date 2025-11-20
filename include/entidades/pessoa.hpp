#ifndef PESSOA_HPP_INCLUDED
#define PESSOA_HPP_INCLUDED
#include "DOMINIOS.hpp"

/**
 * @file pessoa.hpp
 * @brief Definição da classe Pessoa para o sistema de gestão de hotéis
 * @author Projeto TP1
 * @date 2025
 */

/**
 * @class Pessoa
 * @brief Classe base que representa uma pessoa no sistema de gestão de hotéis
 *
 * Esta classe serve como base para outras entidades do sistema (Gerente e Hóspede).
 * Contém os atributos básicos comuns a todas as pessoas: nome e email.
 *
 * @details
 * Atributos:
 * - nome: Nome da pessoa (tipo Nome)
 * - email: Email da pessoa (tipo Email)
 *
 * Relacionamentos:
 * - É especializada pelas classes Gerente e Hóspede
 */
class Pessoa
{
private:
    Nome nome;   ///< Nome da pessoa
    Email email; ///< Email da pessoa

public:
    /**
     * @brief Define o nome da pessoa
     * @param nome Objeto do tipo Nome contendo o nome a ser atribuído
     */
    void setNome(Nome);

    /**
     * @brief Obtém o nome da pessoa
     * @return Nome da pessoa
     */
    Nome getNome();

    /**
     * @brief Define o email da pessoa
     * @param email Objeto do tipo Email contendo o email a ser atribuído
     */
    void setEmail(Email);

    /**
     * @brief Obtém o email da pessoa
     * @return Email da pessoa
     */
    Email getEmail();
};

inline void Pessoa::setNome(Nome nome)
{
    this->nome = nome;
}

inline Nome Pessoa::getNome()
{
    return nome;
}

inline void Pessoa::setEmail(Email email)
{
    this->email = email;
}

inline Email Pessoa::getEmail()
{
    return email;
}

#endif