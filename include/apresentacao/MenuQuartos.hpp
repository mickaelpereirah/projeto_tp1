/**
 * @file MenuQuartos.hpp
 * @brief Definição da classe MenuQuartos para gerenciamento de quartos
 */

#ifndef MENU_QUARTOS_HPP_INCLUDED
#define MENU_QUARTOS_HPP_INCLUDED

#include "hotel.hpp"
#include "quarto.hpp"
#include <vector>

using namespace std;

/**
 * @class MenuQuartos
 * @brief Classe responsável pelo gerenciamento de quartos de um hotel
 * 
 * Esta classe fornece uma interface completa para operações CRUD (Create, Read,
 * Update, Delete) de quartos dentro de um hotel específico. Permite visualizar,
 * criar, editar e excluir quartos, bem como consultar seus detalhes completos
 * incluindo número, capacidade, diária e ramal.
 * 
 * Todos os métodos operam no contexto de um hotel específico, garantindo que
 * as operações sejam realizadas no hotel correto.
 */
class MenuQuartos
{
public:
    /**
     * @brief Exibe o menu de gerenciamento de quartos
     * @param hotel Ponteiro para o hotel cujos quartos serão gerenciados
     * 
     * Apresenta as seguintes opções:
     * 1. Listar quartos
     * 2. Ver detalhes de um quarto
     * 3. Criar novo quarto
     * 4. Editar quarto
     * 5. Excluir quarto
     * 6. Voltar
     * 
     * O menu permanece ativo até que o usuário escolha voltar.
     */
    static void exibir(Hotel* hotel);

private:
    /**
     * @brief Obtém a lista de quartos de um hotel
     * @param hotel Ponteiro para o hotel
     * @return Vector contendo ponteiros para todos os quartos do hotel
     * 
     * Utiliza o serviço ListarQuarto para buscar os quartos no container.
     */
    static vector<Quarto*> listarQuartos(Hotel* hotel);
    
    /**
     * @brief Exibe a lista de quartos formatada
     * @param quartos Vector com os quartos a serem exibidos
     * 
     * Apresenta cada quarto com: número de índice, número do quarto,
     * capacidade, diária e ramal.
     */
    static void exibirListaQuartos(vector<Quarto*> quartos);
    
    /**
     * @brief Menu para listar todos os quartos do hotel
     * @param hotel Ponteiro para o hotel
     * 
     * Exibe a quantidade total de quartos e a lista completa.
     * Pausa a tela após a exibição.
     */
    static void listarQuartosMenu(Hotel* hotel);
    
    /**
     * @brief Permite visualizar detalhes completos de um quarto
     * @param hotel Ponteiro para o hotel
     * 
     * Solicita ao usuário selecionar um quarto da lista e exibe
     * todos os seus detalhes.
     */
    static void verDetalhesQuarto(Hotel* hotel);
    
    /**
     * @brief Exibe os detalhes completos de um quarto específico
     * @param quarto Ponteiro para o quarto
     * 
     * Mostra: número, capacidade, valor da diária e ramal.
     */
    static void mostrarDetalhesQuarto(Quarto* quarto);
    
    /**
     * @brief Cria um novo quarto no hotel
     * @param hotel Ponteiro para o hotel
     * 
     * Solicita ao usuário os dados do novo quarto:
     * - Número (001 a 999, único)
     * - Capacidade (1, 2, 3 ou 4 pessoas)
     * - Diária (0.01 a 1.000.000,00)
     * - Ramal (00 a 50)
     * 
     * Valida os dados e inclui no container se válidos.
     */
    static void criarQuarto(Hotel* hotel);
    
    /**
     * @brief Edita um quarto existente
     * @param hotel Ponteiro para o hotel
     * 
     * Permite alterar: capacidade, diária e ramal.
     * O número do quarto NÃO pode ser alterado (chave primária).
     */
    static void editarQuarto(Hotel* hotel);
    
    /**
     * @brief Exclui um quarto do hotel
     * @param hotel Ponteiro para o hotel
     * 
     * Solicita confirmação antes de excluir.
     * ATENÇÃO: Não verifica se há reservas associadas ao quarto.
     * TODO: Implementar verificação de integridade referencial.
     */
    static void excluirQuarto(Hotel* hotel);
    
    /**
     * @brief Permite ao usuário selecionar um quarto da lista
     * @param quartos Vector com os quartos disponíveis
     * @return Ponteiro para o quarto selecionado ou nullptr se cancelado
     * 
     * Exibe a lista numerada e solicita ao usuário digitar o número
     * correspondente. Permite cancelar digitando 0.
     */
    static Quarto* selecionarQuarto(vector<Quarto*> quartos);
};

#endif
