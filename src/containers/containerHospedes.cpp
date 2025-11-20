#include "containerHospedes.hpp"
#include <iostream>

using namespace std;

bool ContainerHospede::incluir(Hospede *hospede)
{
    string email_hospede = hospede->getEmail().getValor();
    Hospede *hospede_encontrado = pesquisar(email_hospede);

    if (hospede_encontrado != nullptr)
    {
        return false;
    }
    else
    {
        container.insert({email_hospede, hospede});
        return true;        
    }
}

bool ContainerHospede::remover(string email)
{
    return container.erase(email);
}

Hospede *ContainerHospede::pesquisar(string email)
{
    if (container.count(email))
    { // retorna 0 se não existir e 1 se existir
        return container.at(email);
    }
    return nullptr;
}

bool ContainerHospede::atualizar(Hospede *hospede_atualizado)
{
    string email_hospede = hospede_atualizado->getEmail().getValor();    
    container[email_hospede] = hospede_atualizado;

    return true;
}