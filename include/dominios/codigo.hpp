/**
 * @file codigo.hpp
 * @brief Definição da classe Codigo para códigos identificadores
 */

#ifndef CODIGO_HPP_INCLUDED
#define CODIGO_HPP_INCLUDED
#include <string>

using namespace std;

/**
 * @class Codigo
 * @brief Representa um código identificador válido
 * 
 * A classe Codigo é responsável por armazenar e validar códigos
 * utilizados no sistema para identificação de entidades.
 * 
 * As regras de validação típicas podem incluir:
 * - Formato específico (ex: AAA000)
 * - Tamanho fixo ou variável
 * - Caracteres permitidos (letras, números)
 * 
 * A implementação específica das regras de validação é definida
 * no método validar() privado.
 */

class Codigo{
    private:
        string caracteres; ///< Sequência de caracteres do código armazenado

        /**
                 * @brief Valida o código conforme as regras do domínio
                 * @param caracteres Código a ser validado
                 * @return true se o código for válido, false caso contrário
                 * 
                 * Implementa as regras de validação específicas para códigos
                 * no sistema, como formato, tamanho e caracteres permitidos.
                 */
        bool validar(string);
    
    public:
        /**
                 * @brief Define o código 
                 * @param caracteres Código em formato string
                 * @throw invalid_argument se o código for inválido
                 * 
                 * Realiza a validação completa antes de armazenar o valor.
                 * Códigos que não atendem às regras de validação resultam
                 * em exceção.
                 */
        void setValor(string);

        /**
                 * @brief Obtém o código armazenado
                 * @return string Código armazenado
                 */
        string getValor();
};

/**
 * @brief  Implementação inline do método getValor()
 * @return string Código armazenado
 */
inline string Codigo::getValor(){
    return caracteres;
}

#endif // CODIGO_HPP_INCLUDED