/**
 * @file ENTIDADES.hpp
 * @brief Arquivo de inclusao central para todas as entidades do sistema
 *
 * Este arquivo header agrupa todas as entidades do sistema em um unico ponto
 * de inclusao, facilitando o uso das entidades em outros modulos.
 *
 * ENTIDADES INCLUIDAS:
 * - Pessoa (classe base)
 * - Gerente (herda de Pessoa)
 * - Hospede (herda de Pessoa)
 * - Hotel
 * - Quarto
 * - Reserva
 *
 * RELACIONAMENTOS:
 * - Gerente (1) -> Hotel (0..*)
 * - Hotel (1) -> Quarto (1..*)
 * - Hospede (1) -> Reserva (0..*)
 * - Quarto (1) -> Reserva (0..*)
 */

#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED

#include "pessoa.hpp"
#include "gerente.hpp"
#include "hospede.hpp"
#include "hotel.hpp"
#include "quarto.hpp"
#include "reserva.hpp"

#endif // ENTIDADES_HPP_INCLUDED
