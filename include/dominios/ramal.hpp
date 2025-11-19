/**
 * @file ramal.hpp
 * @brief Definição da classe Ramal para números de ramal telefônico válidos
 */

#ifndef RAMAL_HPP_INCLUDED
#define RAMAL_HPP_INCLUDED

/**
 * @class Ramal
 * @brief Representa um número de ramal telefônico válido de 0 a 50
 * 
 * A classe Ramal é responsável por armazenar e validar números de ramal
 * telefônico dentro de um intervalo específico. A validação inclui:
 * - Intervalo de valores: 0 a 50 (inclusive)
 * - Apenas valores inteiros são aceitos
 * 
 * A classe é útil para sistemas que necessitam gerenciar ramais
 * telefônicos com validação de intervalo e formatação consistente.
 * 
 * Exemplos de valores válidos:
 * - 0 (formatado como 0)
 * - 5 (formatado como 5)
 * - 50 (formatado como 50)
 */
class Ramal {
private:
    int valor; ///< Valor do ramal armazenado como inteiro

    /**
     * @brief Valida o número do ramal conforme regras do domínio
     * @param valor Número do ramal a ser validado
     * @return true se o ramal for válido, false caso contrário
     * 
     * Implementa a validação do ramal, verificando se está
     * dentro do intervalo permitido (0 a 50 inclusive).
     * Valores fora deste intervalo são considerados inválidos.
     */
    bool validar(int);

public:
    /**
     * @brief Define o número do ramal
     * @param valor Número do ramal inteiro a ser armazenado
     * @throw invalid_argument Se o ramal for inválido (fora do intervalo 0-50)
     * 
     * Realiza a validação antes de armazenar o valor.
     * Ramais fora do intervalo permitido resultam em exceção
     * com mensagem descritiva do erro.
     */
    void setValor(int);

    /**
     * @brief Obtém o número do ramal armazenado
     * @return int Ramal armazenado como inteiro
     */
    int getValor();
};

/**
 * @brief Implementação inline do método getValor
 * @return int Número do ramal armazenado
 * 
 * Retorna o valor numérico do ramal armazenado internamente.
 */
inline int Ramal::getValor() {
    return valor;
}

#endif // RAMAL_HPP_INCLUDED