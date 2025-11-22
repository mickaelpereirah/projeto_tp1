#ifndef MENU_GERENTE_HPP_INCLUDED
#define MENU_GERENTE_HPP_INCLUDED

#include "gerente.hpp"

class MenuGerente
{
public:
    static void exibir(Gerente* gerente);

private:
    static void exibirCabecalho(Gerente* gerente);
    static void gerenciarQuartos(Gerente* gerente);
    static void gerenciarReservas(Gerente* gerente);
    static void gerenciarHospedes(Gerente* gerente);
};

#endif
