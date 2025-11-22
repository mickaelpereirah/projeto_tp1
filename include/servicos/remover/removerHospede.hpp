/**
 * @file removerHospede.hpp
 * @brief Serviço de remoção de hóspedes
 */

#ifndef REMOVER_HOSPEDE_HPP_INCLUDED
#define REMOVER_HOSPEDE_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"
#include "listar/listarReserva.hpp"

using namespace std;

/**
 * @class RemoverHospede
 * @brief Remove hóspedes do sistema com validação de reservas
 * 
 * **Remoção em Cascata:**
 * - Remove HÓSPEDE
 * - Remove todas as RESERVAS do hóspede
 * 
 * **Regra de Negócio:**
 * - Hóspede com reservas ativas pode ser removido
 * - Reservas são canceladas automaticamente
 * - Quartos ficam disponíveis após remoção
 * 
 * **Impacto:**
 * - Remove histórico de reservas do hóspede
 * - Libera quartos ocupados por suas reservas
 * - Ação irreversível (sem recuperação no MVP)
 */
class RemoverHospede
{
public:
    /**
     * @brief Remove hóspede e todas as suas reservas
     * @param hospede Ponteiro para o hóspede a ser removido
     * @return true se removido com sucesso, false caso contrário
     * 
     * **Processo de Remoção:**
     * 1. Lista todas as reservas do hóspede
     * 2. Remove cada reserva do container
     * 3. Remove hóspede do container
     * 
     * **Efeito Cascata:**
     * @code
     * Hóspede (1)
     *   └─ Reservas (N) [removidas]
     *        └─ Quartos (liberados)
     * @endcode
     * 
     * **Exemplo de uso:**
     * @code
     * Hospede* h = container.pesquisar("maria@email.com");
     * vector<Reserva*> reservas = ListarReserva::listar_reservas_por_hospede(h);
     * cout << "Este hóspede tem " << reservas.size() << " reserva(s)." << endl;
     * cout << "Deseja remover mesmo assim? (sim/nao): ";
     * string resposta;
     * cin >> resposta;
     * if(resposta == "sim") {
     *     if(RemoverHospede::remover_hospede(h)) {
     *         cout << "Hóspede e reservas removidos!" << endl;
     *     }
     * }
     * @endcode
     */
    static bool remover_hospede(Hospede* hospede);
};

#endif // REMOVER_HOSPEDE_HPP_INCLUDED
