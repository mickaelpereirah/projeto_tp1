/**
 * @file capacidade.hpp 
 * @brief Definição da classe Capacidade para representar capacidade de quartos
 */

#ifndef CAPACIDADE_HPP_INCLUDED
#define CAPACIDADE_HPP_INCLUDED

/**
 * @class Capacidade
 * @brief Representa a capacidade de pessoas em um quarto
 * 
 * A classe Capacidade armazena e valida o número de pessoas que um quarto
 * pode acomodar. O valor deve estar dentro do conjunto permitido pelo sistema.
 * 
 * **FORMATO VÁLIDO:**
 * - Valores aceitos: 1, 2, 3 ou 4
 * 
 * **REGRAS DE VALIDAÇÃO:**
 * - Apenas os valores 1, 2, 3 ou 4 são aceitos
 * - Qualquer outro valor resulta em exceção invalid_argument
 * 
 * **EXEMPLOS:**
 * - ✅ Válido: 1 (quarto individual)
 * - ✅ Válido: 2 (quarto duplo)
 * - ✅ Válido: 3 (quarto triplo)
 * - ✅ Válido: 4 (quarto quádruplo)
 * - ❌ Inválido: 0 (não há quarto sem capacidade)
 * - ❌ Inválido: 5 (acima do limite permitido)
 * 
 * O método setValor() realiza a validação e lança exceção se inválido.
 * O método getValor() retorna o valor armazenado.
 */ 
class Capacidade{
    private:
        /**
         * @brief Valor inteiro que representa a capacidade (1, 2, 3 ou 4)
         */
        int valor;

        /**
         * @brief Valida o valor da capacidade
         * @param valor Valor a ser validado
         * @return true se o valor for 1, 2, 3 ou 4; false caso contrário
         * 
         * Verifica se o valor está no conjunto {1, 2, 3, 4}.
         */
        bool validar(int);
    
    public:
        /**
         * @brief Define o valor da capacidade
         * @param valor Novo valor da capacidade (deve ser 1, 2, 3 ou 4)
         * @throw invalid_argument Se o valor não for 1, 2, 3 ou 4
         * 
         * Valida o valor antes de armazenar. Se o valor for inválido,
         * lança exceção e o estado do objeto permanece inalterado.
         * 
         * Exemplo de uso:
         * @code
         * Capacidade cap;
         * try {
         *     cap.setValor(2);  // OK: quarto duplo
         *     cout << "Capacidade definida: " << cap.getValor();
         * } catch (invalid_argument& e) {
         *     cout << "Erro: " << e.what();
         * }
         * @endcode
         */
        void setValor(int);

        /**
         * @brief Retorna o valor atual da capacidade
         * @return int Valor armazenado (1, 2, 3 ou 4)
         */
        int getValor();
};

/**
 * @brief Implementação inline do método getValor
 * @return int Valor da capacidade armazenado
 */
inline int Capacidade::getValor(){
    return valor;
}

#endif // CAPACIDADE_HPP_INCLUDED
