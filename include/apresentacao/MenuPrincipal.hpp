#ifndef MENU_PRINCIPAL_HPP_INCLUDED
#define MENU_PRINCIPAL_HPP_INCLUDED

#include "gerente.hpp"

/**
 * @class MenuPrincipal
 * @brief Classe responsável pelo menu inicial do sistema
 * 
 * Gerencia a tela inicial com opções de criar conta, fazer login e sair.
 * Após login bem-sucedido, direciona para o menu do gerente.
 */
class MenuPrincipal
{
public:
    /**
     * @brief Exibe o menu principal e processa as opções do usuário
     * 
     * Menu principal com as opções:
     * 1. Criar conta (cadastrar novo gerente)
     * 2. Login (autenticar gerente existente)
     * 3. Sair (encerrar o sistema)
     */
    static void exibir();

private:
    /**
     * @brief Processa a criação de uma nova conta de gerente
     */
    static void criarConta();

    /**
     * @brief Processa o login de um gerente
     * @return Ponteiro para o Gerente autenticado, ou nullptr se falhar
     */
    static Gerente* fazerLogin();
};

#endif
