#ifndef CENTRAL_CONTAINERS_HPP_INCLUDED
#define CENTRAL_CONTAINERS_HPP_INCLUDED

#include "CONTAINERS.hpp"

using namespace std;

class CentralContainers
{
private:
    static ContainerReserva containerReservas;
    static ContainerHospede containerHospedes;
    static ContainerHotel containerHoteis;
    static ContainerGerente containerGerentes;
    static ContainerQuarto containerQuartos;
public:
    static ContainerReserva &getContainerReservas();
    static ContainerHospede &getContainerHospedes();
    static ContainerHotel &getContainerHoteis();
    static ContainerGerente &getContainerGerentes();
    static ContainerQuarto &getContainerQuartos();
};

inline ContainerReserva &CentralContainers::getContainerReservas()
{
    return containerReservas;
}

inline ContainerHospede &CentralContainers::getContainerHospedes()
{
    return containerHospedes;
}

inline ContainerHotel &CentralContainers::getContainerHoteis()
{
    return containerHoteis;
}

inline ContainerGerente &CentralContainers::getContainerGerentes()
{
    return containerGerentes;
}

inline ContainerQuarto &CentralContainers::getContainerQuartos()
{
    return containerQuartos;
}

#endif
