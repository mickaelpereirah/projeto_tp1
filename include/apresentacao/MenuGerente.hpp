/**
 * @file MenuGerente.hpp
 * @brief Definição da classe MenuGerente para o menu principal do gerente autenticado
 */

#ifndef MENU_GERENTE_HPP_INCLUDED
#define MENU_GERENTE_HPP_INCLUDED

#include "gerente.hpp"

/**
 * @class MenuGerente
 * @brief Classe responsável pelo menu principal do gerente após autenticação
 * 
 * Esta classe gerencia a interface principal disponível após o login bem-sucedido
 * do gerente. Oferece acesso aos principais módulos do sistema:
 * - Gerenciamento de conta (visualizar, editar e excluir)
 * - Gerenciamento de hotéis (criar, listar, editar, excluir)
 * - Gerenciamento de quartos
 * - Gerenciamento de reservas
 * - Gerenciamento de hóspedes
 * 
 * O menu é contextualizado com as informações do gerente autenticado.
 */
class MenuGerente
{
public:
    /**
     * @brief Exibe o menu principal do gerente
     * @param gerente Ponteiro para o gerente autenticado
     * 
     * Apresenta as seguintes opções:
     * 1. Gerenciar conta
     * 2. Gerenciar hotéis
     * 3. Gerenciar quartos
     * 4. Gerenciar reservas
     * 5. Gerenciar hóspedes
     * 6. Sair (logout)
     * 
     * O menu permanece em loop até que o usuário escolha sair.
     */
    static void exibir(Gerente* gerente);

private:
    /**
     * @brief Exibe o cabeçalho do menu com informações do gerente
     * @param gerente Ponteiro para o gerente autenticado
     * 
     * Mostra o nome do gerente e título "MENU PRINCIPAL DO GERENTE"
     */
    static void exibirCabecalho(Gerente* gerente);
    
    /**
     * @brief Direciona para o submenu de gerenciamento de quartos
     * @param gerente Ponteiro para o gerente autenticado
     * 
     * Permite criar, listar, editar e excluir quartos dos hotéis.
     */
    static void gerenciarQuartos(Gerente* gerente);
    
    /**
     * @brief Direciona para o submenu de gerenciamento de reservas
     * @param gerente Ponteiro para o gerente autenticado
     * 
     * Permite criar, visualizar, editar e excluir reservas.
     */
    static void gerenciarReservas(Gerente* gerente);
    
    /**
     * @brief Direciona para o submenu de gerenciamento de hóspedes
     * @param gerente Ponteiro para o gerente autenticado
     * 
     * Permite criar, listar, editar e excluir hóspedes.
     */
    static void gerenciarHospedes(Gerente* gerente);
};

#endif
