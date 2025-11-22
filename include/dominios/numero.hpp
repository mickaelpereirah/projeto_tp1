/**
 * @file numero.hpp
 * @brief Definição da classe Numero para números de quartos
 */

#ifndef NUMERO_HPP_INCLUDED
#define NUMERO_HPP_INCLUDED

/**
 * @class Numero
 * @brief Representa o número de um quarto
 * 
 * A classe Numero armazena e valida números de quartos dentro do
 * intervalo permitido pelo sistema.
 * 
 * **FORMATO VÁLIDO:**
 * - Valores de 001 a 999
 * 
 * **REGRAS DE VALIDAÇÃO:**
 * - Valor mínimo: 1 (representado como 001)
 * - Valor máximo: 999
 * - Armazenado como inteiro (1 a 999)
 * - Exibido com 3 dígitos (001, 002, ..., 999)
 * 
 * **EXEMPLOS:**
 * - ✅ Válido: 1 (exibido como 001)
 * - ✅ Válido: 101 (quarto 101)
 * - ✅ Válido: 999 (último quarto permitido)
 * - ❌ Inválido: 0 (abaixo do mínimo)
 * - ❌ Inválido: 1000 (acima do máximo)
 * - ❌ Inválido: -5 (valor negativo)
 * 
 * **NOTA DE USO:**
 * - Cada quarto deve ter número único no sistema
 * - Números não utilizados podem ser reutilizados após exclusão
 * - O número é a chave primária do quarto
 */
class Numero
{
private:
    /**
     * @brief Número do quarto armazenado (1 a 999)
     */
    int valor;

    /**
     * @brief Valida o número do quarto
     * @param valor Número a ser validado
     * @return true se o número estiver entre 1 e 999, false caso contrário
     * 
     * Verifica se o valor está no intervalo [1, 999].
     */
    bool validar(int);

public:
    /**
     * @brief Define o número do quarto
     * @param valor Número do quarto (1 a 999)
     * @throw invalid_argument Se o número estiver fora do intervalo
     * 
     * Valida o número antes de armazenar. Se o número for inválido,
     * lança exceção e o estado do objeto permanece inalterado.
     * 
     * Exemplo de uso:
     * @code
     * Numero numQuarto;
     * try {
     *     numQuarto.setValor(101);
     *     cout << "Quarto número: " << numQuarto.getValor();
     * } catch (invalid_argument& e) {
     *     cout << "Número inválido: " << e.what();
     * }
     * @endcode
     */
    void setValor(int);

    /**
     * @brief Obtém o número do quarto
     * @return int Número armazenado (1 a 999)
     */
    int getValor();
};

/**
 * @brief Implementação inline do método getValor
 * @return int Número do quarto armazenado
 */
inline int Numero::getValor()
{
    return valor;
}

#endif // NUMERO_HPP_INCLUDED
