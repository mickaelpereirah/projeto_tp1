
#ifndef ATUALIZAR_HOTEL_HPP_INCLUDED
#define ATUALIZAR_HOTEL_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "../cadastro/cadastro.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"

using namespace std;

class AtualizarHotel : public Cadastro
{
public:
    Hotel *modificar_hotel(Hotel *);
    bool atualizar_hotel(Hotel *);
    bool validar_resposta();
};

#endif