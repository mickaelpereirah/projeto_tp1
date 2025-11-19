/**
 * @file numero.hpp
 * @brief Definição da classe Numero para valores numéricos válidos
 */

#ifndef NUMERO_HPP_INCLUDED
#define NUMERO_HPP_INCLUDED

/**
 * @class Numero
 * @brief Representa um número inteiro válido de 1 a 999
 * 
 * A classe Numero é responsável por armazenar e validar números inteiros
 * dentro de um intervalo específico. A validação inclui:
 * - Intervalo de valores: 1 a 999 (inclusive)
 * - Apenas valores inteiros são aceitos
 * - Formatação de saída com 3 dígitos (ex: 001, 083, 999)
 * 
 * A classe é útil para representar números que requerem formatação
 * consistente, como códigos, identificadores ou valores numéricos
 * com tamanho fixo.
 * 
 * Exemplos de valores válidos:
 * - 1 (formatado como 001)
 * - 83 (formatado como 083)
 * - 999 (formatado como 999)
 */
class Numero {
private:
    int valor; ///< Valor numérico armazenado como inteiro

    /**
     * @brief Valida o número conforme regras do domínio
     * @param valor Número a ser validado
     * @return true se o número for válido, false caso contrário
     * 
     * Implementa a validação do número, verificando se está
     * dentro do intervalo permitido (1 a 999 inclusive).
     * Valores fora deste intervalo são considerados inválidos.
     */
    bool validar(int);

public:
    /**
     * @brief Define o número
     * @param valor Número inteiro a ser armazenado
     * @throw invalid_argument Se o número for inválido (fora do intervalo 1-999)
     * 
     * Realiza a validação antes de armazenar o valor.
     * Números fora do intervalo permitido resultam em exceção
     * com mensagem descritiva do erro.
     * 
     * @note O valor é armazenado como inteiro, mas pode ser
     * formatado na saída com 3 dígitos quando necessário.
     */
    void setValor(int);

    /**
     * @brief Obtém o número armazenado
     * @return int Número armazenado como inteiro
     * 
     * @note Para obter o valor formatado com 3 dígitos,
     * utilize funções de formatação na saída (ex: setw, setfill).
     */
    int getValor();
};

/**
 * @brief Implementação inline do método getValor
 * @return int Número armazenado
 * 
 * Retorna o valor numérico armazenado internamente.
 * Para formatação com zeros à esquerda, utilize:
 * cout << setw(3) << setfill('0') << numero.getValor()
 */
inline int Numero::getValor() {
    return valor;
}

#endif // NUMERO_HPP_INCLUDED