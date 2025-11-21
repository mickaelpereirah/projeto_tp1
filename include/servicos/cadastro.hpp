
#ifndef CADASTRO_HPP_INCLUDED
#define CADASTRO_HPP_INCLUDED

#include <unordered_map>
#include <string>

#include "DOMINIOS.hpp"

using namespace std;

class Cadastro
{
public:
    Capacidade criar_capacidade();
    Cartao criar_cartao();
    Codigo criar_codigo();
    Dinheiro criar_dinheiro();
    Email criar_email();
    Endereco criar_endereco();
    Nome criar_nome();
    Numero criar_numero();
    Ramal criar_ramal();
    Senha criar_senha();
    Telefone criar_telefone();
};

#endif