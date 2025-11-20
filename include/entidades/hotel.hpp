#ifndef HOTEL_HPP_INCLUDED
#define HOTEL_HPP_INCLUDED
#include "DOMINIOS.hpp"

/**
 * @file hotel.hpp
 * @brief Definição da classe Hotel para o sistema de gestão de hotéis
 * @author Projeto TP1
 * @date 2025
 */

/**
 * @class Hotel
 * @brief Classe que representa um hotel no sistema de gestão
 *
 * Esta classe encapsula as informações básicas de um hotel, incluindo
 * identificação, localização e dados de contato.
 *
 * @details
 * Atributos:
 * - nome: Nome do hotel (tipo Nome)
 * - endereco: Endereço do hotel (tipo Endereco)
 * - telefone: Telefone de contato do hotel (tipo Telefone)
 * - codigo: Código único de identificação do hotel (tipo Codigo - chave primária)
 *
 * Relacionamentos:
 * - É gerenciado por Gerente (0:* para 1)
 * - Possui Quarto (1 para 1:*)
 */
class Hotel
{
private:
    Nome nome;         ///< Nome do hotel
    Endereco endereco; ///< Endereço do hotel
    Telefone telefone; ///< Telefone de contato do hotel
    Codigo codigo;     ///< Código único de identificação do hotel (chave primária)

public:
    /**
     * @brief Define o nome do hotel
     * @param nome Objeto do tipo Nome contendo o nome a ser atribuído
     */
    void setNome(Nome);

    /**
     * @brief Obtém o nome do hotel
     * @return Nome do hotel
     */
    Nome getNome();

    /**
     * @brief Define o endereço do hotel
     * @param endereco Objeto do tipo Endereco contendo o endereço a ser atribuído
     */
    void setEndereco(Endereco);

    /**
     * @brief Obtém o endereço do hotel
     * @return Endereço do hotel
     */
    Endereco getEndereco();

    /**
     * @brief Define o telefone do hotel
     * @param telefone Objeto do tipo Telefone contendo o telefone a ser atribuído
     */
    void setTelefone(Telefone);

    /**
     * @brief Obtém o telefone do hotel
     * @return Telefone do hotel
     */
    Telefone getTelefone();

    /**
     * @brief Define o código do hotel
     * @param codigo Objeto do tipo Codigo contendo o código a ser atribuído (chave primária)
     */
    void setCodigo(Codigo);

    /**
     * @brief Obtém o código do hotel
     * @return Código do hotel (chave primária)
     */
    Codigo getCodigo();
};

inline void Hotel::setNome(Nome nome)
{
    this->nome = nome;
}

inline Nome Hotel::getNome()
{
    return nome;
}

inline void Hotel::setEndereco(Endereco endereco)
{
    this->endereco = endereco;
}

inline Endereco Hotel::getEndereco()
{
    return endereco;
}

inline void Hotel::setTelefone(Telefone telefone)
{
    this->telefone = telefone;
}

inline Telefone Hotel::getTelefone()
{
    return telefone;
}

inline void Hotel::setCodigo(Codigo codigo)
{
    this->codigo = codigo;
}

inline Codigo Hotel::getCodigo()
{
    return codigo;
}

#endif