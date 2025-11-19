/**
 * @file capacidade.hpp 
 * @brief Definição da classe Capacidade para valores de capacidade.
 */

#ifndef CAPACIDADE_HPP_INCLUDED
#define CAPACIDADE_HPP_INCLUDED

/**
 * @class Capacidade
 * @brief Representa a capacidade de um quarto, hotel ou entidade relacionada.
 * 
 * A classe Capacidade é responsável por armazenar e validar um valor inteiro
 * que representa a capacidade (por exemplo, número de pessoas).
 * 
 * Regras típicas de validação (exemplo):
 * - Deve ser um número positivo.
 * - Deve ser menor ou igual ao limite definido pelo sistema. 
 *
 * O método setValor() realiza a validação e só atribui o valor se ele for válido.
 * O método getValor() retorna o valor armazenado.
 */ 

 class Capacidade{
    private:
        int valor;  /**< Valor inteiro que representa a capacidade */

        /**
                 * @brief Valida o valor da capacidade.
                 * @param valor 0 valor a ser valido.
                 * @return true se o valor for válido, false caso contrário.
                 */
    
        bool validar(int);
    
    public:

        /**
                 * @brief Define o valor da capacidade.
                 * 
                 * Chama a função validar(). Caso o valor seja inválido,
                 * deve lançar execeção do tipo invalid_argument.
                 * 
                 * @param valor Novo valor da capacidade.
                 * @throw invalid_argument Se o valor estiver fora do intervalo 1-4
                 */
        void setValor(int);

        /**
                 * @brief Retorna o valor atual da capacidade.
                 * @return Valor inteiro armazenado
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