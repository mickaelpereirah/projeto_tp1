/**
 * @file email.hpp
 * @brief Definição da classe Email para endereços de email válidos
 */

#ifndef EMAIL_HPP_INCLUDED
#define EMAIL_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Email
 * @brief Representa um endereço de email válido
 * 
 * A classe Email armazena e valida endereços de email seguindo regras
 * específicas para parte local e domínio.
 * 
 * **FORMATO VÁLIDO:**
 * - parte-local@domínio
 * 
 * **REGRAS DA PARTE LOCAL (antes do @):**
 * - Pode conter: letra (a-z), dígito (0-9), ponto (.) ou hífen (-)
 * - NÃO pode iniciar ou terminar com ponto ou hífen
 * - Ponto ou hífen deve ser seguido por letra(s) ou dígito(s)
 * - Comprimento máximo: 64 caracteres
 * 
 * **REGRAS DO DOMÍNIO (após o @):**
 * - Composto por uma ou mais partes separadas por ponto (.)
 * - Cada parte pode conter: letra (a-z), dígito (0-9) ou hífen (-)
 * - NÃO pode iniciar ou terminar com hífen
 * - Comprimento máximo: 255 caracteres
 * 
 * **EXEMPLOS:**
 * - ✅ Válido: "usuario@exemplo.com"
 * - ✅ Válido: "nome.sobrenome@empresa.com.br"
 * - ✅ Válido: "user-name@dominio.org"
 * - ✅ Válido: "contato123@site.com"
 * - ✅ Válido: "a@b.co" (mínimo)
 * - ❌ Inválido: ".usuario@exemplo.com" (começa com ponto)
 * - ❌ Inválido: "usuario.@exemplo.com" (termina com ponto)
 * - ❌ Inválido: "usuario@" (falta domínio)
 * - ❌ Inválido: "@exemplo.com" (falta parte local)
 * - ❌ Inválido: "usuario..nome@exemplo.com" (pontos consecutivos)
 * - ❌ Inválido: "usuario@-exemplo.com" (domínio começa com hífen)
 * - ❌ Inválido: "usuario@exemplo-.com" (domínio termina com hífen)
 * - ❌ Inválido: "usuario nome@exemplo.com" (espaço não permitido)
 * 
 * **DETALHES TÉCNICOS:**
 * - Total máximo: 64 (local) + 1 (@) + 255 (domínio) = 320 caracteres
 * - Apenas caracteres ASCII básicos (sem acentuação)
 * - Case-insensitive (user@EXEMPLO.com = user@exemplo.com)
 */
class Email
{
private:
    /**
     * @brief Endereço de email armazenado (formato: local@dominio)
     */
    string email;

    /**
     * @brief Valida o endereço de email
     * @param email Endereço de email a ser validado
     * @return true se o email for válido, false caso contrário
     * 
     * Executa as seguintes validações:
     * 1. Verifica presença de exatamente um '@'
     * 2. Valida parte local:
     *    - Comprimento máximo 64 caracteres
     *    - Caracteres permitidos: a-z, 0-9, ponto, hífen
     *    - Não começa/termina com ponto ou hífen
     *    - Ponto/hífen seguido por letra ou dígito
     * 3. Valida domínio:
     *    - Comprimento máximo 255 caracteres
     *    - Partes separadas por ponto
     *    - Cada parte: a-z, 0-9, hífen
     *    - Não começa/termina com hífen
     */
    bool validar(string email);

public:
    /**
     * @brief Define o endereço de email
     * @param email Endereço de email em formato string
     * @throw invalid_argument Se o email for inválido
     * 
     * Realiza a validação completa antes de armazenar.
     * 
     * Exemplo de uso:
     * @code
     * Email emailGerente;
     * try {
     *     emailGerente.setValor("gerente@hotel.com");
     *     cout << "Email válido: " << emailGerente.getValor();
     * } catch (invalid_argument& e) {
     *     cout << "Email inválido: " << e.what();
     * }
     * @endcode
     */
    void setValor(string email);

    /**
     * @brief Obtém o endereço de email armazenado
     * @return string Endereço de email no formato local@dominio
     */
    string getValor();
};

/**
 * @brief Implementação inline do método getValor
 * @return string Endereço de email armazenado
 */
inline string Email::getValor()
{
    return email;
}

#endif // EMAIL_HPP_INCLUDED
