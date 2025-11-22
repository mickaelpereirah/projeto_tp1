#include "MenuPrincipal.hpp"
#include "MenuGerente.hpp"
#include "Utilidades.hpp"
#include "cadastroGerente.hpp"
#include "autenticarGerente.hpp"
#include <iostream>

using namespace std;

void MenuPrincipal::exibir()
{
    int opcao;
    bool sair = false;

    while (!sair)
    {
        Utilidades::limparTela();
        Utilidades::mostrarCabecalho("SISTEMA DE GESTAO DE HOTEIS");
        
        cout << endl;
        cout << "1. Criar conta" << endl;
        cout << "2. Login" << endl;
        cout << "3. Sair" << endl;

        opcao = Utilidades::lerOpcao(1, 3);

        switch (opcao)
        {
            case 1:
                criarConta();
                break;
            case 2:
            {
                Gerente* gerente = fazerLogin();
                if (gerente != nullptr)
                {
                    Utilidades::mostrarSucesso("Login realizado com sucesso!");
                    Utilidades::pausar();
                    
                    // Chama o menu do gerente
                    MenuGerente::exibir(gerente);
                }
                break;
            }
            case 3:
                if (Utilidades::confirmar("Deseja realmente sair?"))
                {
                    sair = true;
                    Utilidades::mostrarMensagem("Ate logo!");
                }
                break;
        }
    }
}

void MenuPrincipal::criarConta()
{
    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("CRIAR NOVA CONTA");
    
    cout << endl;
    cout << "Preencha os dados para criar sua conta de gerente:" << endl;
    cout << endl;

    CadastroGerente cadastro;
    bool sucesso = cadastro.novo_gerente();

    if (sucesso)
    {
        Utilidades::mostrarSucesso("Conta criada com sucesso!");
        Utilidades::mostrarMensagem("Agora voce pode fazer login no sistema.");
    }
    else
    {
        Utilidades::mostrarErro("Nao foi possivel criar a conta.");
        Utilidades::mostrarMensagem("O email informado ja esta cadastrado no sistema.");
    }

    Utilidades::pausar();
}

Gerente* MenuPrincipal::fazerLogin()
{
    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("LOGIN");
    
    cout << endl;
    string email = Utilidades::lerString("Email: ");
    string senha = Utilidades::lerString("Senha: ");

    Gerente* gerente = AutenticarGerente::login(email, senha);

    if (gerente == nullptr)
    {
        Utilidades::mostrarErro("Email ou senha incorretos!");
        Utilidades::pausar();
    }

    return gerente;
}
