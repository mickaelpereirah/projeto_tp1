#include "containerQuartos.hpp"
#include <iostream>

using namespace std;

bool ContainerQuarto::incluir(Quarto *quarto)
{
    int numero_quarto = quarto->getNumero().getValor();
    Quarto *quarto_encontrado = pesquisar(numero_quarto);

    if (quarto_encontrado != nullptr)
    {
        return false;
    }
    else
    {
        container.insert({numero_quarto, quarto});
        return true;        
    }
}

bool ContainerQuarto::remover(int numero)
{
    return container.erase(numero);
}

Quarto *ContainerQuarto::pesquisar(int numero)
{
    if (container.count(numero))
    { // retorna 0 se não existir e 1 se existir
        return container.at(numero);
    }
    return nullptr;
}

bool ContainerQuarto::atualizar(Quarto *quarto_atualizado)
{
    int numero_quarto = quarto_atualizado->getNumero().getValor();    
    container[numero_quarto] = quarto_atualizado;

    return true;
}