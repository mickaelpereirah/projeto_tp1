#ifndef LISTAR_HOSPEDE_HPP_INCLUDED
#define LISTAR_HOSPEDE_HPP_INCLUDED

#include <vector>
#include <set>
#include "DOMINIOS.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"
#include "listar/listarQuarto.hpp"

using namespace std;

class ListarHospede
{
public:
    static vector<Hospede*> listar_hospedes(Hotel* hotel);
};

#endif

