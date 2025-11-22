#ifndef MENU_CONTA_HPP_INCLUDED
#define MENU_CONTA_HPP_INCLUDED

#include "gerente.hpp"

/**
 * @class MenuConta
 * @brief Classe responsável pelo gerenciamento da conta do gerente
 * 
 * Permite o gerente visualizar, editar e excluir sua própria conta.
 */
class MenuConta
{
public:
    /**
     * @brief Exibe o menu de gerenciamento de conta
     * @param gerente Ponteiro para o gerente autenticado
     * @return true se a conta foi excluída (logout forçado), false caso contrário
     * 
     * Opções disponíveis:
     * 1. Visualizar meus dados
     * 2. Editar meus dados
     * 3. Excluir minha conta
     * 4. Voltar
     */
    static bool exibir(Gerente* gerente);

private:
    /**
     * @brief Exibe os dados completos do gerente
     * @param gerente Ponteiro para o gerente
     */
    static void visualizarDados(Gerente* gerente);

    /**
     * @brief Permite editar os dados do gerente
     * @param gerente Ponteiro para o gerente
     */
    static void editarDados(Gerente* gerente);

    /**
     * @brief Exclui a conta do gerente (com confirmação)
     * @param gerente Ponteiro para o gerente
     * @return true se a conta foi excluída, false caso contrário
     */
    static bool excluirConta(Gerente* gerente);
};

#endif
