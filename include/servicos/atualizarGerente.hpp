
#ifndef ATUALIZAR_GERENTE_HPP_INCLUDED
#define ATUALIZAR_GERENTE_HPP_INCLUDED

#include "DOMINIOS.hpp"
#include "cadastro.hpp"
#include "gerente.hpp"
#include "centralContainers.hpp"

using namespace std;

class AtualizarGerente : public Cadastro
{
public:
    Gerente *modificar_gerente(Gerente*);
    bool atualizar_gerente(Gerente*);
    bool validar_resposta();
};

#endif