#include <iostream>

#include "atualizarReserva.hpp"
#include "validar/validarReserva.hpp"
#include "listarQuarto.hpp"

using namespace std;

Data AtualizarReserva::atualizar_data_inicial()
{
    Data d;
    string inicial;
    while (true)
    {
        cout << "Digite a data de chegada: ";
        getline(cin, inicial);
        try
        {
            d.setValor(inicial);
            break;
        }
        catch (const invalid_argument &e)
        {
            cout << "[Data Invalida:" << inicial << "]" << endl;
            cout << "- Formato: dia-mes-ano (ex: 15-JAN-2024)" << endl;
        }
    }
    return d;
}

Data AtualizarReserva::atualizar_data_final()
{
    Data d;
    string final;
    while (true)
    {
        cout << "Digite a data de partida: ";
        getline(cin, final);
        try
        {
            d.setValor(final);
            break;
        }
        catch (const invalid_argument &e)
        {
            cout << "[Data Invalida:" << final << "]" << endl;
            cout << "- Formato: dia-mes-ano (ex: 20-JAN-2024)" << endl;
        }
    }
    return d;
}

bool AtualizarReserva::validar_datas(const Data &inicial, const Data &final)
{
    return ValidarReserva::compararDatas(inicial, final) < 0;
}

bool AtualizarReserva::validar_resposta()
{
    string resposta;
    while (true)
    {
        getline(cin, resposta);
        if (resposta == "sim")
        {
            return true;
        }
        else if (resposta == "nao")
        {
            return false;
        }
        else
        {
            cout << "Responda apenas 'sim' ou 'nao'." << endl;
        }
    }
}

Reserva *AtualizarReserva::modificar_reserva(Reserva *reserva, int numero_quarto)
{
    cout << "ATUALIZAR RESERVA" << endl;
    cout << endl;
    cout << "IMPORTANTE: O valor sera recalculado automaticamente" << endl;
    cout << "baseado no numero de dias e valor da diaria do quarto." << endl;
    cout << endl;

    Data nova_chegada = reserva->getChegada();
    Data nova_partida = reserva->getPartida();
    bool datas_alteradas = false;

    cout << "Deseja atualizar a data de chegada (sim / nao): ";
    if (validar_resposta())
    {
        nova_chegada = atualizar_data_inicial();
        datas_alteradas = true;
    }

    cout << "Deseja atualizar a data de partida (sim / nao): ";
    if (validar_resposta())
    {
        Data temp_partida = atualizar_data_final();

        // Validar que a data final é posterior à data inicial
        if (!validar_datas(nova_chegada, temp_partida))
        {
            cout << "Erro: A data de partida deve ser posterior à data de chegada." << endl;
            cout << "Data de partida nao foi alterada." << endl;
        }
        else
        {
            nova_partida = temp_partida;
            datas_alteradas = true;
        }
    }

    // Se as datas foram alteradas, verificar disponibilidade e recalcular valor
    if (datas_alteradas)
    {
        // Verificar conflito (ignorando a reserva atual)
        string codigo_atual = reserva->getCodigo().getValor();
        if (!ValidarReserva::verificarDisponibilidade(numero_quarto, nova_chegada, nova_partida, codigo_atual))
        {
            cout << endl;
            cout << "[ERRO] Conflito de reserva! O quarto ja esta reservado neste periodo." << endl;
            cout << "As datas NAO foram alteradas." << endl;
            return reserva;
        }

        // Buscar o quarto pelo número usando o container
        Quarto *quarto = CentralContainers::getContainerQuartos().pesquisarPorNumero(numero_quarto);

        if (quarto != nullptr)
        {
            // Recalcular valor usando o serviço ValidarReserva
            double novo_valor = ValidarReserva::calcularValorTotal(quarto, nova_chegada, nova_partida);
            Dinheiro dinheiro;
            dinheiro.setValor(novo_valor);

            // Atualizar a reserva com novos valores
            reserva->setChegada(nova_chegada);
            reserva->setPartida(nova_partida);
            reserva->setDinheiro(dinheiro);

            cout << endl;
            cout << "[INFO] Valor recalculado automaticamente: R$ " << novo_valor << endl;
        }
        else
        {
            cout << endl;
            cout << "[ERRO] Nao foi possivel encontrar o quarto para recalcular o valor." << endl;
            cout << "As datas NAO foram alteradas." << endl;
            return reserva;
        }
    }

    return reserva;
}

bool AtualizarReserva::atualizar_reserva(Reserva *reserva, int numero_quarto)
{
    modificar_reserva(reserva, numero_quarto);
    return CentralContainers::getContainerReservas().atualizar(reserva);
}
