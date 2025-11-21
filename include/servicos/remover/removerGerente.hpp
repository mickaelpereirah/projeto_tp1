#ifndef REMOVER_GERENTE_HPP_INCLUDED
#define REMOVER_GERENTE_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"
#include "listar/listarHotel.hpp"
#include "remover/removerHotel.hpp"

using namespace std;

class RemoverGerente
{
public:
    static bool remover_gerente(Gerente* gerente);
};

#endif

