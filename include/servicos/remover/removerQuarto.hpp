/**
 * @file removerQuarto.hpp
 * @brief Serviço de remoção de quartos
 */

#ifndef REMOVER_QUARTO_HPP_INCLUDED
#define REMOVER_QUARTO_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"
#include "listar/listarReserva.hpp"

using namespace std;

/**
 * @class RemoverQuarto
 * @brief Remove quartos do sistema com remoção em cascata
 * 
 * **Remoção em Cascata:**
 * - Remove QUARTO
 * - Remove todas as RESERVAS do quarto
 * 
 * **Regra de Negócio:**
 * - Quarto com reservas ativas pode ser removido
 * - Todas as reservas são canceladas automaticamente
 * - Hotel permanece no sistema (apenas perde o quarto)
 * 
 * **Impacto:**
 * - Remove capacidade de hospedagem do hotel
 * - Cancela reservas futuras e ativas do quarto
 * - Ação irreversível (sem recuperação no MVP)
 */
class RemoverQuarto
{
public:
    /**
     * @brief Remove quarto e todas as suas reservas
     * @param quarto Ponteiro para o quarto a ser removido
     * @return true se removido com sucesso, false caso contrário
     * 
     * **Processo de Remoção:**
     * 1. Lista todas as reservas do quarto
     * 2. Remove cada reserva do container
     * 3. Remove quarto do container
     * 
     * **Efeito Cascata:**
     * @code
     * Quarto (1)
     *   └─ Reservas (N) [removidas]
     * @endcode
     * 
     * **Exemplo de uso:**
     * @code
     * Quarto* q = container.pesquisar(101);
     * vector<Reserva*> reservas = ListarReserva::listar_reservas_por_quarto(q);
     * 
     * cout << "Quarto 101 tem " << reservas.size() << " reserva(s)." << endl;
     * cout << "Deseja remover este quarto? (sim/nao): ";
     * string resposta;
     * cin >> resposta;
     * 
     * if(resposta == "sim") {
     *     if(RemoverQuarto::remover_quarto(q)) {
     *         cout << "Quarto e suas reservas foram removidos!" << endl;
     *         cout << "O hotel permanece cadastrado." << endl;
     *     }
     * }
     * @endcode
     */
    static bool remover_quarto(Quarto* quarto);
};

#endif // REMOVER_QUARTO_HPP_INCLUDED
