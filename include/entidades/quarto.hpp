#ifndef QUARTO_HPP_INCLUDED
#define QUARTO_HPP_INCLUDED
#include "DOMINIOS.hpp"

/**
 * @file quarto.hpp
 * @brief Definição da classe Quarto para o sistema de gestão de hotéis
 * @author Projeto TP1
 * @date 2025
 */

/**
 * @class Quarto
 * @brief Classe que representa um quarto de hotel no sistema de gestão
 *
 * Esta classe encapsula as informações de um quarto, incluindo sua identificação,
 * capacidade, valor da diária e ramal de comunicação.
 *
 * @details
 * Atributos:
 * - numero: Número do quarto (tipo Numero)
 * - capacidade: Capacidade de ocupação do quarto (tipo Capacidade)
 * - dinheiro: Valor da diária do quarto (tipo Dinheiro)
 * - ramal: Ramal de comunicação do quarto (tipo Ramal)
 *
 * Relacionamentos:
 * - Pertence a Hotel (1:* para 1)
 * - É reservado por Reserva (1 para 0:*)
 */
class Quarto
{
private:
    Numero numero;         ///< Número identificador do quarto
    Capacidade capacidade; ///< Capacidade de ocupação do quarto (1-4 pessoas)
    Dinheiro dinheiro;     ///< Valor da diária do quarto
    Ramal ramal;           ///< Ramal de comunicação do quarto

public:
    /**
     * @brief Define o número do quarto
     * @param numero Objeto do tipo Numero contendo o número a ser atribuído
     */
    void setNumero(Numero);

    /**
     * @brief Obtém o número do quarto
     * @return Número do quarto
     */
    Numero getNumero();

    /**
     * @brief Define a capacidade do quarto
     * @param capacidade Objeto do tipo Capacidade contendo a capacidade a ser atribuída
     */
    void setCapacidade(Capacidade);

    /**
     * @brief Obtém a capacidade do quarto
     * @return Capacidade do quarto
     */
    Capacidade getCapacidade();

    /**
     * @brief Define o valor da diária do quarto
     * @param dinheiro Objeto do tipo Dinheiro contendo o valor a ser atribuído
     */
    void setDinheiro(Dinheiro);

    /**
     * @brief Obtém o valor da diária do quarto
     * @return Valor da diária do quarto
     */
    Dinheiro getDinheiro();

    /**
     * @brief Define o ramal do quarto
     * @param ramal Objeto do tipo Ramal contendo o ramal a ser atribuído
     */
    void setRamal(Ramal);

    /**
     * @brief Obtém o ramal do quarto
     * @return Ramal do quarto
     */
    Ramal getRamal();
};

inline void Quarto::setNumero(Numero numero)
{
    this->numero = numero;
}

inline Numero Quarto::getNumero()
{
    return numero;
}

inline void Quarto::setCapacidade(Capacidade capacidade)
{
    this->capacidade = capacidade;
}

inline Capacidade Quarto::getCapacidade()
{
    return capacidade;
}

inline void Quarto::setDinheiro(Dinheiro dinheiro)
{
    this->dinheiro = dinheiro;
}

inline Dinheiro Quarto::getDinheiro()
{
    return dinheiro;
}

inline void Quarto::setRamal(Ramal ramal)
{
    this->ramal = ramal;
}

inline Ramal Quarto::getRamal()
{
    return ramal;
}

#endif