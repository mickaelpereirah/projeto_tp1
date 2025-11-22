/**
 * @file MenuReservas.hpp
 * @brief Definição da classe MenuReservas para gerenciamento de reservas
 */

#ifndef MENU_RESERVAS_HPP_INCLUDED
#define MENU_RESERVAS_HPP_INCLUDED

#include "hotel.hpp"
#include "reserva.hpp"
#include "quarto.hpp"
#include "hospede.hpp"
#include <vector>

using namespace std;

/**
 * @class MenuReservas
 * @brief Classe responsável pelo gerenciamento de reservas de um hotel
 * 
 * Esta classe fornece interface completa para operações CRUD de reservas,
 * incluindo validações de disponibilidade, cálculo automático de valores
 * e associação com quartos e hóspedes. Gerencia todo o ciclo de vida de
 * uma reserva desde a criação até a exclusão.
 * 
 * Características principais:
 * - Validação de conflito de datas entre reservas
 * - Cálculo automático do valor total baseado no período
 * - Recálculo automático quando datas são alteradas
 * - Verificação de existência de quartos e hóspedes
 * - Exibição de informações contextualizadas (quarto, hóspede)
 */
class MenuReservas
{
public:
    /**
     * @brief Exibe o menu de gerenciamento de reservas
     * @param hotel Ponteiro para o hotel cujas reservas serão gerenciadas
     * 
     * Apresenta as seguintes opções:
     * 1. Listar reservas
     * 2. Ver detalhes de uma reserva
     * 3. Criar nova reserva
     * 4. Editar reserva
     * 5. Excluir reserva
     * 6. Voltar
     * 
     * Mostra também o total de reservas cadastradas no hotel.
     */
    static void exibir(Hotel* hotel);

private:
    /**
     * @brief Obtém todas as reservas do hotel
     * @param hotel Ponteiro para o hotel
     * @return Vector contendo ponteiros para todas as reservas
     * 
     * Busca reservas em todos os quartos do hotel através dos containers.
     */
    static vector<Reserva*> listarReservas(Hotel* hotel);
    
    /**
     * @brief Exibe a lista de reservas formatada com contexto
     * @param reservas Vector com as reservas
     * @param hotel Ponteiro para o hotel (para buscar dados contextuais)
     * 
     * Para cada reserva mostra: código, datas de chegada/partida, valor,
     * número do quarto e email do hóspede.
     */
    static void exibirListaReservas(vector<Reserva*> reservas, Hotel* hotel);
    
    /**
     * @brief Menu para listar todas as reservas
     * @param hotel Ponteiro para o hotel
     * 
     * Exibe quantidade total e lista completa de reservas.
     */
    static void listarReservasMenu(Hotel* hotel);
    
    /**
     * @brief Permite visualizar detalhes completos de uma reserva
     * @param hotel Ponteiro para o hotel
     * 
     * Solicita seleção de uma reserva e exibe todos os detalhes
     * incluindo informações do quarto e do hóspede.
     */
    static void verDetalhesReserva(Hotel* hotel);
    
    /**
     * @brief Exibe detalhes completos de uma reserva específica
     * @param reserva Ponteiro para a reserva
     * @param hotel Ponteiro para o hotel
     * 
     * Mostra: código, datas, valor, dados do quarto (número, capacidade,
     * diária, ramal) e dados do hóspede (nome, email, endereço).
     */
    static void mostrarDetalhesReserva(Reserva* reserva, Hotel* hotel);
    
    /**
     * @brief Cria uma nova reserva
     * @param hotel Ponteiro para o hotel
     * 
     * Processo de criação:
     * 1. Verifica se há quartos e hóspedes cadastrados
     * 2. Exibe quartos disponíveis e hóspedes cadastrados
     * 3. Solicita: número do quarto, email do hóspede, datas
     * 4. Valida disponibilidade do quarto no período
     * 5. Calcula valor total automaticamente
     * 6. Gera código único (10 caracteres alfanuméricos)
     * 7. Cria e armazena a reserva
     * 
     * IMPORTANTE: Não permite conflito de datas no mesmo quarto.
     */
    static void criarReserva(Hotel* hotel);
    
    /**
     * @brief Edita uma reserva existente
     * @param hotel Ponteiro para o hotel
     * 
     * Permite alterar APENAS as datas de chegada e partida.
     * O código, quarto e hóspede NÃO podem ser alterados.
     * 
     * Ao alterar datas:
     * - Valida disponibilidade no novo período
     * - Recalcula automaticamente o valor total
     * - Exibe o novo valor calculado
     */
    static void editarReserva(Hotel* hotel);
    
    /**
     * @brief Exclui uma reserva
     * @param hotel Ponteiro para o hotel
     * 
     * Solicita confirmação antes de excluir.
     * ATENÇÃO: Operação irreversível!
     */
    static void excluirReserva(Hotel* hotel);
    
    /**
     * @brief Permite ao usuário selecionar uma reserva
     * @param reservas Vector com as reservas disponíveis
     * @return Ponteiro para a reserva selecionada ou nullptr se cancelado
     */
    static Reserva* selecionarReserva(vector<Reserva*> reservas);
    
    /**
     * @brief Obtém o número do quarto de uma reserva
     * @param reserva Ponteiro para a reserva
     * @param hotel Ponteiro para o hotel
     * @return Número do quarto ou -1 se não encontrado
     * 
     * Busca em todos os quartos do hotel qual contém esta reserva.
     */
    static int obterNumeroQuartoReserva(Reserva* reserva, Hotel* hotel);
    
    /**
     * @brief Obtém o email do hóspede de uma reserva
     * @param reserva Ponteiro para a reserva
     * @param hotel Ponteiro para o hotel
     * @return Email do hóspede ou string vazia se não encontrado
     * 
     * Busca em todos os hóspedes do hotel qual possui esta reserva.
     */
    static string obterEmailHospedeReserva(Reserva* reserva, Hotel* hotel);
};

#endif
