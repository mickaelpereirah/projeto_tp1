#ifndef RESERVA_HPP_INCLUDED
#define RESERVA_HPP_INCLUDED
#include "DOMINIOS.hpp"

class Reserva
{
private:
    Data chegada;
    Data partida;
    Dinheiro valor;
    Codigo codigo;

public:
    void setData(Data);
    Data getData();
    void setData(Data);
    Data getData();
    void setDinheiro(Dinheiro);
    Dinheiro getDinheiro();
    void setCodigo(Codigo);
    Codigo getCodigo();
};

inline void Reserva::setData(Data chegada)
{
    this->chegada = chegada;
}

inline Data Reserva::getData()
{
    return chegada;
}

inline void Reserva::setData(Data partida)
{
    this->partida = partida;
}

inline Data Reserva::getData()
{
    return partida;
}

inline void Reserva::setDinheiro(Dinheiro valor)
{
    this->valor = valor;
}

inline Dinheiro Reserva::getDinheiro()
{
    return valor;
}

inline void Reserva::setCodigo(Codigo codigo)
{
    this->codigo = codigo;
}

inline Codigo Reserva::getCodigo()
{
    return codigo;
}

#endif