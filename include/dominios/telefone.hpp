/**
 * @file telefone.hpp
 * @brief Definição da classe Telefone para números telefônicos internacionais
 */

#ifndef TELEFONE_HPP_INCLUDED
#define TELEFONE_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Telefone
 * @brief Representa um número de telefone internacional
 * 
 * A classe Telefone armazena e valida números telefônicos no formato
 * internacional, começando com símbolo de adição (+) seguido por dígitos.
 * 
 * **FORMATO VÁLIDO:**
 * - +DDDDDDDDDDDDDD
 * - D é dígito (0-9)
 * 
 * **REGRAS DE VALIDAÇÃO:**
 * - Deve começar com o símbolo + (mais)
 * - Seguido por exatamente 14 dígitos (0-9)
 * - Não são permitidos:
 *   - Espaços em branco
 *   - Parênteses
 *   - Hífens ou outros separadores
 *   - Letras ou caracteres especiais (exceto o + inicial)
 * - Total: 15 caracteres (1 símbolo + e 14 dígitos)
 * 
 * **ESTRUTURA TÍPICA:**
 * - Código do país: 1-3 dígitos (ex: +55 para Brasil)
 * - Código de área: 2 dígitos (ex: 61 para Brasília)
 * - Número: restante dos dígitos
 * 
 * **EXEMPLOS:**
 * - ✅ Válido: "+55619876543210" (Brasil, Brasília)
 * - ✅ Válido: "+12025551234000" (EUA)
 * - ✅ Válido: "+44207946000000" (Reino Unido)
 * - ✅ Válido: "+00000000000000" (número de teste)
 * - ❌ Inválido: "55619876543210" (falta o símbolo +)
 * - ❌ Inválido: "+5561987654321" (apenas 13 dígitos, precisa de 14)
 * - ❌ Inválido: "+556198765432100" (15 dígitos, precisa de 14)
 * - ❌ Inválido: "+55 61 98765 4321" (contém espaços)
 * - ❌ Inválido: "+55-61-98765-4321" (contém hífens)
 * - ❌ Inválido: "+55(61)987654321" (contém parênteses)
 * - ❌ Inválido: "55-61-98765-4321" (falta + e tem hífens)
 * - ❌ Inválido: "+5561987654321a" (contém letra)
 * 
 * **EXEMPLOS POR PAÍS:**
 * | País          | Código | Exemplo Completo     |
 * |---------------|--------|----------------------|
 * | Brasil        | +55    | +55619876543210      |
 * | EUA           | +1     | +12025551234000      |
 * | Reino Unido   | +44    | +44207946000000      |
 * | Argentina     | +54    | +54119876543210      |
 * | Portugal      | +351   | +35121234567800      |
 * 
 * **NOTA TÉCNICA:**
 * - O formato é simplificado para fins educacionais
 * - Em sistemas reais, validação de telefone é mais complexa
 * - Não verifica se o código do país ou formato específico são válidos
 * - Apenas garante: + seguido de 14 dígitos
 */
class Telefone
{
private:
    /**
     * @brief Número de telefone armazenado (+DDDDDDDDDDDDDD)
     */
    string numero;

    /**
     * @brief Valida o número de telefone
     * @param numero Número a ser validado
     * @return true se o número for válido, false caso contrário
     * 
     * Executa as seguintes validações:
     * 1. Verifica se tem exatamente 15 caracteres (+ e 14 dígitos)
     * 2. Verifica se o primeiro caractere é '+'
     * 3. Verifica se os 14 caracteres seguintes são todos dígitos (0-9)
     * 4. Garante que não há espaços, parênteses ou outros caracteres
     */
    bool validar(string);

public:
    /**
     * @brief Define o número de telefone
     * @param numero Número em formato string (+DDDDDDDDDDDDDD)
     * @throw invalid_argument Se o número for inválido
     * 
     * Realiza a validação completa antes de armazenar.
     * O número deve estar no formato internacional completo.
     * 
     * Exemplo de uso:
     * @code
     * Telefone telHotel;
     * try {
     *     telHotel.setValor("+55619876543210");
     *     cout << "Telefone válido: " << telHotel.getValor();
     * } catch (invalid_argument& e) {
     *     cout << "Telefone inválido: " << e.what();
     * }
     * @endcode
     */
    void setValor(string);

    /**
     * @brief Obtém o número de telefone armazenado
     * @return string Número de telefone no formato +DDDDDDDDDDDDDD
     */
    string getValor();
};

/**
 * @brief Implementação inline do método getValor
 * @return string Número de telefone armazenado
 */
inline string Telefone::getValor()
{
    return numero;
}

#endif // TELEFONE_HPP_INCLUDED
