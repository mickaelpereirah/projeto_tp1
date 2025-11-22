#ifndef AUTENTICAR_GERENTE_HPP_INCLUDED
#define AUTENTICAR_GERENTE_HPP_INCLUDED

#include <string>
#include "gerente.hpp"
#include "centralContainers.hpp"

using namespace std;

/**
 * @class AutenticarGerente
 * @brief Classe responsável pela autenticação de gerentes no sistema
 * 
 * Fornece métodos para verificar credenciais de login (email e senha)
 * e retornar o gerente autenticado.
 */
class AutenticarGerente
{
public:
    /**
     * @brief Autentica um gerente no sistema
     * @param email Email do gerente
     * @param senha Senha do gerente
     * @return Ponteiro para o Gerente autenticado, ou nullptr se as credenciais forem inválidas
     */
    static Gerente* login(string email, string senha);
};

#endif
