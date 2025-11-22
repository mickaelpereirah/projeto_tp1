#include "MenuGerente.hpp"
#include "MenuConta.hpp"
#include "MenuHoteis.hpp"
#include "MenuQuartos.hpp"
#include "MenuReservas.hpp"
#include "MenuHospedes.hpp"
#include "Utilidades.hpp"
#include "listarHotel.hpp"
#include <iostream>

using namespace std;

void MenuGerente::exibir(Gerente* gerente)
{
    int opcao;
    bool logout = false;

    while (!logout)
    {
        Utilidades::limparTela();
        exibirCabecalho(gerente);
        
        // Contar quantos hotéis o gerente possui
        vector<Hotel*> hoteis = ListarHotel::listar_hoteis(gerente);
        int totalHoteis = hoteis.size();
        
        cout << endl;
        cout << "1. Gerenciar minha conta" << endl;
        cout << "2. Gerenciar meus hoteis (" << totalHoteis << " cadastrados)" << endl;
        cout << "3. Gerenciar quartos" << endl;
        cout << "4. Gerenciar reservas" << endl;
        cout << "5. Gerenciar hospedes" << endl;
        cout << "6. Logout" << endl;

        opcao = Utilidades::lerOpcao(1, 6);

        switch (opcao)
        {
            case 1:
            {
                // Chama MenuConta e verifica se a conta foi excluída
                bool contaExcluida = MenuConta::exibir(gerente);
                if (contaExcluida)
                {
                    // Se a conta foi excluída, força logout
                    logout = true;
                }
                break;
            }
            case 2:
                // Chama MenuHoteis
                MenuHoteis::exibir(gerente);
                break;
            case 3:
                // Gerenciar Quartos - Seleciona hotel primeiro
                gerenciarQuartos(gerente);
                break;
            case 4:
                // Gerenciar Reservas - Seleciona hotel primeiro
                gerenciarReservas(gerente);
                break;
            case 5:
                // Gerenciar Hóspedes - Seleciona hotel primeiro
                gerenciarHospedes(gerente);
                break;
            case 6:
                if (Utilidades::confirmar("Deseja realmente fazer logout?"))
                {
                    logout = true;
                    Utilidades::mostrarMensagem("Logout realizado com sucesso!");
                }
                break;
        }
    }
}

void MenuGerente::exibirCabecalho(Gerente* gerente)
{
    string nomeGerente = gerente->getNome().getValor();
    string mensagem = "BEM-VINDO, " + nomeGerente + "!";
    Utilidades::mostrarCabecalho(mensagem);
}

void MenuGerente::gerenciarQuartos(Gerente* gerente)
{
    // Listar hotéis do gerente
    vector<Hotel*> hoteis = ListarHotel::listar_hoteis(gerente);
    
    if (hoteis.empty())
    {
        Utilidades::mostrarErro("Voce nao possui hoteis cadastrados.");
        Utilidades::mostrarMensagem("Cadastre um hotel primeiro em 'Gerenciar meus hoteis'.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("GERENCIAR QUARTOS - SELECIONE O HOTEL");
    
    cout << endl;
    cout << "Selecione o hotel:" << endl;
    cout << endl;
    
    for (size_t i = 0; i < hoteis.size(); i++)
    {
        Hotel* h = hoteis[i];
        cout << "  [" << (i + 1) << "] " << h->getNome().getValor() 
             << " - " << h->getEndereco().getValor() << endl;
    }
    
    cout << endl;
    cout << "Digite o numero do hotel (ou 0 para cancelar): ";
    
    int opcao = Utilidades::lerOpcao(0, hoteis.size());
    
    if (opcao == 0)
    {
        Utilidades::mostrarMensagem("Operacao cancelada.");
        Utilidades::pausar();
        return;
    }
    
    Hotel* hotel = hoteis[opcao - 1];
    
    // Chama o MenuQuartos para o hotel selecionado
    MenuQuartos::exibir(hotel);
}

void MenuGerente::gerenciarReservas(Gerente* gerente)
{
    // Listar hotéis do gerente
    vector<Hotel*> hoteis = ListarHotel::listar_hoteis(gerente);
    
    if (hoteis.empty())
    {
        Utilidades::mostrarErro("Voce nao possui hoteis cadastrados.");
        Utilidades::mostrarMensagem("Cadastre um hotel primeiro em 'Gerenciar meus hoteis'.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("GERENCIAR RESERVAS - SELECIONE O HOTEL");
    
    cout << endl;
    cout << "Selecione o hotel:" << endl;
    cout << endl;
    
    for (size_t i = 0; i < hoteis.size(); i++)
    {
        Hotel* h = hoteis[i];
        cout << "  [" << (i + 1) << "] " << h->getNome().getValor() 
             << " - " << h->getEndereco().getValor() << endl;
    }
    
    cout << endl;
    cout << "Digite o numero do hotel (ou 0 para cancelar): ";
    
    int opcao = Utilidades::lerOpcao(0, hoteis.size());
    
    if (opcao == 0)
    {
        Utilidades::mostrarMensagem("Operacao cancelada.");
        Utilidades::pausar();
        return;
    }
    
    Hotel* hotel = hoteis[opcao - 1];
    
    // Chama o MenuReservas para o hotel selecionado
    MenuReservas::exibir(hotel);
}

void MenuGerente::gerenciarHospedes(Gerente* gerente)
{
    // Listar hotéis do gerente
    vector<Hotel*> hoteis = ListarHotel::listar_hoteis(gerente);
    
    if (hoteis.empty())
    {
        Utilidades::mostrarErro("Voce nao possui hoteis cadastrados.");
        Utilidades::mostrarMensagem("Cadastre um hotel primeiro em 'Gerenciar meus hoteis'.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("GERENCIAR HOSPEDES - SELECIONE O HOTEL");
    
    cout << endl;
    cout << "Selecione o hotel:" << endl;
    cout << endl;
    
    for (size_t i = 0; i < hoteis.size(); i++)
    {
        Hotel* h = hoteis[i];
        cout << "  [" << (i + 1) << "] " << h->getNome().getValor() 
             << " - " << h->getEndereco().getValor() << endl;
    }
    
    cout << endl;
    cout << "Digite o numero do hotel (ou 0 para cancelar): ";
    
    int opcao = Utilidades::lerOpcao(0, hoteis.size());
    
    if (opcao == 0)
    {
        Utilidades::mostrarMensagem("Operacao cancelada.");
        Utilidades::pausar();
        return;
    }
    
    Hotel* hotel = hoteis[opcao - 1];
    
    // Chama o MenuHospedes para o hotel selecionado
    MenuHospedes::exibir(hotel);
}
