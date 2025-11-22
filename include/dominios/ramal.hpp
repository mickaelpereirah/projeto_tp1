/**
 * @file ramal.hpp
 * @brief Definição da classe Ramal para ramais telefônicos
 */

#ifndef RAMAL_HPP_INCLUDED
#define RAMAL_HPP_INCLUDED

/**
 * @class Ramal
 * @brief Representa um ramal telefônico de quarto
 * 
 * A classe Ramal armazena e valida números de ramais telefônicos
 * associados a quartos de hotel.
 * 
 * **FORMATO VÁLIDO:**
 * - Valores de 00 a 50
 * 
 * **REGRAS DE VALIDAÇÃO:**
 * - Valor mínimo: 0 (representado como 00)
 * - Valor máximo: 50
 * - Armazenado como inteiro (0 a 50)
 * - Exibido com 2 dígitos (00, 01, ..., 50)
 * 
 * **EXEMPLOS:**
 * - ✅ Válido: 0 (ramal 00)
 * - ✅ Válido: 10 (ramal 10)
 * - ✅ Válido: 50 (ramal máximo)
 * - ❌ Inválido: -1 (valor negativo)
 * - ❌ Inválido: 51 (acima do máximo)
 * - ❌ Inválido: 100 (muito acima do máximo)
 * 
 * **NOTA DE USO:**
 * - Ramais podem ser repetidos em quartos diferentes
 * - Ramal 00 pode indicar que não há ramal associado
 * - Usado para comunicação interna do hotel
 */
class Ramal
{
private:
    /**
     * @brief Número do ramal armazenado (0 a 50)
     */
    int valor;

    /**
     * @brief Valida o número do ramal
     * @param valor Ramal a ser validado
     * @return true se o ramal estiver entre 0 e 50, false caso contrário
     * 
     * Verifica se o valor está no intervalo [0, 50].
     */
    bool validar(int);

public:
    /**
     * @brief Define o número do ramal
     * @param valor Número do ramal (0 a 50)
     * @throw invalid_argument Se o ramal estiver fora do intervalo
     * 
     * Valida o ramal antes de armazenar. Se o ramal for inválido,
     * lança exceção e o estado do objeto permanece inalterado.
     * 
     * Exemplo de uso:
     * @code
     * Ramal ramalQuarto;
     * try {
     *     ramalQuarto.setValor(25);
     *     cout << "Ramal: " << ramalQuarto.getValor();
     * } catch (invalid_argument& e) {
     *     cout << "Ramal inválido: " << e.what();
     * }
     * @endcode
     */
    void setValor(int);

    /**
     * @brief Obtém o número do ramal
     * @return int Ramal armazenado (0 a 50)
     */
    int getValor();
};

/**
 * @brief Implementação inline do método getValor
 * @return int Número do ramal armazenado
 */
inline int Ramal::getValor()
{
    return valor;
}

#endif // RAMAL_HPP_INCLUDED
