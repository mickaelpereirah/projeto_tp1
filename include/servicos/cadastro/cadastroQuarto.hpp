#ifndef CADASTRO_QUARTO_HPP_INCLUDED
#define CADASTRO_QUARTO_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "cadastro.hpp"
#include "quarto.hpp"
#include "centralContainers.hpp"

using namespace std;

class CadastroQuarto : public Cadastro
{
public:
    Quarto *criar_quarto();
    bool novo_quarto();
};

#endif