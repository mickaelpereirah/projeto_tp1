/**
 * @file dinheiro.hpp
 * @brief Definição da classe Dinheiro para valores monetários
 */

#ifndef DINHEIRO_HPP_INCLUDED
#define DINHEIRO_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Dinheiro
 * @brief Representa um valor monetário válido entre R$ 1,00 e R$ 1.000.000,00
 * 
 * A classe Dinheiro armazena valores monetários com precisão de centavos,
 * utilizando internamente representação em centavos (inteiro) para evitar
 * problemas de precisão com ponto flutuante.
 * 
 * Características principais:
 * - Intervalo: R$ 1,00 a R$ 1.000.000,00
 * - Precisão: 2 casas decimais (centavos)
 * - Armazenamento interno: valor em centavos (inteiro)
 * - Formato de entrada/saída: ponto como separador decimal (ex: 150.75)
 */
class Dinheiro
{
private:
    int valor; ///< Valor armazenado em centavos para precisão

    /**
     * @brief Valida o valor monetário
     * @param valor Valor em double a ser validado
     * @return true se o valor for válido, false caso contrário
     * 
     * Verifica se o valor está dentro do intervalo permitido:
     * - Mínimo: 1.00 (R$ 1,00)
     * - Máximo: 1000000.00 (R$ 1.000.000,00)
     */
    bool validar(double);

public:
    /**
     * @brief Define o valor monetário
     * @param valor Valor em formato double (ex: 150.75)
     * @throw invalid_argument Se o valor estiver fora do intervalo 1.00-1000000.00
     * 
     * Converte o valor para centavos (multiplica por 100) e valida
     * antes de armazenar. Valores inválidos resultam em exceção
     * com mensagem descritiva.
     */
    void setValor(double);

    /**
     * @brief Obtém o valor monetário formatado
     * @return double Valor convertido de centavos para reais com 2 casas decimais
     * 
     * Converte o valor interno de centavos para reais (divide por 100.00)
     * e retorna como double com precisão de 2 casas decimais.
     */
    double getValor();
};

/**
 * @brief Implementação inline do método getValor
 * @return double Valor convertido de centavos para reais
 * 
 * Realiza a conversão do valor interno (centavos) para
 * o formato monetário padrão (reais com 2 casas decimais).
 */
inline double Dinheiro::getValor()
{
    return valor / 100.00;
}

#endif // DINHEIRO_HPP_INCLUDED