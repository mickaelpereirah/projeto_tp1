#include <iostream>
#include <stdexcept>

#include "cadastroReserva.hpp"

using namespace std;


Data CadastroReserva::criar_data_inicial()
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

Data CadastroReserva::criar_data_final()
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

bool CadastroReserva::validar_datas(const Data &inicial, const Data &final)
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

Reserva *CadastroReserva::criar_reserva()
{
    Reserva *r = new Reserva();

    cout << "CRIAR RESERVA" << endl;
    Data inicial = criar_data_inicial();
    Data final;
    while (true)
    {
        final = criar_data_final();
        bool datas_corretas = validar_datas(inicial, final);
        if (datas_corretas)
        {
            break;
        }
        else
        {
            cout << "Erro: A data de partida deve ser posterior à data de chegada." << endl;
        }
    }
    Dinheiro valor = criar_dinheiro();
    Codigo codigo = criar_codigo();

    r->setChegada(inicial);
    r->setPartida(final);
    r->setDinheiro(valor);
    r->setCodigo(codigo);

    return r;
}

bool CadastroReserva::nova_reserva()
{
    Reserva *reserva = criar_reserva();
    
    // Solicitar número do quarto
    cout << "Digite o número do quarto: ";
    Numero numero_obj = criar_numero();
    int numero_quarto = numero_obj.getValor();
    
    // Solicitar email do hóspede
    cout << "Digite o email do hóspede: ";
    Email email_hospede_obj = criar_email();
    string email_hospede = email_hospede_obj.getValor();
    
    return CentralContainers::getContainerReservas().incluir(reserva, numero_quarto, email_hospede);
}