#include "MenuConta.hpp"
#include "Utilidades.hpp"
#include "atualizarGerente.hpp"
#include "removerGerente.hpp"
#include <iostream>

using namespace std;

bool MenuConta::exibir(Gerente* gerente)
{
    int opcao;
    bool voltar = false;
    bool contaExcluida = false;

    while (!voltar && !contaExcluida)
    {
        Utilidades::limparTela();
        Utilidades::mostrarCabecalho("GERENCIAR MINHA CONTA");
        
        cout << endl;
        cout << "1. Visualizar meus dados" << endl;
        cout << "2. Editar meus dados" << endl;
        cout << "3. Excluir minha conta" << endl;
        cout << "4. Voltar" << endl;

        opcao = Utilidades::lerOpcao(1, 4);

        switch (opcao)
        {
            case 1:
                visualizarDados(gerente);
                Utilidades::pausar();
                break;
            case 2:
                editarDados(gerente);
                break;
            case 3:
                contaExcluida = excluirConta(gerente);
                if (contaExcluida)
                {
                    Utilidades::pausar();
                }
                break;
            case 4:
                voltar = true;
                break;
        }
    }

    // Retorna true se a conta foi excluída (para forçar logout)
    return contaExcluida;
}

void MenuConta::visualizarDados(Gerente* gerente)
{
    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("MEUS DADOS");
    
    cout << endl;
    Utilidades::mostrarLinha('-', 60);
    cout << "Nome:   " << gerente->getNome().getValor() << endl;
    cout << "Email:  " << gerente->getEmail().getValor() << endl;
    cout << "Ramal:  " << gerente->getRamal().getValor() << endl;
    cout << "Senha:  " << string(gerente->getSenha().getValor().length(), '*') << " (oculta)" << endl;
    Utilidades::mostrarLinha('-', 60);
}

void MenuConta::editarDados(Gerente* gerente)
{
    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("EDITAR MEUS DADOS");
    
    cout << endl;
    cout << "ATENCAO: O email NAO pode ser alterado (chave primaria)." << endl;
    cout << endl;

    AtualizarGerente atualizador;
    bool sucesso = atualizador.atualizar_gerente(gerente);

    if (sucesso)
    {
        Utilidades::mostrarSucesso("Dados atualizados com sucesso!");
    }
    else
    {
        Utilidades::mostrarErro("Erro ao atualizar dados.");
    }

    Utilidades::pausar();
}

bool MenuConta::excluirConta(Gerente* gerente)
{
    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("EXCLUIR MINHA CONTA");
    
    cout << endl;
    Utilidades::mostrarLinha('!', 60);
    cout << "ATENCAO: Esta acao e IRREVERSIVEL!" << endl;
    cout << "Todos os seus hoteis, quartos e reservas serao excluidos!" << endl;
    Utilidades::mostrarLinha('!', 60);
    cout << endl;

    if (!Utilidades::confirmar("Tem certeza que deseja excluir sua conta?"))
    {
        Utilidades::mostrarMensagem("Operacao cancelada.");
        return false;
    }

    // Executar remoção
    bool sucesso = RemoverGerente::remover_gerente(gerente);

    if (sucesso)
    {
        Utilidades::mostrarSucesso("Conta excluida com sucesso!");
        Utilidades::mostrarMensagem("Voce sera desconectado do sistema.");
        return true;
    }
    else
    {
        Utilidades::mostrarErro("Erro ao excluir conta.");
        return false;
    }
}
