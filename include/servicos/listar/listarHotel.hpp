#ifndef LISTAR_HOTEL_HPP_INCLUDED
#define LISTAR_HOTEL_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"

using namespace std;

class ListarHotel
{
public:
    static vector<Hotel> listar_hoteis(*Gerente);
};

#endif