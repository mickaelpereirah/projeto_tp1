#include <iostream>

#include "atualizarReserva.hpp"

using namespace std;

Data AtualizarReserva::atualizar_data_inicial()
{
    Data d;
    string inicial;
    while (true)
    {
        cout << "Digite a data inicial da reserva: ";
        getline(cin, inicial);
        try
        {
            d.setValor(inicial);
            break;
        }
        catch (const invalid_argument &e)
        {
            cout << "[Data Invalida:" << inicial << "]" << endl;
            cout << "- Formato: dia-mes-ano" << endl;
            cout << "- Dia deve ser um numero de 1 a 31" << endl;
            cout << "- Mes deve ser um dos seguintes: JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ" << endl;
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
        cout << "Digite a data final da reserva: ";
        getline(cin, final);
        try
        {
            d.setValor(final);
            break;
        }
        catch (const invalid_argument &e)
        {
            cout << "[Data Invalida:" << final << "]" << endl;
            cout << "- Formato: dia-mes-ano" << endl;
            cout << "- Dia deve ser um numero de 1 a 31" << endl;
            cout << "- Mes deve ser um dos seguintes: JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ" << endl;
        }
    }
    return d;
}

bool AtualizarReserva::validar_datas(const Data &inicial, const Data &final)
{
    string data_inicial = inicial.getValor();
    string data_final = final.getValor();

    // Extrair componentes da data inicial (formato: DD-MMM-YYYY)
    int dia_inicial = stoi(data_inicial.substr(0, 2));
    string mes_inicial = data_inicial.substr(3, 3);
    int ano_inicial = stoi(data_inicial.substr(7, 4));

    // Extrair componentes da data final
    int dia_final = stoi(data_final.substr(0, 2));
    string mes_final = data_final.substr(3, 3);
    int ano_final = stoi(data_final.substr(7, 4));

    // Converter mês de string para número
    auto converter_mes = [](const string &mes) -> int
    {
        if (mes == "JAN")
            return 1;
        if (mes == "FEV")
            return 2;
        if (mes == "MAR")
            return 3;
        if (mes == "ABR")
            return 4;
        if (mes == "MAI")
            return 5;
        if (mes == "JUN")
            return 6;
        if (mes == "JUL")
            return 7;
        if (mes == "AGO")
            return 8;
        if (mes == "SET")
            return 9;
        if (mes == "OUT")
            return 10;
        if (mes == "NOV")
            return 11;
        if (mes == "DEZ")
            return 12;
        return 0;
    };

    int num_mes_inicial = converter_mes(mes_inicial);
    int num_mes_final = converter_mes(mes_final);

    // Comparar datas
    if (ano_final > ano_inicial)
    {
        return true;
    }
    else if (ano_final < ano_inicial)
    {
        return false;
    }
    else
    { // anos iguais
        if (num_mes_final > num_mes_inicial)
        {
            return true;
        }
        else if (num_mes_final < num_mes_inicial)
        {
            return false;
        }
        else
        { // anos e meses iguais
            return dia_final > dia_inicial;
        }
    }
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

Reserva *AtualizarReserva::modificar_reserva(Reserva *reserva)
{
    cout << "ATUALIZAR RESERVA" << endl;

    cout << "Deseja atualizar a data de chegada (sim / nao): ";
    if (validar_resposta())
    {
        Data inicial = atualizar_data_inicial();
        reserva->setChegada(inicial);
    }
    cout << "Deseja atualizar a data de partida (sim / nao): ";
    if (validar_resposta())
    {
        Data final = atualizar_data_final();
        // Validar que a data final é posterior à data inicial
        bool datas_validas = validar_datas(reserva->getChegada(), final);
        if (datas_validas)
        {
            reserva->setPartida(final);
        }
        else
        {
            cout << "Erro: A data de partida deve ser posterior à data de chegada." << endl;
        }
    }
    cout << "Deseja atualizar o valor (sim / nao): ";
    if (validar_resposta())
    {
        Dinheiro dinheiro = criar_dinheiro();
        reserva->setDinheiro(dinheiro);
    }

    return reserva;
}

bool AtualizarReserva::atualizar_reserva(Reserva *reserva)
{
    modificar_reserva(reserva);
    return CentralContainers::getContainerReservas().atualizar(reserva);
}