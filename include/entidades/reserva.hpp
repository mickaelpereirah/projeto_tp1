#ifndef RESERVA_HPP_INCLUDED
#define RESERVA_HPP_INCLUDED
#include "DOMINIOS.hpp"

/**
 * @file reserva.hpp
 * @brief Definição da classe Reserva para o sistema de gestão de hotéis
 * @author Projeto TP1
 * @date 2025
 */

/**
 * @class Reserva
 * @brief Classe que representa uma reserva no sistema de gestão de hotéis
 *
 * Esta classe encapsula as informações de uma reserva, incluindo datas de
 * chegada e partida, valor total e código de identificação.
 *
 * @details
 * Atributos:
 * - chegada: Data de chegada da reserva (tipo Data)
 * - partida: Data de partida da reserva (tipo Data)
 * - valor: Valor total da reserva (tipo Dinheiro)
 * - codigo: Código único de identificação da reserva (tipo Codigo - chave primária)
 *
 * Relacionamentos:
 * - É feita por Hóspede (0:* para 1)
 * - Reserva Quarto (1 para 0:*)
 *
 * Regras de negócio:
 * - Não podem ocorrer conflitos entre reservas do mesmo quarto
 * - Data de partida deve ser posterior à data de chegada
 */
class Reserva
{
private:
    Data chegada;   ///< Data de chegada da reserva
    Data partida;   ///< Data de partida da reserva
    Dinheiro valor; ///< Valor total da reserva
    Codigo codigo;  ///< Código único de identificação da reserva (chave primária)

public:
    /**
     * @brief Define a data de chegada da reserva
     * @param chegada Objeto do tipo Data contendo a data de chegada
     */
    void setChegada(Data);

    /**
     * @brief Obtém a data de chegada da reserva
     * @return Data de chegada da reserva
     */
    Data getChegada();

    /**
     * @brief Define a data de partida da reserva
     * @param partida Objeto do tipo Data contendo a data de partida
     */
    void setPartida(Data);

    /**
     * @brief Obtém a data de partida da reserva
     * @return Data de partida da reserva
     */
    Data getPartida();

    /**
     * @brief Define o valor da reserva
     * @param valor Objeto do tipo Dinheiro contendo o valor a ser atribuído
     */
    void setDinheiro(Dinheiro);

    /**
     * @brief Obtém o valor da reserva
     * @return Valor da reserva
     */
    Dinheiro getDinheiro();

    /**
     * @brief Define o código da reserva
     * @param codigo Objeto do tipo Codigo contendo o código a ser atribuído (chave primária)
     */
    void setCodigo(Codigo);

    /**
     * @brief Obtém o código da reserva
     * @return Código da reserva (chave primária)
     */
    Codigo getCodigo();
};

inline void Reserva::setChegada(Data chegada)
{
    this->chegada = chegada;
}

inline Data Reserva::getChegada()
{
    return chegada;
}

inline void Reserva::setPartida(Data partida)
{
    this->partida = partida;
}

inline Data Reserva::getPartida()
{
    return partida;
}

inline void Reserva::setDinheiro(Dinheiro valor)
{
    this->valor = valor;
}

inline Dinheiro Reserva::getDinheiro()
{
    return valor;
}

inline void Reserva::setCodigo(Codigo codigo)
{
    this->codigo = codigo;
}

inline Codigo Reserva::getCodigo()
{
    return codigo;
}

#endif