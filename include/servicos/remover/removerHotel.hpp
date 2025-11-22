/**
 * @file removerHotel.hpp
 * @brief Serviço de remoção de hotéis
 */

#ifndef REMOVER_HOTEL_HPP_INCLUDED
#define REMOVER_HOTEL_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"
#include "listar/listarQuarto.hpp"
#include "listar/listarReserva.hpp"

using namespace std;

/**
 * @class RemoverHotel
 * @brief Remove hotéis do sistema com remoção em cascata
 * 
 * **Remoção em Cascata:**
 * - Remove HOTEL
 * - Remove todos os QUARTOS do hotel
 * - Remove todas as RESERVAS dos quartos
 * 
 * **Regra de Negócio:**
 * - Hotel com quartos e reservas pode ser removido
 * - Todas as reservas são canceladas
 * - Hóspedes NÃO são removidos (apenas suas reservas deste hotel)
 * 
 * **Impacto:**
 * - Remove estrutura completa do hotel
 * - Cancela todas as reservas ativas
 * - Ação irreversível (sem recuperação no MVP)
 */
class RemoverHotel
{
public:
    /**
     * @brief Remove hotel e todos os dados associados em cascata
     * @param hotel Ponteiro para o hotel a ser removido
     * @return true se removido com sucesso, false caso contrário
     * 
     * **Processo de Remoção:**
     * 1. Lista todos os quartos do hotel
     * 2. Para cada quarto:
     *    - Lista reservas do quarto
     *    - Remove cada reserva
     *    - Remove quarto
     * 3. Remove hotel do container
     * 
     * **Efeito Cascata:**
     * @code
     * Hotel (1)
     *   └─ Quartos (N) [removidos]
     *        └─ Reservas (N) [removidas]
     * @endcode
     * 
     * **Exemplo de uso:**
     * @code
     * Hotel* h = container.pesquisar("H0001");
     * vector<Quarto*> quartos = ListarQuarto::listar_quartos(h);
     * cout << "Este hotel tem " << quartos.size() << " quarto(s)." << endl;
     * 
     * // Conta total de reservas
     * int total_reservas = 0;
     * for(auto q : quartos) {
     *     total_reservas += ListarReserva::listar_reservas_por_quarto(q).size();
     * }
     * cout << "Total de reservas: " << total_reservas << endl;
     * 
     * cout << "Deseja remover este hotel? (sim/nao): ";
     * string resposta;
     * cin >> resposta;
     * if(resposta == "sim") {
     *     if(RemoverHotel::remover_hotel(h)) {
     *         cout << "Hotel, quartos e reservas removidos!" << endl;
     *     }
     * }
     * @endcode
     */
    static bool remover_hotel(Hotel* hotel);
};

#endif // REMOVER_HOTEL_HPP_INCLUDED
