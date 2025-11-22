/**
 * @file nome.hpp
 * @brief Definição da classe Nome para nomes pessoais válidos
 */

#ifndef NOME_HPP_INCLUDED
#define NOME_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Nome
 * @brief Representa um nome pessoal válido
 * 
 * A classe Nome armazena e valida nomes pessoais seguindo regras
 * específicas de formatação e capitalização.
 * 
 * **FORMATO VÁLIDO:**
 * - Texto com 5 a 20 caracteres
 * 
 * **CARACTERES PERMITIDOS:**
 * - Letra (a-z ou A-Z)
 * - Espaço em branco ( )
 * 
 * **REGRAS DE FORMATAÇÃO:**
 * - Cada caracter pode ser letra (a-z ou A-Z) ou espaço em branco
 * - Primeiro caracter de cada termo é letra maiúscula (A-Z)
 * - Espaço em branco é seguido por letra
 * - Último caracter não pode ser espaço em branco
 * 
 * **DEFINIÇÃO DE TERMO:**
 * - Termo: sequência de letras separada por espaço
 * - Exemplo: "Joao Silva" tem 2 termos: "Joao" e "Silva"
 * - Cada termo deve começar com letra maiúscula
 * 
 * **EXEMPLOS:**
 * - ✅ Válido: "Joao Silva" (5 caracteres, 2 termos capitalizados)
 * - ✅ Válido: "Maria Santos" (12 caracteres)
 * - ✅ Válido: "Carlos Alberto Souza" (20 caracteres, 3 termos)
 * - ✅ Válido: "Ana C" (5 caracteres, inicial permitida)
 * - ✅ Válido: "Pedro De Almeida" ("De" capitalizado)
 * - ❌ Inválido: "João" (apenas 4 caracteres, mínimo é 5)
 * - ❌ Inválido: "Nome Muito Grande Demais" (mais de 20 caracteres)
 * - ❌ Inválido: "joao silva" (não começa com maiúscula)
 * - ❌ Inválido: "Joao silva" (segundo termo não começa com maiúscula)
 * - ❌ Inválido: "JOAO SILVA" (todas maiúsculas, não segue padrão)
 * - ❌ Inválido: "Joao Silva " (termina com espaço)
 * - ❌ Inválido: " Joao Silva" (começa com espaço)
 * - ❌ Inválido: "Joao  Silva" (espaços consecutivos)
 * - ❌ Inválido: "Joao123" (contém dígito)
 * - ❌ Inválido: "Joao-Silva" (contém hífen)
 * - ❌ Inválido: "João Silva" (contém acentuação)
 * 
 * **VALIDAÇÕES ESPECÍFICAS:**
 * - Comprimento entre 5 e 20 caracteres (inclusive)
 * - Apenas letras (a-z, A-Z) e espaços permitidos
 * - Primeiro caractere de cada termo: maiúscula (A-Z)
 * - Após o primeiro caractere de cada termo: minúsculas (a-z)
 * - Espaço sempre seguido por letra maiúscula (início de novo termo)
 * - Não pode começar ou terminar com espaço
 * - Não permite espaços consecutivos
 */
class Nome {
private:
    /**
     * @brief Texto do nome armazenado (5-20 caracteres)
     */
    string texto;

    /**
     * @brief Valida o nome pessoal
     * @param texto Nome a ser validado
     * @return true se o nome for válido, false caso contrário
     * 
     * Executa as seguintes validações:
     * 1. Verifica comprimento (5 a 20 caracteres)
     * 2. Valida caracteres permitidos (apenas letras e espaços)
     * 3. Verifica que primeiro caractere de cada termo é maiúscula
     * 4. Verifica que demais caracteres do termo são minúsculas
     * 5. Garante que espaço é sempre seguido por letra (início de termo)
     * 6. Verifica que não começa nem termina com espaço
     * 7. Garante que não há espaços consecutivos
     */
    bool validar(string);

public:
    /**
     * @brief Define o nome pessoal
     * @param texto Nome em formato string (5-20 caracteres)
     * @throw invalid_argument Se o nome for inválido
     * 
     * Realiza a validação completa antes de armazenar.
     * 
     * Exemplo de uso:
     * @code
     * Nome nomeGerente;
     * try {
     *     nomeGerente.setValor("Carlos Silva");
     *     cout << "Nome válido: " << nomeGerente.getValor();
     * } catch (invalid_argument& e) {
     *     cout << "Nome inválido: " << e.what();
     * }
     * @endcode
     */
    void setValor(string);

    /**
     * @brief Obtém o nome armazenado
     * @return string Nome no formato válido (5-20 caracteres)
     */
    string getValor();
};

/**
 * @brief Implementação inline do método getValor
 * @return string Nome armazenado
 */
inline string Nome::getValor(){
    return texto; 
}

#endif // NOME_HPP_INCLUDED
