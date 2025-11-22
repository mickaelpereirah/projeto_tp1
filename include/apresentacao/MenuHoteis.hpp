#ifndef MENU_HOTEIS_HPP_INCLUDED
#define MENU_HOTEIS_HPP_INCLUDED

#include "gerente.hpp"
#include "hotel.hpp"
#include <vector>

/**
 * @class MenuHoteis
 * @brief Classe responsável pelo gerenciamento de hotéis do gerente
 * 
 * Permite criar, listar, visualizar detalhes, editar e excluir hotéis.
 * Em breve: selecionar hotel para gerenciar quartos, reservas e hóspedes.
 */
class MenuHoteis
{
public:
    /**
     * @brief Exibe o menu de gerenciamento de hotéis
     * @param gerente Ponteiro para o gerente autenticado
     * 
     * Opções disponíveis:
     * 1. Listar meus hotéis
     * 2. Ver detalhes de um hotel
     * 3. Criar novo hotel
     * 4. Editar hotel
     * 5. Excluir hotel
     * 6. Voltar
     */
    static void exibir(Gerente* gerente);

private:
    /**
     * @brief Lista todos os hotéis do gerente
     * @param gerente Ponteiro para o gerente
     * @return Vector com ponteiros para os hotéis
     */
    static vector<Hotel*> listarHoteis(Gerente* gerente);

    /**
     * @brief Exibe a lista de hotéis formatada
     * @param hoteis Vector com os hotéis
     */
    static void exibirListaHoteis(vector<Hotel*> hoteis);

    /**
     * @brief Lista todos os hotéis (opção do menu)
     * @param gerente Ponteiro para o gerente
     */
    static void listarHoteisMenu(Gerente* gerente);

    /**
     * @brief Exibe detalhes completos de um hotel
     * @param gerente Ponteiro para o gerente
     */
    static void verDetalhesHotel(Gerente* gerente);

    /**
     * @brief Exibe os detalhes de um hotel específico
     * @param hotel Ponteiro para o hotel
     */
    static void mostrarDetalhesHotel(Hotel* hotel);

    /**
     * @brief Cria um novo hotel
     * @param gerente Ponteiro para o gerente
     */
    static void criarHotel(Gerente* gerente);

    /**
     * @brief Edita um hotel existente
     * @param gerente Ponteiro para o gerente
     */
    static void editarHotel(Gerente* gerente);

    /**
     * @brief Exclui um hotel
     * @param gerente Ponteiro para o gerente
     */
    static void excluirHotel(Gerente* gerente);

    /**
     * @brief Seleciona um hotel da lista
     * @param hoteis Vector com os hotéis disponíveis
     * @return Ponteiro para o hotel selecionado ou nullptr se cancelado
     */
    static Hotel* selecionarHotel(vector<Hotel*> hoteis);
};

#endif
