#include "MenuHospedes.hpp"
#include "Utilidades.hpp"
#include "cadastroHospede.hpp"
#include "atualizarHospede.hpp"
#include "removerHospede.hpp"
#include "listarHospede.hpp"
#include "listarReserva.hpp"
#include <iostream>

using namespace std;

void MenuHospedes::exibir(Hotel* hotel)
{
    int opcao;
    bool voltar = false;

    while (!voltar)
    {
        Utilidades::limparTela();
        Utilidades::mostrarCabecalho("GERENCIAR HOSPEDES - " + hotel->getNome().getValor());
        
        vector<Hospede*> todosHospedes = ListarHospede::listar_todos_hospedes();
        vector<Hospede*> hospedesDoHotel = ListarHospede::listar_hospedes_por_hotel(hotel);
        
        cout << endl;
        cout << "Total de hospedes no sistema: " << todosHospedes.size() << endl;
        cout << "Hospedes com reservas neste hotel: " << hospedesDoHotel.size() << endl;
        
        cout << endl;
        cout << "1. Listar TODOS os hospedes (sistema)" << endl;
        cout << "2. Listar hospedes DESTE HOTEL (com reservas)" << endl;
        cout << "3. Ver detalhes de um hospede" << endl;
        cout << "4. Criar novo hospede" << endl;
        cout << "5. Editar hospede" << endl;
        cout << "6. Excluir hospede" << endl;
        cout << "7. Voltar" << endl;

        opcao = Utilidades::lerOpcao(1, 7);

        switch (opcao)
        {
            case 1:
                listarTodosHospedesMenu();
                break;
            case 2:
                listarHospedesDoHotelMenu(hotel);
                break;
            case 3:
                verDetalhesHospede(hotel);
                break;
            case 4:
                criarHospede(hotel);
                break;
            case 5:
                editarHospede(hotel);
                break;
            case 6:
                excluirHospede(hotel);
                break;
            case 7:
                voltar = true;
                break;
        }
    }
}

vector<Hospede*> MenuHospedes::listarHospedes(Hotel* hotel)
{
    return ListarHospede::listar_hospedes(hotel);
}

void MenuHospedes::exibirListaHospedes(vector<Hospede*> hospedes)
{
    cout << endl;
    Utilidades::mostrarLinha('-', 80);
    for (size_t i = 0; i < hospedes.size(); i++)
    {
        Hospede* h = hospedes[i];
        cout << "  [" << (i + 1) << "] " << h->getNome().getValor() << endl;
        cout << "      Email: " << h->getEmail().getValor() << endl;
        cout << "      Endereco: " << h->getEndereco().getValor() << endl;
        if (i < hospedes.size() - 1)
        {
            cout << endl;
        }
    }
    Utilidades::mostrarLinha('-', 80);
}

// SOLUÇÃO 1: Listar TODOS os hóspedes do sistema
void MenuHospedes::listarTodosHospedesMenu()
{
    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("TODOS OS HOSPEDES DO SISTEMA");
    
    vector<Hospede*> hospedes = ListarHospede::listar_todos_hospedes();
    
    if (hospedes.empty())
    {
        cout << endl;
        Utilidades::mostrarMensagem("Nenhum hospede cadastrado no sistema.");
    }
    else
    {
        cout << endl;
        cout << "Total: " << hospedes.size() << " hospede(s)" << endl;
        exibirListaHospedes(hospedes);
    }

    Utilidades::pausar();
}

// SOLUÇÃO 2: Listar hóspedes DESTE HOTEL (com reservas)
void MenuHospedes::listarHospedesDoHotelMenu(Hotel* hotel)
{
    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("HOSPEDES COM RESERVAS - " + hotel->getNome().getValor());
    
    vector<Hospede*> hospedes = ListarHospede::listar_hospedes_por_hotel(hotel);
    
    if (hospedes.empty())
    {
        cout << endl;
        Utilidades::mostrarMensagem("Este hotel ainda nao possui hospedes com reservas.");
    }
    else
    {
        cout << endl;
        cout << "Total: " << hospedes.size() << " hospede(s) com reservas neste hotel" << endl;
        exibirListaHospedes(hospedes);
    }

    Utilidades::pausar();
}

void MenuHospedes::verDetalhesHospede(Hotel* hotel)
{
    vector<Hospede*> hospedes = listarHospedes(hotel);
    
    if (hospedes.empty())
    {
        Utilidades::mostrarErro("Nenhum hospede cadastrado no sistema.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("VER DETALHES DO HOSPEDE");
    
    cout << endl;
    cout << "Selecione o hospede:" << endl;
    exibirListaHospedes(hospedes);
    
    Hospede* hospede = selecionarHospede(hospedes);
    
    if (hospede == nullptr)
    {
        Utilidades::mostrarMensagem("Operacao cancelada.");
        Utilidades::pausar();
        return;
    }

    mostrarDetalhesHospede(hospede);
    Utilidades::pausar();
}

void MenuHospedes::mostrarDetalhesHospede(Hospede* hospede)
{
    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("DETALHES DO HOSPEDE");
    
    cout << endl;
    Utilidades::mostrarLinha('=', 80);
    cout << "Nome:     " << hospede->getNome().getValor() << endl;
    cout << "Email:    " << hospede->getEmail().getValor() << endl;
    cout << "Endereco: " << hospede->getEndereco().getValor() << endl;
    cout << "Cartao:   " << hospede->getCartao().getValor() << endl;
    Utilidades::mostrarLinha('-', 80);
    
    // Contar reservas do hóspede
    vector<Reserva*> reservas = ListarReserva::listar_reservas_por_hospede(hospede);
    cout << "Reservas cadastradas: " << reservas.size() << endl;
    
    Utilidades::mostrarLinha('=', 80);
}

void MenuHospedes::criarHospede(Hotel* hotel)
{
    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("CRIAR NOVO HOSPEDE");
    
    cout << endl;
    cout << "Hotel: " << hotel->getNome().getValor() << endl;
    cout << endl;
    cout << "Preencha os dados do novo hospede:" << endl;
    cout << endl;

    CadastroHospede cadastro;
    Hospede* hospede = cadastro.criar_hospede();
    
    bool sucesso = CentralContainers::getContainerHospedes().incluir(hospede);

    if (sucesso)
    {
        Utilidades::mostrarSucesso("Hospede criado com sucesso!");
        cout << endl;
        Utilidades::mostrarMensagem("O hospede foi cadastrado no sistema e pode fazer reservas em qualquer hotel.");
    }
    else
    {
        Utilidades::mostrarErro("Nao foi possivel criar o hospede.");
        Utilidades::mostrarMensagem("O email informado ja esta cadastrado no sistema.");
        delete hospede;
    }

    Utilidades::pausar();
}

void MenuHospedes::editarHospede(Hotel* hotel)
{
    vector<Hospede*> hospedes = listarHospedes(hotel);
    
    if (hospedes.empty())
    {
        Utilidades::mostrarErro("Nenhum hospede cadastrado no sistema.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("EDITAR HOSPEDE");
    
    cout << endl;
    cout << "Selecione o hospede que deseja editar:" << endl;
    exibirListaHospedes(hospedes);
    
    Hospede* hospede = selecionarHospede(hospedes);
    
    if (hospede == nullptr)
    {
        Utilidades::mostrarMensagem("Operacao cancelada.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("EDITAR HOSPEDE " + hospede->getNome().getValor());
    
    cout << endl;
    cout << "ATENCAO: O email do hospede NAO pode ser alterado." << endl;
    cout << endl;

    AtualizarHospede atualizador;
    bool sucesso = atualizador.atualizar_hospede(hospede);

    if (sucesso)
    {
        Utilidades::mostrarSucesso("Hospede atualizado com sucesso!");
    }
    else
    {
        Utilidades::mostrarErro("Erro ao atualizar hospede.");
    }

    Utilidades::pausar();
}

void MenuHospedes::excluirHospede(Hotel* hotel)
{
    vector<Hospede*> hospedes = listarHospedes(hotel);
    
    if (hospedes.empty())
    {
        Utilidades::mostrarErro("Nenhum hospede cadastrado no sistema.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("EXCLUIR HOSPEDE");
    
    cout << endl;
    cout << "Selecione o hospede que deseja excluir:" << endl;
    exibirListaHospedes(hospedes);
    
    Hospede* hospede = selecionarHospede(hospedes);
    
    if (hospede == nullptr)
    {
        Utilidades::mostrarMensagem("Operacao cancelada.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("EXCLUIR HOSPEDE " + hospede->getNome().getValor());
    
    cout << endl;
    Utilidades::mostrarLinha('!', 80);
    cout << "ATENCAO: Esta acao e IRREVERSIVEL!" << endl;
    cout << "Todas as reservas deste hospede serao excluidas!" << endl;
    Utilidades::mostrarLinha('!', 80);
    cout << endl;

    if (!Utilidades::confirmar("Tem certeza que deseja excluir este hospede?"))
    {
        Utilidades::mostrarMensagem("Operacao cancelada.");
        Utilidades::pausar();
        return;
    }

    bool sucesso = RemoverHospede::remover_hospede(hospede);

    if (sucesso)
    {
        Utilidades::mostrarSucesso("Hospede excluido com sucesso!");
        delete hospede;
    }
    else
    {
        Utilidades::mostrarErro("Erro ao excluir hospede.");
    }

    Utilidades::pausar();
}

Hospede* MenuHospedes::selecionarHospede(vector<Hospede*> hospedes)
{
    if (hospedes.empty())
    {
        return nullptr;
    }

    cout << endl;
    cout << "Digite o numero do hospede (ou 0 para cancelar): ";
    
    int opcao = Utilidades::lerOpcao(0, hospedes.size());
    
    if (opcao == 0)
    {
        return nullptr;
    }
    
    return hospedes[opcao - 1];
}
