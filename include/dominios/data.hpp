/**
 * @file data.hpp
 * @brief Definição da classe Data para datas válidas
 */

#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Data
 * @brief Representa uma data válida no sistema
 *
 * A classe Data armazena e valida datas no formato dia-mês-ano, com validação
 * completa de dias válidos por mês, incluindo tratamento de anos bissextos.
 * 
 * **FORMATO VÁLIDO:**
 * - dia-mês-ano
 * - Dia é número de 1 a 31
 * - Mês é JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV ou DEZ
 * - Ano é número de 2000 a 2999
 * - Data deve ser válida considerando os anos bissextos
 * 
 * **REGRAS DE VALIDAÇÃO:**
 * 1. **Formato**: DD-MMM-AAAA onde:
 *    - DD = dia (01 a 31)
 *    - MMM = mês por extenso em maiúsculas (JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ)
 *    - AAAA = ano (2000 a 2999)
 * 
 * 2. **Dia**: Deve ser válido para o mês:
 *    - Meses com 31 dias: JAN, MAR, MAI, JUL, AGO, OUT, DEZ
 *    - Meses com 30 dias: ABR, JUN, SET, NOV
 *    - FEV: 28 dias (anos normais) ou 29 dias (anos bissextos)
 * 
 * 3. **Ano Bissexto**: Um ano é bissexto se:
 *    - É divisível por 4 E não é divisível por 100, OU
 *    - É divisível por 400
 *    - Exemplos: 2000 (bissexto), 2004 (bissexto), 2100 (não bissexto)
 * 
 * **EXEMPLOS:**
 * - ✅ Válido: "15-JAN-2024" (15 de janeiro de 2024)
 * - ✅ Válido: "29-FEV-2024" (2024 é bissexto)
 * - ✅ Válido: "31-DEZ-2999" (último dia do intervalo)
 * - ✅ Válido: "01-JAN-2000" (primeiro dia do intervalo)
 * - ❌ Inválido: "29-FEV-2023" (2023 não é bissexto)
 * - ❌ Inválido: "31-ABR-2024" (abril tem apenas 30 dias)
 * - ❌ Inválido: "32-JAN-2024" (dia inválido)
 * - ❌ Inválido: "15-13-2024" (mês deve ser por extenso)
 * - ❌ Inválido: "15-jan-2024" (mês deve estar em maiúsculas)
 * - ❌ Inválido: "15/JAN/2024" (separador deve ser hífen)
 * - ❌ Inválido: "15-JAN-1999" (ano antes de 2000)
 * - ❌ Inválido: "15-JAN-3000" (ano depois de 2999)
 * 
 * **TABELA DE DIAS POR MÊS:**
 * | Mês | Dias (normal) | Dias (bissexto) |
 * |-----|---------------|-----------------|
 * | JAN | 31            | 31              |
 * | FEV | 28            | 29              |
 * | MAR | 31            | 31              |
 * | ABR | 30            | 30              |
 * | MAI | 31            | 31              |
 * | JUN | 30            | 30              |
 * | JUL | 31            | 31              |
 * | AGO | 31            | 31              |
 * | SET | 30            | 30              |
 * | OUT | 31            | 31              |
 * | NOV | 30            | 30              |
 * | DEZ | 31            | 31              |
 */
class Data
{
private:
    /**
     * @brief Data armazenada em formato string (DD-MMM-AAAA)
     */
    string data;

    /**
     * @brief Valida a data conforme as regras do domínio
     * @param data Data a ser validada em formato string
     * @return true se a data for válida, false caso contrário
     *
     * Implementa a validação completa da data:
     * 1. Verifica formato DD-MMM-AAAA
     * 2. Valida dia (1 a 31)
     * 3. Valida mês (JAN a DEZ em maiúsculas)
     * 4. Valida ano (2000 a 2999)
     * 5. Verifica se dia é válido para o mês
     * 6. Considera anos bissextos para fevereiro
     * 
     * **Algoritmo de ano bissexto:**
     * - Se divisível por 400 → bissexto
     * - Se divisível por 100 → não bissexto
     * - Se divisível por 4 → bissexto
     * - Caso contrário → não bissexto
     */
    bool validar(string);

public:
    /**
     * @brief Define a data
     * @param data Data em formato string (DD-MMM-AAAA)
     * @throw invalid_argument Se a data for inválida
     *
     * Realiza a validação completa antes de armazenar o valor.
     * Datas que não atendem às regras de validação resultam em exceção.
     * 
     * Exemplo de uso:
     * @code
     * Data dataReserva;
     * try {
     *     dataReserva.setValor("15-JAN-2024");
     *     cout << "Data válida: " << dataReserva.getValor();
     * } catch (invalid_argument& e) {
     *     cout << "Data inválida: " << e.what();
     * }
     * @endcode
     */
    void setValor(string);

    /**
     * @brief Obtém a data armazenada
     * @return string Data armazenada em formato DD-MMM-AAAA
     */
    string getValor() const;
};

/**
 * @brief Implementação inline do método getValor()
 * @return string Data armazenada
 */
inline string Data::getValor() const
{
    return data;
}

#endif // DATA_HPP_INCLUDED
