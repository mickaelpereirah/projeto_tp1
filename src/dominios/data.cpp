#include "data.hpp"
#include <string>
#include <regex>
#include <algorithm> // transform
#include <cctype>    // toupper
#include <cstdlib>   // stoi
#include <stdexcept>

using namespace std;

bool validarData(const string data)
{
    regex padrao(R"(^\d{2}-[A-Za-z]{3}-\d{4}$)");
    return regex_match(data, padrao);
}

bool bissexto(int ano)
{
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

bool validar_ano(string ano_str)
{
    int ano = stoi(ano_str);
    return (ano >= 2000 && ano <= 2999);
}

bool validar_mes(string mes)
{
    transform(mes.begin(), mes.end(), mes.begin(), ::toupper);
    string meses_validos[] = {"JAN", "FEV", "MAR", "ABR", "MAI", "JUN",
                              "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"};

    for (auto &m : meses_validos)
    {
        if (mes == m)
            return true;
    }
    return false;
}

bool validar_dia(string dia_str, string mes, int ano)
{
    int dia = stoi(dia_str);
    transform(mes.begin(), mes.end(), mes.begin(), ::toupper);

    int max_dias = 31;

    if (mes == "ABR" || mes == "JUN" || mes == "SET" || mes == "NOV")
        max_dias = 30;
    else if (mes == "FEV")
        max_dias = bissexto(ano) ? 29 : 28;

    return (dia >= 1 && dia <= max_dias);
}

bool Data::validar(string data)
{
    if (!validarData(data))
    {
        return false; // formato inválido
    }

    // separa partes: DD-MMM-YYYY
    string dia = data.substr(0, 2);
    string mes = data.substr(3, 3);
    string ano = data.substr(7, 4);

    // valida partes individualmente
    if (!validar_ano(ano))
        return false;

    if (!validar_mes(mes))
        return false;

    if (!validar_dia(dia, mes, stoi(ano)))
        return false;

    return true;
}

void Data::setValor(string data) {
    if (!validar(data)) {
        throw invalid_argument("Data invalida");
    }
    this->data = data;
}
