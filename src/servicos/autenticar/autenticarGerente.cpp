#include "autenticarGerente.hpp"

using namespace std;

Gerente* AutenticarGerente::login(string email, string senha)
{
    // Busca o gerente pelo email
    Gerente* gerente = CentralContainers::getContainerGerentes().pesquisar(email);
    
    // Se o gerente não existe, retorna nullptr
    if (gerente == nullptr)
    {
        return nullptr;
    }
    
    // Verifica se a senha está correta
    if (gerente->getSenha().getValor() == senha)
    {
        return gerente;
    }
    
    // Senha incorreta
    return nullptr;
}
