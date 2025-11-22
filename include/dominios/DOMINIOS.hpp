/**
 * @file DOMINIOS.hpp
 * @brief Arquivo de inclusão central para todos os domínios do sistema
 * 
 * Este arquivo header agrupa todos os domínios do sistema em um único ponto
 * de inclusão, facilitando o uso dos domínios em outros módulos. Basta incluir
 * este arquivo para ter acesso a todos os domínios disponíveis.
 * 
 * **DOMÍNIOS INCLUÍDOS:**
 * 
 * | Domínio    | Formato Válido                                      | Uso                          |
 * |------------|-----------------------------------------------------|------------------------------|
 * | Capacidade | 1, 2, 3 ou 4                                        | Capacidade de pessoas        |
 * | Cartao     | 16 dígitos + Luhn                                   | Cartão de crédito            |
 * | Codigo     | 10 caracteres alfanuméricos                         | Identificador único          |
 * | Data       | DD-MMM-AAAA (2000-2999)                             | Datas de reserva             |
 * | Dinheiro   | 0,01 a 1.000.000,00                                 | Valores monetários           |
 * | Email      | parte-local@dominio                                 | Email de usuários            |
 * | Endereco   | 5-30 caracteres                                     | Endereço textual             |
 * | Nome       | 5-20 caracteres, capitalizado                       | Nome pessoal                 |
 * | Numero     | 001 a 999                                           | Número de quarto             |
 * | Ramal      | 00 a 50                                             | Ramal telefônico             |
 * | Senha      | 5 caracteres com requisitos                         | Senha de acesso              |
 * | Telefone   | +DDDDDDDDDDDDDD                                     | Telefone internacional       |
 * 
 * **PRINCÍPIOS DOS DOMÍNIOS:**
 * 
 * Todos os domínios seguem os mesmos princípios de design:
 * 1. **Encapsulamento**: Atributo privado, acesso via métodos públicos
 * 2. **Validação rigorosa**: setValor() valida antes de armazenar
 * 3. **Exceções**: Lançam invalid_argument se valor inválido
 * 4. **Imutabilidade controlada**: Valor só muda via setValor()
 * 5. **Inline getters**: Métodos getValor() implementados inline para performance
 * 
 * **EXEMPLO DE USO:**
 * @code
 * #include "DOMINIOS.hpp"
 * 
 * // Criar e validar um email
 * Email emailGerente;
 * try {
 *     emailGerente.setValor("gerente@hotel.com");
 * } catch (invalid_argument& e) {
 *     cout << "Email inválido: " << e.what();
 * }
 * 
 * // Criar e validar uma data
 * Data dataReserva;
 * try {
 *     dataReserva.setValor("15-JAN-2024");
 * } catch (invalid_argument& e) {
 *     cout << "Data inválida: " << e.what();
 * }
 * @endcode
 * 
 * **NOTA DE IMPLEMENTAÇÃO:**
 * - Nas implementações dos códigos de validação não é considerada acentuação nem letra ç
 * - Todos os domínios usam apenas caracteres ASCII básicos
 * - Validações seguem rigorosamente a especificação do sistema
 */

#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include "capacidade.hpp"
#include "cartao.hpp"
#include "codigo.hpp"
#include "data.hpp"
#include "dinheiro.hpp"
#include "email.hpp"
#include "endereco.hpp"
#include "nome.hpp"
#include "numero.hpp"
#include "ramal.hpp"
#include "senha.hpp"
#include "telefone.hpp"

#endif // DOMINIOS_HPP_INCLUDED
