/**
 * @file endereco.hpp
 * @brief Definição da classe Endereco para endereços textuais válidos
 */

#ifndef ENDERECO_HPP_INCLUDED
#define ENDERECO_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Endereco
 * @brief Representa um endereço textual válido
 * 
 * A classe Endereco armazena e valida endereços textuais com regras
 * específicas de formatação e sequenciamento de caracteres.
 * 
 * **FORMATO VÁLIDO:**
 * - Texto com 5 a 30 caracteres
 * 
 * **CARACTERES PERMITIDOS:**
 * - Letra (a-z ou A-Z)
 * - Dígito (0-9)
 * - Vírgula (,)
 * - Ponto (.)
 * - Espaço em branco ( )
 * 
 * **REGRAS DE SEQUÊNCIA:**
 * - Vírgula NÃO pode ser seguida por vírgula ou ponto
 * - Ponto NÃO pode ser seguido por vírgula ou ponto
 * - Espaço em branco é seguido por letra ou dígito
 * - Primeiro caractere NÃO pode ser vírgula, ponto ou espaço em branco
 * - Último caractere NÃO pode ser vírgula, ponto ou espaço em branco
 * 
 * **EXEMPLOS:**
 * - ✅ Válido: "Rua das Flores, 123"
 * - ✅ Válido: "Av. Principal 1000"
 * - ✅ Válido: "Praca da Se, 25"
 * - ✅ Válido: "Centro, Bloco A"
 * - ✅ Válido: "Quadra 10, Lote 5"
 * - ❌ Inválido: "Rua" (apenas 3 caracteres, mínimo é 5)
 * - ❌ Inválido: "Este endereco tem mais de trinta caracteres" (mais de 30)
 * - ❌ Inválido: ",Rua das Flores" (começa com vírgula)
 * - ❌ Inválido: "Rua das Flores," (termina com vírgula)
 * - ❌ Inválido: "Rua das Flores,, 123" (vírgula seguida de vírgula)
 * - ❌ Inválido: "Rua. Principal,. 123" (ponto seguido de vírgula)
 * - ❌ Inválido: "Rua  das Flores" (espaço seguido de espaço - não está claro na spec)
 * - ❌ Inválido: " Rua das Flores" (começa com espaço)
 * - ❌ Inválido: "Rua das Flores " (termina com espaço)
 * - ❌ Inválido: "Rua #10" (caractere especial # não permitido)
 * 
 * **VALIDAÇÕES ESPECÍFICAS:**
 * - Comprimento entre 5 e 30 caracteres (inclusive)
 * - Apenas caracteres permitidos (a-z, A-Z, 0-9, vírgula, ponto, espaço)
 * - Vírgula → pode vir: letra, dígito, espaço (NÃO: vírgula, ponto)
 * - Ponto → pode vir: letra, dígito, espaço (NÃO: vírgula, ponto)
 * - Espaço → DEVE vir: letra ou dígito (NÃO: vírgula, ponto, espaço)
 * - Primeiro caractere: letra ou dígito
 * - Último caractere: letra ou dígito
 */
class Endereco{
private:
    /**
     * @brief Texto do endereço armazenado (5-30 caracteres)
     */
    string texto;

    /**
     * @brief Valida o endereço textual
     * @param texto Endereço a ser validado
     * @return true se o endereço for válido, false caso contrário
     * 
     * Executa as seguintes validações:
     * 1. Verifica comprimento (5 a 30 caracteres)
     * 2. Valida caracteres permitidos (a-z, A-Z, 0-9, vírgula, ponto, espaço)
     * 3. Verifica primeiro caractere (não pode ser vírgula, ponto ou espaço)
     * 4. Verifica último caractere (não pode ser vírgula, ponto ou espaço)
     * 5. Valida sequências:
     *    - Vírgula não seguida de vírgula ou ponto
     *    - Ponto não seguido de vírgula ou ponto
     *    - Espaço seguido de letra ou dígito
     */
    bool validar(string);

public:
    /**
     * @brief Define o endereço textual
     * @param texto Endereço em formato string (5-30 caracteres)
     * @throw invalid_argument Se o endereço for inválido
     * 
     * Realiza a validação completa antes de armazenar.
     * 
     * Exemplo de uso:
     * @code
     * Endereco endHospede;
     * try {
     *     endHospede.setValor("Rua das Flores, 123");
     *     cout << "Endereço válido: " << endHospede.getValor();
     * } catch (invalid_argument& e) {
     *     cout << "Endereço inválido: " << e.what();
     * }
     * @endcode
     */
    void setValor(string);

    /**
     * @brief Obtém o endereço armazenado
     * @return string Endereço no formato válido (5-30 caracteres)
     */
    string getValor();
};

/**
 * @brief Implementação inline do método getValor
 * @return string Endereço armazenado
 */
inline string Endereco::getValor(){
    return texto; 
}

#endif // ENDERECO_HPP_INCLUDED
