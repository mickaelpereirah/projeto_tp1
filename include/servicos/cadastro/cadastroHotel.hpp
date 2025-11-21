#ifndef CADASTRO_HOTEL_HPP_INCLUDED
#define CADASTRO_HOTEL_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "cadastro.hpp"
#include "hotel.hpp"
#include "centralContainers.hpp"

using namespace std;

class CadastroHotel : public Cadastro
{
public:
    Hotel *criar_hotel();
    bool novo_hotel();
};

#endif