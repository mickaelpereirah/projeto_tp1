#ifndef HOSPEDE_HPP_INCLUDED
#define HOSPEDE_HPP_INCLUDED
#include "DOMINIOS.hpp"
#include "pessoa.hpp"

/**
 * @file hospede.hpp
 * @brief Definição da classe Hospede para o sistema de gestão de hotéis
 * @author Projeto TP1
 * @date 2025
 */

/**
 * @class Hospede
 * @brief Classe que representa um hóspede no sistema de gestão de hotéis
 * @extends Pessoa
 *
 * Esta classe herda de Pessoa e adiciona atributos específicos para hóspedes.
 * Um hóspede pode fazer reservas em hotéis e possui endereço e cartão de pagamento.
 *
 * @details
 * Atributos herdados de Pessoa:
 * - nome: Nome do hóspede
 * - email: Email do hóspede
 *
 * Atributos específicos:
 * - endereco: Endereço do hóspede (tipo Endereco)
 * - cartao: Cartão de pagamento do hóspede (tipo Cartao)
 *
 * Relacionamentos:
 * - Herda de Pessoa (1:1)
 * - Faz Reserva (0:* para 1)
 */
class Hospede : public Pessoa
{
private:
    Endereco endereco; ///< Endereço do hóspede
    Cartao cartao;     ///< Cartão de pagamento do hóspede

public:
    /**
     * @brief Define o endereço do hóspede
     * @param endereco Objeto do tipo Endereco contendo o endereço a ser atribuído
     */
    void setEndereco(Endereco);

    /**
     * @brief Obtém o endereço do hóspede
     * @return Endereço do hóspede
     */
    Endereco getEndereco();

    /**
     * @brief Define o cartão do hóspede
     * @param cartao Objeto do tipo Cartao contendo o cartão a ser atribuído
     */
    void setCartao(Cartao);

    /**
     * @brief Obtém o cartão do hóspede
     * @return Cartão do hóspede
     */
    Cartao getCartao();
};

inline void Hospede::setEndereco(Endereco endereco)
{
    this->endereco = endereco;
}

inline Endereco Hospede::getEndereco()
{
    return endereco;
}

inline void Hospede::setCartao(Cartao cartao)
{
    this->cartao = cartao;
}

inline Cartao Hospede::getCartao()
{
    return cartao;
}

#endif