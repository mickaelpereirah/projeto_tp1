/**
 * @file listarQuarto.hpp
 * @brief Serviço de listagem de quartos
 */

#ifndef LISTAR_QUARTO_HPP_INCLUDED
#define LISTAR_QUARTO_HPP_INCLUDED

#include <vector>
#include "DOMINIOS.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"

using namespace std;

/**
 * @class ListarQuarto
 * @brief Lista quartos de um hotel específico
 * 
 * **Escopo de Listagem:**
 * - Lista apenas quartos do hotel especificado
 * - Implementa isolamento de dados por hotel
 * - Lista pode incluir quartos em qualquer estado (disponível/ocupado/manutenção)
 * 
 * **Regra de Negócio:**
 * - Quartos pertencem a um único hotel
 * - Lista completa independente do estado do quarto
 * - Gerente visualiza todos os quartos do seu hotel
 */
class ListarQuarto
{
public:
    /**
     * @brief Lista todos os quartos de um hotel específico
     * @param hotel Ponteiro para o hotel
     * @return vector<Quarto*> Vetor com quartos do hotel
     * 
     * **Comportamento:**
     * 1. Busca no container de quartos
     * 2. Filtra quartos onde quarto.hotel_codigo == hotel.codigo
     * 3. Retorna lista completa de quartos do hotel
     * 4. Lista vazia se hotel não tem quartos cadastrados
     * 
     * **Estados Incluídos:**
     * - Disponível (pronto para reserva)
     * - Ocupado (com reserva ativa)
     * - Manutenção (temporariamente indisponível)
     * 
     * **Exemplo de uso:**
     * @code
     * vector<Quarto*> quartos = ListarQuarto::listar_quartos(meuHotel);
     * cout << "Total de quartos: " << quartos.size() << endl;
     * for(auto q : quartos) {
     *     cout << "Quarto " << q->getNumero() << " - " << q->getEstado() << endl;
     * }
     * @endcode
     */
    static vector<Quarto*> listar_quartos(Hotel* hotel);
};

#endif // LISTAR_QUARTO_HPP_INCLUDED
