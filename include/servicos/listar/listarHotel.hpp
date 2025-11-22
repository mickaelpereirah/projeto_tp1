/**
 * @file listarHotel.hpp
 * @brief Serviço de listagem de hotéis
 */

#ifndef LISTAR_HOTEL_HPP_INCLUDED
#define LISTAR_HOTEL_HPP_INCLUDED

#include <vector>
#include "DOMINIOS.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"

using namespace std;

/**
 * @class ListarHotel
 * @brief Lista hotéis cadastrados de um gerente específico
 * 
 * **Escopo de Listagem:**
 * - Lista apenas hotéis do gerente logado
 * - Gerente só visualiza seus próprios hotéis
 * - Implementa isolamento de dados por gerente
 * 
 * **Regra de Negócio:**
 * - Cada gerente gerencia seus hotéis
 * - Não há acesso cross-gerente
 * - Lista pode estar vazia se gerente não tem hotéis
 */
class ListarHotel
{
public:
    /**
     * @brief Lista todos os hotéis de um gerente específico
     * @param gerente Ponteiro para o gerente autenticado
     * @return vector<Hotel*> Vetor com hotéis do gerente
     * 
     * **Comportamento:**
     * 1. Busca no container de hotéis
     * 2. Filtra hotéis onde gerente.email == hotel.gerente
     * 3. Retorna lista filtrada
     * 4. Lista vazia se gerente não tem hotéis
     * 
     * **Exemplo de uso:**
     * @code
     * Gerente* g = AutenticarGerente::login("joao@hotel.com", "senha");
     * vector<Hotel*> meus_hoteis = ListarHotel::listar_hoteis(g);
     * cout << "Você gerencia " << meus_hoteis.size() << " hotel(is)" << endl;
     * @endcode
     */
    static vector<Hotel*> listar_hoteis(Gerente* gerente);
};

#endif // LISTAR_HOTEL_HPP_INCLUDED
