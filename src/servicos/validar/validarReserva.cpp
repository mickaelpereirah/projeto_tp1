#include "validar/validarReserva.hpp"
#include <iostream>

using namespace std;

bool ValidarReserva::verificarDisponibilidade(int numero_quarto, Data chegada, Data partida, string codigo_reserva_atual)
{
    // Buscar todas as reservas do quarto
    vector<Reserva*> reservas = CentralContainers::getContainerReservas().pesquisarPorQuarto(numero_quarto);

    // Verificar conflito com cada reserva existente
    for (Reserva* reserva_existente : reservas)
    {
        // Se estamos editando uma reserva, ignorar ela mesma na verificação
        if (!codigo_reserva_atual.empty() && reserva_existente->getCodigo().getValor() == codigo_reserva_atual)
        {
            continue;
        }

        // Verificar se há conflito de datas
        if (temConflitoData(chegada, partida, reserva_existente->getChegada(), reserva_existente->getPartida()))
        {
            return false; // Há conflito
        }
    }

    return true; // Não há conflito
}

double ValidarReserva::calcularValorTotal(Quarto* quarto, Data chegada, Data partida)
{
    if (quarto == nullptr)
    {
        return 0.0;
    }

    int numDias = calcularNumeroDias(chegada, partida);
    double valorDiaria = quarto->getDinheiro().getValor();

    return numDias * valorDiaria;
}

int ValidarReserva::calcularNumeroDias(Data chegada, Data partida)
{
    // Converter mês de string para número
    auto converter_mes = [](const string &mes) -> int
    {
        if (mes == "JAN") return 1;
        if (mes == "FEV") return 2;
        if (mes == "MAR") return 3;
        if (mes == "ABR") return 4;
        if (mes == "MAI") return 5;
        if (mes == "JUN") return 6;
        if (mes == "JUL") return 7;
        if (mes == "AGO") return 8;
        if (mes == "SET") return 9;
        if (mes == "OUT") return 10;
        if (mes == "NOV") return 11;
        if (mes == "DEZ") return 12;
        return 0;
    };

    // Calcular dias (aproximação simples: 30 dias por mês)
    string data_chegada = chegada.getValor();
    string data_partida = partida.getValor();

    int dia_chegada = stoi(data_chegada.substr(0, 2));
    int mes_chegada = converter_mes(data_chegada.substr(3, 3));
    int ano_chegada = stoi(data_chegada.substr(7, 4));

    int dia_partida = stoi(data_partida.substr(0, 2));
    int mes_partida = converter_mes(data_partida.substr(3, 3));
    int ano_partida = stoi(data_partida.substr(7, 4));

    // Cálculo simplificado: converter tudo para dias
    int dias_chegada = ano_chegada * 360 + mes_chegada * 30 + dia_chegada;
    int dias_partida = ano_partida * 360 + mes_partida * 30 + dia_partida;

    return dias_partida - dias_chegada;
}

bool ValidarReserva::temConflitoData(Data chegada1, Data partida1, Data chegada2, Data partida2)
{
    // Uma reserva conflita com outra se:
    // - chegada1 está entre chegada2 e partida2, OU
    // - partida1 está entre chegada2 e partida2, OU
    // - chegada2 está entre chegada1 e partida1, OU
    // - partida2 está entre chegada1 e partida1

    int comp_chegada1_chegada2 = compararDatas(chegada1, chegada2);
    int comp_chegada1_partida2 = compararDatas(chegada1, partida2);
    int comp_partida1_chegada2 = compararDatas(partida1, chegada2);
    int comp_partida1_partida2 = compararDatas(partida1, partida2);

    // Caso 1: chegada1 está entre chegada2 e partida2
    if (comp_chegada1_chegada2 >= 0 && comp_chegada1_partida2 < 0)
    {
        return true;
    }

    // Caso 2: partida1 está entre chegada2 e partida2
    if (comp_partida1_chegada2 > 0 && comp_partida1_partida2 <= 0)
    {
        return true;
    }

    // Caso 3: reserva1 engloba completamente reserva2
    if (comp_chegada1_chegada2 <= 0 && comp_partida1_partida2 >= 0)
    {
        return true;
    }

    return false;
}

int ValidarReserva::compararDatas(Data data1, Data data2)
{
    // Converter mês de string para número
    auto converter_mes = [](const string &mes) -> int
    {
        if (mes == "JAN") return 1;
        if (mes == "FEV") return 2;
        if (mes == "MAR") return 3;
        if (mes == "ABR") return 4;
        if (mes == "MAI") return 5;
        if (mes == "JUN") return 6;
        if (mes == "JUL") return 7;
        if (mes == "AGO") return 8;
        if (mes == "SET") return 9;
        if (mes == "OUT") return 10;
        if (mes == "NOV") return 11;
        if (mes == "DEZ") return 12;
        return 0;
    };

    string str_data1 = data1.getValor();
    string str_data2 = data2.getValor();

    int dia1 = stoi(str_data1.substr(0, 2));
    int mes1 = converter_mes(str_data1.substr(3, 3));
    int ano1 = stoi(str_data1.substr(7, 4));

    int dia2 = stoi(str_data2.substr(0, 2));
    int mes2 = converter_mes(str_data2.substr(3, 3));
    int ano2 = stoi(str_data2.substr(7, 4));

    // Comparar
    if (ano1 < ano2) return -1;
    if (ano1 > ano2) return 1;

    if (mes1 < mes2) return -1;
    if (mes1 > mes2) return 1;

    if (dia1 < dia2) return -1;
    if (dia1 > dia2) return 1;

    return 0; // Datas iguais
}
