/**
 * @file centralContainers.hpp
 * @brief Definição da classe CentralContainers
 */

#ifndef CENTRAL_CONTAINERS_HPP_INCLUDED
#define CENTRAL_CONTAINERS_HPP_INCLUDED

#include "CONTAINERS.hpp"

using namespace std;

/**
 * @class CentralContainers
 * @brief Classe central para gerenciar todos os containers do sistema
 * 
 * Esta classe implementa o padrão Singleton para fornecer acesso centralizado
 * a todos os containers de armazenamento de dados do sistema. Cada container
 * gerencia uma entidade específica do domínio (Reservas, Hóspedes, Hotéis, etc.).
 * 
 * Os containers são estáticos e únicos durante toda a execução do programa,
 * garantindo que todos os módulos acessem a mesma instância de dados.
 * 
 * Arquitetura:
 * - Camada de Serviço: acessa containers através desta classe
 * - Camada de Apresentação: NÃO acessa diretamente, usa serviços
 * - Armazenamento: em memória (RAM) durante execução do programa
 * 
 * Responsabilidades:
 * - Fornecer acesso único aos containers
 * - Garantir inicialização correta dos containers
 * - Manter singleton dos containers durante execução
 * 
 * IMPORTANTE: Os dados são perdidos quando o programa é encerrado.
 * Não há persistência em banco de dados ou arquivo.
 */
class CentralContainers
{
private:
    /**
     * @brief Container de reservas (singleton)
     * 
     * Armazena todas as reservas do sistema organizadas por quarto e hóspede.
     */
    static ContainerReserva containerReservas;
    
    /**
     * @brief Container de hóspedes (singleton)
     * 
     * Armazena todos os hóspedes cadastrados no sistema, indexados por email.
     */
    static ContainerHospede containerHospedes;
    
    /**
     * @brief Container de hotéis (singleton)
     * 
     * Armazena todos os hotéis do sistema, organizados por gerente proprietário.
     */
    static ContainerHotel containerHoteis;
    
    /**
     * @brief Container de gerentes (singleton)
     * 
     * Armazena todos os gerentes cadastrados no sistema, indexados por email.
     */
    static ContainerGerente containerGerentes;
    
    /**
     * @brief Container de quartos (singleton)
     * 
     * Armazena todos os quartos do sistema, organizados por hotel.
     */
    static ContainerQuarto containerQuartos;
    
public:
    /**
     * @brief Obtém referência para o container de reservas
     * @return Referência para ContainerReserva
     * 
     * Usado pelos serviços de reserva (cadastro, listagem, atualização, remoção)
     * 
     * Exemplo de uso:
     * @code
     * ContainerReserva& container = CentralContainers::getContainerReservas();
     * Reserva* r = container.pesquisar("ABC1234567");
     * @endcode
     */
    static ContainerReserva &getContainerReservas();
    
    /**
     * @brief Obtém referência para o container de hóspedes
     * @return Referência para ContainerHospede
     * 
     * Usado pelos serviços de hóspede (cadastro, listagem, atualização, remoção)
     */
    static ContainerHospede &getContainerHospedes();
    
    /**
     * @brief Obtém referência para o container de hotéis
     * @return Referência para ContainerHotel
     * 
     * Usado pelos serviços de hotel (cadastro, listagem, atualização, remoção)
     */
    static ContainerHotel &getContainerHoteis();
    
    /**
     * @brief Obtém referência para o container de gerentes
     * @return Referência para ContainerGerente
     * 
     * Usado pelos serviços de gerente (cadastro, autenticação, atualização, remoção)
     */
    static ContainerGerente &getContainerGerentes();
    
    /**
     * @brief Obtém referência para o container de quartos
     * @return Referência para ContainerQuarto
     * 
     * Usado pelos serviços de quarto (cadastro, listagem, atualização, remoção)
     */
    static ContainerQuarto &getContainerQuartos();
};

/**
 * @brief Implementação inline do método getContainerReservas()
 * @return Referência para o container de reservas
 */
inline ContainerReserva &CentralContainers::getContainerReservas()
{
    return containerReservas;
}

/**
 * @brief Implementação inline do método getContainerHospedes()
 * @return Referência para o container de hóspedes
 */
inline ContainerHospede &CentralContainers::getContainerHospedes()
{
    return containerHospedes;
}

/**
 * @brief Implementação inline do método getContainerHoteis()
 * @return Referência para o container de hotéis
 */
inline ContainerHotel &CentralContainers::getContainerHoteis()
{
    return containerHoteis;
}

/**
 * @brief Implementação inline do método getContainerGerentes()
 * @return Referência para o container de gerentes
 */
inline ContainerGerente &CentralContainers::getContainerGerentes()
{
    return containerGerentes;
}

/**
 * @brief Implementação inline do método getContainerQuartos()
 * @return Referência para o container de quartos
 */
inline ContainerQuarto &CentralContainers::getContainerQuartos()
{
    return containerQuartos;
}

#endif
