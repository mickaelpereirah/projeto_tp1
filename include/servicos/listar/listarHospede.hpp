/**
 * @file listarHospede.hpp
 * @brief Serviço de listagem de hóspedes
 */

#ifndef LISTAR_HOSPEDE_HPP_INCLUDED
#define LISTAR_HOSPEDE_HPP_INCLUDED

#include <vector>
#include <set>
#include "DOMINIOS.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"
#include "listar/listarQuarto.hpp"

using namespace std;

/**
 * @class ListarHospede
 * @brief Lista hóspedes cadastrados no sistema
 * 
 * **Duas Abordagens de Listagem:**
 * 
 * **Solução 1 - Global (listar_todos_hospedes):**
 * - Lista TODOS os hóspedes do sistema
 * - Independente de hotel ou reserva
 * - Útil para visão administrativa geral
 * 
 * **Solução 2 - Por Hotel (listar_hospedes_por_hotel):**
 * - Lista apenas hóspedes COM RESERVAS em hotel específico
 * - Filtra por quartos do hotel
 * - Útil para gestão específica do hotel
 * 
 * **Método Padrão (listar_hospedes):**
 * - Atualmente usa Solução 1 (todos os hóspedes)
 * - Pode ser alterado para usar Solução 2 se necessário
 */
class ListarHospede
{
public:
    /**
     * @brief Lista TODOS os hóspedes cadastrados no sistema
     * @return vector<Hospede*> Vetor com todos os hóspedes
     * 
     * **Comportamento:**
     * - Percorre container de hóspedes
     * - Retorna lista completa sem filtros
     * - Independe de hotel ou reserva
     * 
     * **Exemplo de uso:**
     * @code
     * vector<Hospede*> todos = ListarHospede::listar_todos_hospedes();
     * cout << "Total de hóspedes: " << todos.size() << endl;
     * @endcode
     */
    static vector<Hospede*> listar_todos_hospedes();
    
    /**
     * @brief Lista hóspedes que TEM RESERVAS em hotel específico
     * @param hotel Ponteiro para o hotel
     * @return vector<Hospede*> Vetor com hóspedes do hotel
     * 
     * **Comportamento:**
     * 1. Obtém quartos do hotel
     * 2. Para cada quarto, obtém reservas
     * 3. Para cada reserva, obtém hóspede
     * 4. Remove duplicatas (set)
     * 5. Retorna lista de hóspedes únicos
     * 
     * **Exemplo de uso:**
     * @code
     * vector<Hospede*> hospedes = ListarHospede::listar_hospedes_por_hotel(meuHotel);
     * cout << "Hóspedes com reservas neste hotel: " << hospedes.size() << endl;
     * @endcode
     */
    static vector<Hospede*> listar_hospedes_por_hotel(Hotel* hotel);
    
    /**
     * @brief Método padrão de listagem - retorna TODOS os hóspedes
     * @param hotel Ponteiro para hotel (parâmetro mantido para compatibilidade)
     * @return vector<Hospede*> Vetor com todos os hóspedes do sistema
     * 
     * **Comportamento Atual:**
     * - Ignora parâmetro hotel
     * - Chama listar_todos_hospedes()
     * - Retorna lista global
     * 
     * **Nota:** Pode ser alterado para chamar listar_hospedes_por_hotel()
     * se houver necessidade de filtrar por hotel.
     */
    static vector<Hospede*> listar_hospedes(Hotel* hotel);
};

#endif // LISTAR_HOSPEDE_HPP_INCLUDED
