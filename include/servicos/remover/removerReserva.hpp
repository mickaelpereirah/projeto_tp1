/**
 * @file removerReserva.hpp
 * @brief Serviço de remoção de reservas
 */

#ifndef REMOVER_RESERVA_HPP_INCLUDED
#define REMOVER_RESERVA_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"

using namespace std;

/**
 * @class RemoverReserva
 * @brief Remove reservas do sistema
 * 
 * **Remoção Simples:**
 * - Remove apenas a RESERVA
 * - NÃO remove Quarto (fica disponível)
 * - NÃO remove Hóspede (mantém cadastro)
 * 
 * **Regra de Negócio:**
 * - Reserva pode ser cancelada a qualquer momento
 * - Quarto volta a ficar disponível após remoção
 * - Hóspede mantém outras reservas (se houver)
 * 
 * **Uso Principal:**
 * - Cancelamento de reservas
 * - Liberação de quartos
 * - Correção de erros de cadastro
 */
class RemoverReserva
{
public:
    /**
     * @brief Remove uma reserva específica do sistema
     * @param reserva Ponteiro para a reserva a ser removida
     * @return true se removida com sucesso, false caso contrário
     * 
     * **Processo de Remoção:**
     * 1. Localiza reserva no container
     * 2. Remove do mapa de reservas por quarto
     * 3. Libera quarto (estado volta para disponível)
     * 4. Mantém hóspede cadastrado
     * 
     * **Efeitos:**
     * - Quarto: liberado para novas reservas
     * - Hóspede: continua no sistema
     * - Histórico: reserva removida permanentemente
     * 
     * **Exemplo de uso:**
     * @code
     * Reserva* r = container.pesquisar("ABC1234567");
     * cout << "Deseja cancelar esta reserva? (sim/nao): ";
     * string resposta;
     * cin >> resposta;
     * 
     * if(resposta == "sim") {
     *     if(RemoverReserva::remover_reserva(r)) {
     *         cout << "Reserva " << r->getCodigo() << " cancelada com sucesso!" << endl;
     *         cout << "Quarto " << r->getQuarto()->getNumero() << " está disponível novamente." << endl;
     *     }
     * }
     * @endcode
     * 
     * **Nota:** 
     * No MVP não há política de reembolso ou multas por cancelamento.
     * Remoção é irreversível, sem possibilidade de recuperação.
     */
    static bool remover_reserva(Reserva* reserva);
};

#endif // REMOVER_RESERVA_HPP_INCLUDED
