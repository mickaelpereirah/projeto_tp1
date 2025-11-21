#ifndef LISTAR_QUARTO_HPP_INCLUDED
#define LISTAR_QUARTO_HPP_INCLUDED

#include <vector>
#include "DOMINIOS.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"

using namespace std;

class ListarQuarto
{
public:
    static vector<Quarto*> listar_quartos(Hotel* hotel);
};

#endif

