#ifndef CENTRAL_CONTAINERS_HPP_INCLUDED
#define CENTRAL_CONTAINERS_HPP_INCLUDED

#include "CONTAINERS.hpp"

using namespace std;

class CentralContainers
{
private:
    static ContainerReserva containerReserva;
    static ContainerHospede containerHospede;
    static ContainerHotel containerHoteis;
    static ContainerGerente containerGerentes;
    static ContainerQuarto containerQuartos;
public:
    static ContainerReserva &getContainerReserva();
    static ContainerHospede &getContainerHospede();
    static ContainerHotel &getContainerHoteis();
    static ContainerGerente &getContainerGerentes();
    static ContainerQuarto &getContainerQuartos();
};

inline ContainerReserva &CentralContainers::getContainerReserva()
{
    return containerReserva;
}

inline ContainerHospede &CentralContainers::getContainerHospede()
{
    return containerHospede;
}

inline ContainerHotei &CentralContainers::getContainerHoteis()
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