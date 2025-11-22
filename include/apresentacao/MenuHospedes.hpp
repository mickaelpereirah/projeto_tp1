/**
 * @file MenuHospedes.hpp
 * @brief Definição da classe MenuHospedes para gerenciamento de hóspedes
 */

#ifndef MENU_HOSPEDES_HPP_INCLUDED
#define MENU_HOSPEDES_HPP_INCLUDED

#include "hotel.hpp"
#include "hospede.hpp"
#include "reserva.hpp"
#include <vector>

using namespace std;

/**
 * @class MenuHospedes
 * @brief Classe responsável pelo gerenciamento de hóspedes de um hotel
 * 
 * Esta classe fornece interface para operações CRUD de hóspedes dentro do
 * contexto de um hotel. Gerencia cadastro, visualização, edição e exclusão
 * de hóspedes, incluindo validação de dados como email, nome, endereço e
 * número de cartão de crédito.
 * 
 * Características:
 * - Email como identificador único (não pode ser alterado)
 * - Validação de formato de cartão (16 dígitos com algoritmo de Luhn)
 * - Validação de nome (5-20 caracteres, primeira letra maiúscula)
 * - Validação de endereço (5-30 caracteres)
 * - Listagem de todos os hóspedes ou apenas do hotel específico
 */
class MenuHospedes
{
public:
    /**
     * @brief Exibe o menu de gerenciamento de hóspedes
     * @param hotel Ponteiro para o hotel cujos hóspedes serão gerenciados
     * 
     * Apresenta as seguintes opções:
     * 1. Listar todos os hóspedes do sistema
     * 2. Listar hóspedes deste hotel (com reservas)
     * 3. Ver detalhes de um hóspede
     * 4. Criar novo hóspede
     * 5. Editar hóspede
     * 6. Excluir hóspede
     * 7. Voltar
     * 
     * O menu mostra o total de hóspedes cadastrados no sistema.
     */
    static void exibir(Hotel* hotel);

private:
    /**
     * @brief Obtém a lista de hóspedes do hotel
     * @param hotel Ponteiro para o hotel
     * @return Vector contendo ponteiros para os hóspedes do hotel
     * 
     * Utiliza o serviço ListarHospede para buscar hóspedes no container.
     */
    static vector<Hospede*> listarHospedes(Hotel* hotel);
    
    /**
     * @brief Exibe a lista de hóspedes formatada
     * @param hospedes Vector com os hóspedes a serem exibidos
     * 
     * Para cada hóspede mostra: número de índice, nome, email e endereço.
     */
    static void exibirListaHospedes(vector<Hospede*> hospedes);
    
    /**
     * @brief Lista TODOS os hóspedes cadastrados no sistema
     * 
     * Mostra hóspedes de todos os hotéis, independente de terem reservas.
     * Útil para verificar todos os cadastros no sistema.
     */
    static void listarTodosHospedesMenu();
    
    /**
     * @brief Lista apenas hóspedes DESTE HOTEL (com reservas)
     * @param hotel Ponteiro para o hotel
     * 
     * Mostra apenas hóspedes que possuem reservas neste hotel específico.
     */
    static void listarHospedesDoHotelMenu(Hotel* hotel);
    
    /**
     * @brief Permite visualizar detalhes completos de um hóspede
     * @param hotel Ponteiro para o hotel
     * 
     * Solicita ao usuário selecionar um hóspede e exibe todos os detalhes.
     */
    static void verDetalhesHospede(Hotel* hotel);
    
    /**
     * @brief Exibe os detalhes completos de um hóspede específico
     * @param hospede Ponteiro para o hóspede
     * 
     * Mostra: nome, email, endereço e número do cartão de crédito.
     */
    static void mostrarDetalhesHospede(Hospede* hospede);
    
    /**
     * @brief Cria um novo hóspede
     * @param hotel Ponteiro para o hotel
     * 
     * Solicita ao usuário os dados do novo hóspede:
     * - Nome (5-20 caracteres, primeira letra maiúscula)
     * - Email (formato válido, único no sistema)
     * - Endereço (5-30 caracteres)
     * - Cartão (16 dígitos com validação de Luhn)
     * 
     * IMPORTANTE: Todos os campos são obrigatórios e validados.
     */
    static void criarHospede(Hotel* hotel);
    
    /**
     * @brief Edita um hóspede existente
     * @param hotel Ponteiro para o hotel
     * 
     * Permite alterar: nome, endereço e cartão.
     * O email NÃO pode ser alterado (chave primária).
     */
    static void editarHospede(Hotel* hotel);
    
    /**
     * @brief Exclui um hóspede do sistema
     * @param hotel Ponteiro para o hotel
     * 
     * Solicita confirmação antes de excluir.
     * ATENÇÃO: Deve verificar se o hóspede possui reservas ativas
     * antes de permitir a exclusão (integridade referencial).
     */
    static void excluirHospede(Hotel* hotel);
    
    /**
     * @brief Permite ao usuário selecionar um hóspede da lista
     * @param hospedes Vector com os hóspedes disponíveis
     * @return Ponteiro para o hóspede selecionado ou nullptr se cancelado
     * 
     * Exibe lista numerada e solicita ao usuário digitar o número
     * correspondente. Permite cancelar digitando 0.
     */
    static Hospede* selecionarHospede(vector<Hospede*> hospedes);
};

#endif
