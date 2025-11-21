
#ifndef ATUALIZAR_QUARTO_HPP_INCLUDED
#define ATUALIZAR_QUARTO_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "../cadastro/cadastro.hpp"
#include "ENTIDADES.hpp"
#include "centralContainers.hpp"

using namespace std;

class AtualizarQuarto : public Cadastro
{
public:
    Quarto *modificar_quarto(Quarto *);
    bool atualizar_quarto(Quarto *);
    bool validar_resposta();
};

#endif