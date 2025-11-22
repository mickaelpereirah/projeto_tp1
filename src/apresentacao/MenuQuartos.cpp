#include "MenuQuartos.hpp"
#include "Utilidades.hpp"
#include "cadastroQuarto.hpp"
#include "atualizarQuarto.hpp"
#include "removerQuarto.hpp"
#include "listarQuarto.hpp"
#include "listarReserva.hpp"
#include <iostream>

using namespace std;

void MenuQuartos::exibir(Hotel* hotel)
{
    int opcao;
    bool voltar = false;

    while (!voltar)
    {
        Utilidades::limparTela();
        Utilidades::mostrarCabecalho("GERENCIAR QUARTOS - " + hotel->getNome().getValor());
        
        vector<Quarto*> quartos = listarQuartos(hotel);
        cout << endl;
        cout << "Total de quartos cadastrados: " << quartos.size() << endl;
        
        cout << endl;
        cout << "1. Listar quartos" << endl;
        cout << "2. Ver detalhes de um quarto" << endl;
        cout << "3. Criar novo quarto" << endl;
        cout << "4. Editar quarto" << endl;
        cout << "5. Excluir quarto" << endl;
        cout << "6. Voltar" << endl;

        opcao = Utilidades::lerOpcao(1, 6);

        switch (opcao)
        {
            case 1:
                listarQuartosMenu(hotel);
                break;
            case 2:
                verDetalhesQuarto(hotel);
                break;
            case 3:
                criarQuarto(hotel);
                break;
            case 4:
                editarQuarto(hotel);
                break;
            case 5:
                excluirQuarto(hotel);
                break;
            case 6:
                voltar = true;
                break;
        }
    }
}

vector<Quarto*> MenuQuartos::listarQuartos(Hotel* hotel)
{
    return ListarQuarto::listar_quartos(hotel);
}

void MenuQuartos::exibirListaQuartos(vector<Quarto*> quartos)
{
    cout << endl;
    Utilidades::mostrarLinha('-', 60);
    for (size_t i = 0; i < quartos.size(); i++)
    {
        Quarto* q = quartos[i];
        cout << "  [" << (i + 1) << "] Quarto " << q->getNumero().getValor() << endl;
        cout << "      Capacidade: " << q->getCapacidade().getValor() << " pessoa(s)" << endl;
        cout << "      Diaria: R$ " << q->getDinheiro().getValor() << endl;
        cout << "      Ramal: " << q->getRamal().getValor() << endl;
        if (i < quartos.size() - 1)
        {
            cout << endl;
        }
    }
    Utilidades::mostrarLinha('-', 60);
}

void MenuQuartos::listarQuartosMenu(Hotel* hotel)
{
    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("QUARTOS - " + hotel->getNome().getValor());
    
    vector<Quarto*> quartos = listarQuartos(hotel);
    
    if (quartos.empty())
    {
        cout << endl;
        Utilidades::mostrarMensagem("Este hotel ainda nao possui quartos cadastrados.");
    }
    else
    {
        cout << endl;
        cout << "Total: " << quartos.size() << " quarto(s)" << endl;
        exibirListaQuartos(quartos);
    }

    Utilidades::pausar();
}

void MenuQuartos::verDetalhesQuarto(Hotel* hotel)
{
    vector<Quarto*> quartos = listarQuartos(hotel);
    
    if (quartos.empty())
    {
        Utilidades::mostrarErro("Este hotel nao possui quartos cadastrados.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("VER DETALHES DO QUARTO");
    
    cout << endl;
    cout << "Selecione o quarto:" << endl;
    exibirListaQuartos(quartos);
    
    Quarto* quarto = selecionarQuarto(quartos);
    
    if (quarto == nullptr)
    {
        Utilidades::mostrarMensagem("Operacao cancelada.");
        Utilidades::pausar();
        return;
    }

    mostrarDetalhesQuarto(quarto);
    Utilidades::pausar();
}

void MenuQuartos::mostrarDetalhesQuarto(Quarto* quarto)
{
    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("DETALHES DO QUARTO");
    
    cout << endl;
    Utilidades::mostrarLinha('=', 60);
    cout << "Numero:     " << quarto->getNumero().getValor() << endl;
    cout << "Capacidade: " << quarto->getCapacidade().getValor() << " pessoa(s)" << endl;
    cout << "Diaria:     R$ " << quarto->getDinheiro().getValor() << endl;
    cout << "Ramal:      " << quarto->getRamal().getValor() << endl;
    Utilidades::mostrarLinha('-', 60);
    
    // Contar reservas do quarto
    vector<Reserva*> reservas = CentralContainers::getContainerReservas().pesquisarPorQuarto(quarto->getNumero().getValor());
    cout << "Reservas cadastradas: " << reservas.size() << endl;
    
    Utilidades::mostrarLinha('=', 60);
}

void MenuQuartos::criarQuarto(Hotel* hotel)
{
    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("CRIAR NOVO QUARTO");
    
    cout << endl;
    cout << "Hotel: " << hotel->getNome().getValor() << endl;
    cout << endl;
    cout << "Preencha os dados do novo quarto:" << endl;
    cout << endl;

    CadastroQuarto cadastro;
    Quarto* quarto = cadastro.criar_quarto();
    
    string codigo_hotel = hotel->getCodigo().getValor();
    bool sucesso = CentralContainers::getContainerQuartos().incluir(quarto, codigo_hotel);

    if (sucesso)
    {
        Utilidades::mostrarSucesso("Quarto criado com sucesso!");
    }
    else
    {
        Utilidades::mostrarErro("Nao foi possivel criar o quarto.");
        Utilidades::mostrarMensagem("O numero informado ja esta cadastrado.");
        delete quarto;
    }

    Utilidades::pausar();
}

void MenuQuartos::editarQuarto(Hotel* hotel)
{
    vector<Quarto*> quartos = listarQuartos(hotel);
    
    if (quartos.empty())
    {
        Utilidades::mostrarErro("Este hotel nao possui quartos cadastrados.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("EDITAR QUARTO");
    
    cout << endl;
    cout << "Selecione o quarto que deseja editar:" << endl;
    exibirListaQuartos(quartos);
    
    Quarto* quarto = selecionarQuarto(quartos);
    
    if (quarto == nullptr)
    {
        Utilidades::mostrarMensagem("Operacao cancelada.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("EDITAR QUARTO " + to_string(quarto->getNumero().getValor()));
    
    cout << endl;
    cout << "ATENCAO: O numero do quarto NAO pode ser alterado." << endl;
    cout << endl;

    AtualizarQuarto atualizador;
    bool sucesso = atualizador.atualizar_quarto(quarto);

    if (sucesso)
    {
        Utilidades::mostrarSucesso("Quarto atualizado com sucesso!");
    }
    else
    {
        Utilidades::mostrarErro("Erro ao atualizar quarto.");
    }

    Utilidades::pausar();
}

void MenuQuartos::excluirQuarto(Hotel* hotel)
{
    vector<Quarto*> quartos = listarQuartos(hotel);
    
    if (quartos.empty())
    {
        Utilidades::mostrarErro("Este hotel nao possui quartos cadastrados.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("EXCLUIR QUARTO");
    
    cout << endl;
    cout << "Selecione o quarto que deseja excluir:" << endl;
    exibirListaQuartos(quartos);
    
    Quarto* quarto = selecionarQuarto(quartos);
    
    if (quarto == nullptr)
    {
        Utilidades::mostrarMensagem("Operacao cancelada.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("EXCLUIR QUARTO " + to_string(quarto->getNumero().getValor()));
    
    cout << endl;
    Utilidades::mostrarLinha('!', 60);
    cout << "ATENCAO: Esta acao e IRREVERSIVEL!" << endl;
    cout << "Todas as reservas deste quarto serao excluidas!" << endl;
    Utilidades::mostrarLinha('!', 60);
    cout << endl;

    if (!Utilidades::confirmar("Tem certeza que deseja excluir este quarto?"))
    {
        Utilidades::mostrarMensagem("Operacao cancelada.");
        Utilidades::pausar();
        return;
    }

    bool sucesso = RemoverQuarto::remover_quarto(quarto);

    if (sucesso)
    {
        Utilidades::mostrarSucesso("Quarto excluido com sucesso!");
        delete quarto;
    }
    else
    {
        Utilidades::mostrarErro("Erro ao excluir quarto.");
    }

    Utilidades::pausar();
}

Quarto* MenuQuartos::selecionarQuarto(vector<Quarto*> quartos)
{
    if (quartos.empty())
    {
        return nullptr;
    }

    cout << endl;
    cout << "Digite o numero do quarto (ou 0 para cancelar): ";
    
    int opcao = Utilidades::lerOpcao(0, quartos.size());
    
    if (opcao == 0)
    {
        return nullptr;
    }
    
    return quartos[opcao - 1];
}
