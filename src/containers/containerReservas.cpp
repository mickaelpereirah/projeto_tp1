#include "containerReservas.hpp"
#include <iostream>

using namespace std;

bool ContainerReserva::incluir(Reserva *reserva, int numero_quarto, string email_hospede)
{
    // Verificar se a reserva já existe (por código)
    string codigo_reserva = reserva->getCodigo().getValor();
    Reserva *reserva_encontrada = pesquisar(codigo_reserva);

    if (reserva_encontrada != nullptr)
    {
        return false;  // Reserva já existe
    }

    // Adicionar ao vector do quarto e hóspede
    container[numero_quarto][email_hospede].push_back(reserva);
    return true;
}

bool ContainerReserva::remover(string codigo)
{
    // Iterar sobre todos os quartos e hóspedes para encontrar a reserva
    for (auto& quarto_pair : container)
    {
        for (auto& hospede_pair : quarto_pair.second)
        {
            vector<Reserva*>& reservas = hospede_pair.second;
            for (auto it = reservas.begin(); it != reservas.end(); ++it)
            {
                if ((*it)->getCodigo().getValor() == codigo)
                {
                    reservas.erase(it);
                    return true;
                }
            }
        }
    }
    return false;
}

Reserva* ContainerReserva::pesquisar(string codigo)
{
    // Iterar sobre todos os quartos e hóspedes para encontrar a reserva
    for (auto& quarto_pair : container)
    {
        for (auto& hospede_pair : quarto_pair.second)
        {
            vector<Reserva*>& reservas = hospede_pair.second;
            for (Reserva* reserva : reservas)
            {
                if (reserva->getCodigo().getValor() == codigo)
                {
                    return reserva;
                }
            }
        }
    }
    return nullptr;
}

vector<Reserva*> ContainerReserva::pesquisar(int numero_quarto, string email_hospede)
{
    if (container.count(numero_quarto) && container[numero_quarto].count(email_hospede))
    {
        return container[numero_quarto][email_hospede];
    }
    return vector<Reserva*>();  // Retorna vector vazio
}

vector<Reserva*> ContainerReserva::pesquisarPorQuarto(int numero_quarto)
{
    vector<Reserva*> resultado;
    
    if (container.count(numero_quarto))
    {
        // Iterar sobre todos os hóspedes deste quarto
        for (auto& hospede_pair : container[numero_quarto])
        {
            vector<Reserva*>& reservas = hospede_pair.second;
            resultado.insert(resultado.end(), reservas.begin(), reservas.end());
        }
    }
    
    return resultado;
}

vector<Reserva*> ContainerReserva::pesquisarPorHospede(string email)
{
    vector<Reserva*> resultado;
    
    // Iterar sobre todos os quartos procurando o email do hóspede
    for (auto& quarto_pair : container)
    {
        if (quarto_pair.second.count(email))
        {
            vector<Reserva*>& reservas = quarto_pair.second[email];
            resultado.insert(resultado.end(), reservas.begin(), reservas.end());
        }
    }
    
    return resultado;
}

bool ContainerReserva::atualizar(Reserva *reserva_atualizada)
{
    string codigo_reserva = reserva_atualizada->getCodigo().getValor();
    
    // Encontrar e atualizar a reserva
    for (auto& quarto_pair : container)
    {
        for (auto& hospede_pair : quarto_pair.second)
        {
            vector<Reserva*>& reservas = hospede_pair.second;
            for (Reserva*& r : reservas)
            {
                if (r->getCodigo().getValor() == codigo_reserva)
                {
                    r = reserva_atualizada;  // Atualiza o ponteiro
                    return true;
                }
            }
        }
    }
    return false;
}