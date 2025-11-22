/**
 * @file dinheiro.hpp
 * @brief Definição da classe Dinheiro para valores monetários
 */

#ifndef DINHEIRO_HPP_INCLUDED
#define DINHEIRO_HPP_INCLUDED

/**
 * @class Dinheiro
 * @brief Representa um valor monetário válido no sistema
 * 
 * A classe Dinheiro armazena valores monetários como inteiros para evitar
 * erros de arredondamento típicos de ponto flutuante. O valor é armazenado
 * em centavos (menor unidade monetária).
 * 
 * **FORMATO VÁLIDO:**
 * - Valor de 0,01 a 1.000.000,00
 * - Armazenamento deve ser em inteiro para evitar erro de arredondamento
 * 
 * **REGRAS DE VALIDAÇÃO:**
 * 1. Valor mínimo: 0,01 (1 centavo = 1 unidade inteira)
 * 2. Valor máximo: 1.000.000,00 (100.000.000 centavos)
 * 3. Armazenamento interno: valor em centavos como inteiro
 *    - Exemplo: R$ 10,50 → armazenado como 1050
 *    - Exemplo: R$ 100,00 → armazenado como 10000
 * 
 * **EXEMPLOS:**
 * - ✅ Válido: 0,01 (1 centavo)
 * - ✅ Válido: 10,50 (R$ 10,50)
 * - ✅ Válido: 1000,00 (R$ 1.000,00)
 * - ✅ Válido: 1000000,00 (R$ 1.000.000,00 - valor máximo)
 * - ❌ Inválido: 0,00 (abaixo do mínimo)
 * - ❌ Inválido: -10,00 (valor negativo)
 * - ❌ Inválido: 1000000,01 (acima do máximo)
 * 
 * **NOTA TÉCNICA:**
 * O armazenamento em inteiro evita problemas como:
 * - 0.1 + 0.2 != 0.3 (erro de ponto flutuante)
 * - Perda de precisão em operações monetárias
 * - Arredondamentos incorretos
 * 
 * Para converter:
 * - double para centavos: valor_double * 100
 * - centavos para double: valor_centavos / 100.0
 */
class Dinheiro
{
private:
    /**
     * @brief Valor monetário armazenado em centavos (inteiro)
     * 
     * Armazena o valor em centavos para evitar erros de arredondamento.
     * Exemplo: R$ 10,50 = 1050 centavos
     */
    int valor;

    /**
     * @brief Valida o valor monetário
     * @param valor Valor em formato double (0,01 a 1.000.000,00)
     * @return true se o valor for válido, false caso contrário
     * 
     * Verifica se o valor está dentro do intervalo permitido:
     * - Mínimo: 0,01 (equivalente a 1 centavo)
     * - Máximo: 1.000.000,00 (equivalente a 100.000.000 centavos)
     */
    bool validar(double);

public:
    /**
     * @brief Define o valor monetário
     * @param valor Valor em formato double (0,01 a 1.000.000,00)
     * @throw invalid_argument Se o valor estiver fora do intervalo
     * 
     * Converte o valor double para centavos (inteiro) e armazena.
     * Se o valor for inválido, lança exceção.
     * 
     * Exemplo de uso:
     * @code
     * Dinheiro diaria;
     * try {
     *     diaria.setValor(150.50);  // R$ 150,50
     *     cout << "Diária: R$ " << diaria.getValor();
     * } catch (invalid_argument& e) {
     *     cout << "Valor inválido: " << e.what();
     * }
     * @endcode
     */
    void setValor(double);

    /**
     * @brief Obtém o valor monetário
     * @return double Valor em reais (formato decimal)
     * 
     * Converte o valor armazenado em centavos de volta para reais.
     * Retorna: valor_centavos / 100.0
     */
    double getValor();
};

/**
 * @brief Implementação inline do método getValor()
 * @return double Valor em reais
 */
inline double Dinheiro::getValor()
{
    return valor / 100.0;
}

#endif // DINHEIRO_HPP_INCLUDED
