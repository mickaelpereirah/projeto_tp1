#include "MenuReservas.hpp"
#include "Utilidades.hpp"
#include "cadastroReserva.hpp"
#include "atualizarReserva.hpp"
#include "removerReserva.hpp"
#include "listarReserva.hpp"
#include "listarQuarto.hpp"
#include "listarHospede.hpp"
#include "validarReserva.hpp"
#include <iostream>

using namespace std;

void MenuReservas::exibir(Hotel* hotel)
{
    int opcao;
    bool voltar = false;

    while (!voltar)
    {
        Utilidades::limparTela();
        Utilidades::mostrarCabecalho("GERENCIAR RESERVAS - " + hotel->getNome().getValor());
        
        vector<Reserva*> reservas = listarReservas(hotel);
        cout << endl;
        cout << "Total de reservas cadastradas: " << reservas.size() << endl;
        
        cout << endl;
        cout << "1. Listar reservas" << endl;
        cout << "2. Ver detalhes de uma reserva" << endl;
        cout << "3. Criar nova reserva" << endl;
        cout << "4. Editar reserva" << endl;
        cout << "5. Excluir reserva" << endl;
        cout << "6. Voltar" << endl;

        opcao = Utilidades::lerOpcao(1, 6);

        switch (opcao)
        {
            case 1:
                listarReservasMenu(hotel);
                break;
            case 2:
                verDetalhesReserva(hotel);
                break;
            case 3:
                criarReserva(hotel);
                break;
            case 4:
                editarReserva(hotel);
                break;
            case 5:
                excluirReserva(hotel);
                break;
            case 6:
                voltar = true;
                break;
        }
    }
}

vector<Reserva*> MenuReservas::listarReservas(Hotel* hotel)
{
    // Obter todos os quartos do hotel
    vector<Quarto*> quartos = ListarQuarto::listar_quartos(hotel);
    vector<Reserva*> todasReservas;
    
    // Para cada quarto, obter suas reservas
    for (Quarto* quarto : quartos)
    {
        vector<Reserva*> reservasQuarto = ListarReserva::listar_reservas_por_quarto(quarto);
        todasReservas.insert(todasReservas.end(), reservasQuarto.begin(), reservasQuarto.end());
    }
    
    return todasReservas;
}

void MenuReservas::exibirListaReservas(vector<Reserva*> reservas, Hotel* hotel)
{
    cout << endl;
    Utilidades::mostrarLinha('-', 80);
    for (size_t i = 0; i < reservas.size(); i++)
    {
        Reserva* r = reservas[i];
        cout << "  [" << (i + 1) << "] Reserva " << r->getCodigo().getValor() << endl;
        cout << "      Chegada: " << r->getChegada().getValor() << endl;
        cout << "      Partida: " << r->getPartida().getValor() << endl;
        cout << "      Valor: R$ " << r->getDinheiro().getValor() << endl;
        
        // Tentar encontrar o quarto e hóspede da reserva
        int numeroQuarto = obterNumeroQuartoReserva(r, hotel);
        string emailHospede = obterEmailHospedeReserva(r, hotel);
        
        if (numeroQuarto != -1)
        {
            cout << "      Quarto: " << numeroQuarto << endl;
        }
        
        if (!emailHospede.empty())
        {
            cout << "      Hospede: " << emailHospede << endl;
        }
        
        if (i < reservas.size() - 1)
        {
            cout << endl;
        }
    }
    Utilidades::mostrarLinha('-', 80);
}

void MenuReservas::listarReservasMenu(Hotel* hotel)
{
    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("RESERVAS - " + hotel->getNome().getValor());
    
    vector<Reserva*> reservas = listarReservas(hotel);
    
    if (reservas.empty())
    {
        cout << endl;
        Utilidades::mostrarMensagem("Este hotel ainda nao possui reservas cadastradas.");
    }
    else
    {
        cout << endl;
        cout << "Total: " << reservas.size() << " reserva(s)" << endl;
        exibirListaReservas(reservas, hotel);
    }

    Utilidades::pausar();
}

void MenuReservas::verDetalhesReserva(Hotel* hotel)
{
    vector<Reserva*> reservas = listarReservas(hotel);
    
    if (reservas.empty())
    {
        Utilidades::mostrarErro("Este hotel nao possui reservas cadastradas.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("VER DETALHES DA RESERVA");
    
    cout << endl;
    cout << "Selecione a reserva:" << endl;
    exibirListaReservas(reservas, hotel);
    
    Reserva* reserva = selecionarReserva(reservas);
    
    if (reserva == nullptr)
    {
        Utilidades::mostrarMensagem("Operacao cancelada.");
        Utilidades::pausar();
        return;
    }

    mostrarDetalhesReserva(reserva, hotel);
    Utilidades::pausar();
}

void MenuReservas::mostrarDetalhesReserva(Reserva* reserva, Hotel* hotel)
{
    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("DETALHES DA RESERVA");
    
    cout << endl;
    Utilidades::mostrarLinha('=', 80);
    cout << "Codigo:     " << reserva->getCodigo().getValor() << endl;
    cout << "Chegada:    " << reserva->getChegada().getValor() << endl;
    cout << "Partida:    " << reserva->getPartida().getValor() << endl;
    cout << "Valor:      R$ " << reserva->getDinheiro().getValor() << endl;
    
    Utilidades::mostrarLinha('-', 80);
    
    // Obter informações do quarto
    int numeroQuarto = obterNumeroQuartoReserva(reserva, hotel);
    if (numeroQuarto != -1)
    {
        cout << "Quarto numero: " << numeroQuarto << endl;
        
        // Buscar detalhes do quarto
        vector<Quarto*> quartos = ListarQuarto::listar_quartos(hotel);
        for (Quarto* q : quartos)
        {
            if (q->getNumero().getValor() == numeroQuarto)
            {
                cout << "Capacidade: " << q->getCapacidade().getValor() << " pessoa(s)" << endl;
                cout << "Diaria: R$ " << q->getDinheiro().getValor() << endl;
                cout << "Ramal: " << q->getRamal().getValor() << endl;
                break;
            }
        }
    }
    
    Utilidades::mostrarLinha('-', 80);
    
    // Obter informações do hóspede
    string emailHospede = obterEmailHospedeReserva(reserva, hotel);
    if (!emailHospede.empty())
    {
        cout << "Hospede (email): " << emailHospede << endl;
        
        // Buscar detalhes do hóspede
        vector<Hospede*> hospedes = ListarHospede::listar_hospedes(hotel);
        for (Hospede* h : hospedes)
        {
            if (h->getEmail().getValor() == emailHospede)
            {
                cout << "Nome: " << h->getNome().getValor() << endl;
                cout << "Endereco: " << h->getEndereco().getValor() << endl;
                break;
            }
        }
    }
    
    Utilidades::mostrarLinha('=', 80);
}

void MenuReservas::criarReserva(Hotel* hotel)
{
    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("CRIAR NOVA RESERVA");
    
    cout << endl;
    cout << "Hotel: " << hotel->getNome().getValor() << endl;
    cout << endl;
    
    // Verificar se há quartos cadastrados
    vector<Quarto*> quartos = ListarQuarto::listar_quartos(hotel);
    if (quartos.empty())
    {
        Utilidades::mostrarErro("Este hotel nao possui quartos cadastrados.");
        Utilidades::mostrarMensagem("Cadastre um quarto primeiro em 'Gerenciar quartos'.");
        Utilidades::pausar();
        return;
    }
    
    // Verificar se há hóspedes cadastrados
    vector<Hospede*> hospedes = ListarHospede::listar_hospedes(hotel);
    if (hospedes.empty())
    {
        Utilidades::mostrarErro("Este hotel nao possui hospedes cadastrados.");
        Utilidades::mostrarMensagem("Cadastre um hospede primeiro em 'Gerenciar hospedes'.");
        Utilidades::pausar();
        return;
    }
    
    // Mostrar quartos disponíveis
    cout << "QUARTOS DISPONIVEIS:" << endl;
    Utilidades::mostrarLinha('-', 60);
    for (Quarto* q : quartos)
    {
        cout << "  Quarto " << q->getNumero().getValor();
        cout << " - Capacidade: " << q->getCapacidade().getValor();
        cout << " - Diaria: R$ " << q->getDinheiro().getValor() << endl;
    }
    Utilidades::mostrarLinha('-', 60);
    cout << endl;
    
    // Mostrar hóspedes disponíveis
    cout << "HOSPEDES CADASTRADOS:" << endl;
    Utilidades::mostrarLinha('-', 60);
    for (Hospede* h : hospedes)
    {
        cout << "  " << h->getNome().getValor();
        cout << " - " << h->getEmail().getValor() << endl;
    }
    Utilidades::mostrarLinha('-', 60);
    cout << endl;
    
    cout << "Preencha os dados da nova reserva:" << endl;
    cout << endl;

    // Solicitar dados da reserva
    cout << "Digite o numero do quarto: ";
    Numero numero_obj;
    string numero_str = Utilidades::lerString("");
    try
    {
        numero_obj.setValor(stoi(numero_str));
    }
    catch (...)
    {
        Utilidades::mostrarErro("Numero de quarto invalido.");
        Utilidades::pausar();
        return;
    }
    int numero_quarto = numero_obj.getValor();
    
    // Verificar se o quarto existe neste hotel
    bool quartoExiste = false;
    Quarto* quartoSelecionado = nullptr;
    for (Quarto* q : quartos)
    {
        if (q->getNumero().getValor() == numero_quarto)
        {
            quartoExiste = true;
            quartoSelecionado = q;
            break;
        }
    }
    
    if (!quartoExiste)
    {
        Utilidades::mostrarErro("Este quarto nao existe neste hotel.");
        Utilidades::pausar();
        return;
    }
    
    cout << "Digite o email do hospede: ";
    Email email_obj;
    string email_str = Utilidades::lerString("");
    try
    {
        email_obj.setValor(email_str);
    }
    catch (...)
    {
        Utilidades::mostrarErro("Email invalido.");
        Utilidades::pausar();
        return;
    }
    string email_hospede = email_obj.getValor();
    
    // Verificar se o hóspede existe neste hotel
    bool hospedeExiste = false;
    for (Hospede* h : hospedes)
    {
        if (h->getEmail().getValor() == email_hospede)
        {
            hospedeExiste = true;
            break;
        }
    }
    
    if (!hospedeExiste)
    {
        Utilidades::mostrarErro("Este hospede nao esta cadastrado neste hotel.");
        Utilidades::pausar();
        return;
    }
    
    // Solicitar datas
    cout << "Digite a data de chegada (formato: DD-MMM-AAAA, ex: 15-JAN-2024): ";
    Data chegada;
    string chegada_str = Utilidades::lerString("");
    try
    {
        chegada.setValor(chegada_str);
    }
    catch (...)
    {
        Utilidades::mostrarErro("Data de chegada invalida.");
        Utilidades::pausar();
        return;
    }
    
    cout << "Digite a data de partida (formato: DD-MMM-AAAA, ex: 20-JAN-2024): ";
    Data partida;
    string partida_str = Utilidades::lerString("");
    try
    {
        partida.setValor(partida_str);
    }
    catch (...)
    {
        Utilidades::mostrarErro("Data de partida invalida.");
        Utilidades::pausar();
        return;
    }
    
    // Validar que partida é posterior a chegada
    if (ValidarReserva::compararDatas(chegada, partida) >= 0)
    {
        Utilidades::mostrarErro("A data de partida deve ser posterior a data de chegada.");
        Utilidades::pausar();
        return;
    }
    
    // Verificar disponibilidade do quarto
    if (!ValidarReserva::verificarDisponibilidade(numero_quarto, chegada, partida, ""))
    {
        Utilidades::mostrarErro("O quarto ja esta reservado neste periodo.");
        Utilidades::pausar();
        return;
    }
    
    // Calcular valor total
    double valorTotal = ValidarReserva::calcularValorTotal(quartoSelecionado, chegada, partida);
    Dinheiro valor;
    valor.setValor(valorTotal);
    
    // Gerar código único
    cout << "Digite o codigo da reserva (10 caracteres alfanumericos): ";
    Codigo codigo;
    string codigo_str = Utilidades::lerString("");
    try
    {
        codigo.setValor(codigo_str);
    }
    catch (...)
    {
        Utilidades::mostrarErro("Codigo invalido. Deve conter exatamente 10 caracteres alfanumericos.");
        Utilidades::pausar();
        return;
    }
    
    // Verificar se o código já existe
    if (CentralContainers::getContainerReservas().pesquisar(codigo.getValor()) != nullptr)
    {
        Utilidades::mostrarErro("Este codigo ja esta em uso. Escolha outro codigo.");
        Utilidades::pausar();
        return;
    }
    
    // Criar a reserva
    Reserva* reserva = new Reserva();
    reserva->setChegada(chegada);
    reserva->setPartida(partida);
    reserva->setDinheiro(valor);
    reserva->setCodigo(codigo);
    
    bool sucesso = CentralContainers::getContainerReservas().incluir(reserva, numero_quarto, email_hospede);

    if (sucesso)
    {
        Utilidades::mostrarSucesso("Reserva criada com sucesso!");
        cout << endl;
        cout << "Valor total calculado: R$ " << valorTotal << endl;
    }
    else
    {
        Utilidades::mostrarErro("Nao foi possivel criar a reserva.");
        delete reserva;
    }

    Utilidades::pausar();
}

void MenuReservas::editarReserva(Hotel* hotel)
{
    vector<Reserva*> reservas = listarReservas(hotel);
    
    if (reservas.empty())
    {
        Utilidades::mostrarErro("Este hotel nao possui reservas cadastradas.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("EDITAR RESERVA");
    
    cout << endl;
    cout << "Selecione a reserva que deseja editar:" << endl;
    exibirListaReservas(reservas, hotel);
    
    Reserva* reserva = selecionarReserva(reservas);
    
    if (reserva == nullptr)
    {
        Utilidades::mostrarMensagem("Operacao cancelada.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("EDITAR RESERVA " + reserva->getCodigo().getValor());
    
    cout << endl;
    cout << "ATENCAO: O codigo da reserva NAO pode ser alterado." << endl;
    cout << "O quarto e o hospede da reserva tambem NAO podem ser alterados." << endl;
    cout << "Voce pode alterar apenas as datas de chegada e partida." << endl;
    cout << endl;
    
    // Obter número do quarto desta reserva
    int numeroQuarto = obterNumeroQuartoReserva(reserva, hotel);
    if (numeroQuarto == -1)
    {
        Utilidades::mostrarErro("Nao foi possivel identificar o quarto desta reserva.");
        Utilidades::pausar();
        return;
    }

    AtualizarReserva atualizador;
    bool sucesso = atualizador.atualizar_reserva(reserva, numeroQuarto);

    if (sucesso)
    {
        Utilidades::mostrarSucesso("Reserva atualizada com sucesso!");
    }
    else
    {
        Utilidades::mostrarErro("Erro ao atualizar reserva.");
    }

    Utilidades::pausar();
}

void MenuReservas::excluirReserva(Hotel* hotel)
{
    vector<Reserva*> reservas = listarReservas(hotel);
    
    if (reservas.empty())
    {
        Utilidades::mostrarErro("Este hotel nao possui reservas cadastradas.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("EXCLUIR RESERVA");
    
    cout << endl;
    cout << "Selecione a reserva que deseja excluir:" << endl;
    exibirListaReservas(reservas, hotel);
    
    Reserva* reserva = selecionarReserva(reservas);
    
    if (reserva == nullptr)
    {
        Utilidades::mostrarMensagem("Operacao cancelada.");
        Utilidades::pausar();
        return;
    }

    Utilidades::limparTela();
    Utilidades::mostrarCabecalho("EXCLUIR RESERVA " + reserva->getCodigo().getValor());
    
    cout << endl;
    Utilidades::mostrarLinha('!', 80);
    cout << "ATENCAO: Esta acao e IRREVERSIVEL!" << endl;
    Utilidades::mostrarLinha('!', 80);
    cout << endl;

    if (!Utilidades::confirmar("Tem certeza que deseja excluir esta reserva?"))
    {
        Utilidades::mostrarMensagem("Operacao cancelada.");
        Utilidades::pausar();
        return;
    }

    bool sucesso = RemoverReserva::remover_reserva(reserva);

    if (sucesso)
    {
        Utilidades::mostrarSucesso("Reserva excluida com sucesso!");
        delete reserva;
    }
    else
    {
        Utilidades::mostrarErro("Erro ao excluir reserva.");
    }

    Utilidades::pausar();
}

Reserva* MenuReservas::selecionarReserva(vector<Reserva*> reservas)
{
    if (reservas.empty())
    {
        return nullptr;
    }

    cout << endl;
    cout << "Digite o numero da reserva (ou 0 para cancelar): ";
    
    int opcao = Utilidades::lerOpcao(0, reservas.size());
    
    if (opcao == 0)
    {
        return nullptr;
    }
    
    return reservas[opcao - 1];
}

int MenuReservas::obterNumeroQuartoReserva(Reserva* reserva, Hotel* hotel)
{
    // Buscar em todos os quartos do hotel
    vector<Quarto*> quartos = ListarQuarto::listar_quartos(hotel);
    string codigoReserva = reserva->getCodigo().getValor();
    
    for (Quarto* quarto : quartos)
    {
        vector<Reserva*> reservasQuarto = ListarReserva::listar_reservas_por_quarto(quarto);
        for (Reserva* r : reservasQuarto)
        {
            if (r->getCodigo().getValor() == codigoReserva)
            {
                return quarto->getNumero().getValor();
            }
        }
    }
    
    return -1; // Não encontrou
}

string MenuReservas::obterEmailHospedeReserva(Reserva* reserva, Hotel* hotel)
{
    // Buscar em todos os hóspedes do hotel
    vector<Hospede*> hospedes = ListarHospede::listar_hospedes(hotel);
    string codigoReserva = reserva->getCodigo().getValor();
    
    for (Hospede* hospede : hospedes)
    {
        vector<Reserva*> reservasHospede = ListarReserva::listar_reservas_por_hospede(hospede);
        for (Reserva* r : reservasHospede)
        {
            if (r->getCodigo().getValor() == codigoReserva)
            {
                return hospede->getEmail().getValor();
            }
        }
    }
    
    return ""; // Não encontrou
}
