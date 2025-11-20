#include "containerGerentes.hpp"
#include <iostream>

using namespace std;

bool ContainerGerente::incluir(Gerente *gerente)
{
    string email_gerente = gerente->getEmail().getValor();
    Gerente *gerente_encontrado = pesquisar(email_gerente);

    if (gerente_encontrado != nullptr)
    {
        return false;
    }
    else
    {
        container.insert({email_gerente, gerente});
        return true;        
    }
}

bool ContainerGerente::remover(string email)
{
    return container.erase(email);
}

Gerente *ContainerGerente::pesquisar(string email)
{
    if (container.count(email))
    { // retorna 0 se não existir e 1 se existir
        return container.at(email);
    }
    return nullptr;
}

bool ContainerGerente::atualizar(Gerente *gerente_atualizado) //só pode atualizar ele mesmo
{
    string email_gerente = gerente_atualizado->getEmail().getValor();    
    container[email_gerente] = gerente_atualizado;

    return true;
}