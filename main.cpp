#include "MenuPrincipal.hpp"
#include "centralContainers.hpp"

/**
 * @file main.cpp
 * @brief Ponto de entrada da aplicação
 * 
 * Sistema de Gestão de Hotéis
 * Permite gerentes cadastrarem e gerenciarem hotéis, quartos, 
 * reservas e hóspedes através de uma interface de terminal.
 */

// Inicialização dos containers estáticos
ContainerReserva CentralContainers::containerReservas;
ContainerHospede CentralContainers::containerHospedes;
ContainerHotel CentralContainers::containerHoteis;
ContainerGerente CentralContainers::containerGerentes;
ContainerQuarto CentralContainers::containerQuartos;

int main()
{
    // Exibe o menu principal
    MenuPrincipal::exibir();
    
    return 0;
}
