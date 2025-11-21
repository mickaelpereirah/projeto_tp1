#ifndef REMOVER_HOTEL_HPP_INCLUDED
#define REMOVER_HOTEL_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"
#include "listar/listarQuarto.hpp"
#include "listar/listarReserva.hpp"

using namespace std;

class RemoverHotel
{
public:
    static bool remover_hotel(Hotel* hotel);
};

#endif

