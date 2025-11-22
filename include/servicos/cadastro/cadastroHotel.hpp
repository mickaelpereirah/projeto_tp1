/**
 * @file cadastroHotel.hpp
 * @brief Serviço de cadastro de hotéis
 */

#ifndef CADASTRO_HOTEL_HPP_INCLUDED
#define CADASTRO_HOTEL_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "cadastro.hpp"
#include "hotel.hpp"
#include "centralContainers.hpp"

using namespace std;

/**
 * @class CadastroHotel
 * @brief Cadastra hotéis no sistema
 * @extends Cadastro
 * 
 * **Dados:** Nome, Endereço, Telefone, Código (PK único)  
 * **Validação:** Código único no sistema
 */
class CadastroHotel : public Cadastro
{
public:
    /** @brief Cria objeto Hotel com dados do usuário */
    Hotel *criar_hotel();
    
    /** @brief Cadastra hotel no sistema (retorna true se sucesso) */
    bool novo_hotel();
};

#endif
