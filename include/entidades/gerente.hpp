#ifndef GERENTE_HPP_INCLUDED
#define GERENTE_HPP_INCLUDED
#include "DOMINIOS.hpp"
#include "pessoa.hpp"

/**
 * @file gerente.hpp
 * @brief Definição da classe Gerente para o sistema de gestão de hotéis
 * @author Projeto TP1
 * @date 2025
 */

/**
 * @class Gerente
 * @brief Classe que representa um gerente no sistema de gestão de hotéis
 * @extends Pessoa
 *
 * Esta classe herda de Pessoa e adiciona atributos específicos para gerentes.
 * Um gerente tem acesso ao sistema através de ramal e senha, podendo gerenciar
 * hotéis, quartos, reservas e hóspedes.
 *
 * @details
 * Atributos herdados de Pessoa:
 * - nome: Nome do gerente
 * - email: Email do gerente
 *
 * Atributos específicos:
 * - ramal: Ramal do gerente para comunicação interna (tipo Ramal)
 * - senha: Senha de acesso ao sistema (tipo Senha)
 *
 * Relacionamentos:
 * - Herda de Pessoa (1:1)
 * - Gerencia Hotel (0:* para 1)
 */
class Gerente : public Pessoa
{
private:
    Ramal ramal; ///< Ramal do gerente para comunicação interna
    Senha senha; ///< Senha de acesso do gerente ao sistema

public:
    /**
     * @brief Define o ramal do gerente
     * @param ramal Objeto do tipo Ramal contendo o ramal a ser atribuído
     */
    void setRamal(Ramal);

    /**
     * @brief Obtém o ramal do gerente
     * @return Ramal do gerente
     */
    Ramal getRamal();

    /**
     * @brief Define a senha do gerente
     * @param senha Objeto do tipo Senha contendo a senha a ser atribuída
     */
    void setSenha(Senha);

    /**
     * @brief Obtém a senha do gerente
     * @return Senha do gerente
     */
    Senha getSenha();
};

inline void Gerente::setRamal(Ramal ramal)
{
    this->ramal = ramal;
}

inline Ramal Gerente::getRamal()
{
    return ramal;
}

inline void Gerente::setSenha(Senha senha)
{
    this->senha = senha;
}

inline Senha Gerente::getSenha()
{
    return senha;
}

#endif