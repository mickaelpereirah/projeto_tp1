/**
 * @file Arquitetura.hpp
 * @brief Documentação da Arquitetura do Sistema de Gestão Hoteleira
 * @author Sistema de Gestão Hoteleira
 * @date 2025-11-23
 *
 * @mainpage Sistema de Gestão de Hotéis - Modelo de Arquitetura em Camadas
 *
 * @section intro_arquitetura Introdução
 *
 * Este projeto implementa um **Sistema de Gestão de Hotéis** seguindo o padrão
 * arquitetural em **3 camadas** (Three-Tier Architecture), garantindo separação
 * clara de responsabilidades e baixo acoplamento entre módulos.
 *
 * @section diagrama_principal Diagrama da Arquitetura
 *
 * O diagrama a seguir apresenta a estrutura completa do sistema em camadas:
 *
 * @image html diagrama_projetoTp1.jpeg "Arquitetura em Camadas - Sistema de Gestão Hoteleira" width=800px
 *
 * @section camadas_sistema Descrição das Camadas
 *
 * @subsection camada_apresentacao CAMADA DE APRESENTAÇÃO
 *
 * **Propósito:** Interface com o usuário e controle de fluxo da aplicação
 *
 * **Módulos:**
 * - **main:** Ponto de entrada da aplicação
 * - **CAI:** Caso de Uso Interface - Controla navegação principal
 * - **CAA:** Caso de Uso Autenticação Administrador
 * - **CAP:** Caso de Uso Cadastro Gerente
 * - **CAH:** Caso de Uso Cadastro Hotel
 * - **CAQ:** Caso de Uso Cadastro Quarto
 * - **CAHO:** Caso de Uso Cadastro Hóspede
 * - **CAR:** Caso de Uso Cadastro Reserva
 *
 * **Interface Principal:**
 * - **IAP:** Interface de Apresentação Principal - Define contrato comum
 *
 * @subsection camada_servicos CAMADA DE SERVIÇOS
 *
 * **Propósito:** Implementação da lógica de negócio e regras do domínio
 *
 * **Interfaces de Serviços:**
 * - **ISA:** Interface Serviço Autenticação
 * - **ISP:** Interface Serviço Persistência Gerente
 * - **ISH:** Interface Serviço Persistência Hotel
 * - **ISQ:** Interface Serviço Persistência Quarto
 * - **ISHO:** Interface Serviço Persistência Hóspede
 * - **ISR:** Interface Serviço Persistência Reserva
 *
 * **Centrais de Serviços:**
 * - **CSA:** Central de Serviços de Autenticação
 * - **CSP:** Central de Serviços de Persistência Gerente
 * - **CSH:** Central de Serviços de Persistência Hotel
 * - **CSQ:** Central de Serviços de Persistência Quarto
 * - **CSHO:** Central de Serviços de Persistência Hóspede
 * - **CSR:** Central de Serviços de Persistência Reserva
 *
 * @subsection camada_persistencia CAMADA DE PERSISTÊNCIA
 *
 * **Propósito:** Armazenamento e gerenciamento de dados em memória
 *
 * **Containers Especializados:**
 * - **Gerentes:** Armazena dados de gerentes do sistema
 * - **Hotéis:** Gerencia informações dos hotéis cadastrados
 * - **Quartos:** Controla quartos disponíveis em cada hotel
 * - **Hóspedes:** Mantém registro de hóspedes cadastrados
 * - **Reservas:** Gerencia reservas com controle de conflitos
 *
 * @section principios_arquiteturais Princípios Arquiteturais Aplicados
 *
 * @subsection separacao_responsabilidades Separação de Responsabilidades
 *
 * Cada camada possui responsabilidades específicas e bem definidas:
 * - **Apresentação:** Gerencia interface e experiência do usuário
 * - **Serviços:** Implementa regras de negócio e validações
 * - **Persistência:** Controla armazenamento e recuperação de dados
 *
 * @subsection baixo_acoplamento Baixo Acoplamento
 *
 * As camadas comunicam-se através de interfaces abstratas:
 * - Reduz dependências diretas entre módulos
 * - Facilita testes unitários e uso de mocks
 * - Permite evolução independente das camadas
 *
 * @subsection alta_coesao Alta Coesão
 *
 * Módulos da mesma camada têm propósitos relacionados:
 * - Funcionalidades agrupadas logicamente
 * - Reutilização de código comum
 * - Manutenção simplificada
 *
 * @section fluxo_operacional Fluxo Operacional
 *
 * @subsection fluxo_dados Fluxo de Dados
 *
 * 1. **Usuário** interage com **Camada de Apresentação**
 * 2. **Casos de Uso** delegam para **Interfaces de Serviços**
 * 3. **Centrais de Serviços** implementam lógica de negócio
 * 4. **Containers** persistem dados na **Camada de Persistência**
 * 5. **Resultado** retorna pelas camadas até o usuário
 *
 * @subsection relacionamentos_entidades Relacionamentos de Entidades
 *
 * **Multiplicidades do Domínio:**
 * - Gerente (1) ↔ Hotel (0..*)
 * - Hotel (1) ↔ Quarto (1..*)
 * - Hóspede (1) ↔ Reserva (0..*)
 * - Quarto (1) ↔ Reserva (0..*)
 *
 * @section padroes_utilizados Padrões de Projeto
 *
 * @subsection singleton_pattern Singleton
 * - **Classe:** CentralContainers
 * - **Propósito:** Acesso único e centralizado aos containers
 * - **Benefício:** Controle unificado do armazenamento de dados
 *
 * @subsection interface_segregation Interface Segregation Principle (ISP)
 * - **Classes:** IAP, ISA, ISP, ISH, ISQ, ISHO, ISR
 * - **Propósito:** Interfaces específicas e focadas
 * - **Benefício:** Maior flexibilidade e facilidade de teste
 *
 * @subsection dependency_inversion Dependency Inversion Principle (DIP)
 * - **Aplicação:** Camadas superiores dependem de abstrações
 * - **Benefício:** Facilita mudanças e extensões no sistema
 *
 * @section conclusao Conclusão
 *
 * A arquitetura em camadas implementada garante um sistema robusto,
 * organizando responsabilidades de forma clara e permitindo evolução
 * controlada. O uso de interfaces abstratas e padrões de projeto
 * consolidados assegura flexibilidade e facilidade de manutenção.
 */

#ifndef ARQUITETURA_HPP_INCLUDED
#define ARQUITETURA_HPP_INCLUDED

// Este arquivo serve apenas para documentação da arquitetura
// As implementações reais estão nos respectivos módulos do sistema

#endif // ARQUITETURA_HPP_INCLUDED