/**
 * @file listarReserva.hpp
 * @brief Serviço de listagem de reservas
 */

#ifndef LISTAR_RESERVA_HPP_INCLUDED
#define LISTAR_RESERVA_HPP_INCLUDED

#include <vector>
#include "DOMINIOS.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"

using namespace std;

/**
 * @class ListarReserva
 * @brief Lista reservas com diferentes filtros de consulta
 * 
 * **Duas Formas de Listagem:**
 * 
 * **Por Quarto:**
 * - Lista todas as reservas de um quarto específico
 * - Útil para verificar agenda/ocupação do quarto
 * - Gerente visualiza histórico completo
 * 
 * **Por Hóspede:**
 * - Lista todas as reservas de um hóspede específico
 * - Útil para histórico do cliente
 * - Visualiza reservas em qualquer hotel
 */
class ListarReserva
{
public:
    /**
     * @brief Lista todas as reservas de um quarto específico
     * @param quarto Ponteiro para o quarto
     * @return vector<Reserva*> Vetor com reservas do quarto
     * 
     * **Comportamento:**
     * 1. Busca no container de reservas
     * 2. Filtra reservas onde reserva.quarto == quarto.numero
     * 3. Retorna lista ordenada (pode incluir passadas e futuras)
     * 4. Lista vazia se quarto nunca teve reservas
     * 
     * **Inclui:**
     * - Reservas passadas (já finalizadas)
     * - Reservas ativas (em andamento)
     * - Reservas futuras (agendadas)
     * 
     * **Exemplo de uso:**
     * @code
     * vector<Reserva*> reservas = ListarReserva::listar_reservas_por_quarto(quarto101);
     * cout << "Quarto 101 tem " << reservas.size() << " reserva(s)" << endl;
     * for(auto r : reservas) {
     *     cout << "Reserva " << r->getCodigo() << ": " 
     *          << r->getDataInicial() << " até " << r->getDataFinal() << endl;
     * }
     * @endcode
     */
    static vector<Reserva*> listar_reservas_por_quarto(Quarto* quarto);
    
    /**
     * @brief Lista todas as reservas de um hóspede específico
     * @param hospede Ponteiro para o hóspede
     * @return vector<Reserva*> Vetor com reservas do hóspede
     * 
     * **Comportamento:**
     * 1. Busca no container de reservas
     * 2. Filtra reservas onde reserva.hospede == hospede.email
     * 3. Retorna lista de todas as reservas do hóspede
     * 4. Lista vazia se hóspede nunca fez reservas
     * 
     * **Inclui:**
     * - Reservas em diferentes hotéis
     * - Reservas passadas, ativas e futuras
     * - Histórico completo do cliente
     * 
     * **Exemplo de uso:**
     * @code
     * vector<Reserva*> historico = ListarReserva::listar_reservas_por_hospede(maria);
     * cout << "Maria tem " << historico.size() << " reserva(s) no histórico" << endl;
     * for(auto r : historico) {
     *     cout << "Hotel: " << r->getQuarto()->getHotel()->getNome() << endl;
     * }
     * @endcode
     */
    static vector<Reserva*> listar_reservas_por_hospede(Hospede* hospede);
};

#endif // LISTAR_RESERVA_HPP_INCLUDED
