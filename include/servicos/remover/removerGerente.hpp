/**
 * @file removerGerente.hpp
 * @brief Serviço de remoção de gerentes
 */

#ifndef REMOVER_GERENTE_HPP_INCLUDED
#define REMOVER_GERENTE_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"
#include "listar/listarHotel.hpp"
#include "remover/removerHotel.hpp"

using namespace std;

/**
 * @class RemoverGerente
 * @brief Remove gerentes do sistema com remoção em cascata
 * 
 * **IMPORTANTE - Remoção em Cascata:**
 * - Remove GERENTE
 * - Remove todos os HOTÉIS do gerente
 * - Remove todos os QUARTOS dos hotéis
 * - Remove todas as RESERVAS dos quartos
 * 
 * **Impacto:**
 * - Remoção permanente (não há recuperação no MVP)
 * - Afeta toda hierarquia de dados
 * - Hóspedes NÃO são removidos (apenas suas reservas)
 * 
 * **Segurança:**
 * - Ação irreversível
 * - Requer confirmação na camada de apresentação
 * - Gerente só pode remover a si próprio (após login)
 */
class RemoverGerente
{
public:
    /**
     * @brief Remove gerente e todos os dados associados em cascata
     * @param gerente Ponteiro para o gerente a ser removido
     * @return true se removido com sucesso, false caso contrário
     * 
     * **Processo de Remoção:**
     * 1. Lista todos os hotéis do gerente
     * 2. Para cada hotel, chama RemoverHotel::remover_hotel()
     *    - Remove quartos do hotel
     *    - Remove reservas dos quartos
     * 3. Remove gerente do container
     * 
     * **Efeito Cascata:**
     * @code
     * Gerente (1) 
     *   └─ Hotéis (N) 
     *        └─ Quartos (N) 
     *             └─ Reservas (N) [removidas]
     * @endcode
     * 
     * **Exemplo de uso:**
     * @code
     * Gerente* g = AutenticarGerente::login("joao@hotel.com", "senha");
     * cout << "Deseja realmente excluir sua conta? (sim/nao): ";
     * string resposta;
     * cin >> resposta;
     * if(resposta == "sim") {
     *     if(RemoverGerente::remover_gerente(g)) {
     *         cout << "Conta removida com sucesso!" << endl;
     *         // Logout automático
     *     }
     * }
     * @endcode
     */
    static bool remover_gerente(Gerente* gerente);
};

#endif // REMOVER_GERENTE_HPP_INCLUDED
