
#ifndef CADASTRO_GERENTE_HPP_INCLUDED
#define CADASTRO_GERENTE_HPP_INCLUDED 

#include "DOMINIOS.hpp"
#include "cadastro.hpp"
#include "gerente.hpp"

using namespace std;

class CadastroGerente : Cadastro {
    public: 
        Gerente *criar_gerente();
        
};


#endif