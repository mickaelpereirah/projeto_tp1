#include "MenuHoteis.hpp"
#include "Utilidades.hpp"
#include "cadastroHotel.hpp"
#include "atualizarHotel.hpp"
#include "removerHotel.hpp"
#include "listarHotel.hpp"
#include "listarQuarto.hpp"
#include <iostream>

using namespace std;

void MenuHoteis::exibir(Gerente* gerente)
{
    int opcao;
    bool voltar = false;

    while (!voltar)
    {
        Utilidades::limparTela();
        Utilidades::mostrarCabecalho("GERENCIAR HOTEIS");
        
        // Mostrar quantidade de hotéis
        vector<Hotel*> hoteis = listarHoteis(gerente);
        cout << endl;
        cout << "Total de hoteis cadastrados: " << hoteis.size() << endl;
        
        cout << endl;
        cout << "1. Listar meus hoteis" << endl;
        cout << "2. Ver detalhes de um hotel" << endl;
        cout << "3. Criar novo hotel" << endl;
        cout << "4. Editar hotel" << endl;
        cout << "5. Excluir hotel" << endl;
        cout << "6. Voltar" << endl;

        opcao = Utilidades::lerOpcao(1, 6);

        switch (opcao)
        {
            case 1:
                listarHoteisMenu(gerente);
                break;
            case 2:
                verDetalhesHotel(gerente);
                break;
            case 3:
                criarHotel(gerente);
                break;
            case 4:
                editarHotel(gerente);
                break;
            case 5:
                excluirHotel(gerente);
                break;
            case 6:
                voltar = true;
                break;
        }
    }
}

vector<Hotel*> MenuHoteis::listarHoteis(Gerente* gerente)
{
    return ListarHotel::listar_hoteis(gerente);
}

void MenuHoteis::exibirListaHoteis(vector<Hotel*> hoteis)
{
    cout << endl;
    Utilidades::mostrarLinha('-', 60);
    for (size_t i = 0; i < hoteis.size(); i++)
    {
        Hotel* h = hoteis[i];
        cout << "  [" << (i + 1) << "] " 
             << h->getNome().getValor() << endl;
        cout << "      Endereco: " << h->getEndereco().getValor() << endl;
        cout << "      Codigo: " << h->getCodigo().getValor() << endl;
        if (i < hoteis.size() - 1)
        {
            cout << endl;
        }
    }
    Utilidades::mostrarLinha('-', 60);
}

void MenuHoteis::listarHoteisMenu(Gerente* gerente)
{
    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("MEUS HOTEIS");
    
    vector<Hotel*> hoteis = listarHoteis(gerente);
    
    if (hoteis.empty())
    {
        cout << endl;
        Utilidades::mostrarMensagem("Voce ainda nao possui hoteis cadastrados.");
    }
    else
    {
        cout << endl;
        cout << "Voce possui " << hoteis.size() << " hotel(is) cadastrado(s):" << endl;
        exibirListaHoteis(hoteis);
    }

    Utilidades::pausar();
}

void MenuHoteis::verDetalhesHotel(Gerente* gerente)
{
    vector<Hotel*> hoteis = listarHoteis(gerente);
    
    if (hoteis.empty())
    {
        Utilidades::mostrarErro("Voce nao possui hoteis cadastrados.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("VER DETALHES DO HOTEL");
    
    cout << endl;
    cout << "Selecione o hotel:" << endl;
    exibirListaHoteis(hoteis);
    
    Hotel* hotel = selecionarHotel(hoteis);
    
    if (hotel == nullptr)
    {
        Utilidades::mostrarMensagem("Operacao cancelada.");
        Utilidades::pausar();
        return;
    }

    mostrarDetalhesHotel(hotel);
    Utilidades::pausar();
}

void MenuHoteis::mostrarDetalhesHotel(Hotel* hotel)
{
    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("DETALHES DO HOTEL");
    
    cout << endl;
    Utilidades::mostrarLinha('=', 60);
    cout << "Nome:     " << hotel->getNome().getValor() << endl;
    cout << "Codigo:   " << hotel->getCodigo().getValor() << endl;
    cout << "Endereco: " << hotel->getEndereco().getValor() << endl;
    cout << "Telefone: " << hotel->getTelefone().getValor() << endl;
    Utilidades::mostrarLinha('-', 60);
    
    // Contar quartos do hotel
    vector<Quarto*> quartos = ListarQuarto::listar_quartos(hotel);
    cout << "Quartos cadastrados: " << quartos.size() << endl;
    
    Utilidades::mostrarLinha('=', 60);
}

void MenuHoteis::criarHotel(Gerente* gerente)
{
    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("CRIAR NOVO HOTEL");
    
    cout << endl;
    cout << "Preencha os dados do novo hotel:" << endl;
    cout << endl;

    CadastroHotel cadastro;
    Hotel* hotel = cadastro.criar_hotel();
    
    // Incluir no container com o email do gerente
    string email_gerente = gerente->getEmail().getValor();
    bool sucesso = CentralContainers::getContainerHoteis().incluir(hotel, email_gerente);

    if (sucesso)
    {
        Utilidades::mostrarSucesso("Hotel criado com sucesso!");
    }
    else
    {
        Utilidades::mostrarErro("Nao foi possivel criar o hotel.");
        Utilidades::mostrarMensagem("O codigo informado ja esta cadastrado.");
        delete hotel; // Libera memória
    }

    Utilidades::pausar();
}

void MenuHoteis::editarHotel(Gerente* gerente)
{
    vector<Hotel*> hoteis = listarHoteis(gerente);
    
    if (hoteis.empty())
    {
        Utilidades::mostrarErro("Voce nao possui hoteis cadastrados.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("EDITAR HOTEL");
    
    cout << endl;
    cout << "Selecione o hotel que deseja editar:" << endl;
    exibirListaHoteis(hoteis);
    
    Hotel* hotel = selecionarHotel(hoteis);
    
    if (hotel == nullptr)
    {
        Utilidades::mostrarMensagem("Operacao cancelada.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("EDITAR HOTEL: " + hotel->getNome().getValor());
    
    cout << endl;
    cout << "ATENCAO: O codigo do hotel NAO pode ser alterado (chave primaria)." << endl;
    cout << endl;

    AtualizarHotel atualizador;
    bool sucesso = atualizador.atualizar_hotel(hotel);

    if (sucesso)
    {
        Utilidades::mostrarSucesso("Hotel atualizado com sucesso!");
    }
    else
    {
        Utilidades::mostrarErro("Erro ao atualizar hotel.");
    }

    Utilidades::pausar();
}

void MenuHoteis::excluirHotel(Gerente* gerente)
{
    vector<Hotel*> hoteis = listarHoteis(gerente);
    
    if (hoteis.empty())
    {
        Utilidades::mostrarErro("Voce nao possui hoteis cadastrados.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("EXCLUIR HOTEL");
    
    cout << endl;
    cout << "Selecione o hotel que deseja excluir:" << endl;
    exibirListaHoteis(hoteis);
    
    Hotel* hotel = selecionarHotel(hoteis);
    
    if (hotel == nullptr)
    {
        Utilidades::mostrarMensagem("Operacao cancelada.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("EXCLUIR HOTEL: " + hotel->getNome().getValor());
    
    cout << endl;
    Utilidades::mostrarLinha('!', 60);
    cout << "ATENCAO: Esta acao e IRREVERSIVEL!" << endl;
    cout << "Todos os quartos e reservas deste hotel serao excluidos!" << endl;
    Utilidades::mostrarLinha('!', 60);
    cout << endl;

    if (!Utilidades::confirmar("Tem certeza que deseja excluir este hotel?"))
    {
        Utilidades::mostrarMensagem("Operacao cancelada.");
        Utilidades::pausar();
        return;
    }

    bool sucesso = RemoverHotel::remover_hotel(hotel);

    if (sucesso)
    {
        Utilidades::mostrarSucesso("Hotel excluido com sucesso!");
        delete hotel; // Libera memória
    }
    else
    {
        Utilidades::mostrarErro("Erro ao excluir hotel.");
    }

    Utilidades::pausar();
}

Hotel* MenuHoteis::selecionarHotel(vector<Hotel*> hoteis)
{
    if (hoteis.empty())
    {
        return nullptr;
    }

    cout << endl;
    cout << "Digite o numero do hotel (ou 0 para cancelar): ";
    
    int opcao = Utilidades::lerOpcao(0, hoteis.size());
    
    if (opcao == 0)
    {
        return nullptr;
    }
    
    return hoteis[opcao - 1];
}
