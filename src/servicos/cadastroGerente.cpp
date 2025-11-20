#include <iostream>>
#include <stdexcept>

#include "cadastroGerente.hpp"

using namespace std;


Gerente *CadastroGerente::criar_gerente() {
    Gerente *g = new Gerente();
    
    cout << "CRIAR GERENTE" << endl;
    Nome nome = criar_nome();
    Ramal ramal = criar_ramal();
    Email email = criar_email();
    Senha senha = criar_senha();

    g->setNome(nome);
    g->setRamal(ramal);
    g->setEmail(email);
    g->setSenha(senha);

    return g;
}