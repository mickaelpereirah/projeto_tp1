/**
 * @file containerReservas.hpp
 * @brief Definição da classe ContainerReserva para armazenamento de reservas
 */

#ifndef CONTAINER_RESERVAS_HPP_INCLUDED
#define CONTAINER_RESERVAS_HPP_INCLUDED

#include <unordered_map>
#include <vector>
#include <string>
#include "reserva.hpp"

using namespace std;

/**
 * @class ContainerReserva
 * @brief Container para armazenar e gerenciar reservas do sistema
 * 
 * Esta classe implementa um container complexo para armazenamento em memória
 * de objetos do tipo Reserva. Utiliza uma estrutura hierárquica de mapas
 * aninhados para permitir buscas eficientes por diferentes critérios.
 * 
 * Estrutura de dados:
 * @code
 * unordered_map<int, unordered_map<string, vector<Reserva*>>>
 *     Chave externa: número do quarto (int)
 *     Chave interna: email do hóspede (string)
 *     Valor: vector de reservas (Reserva*)
 * @endcode
 * 
 * Esta estrutura permite:
 * - Buscar todas as reservas de um quarto específico: O(1)
 * - Buscar todas as reservas de um hóspede específico: O(n) onde n = número de quartos
 * - Buscar reservas de um hóspede em um quarto: O(1)
 * - Buscar reserva por código: O(n*m) onde n = quartos, m = hóspedes
 * 
 * Características principais:
 * - Cada reserva possui código único (10 caracteres alfanuméricos)
 * - Um quarto pode ter múltiplas reservas (em períodos diferentes)
 * - Um hóspede pode ter múltiplas reservas (em quartos/períodos diferentes)
 * - Validação de conflito de datas é feita externamente
 * - Suporta operações de remoção em cascata (por quarto ou por hóspede)
 * 
 * Regras de negócio:
 * - Código: 10 caracteres alfanuméricos, único no sistema
 * - Datas: chegada < partida, formato DD-MMM-AAAA
 * - Valor: calculado automaticamente baseado no período e diária
 * - Não permite sobreposição de datas no mesmo quarto
 */
class ContainerReserva {
    private:
        /**
         * @brief Estrutura hierárquica para armazenar reservas
         * 
         * Nível 1 (mapa externo):
         *   - Chave: número do quarto (int)
         *   - Valor: mapa de hóspedes deste quarto
         * 
         * Nível 2 (mapa interno):
         *   - Chave: email do hóspede (string)
         *   - Valor: vector de reservas deste hóspede neste quarto
         * 
         * Esta estrutura facilita:
         * - Buscar todas as reservas de um quarto
         * - Buscar todas as reservas de um hóspede em um quarto específico
         * - Remover todas as reservas de um quarto (quando o quarto é excluído)
         * - Remover todas as reservas de um hóspede (quando o hóspede é excluído)
         */
        unordered_map<int, unordered_map<string, vector<Reserva*>>> container;
        
    public: 
        /**
         * @brief Inclui uma nova reserva no container
         * @param reserva Ponteiro para a reserva a ser incluída
         * @param numero_quarto Número do quarto da reserva
         * @param email_hospede Email do hóspede que fez a reserva
         * @return true se incluída com sucesso, false se o código já existe
         * 
         * O código da reserva deve ser único no sistema. Se já existir uma
         * reserva com o mesmo código, a operação falha.
         * 
         * IMPORTANTE: Esta função NÃO valida conflito de datas. O chamador
         * deve usar ValidarReserva::verificarDisponibilidade() antes de incluir.
         * 
         * Exemplo de uso:
         * @code
         * Reserva* r = new Reserva();
         * r->setCodigo(codigo);
         * r->setChegada(dataChegada);
         * r->setPartida(dataPartida);
         * r->setDinheiro(valorTotal);
         * 
         * // Validar disponibilidade primeiro
         * if(ValidarReserva::verificarDisponibilidade(101, dataChegada, dataPartida, "")) {
         *     if(container.incluir(r, 101, "hospede@email.com")) {
         *         cout << "Reserva criada com sucesso";
         *     }
         * }
         * @endcode
         */
        bool incluir(Reserva*, int numero_quarto, string email_hospede);
        
        /**
         * @brief Remove uma reserva específica do container
         * @param codigo Código da reserva a ser removida
         * @return true se removida com sucesso, false se não encontrada
         * 
         * Busca a reserva em toda a estrutura pelo código e remove.
         * 
         * IMPORTANTE: Não libera a memória do objeto Reserva. O chamador
         * deve fazer delete do ponteiro se necessário.
         * 
         * Exemplo de uso:
         * @code
         * Reserva* r = container.pesquisar("ABC1234567");
         * if(r != nullptr) {
         *     if(container.remover("ABC1234567")) {
         *         delete r;
         *         cout << "Reserva removida com sucesso";
         *     }
         * }
         * @endcode
         */
        bool remover(string codigo);
        
        /**
         * @brief Busca uma reserva específica por código
         * @param codigo Código da reserva (10 caracteres alfanuméricos)
         * @return Ponteiro para a reserva encontrada ou nullptr se não existir
         * 
         * Busca em toda a estrutura hierárquica até encontrar a reserva.
         * Complexidade: O(n*m*k) onde n = quartos, m = hóspedes, k = reservas
         * 
         * Exemplo de uso:
         * @code
         * Reserva* r = container.pesquisar("ABC1234567");
         * if(r != nullptr) {
         *     cout << "Código: " << r->getCodigo().getValor() << endl;
         *     cout << "Chegada: " << r->getChegada().getValor() << endl;
         *     cout << "Valor: R$ " << r->getDinheiro().getValor() << endl;
         * }
         * @endcode
         */
        Reserva* pesquisar(string codigo);
        
        /**
         * @brief Busca reservas de um hóspede em um quarto específico
         * @param numero_quarto Número do quarto
         * @param email_hospede Email do hóspede
         * @return Vector com as reservas encontradas
         * 
         * Útil para verificar histórico de um hóspede em um quarto.
         * Complexidade: O(1)
         */
        vector<Reserva*> pesquisar(int numero_quarto, string email_hospede);
        
        /**
         * @brief Busca todas as reservas de um quarto
         * @param numero_quarto Número do quarto
         * @return Vector com todas as reservas do quarto
         * 
         * Retorna reservas de todos os hóspedes que fizeram reservas neste quarto.
         * Útil para:
         * - Validar disponibilidade do quarto
         * - Listar ocupação do quarto
         * - Verificar conflitos de data
         * 
         * Complexidade: O(m) onde m = número de hóspedes que reservaram o quarto
         */
        vector<Reserva*> pesquisarPorQuarto(int numero_quarto);
        
        /**
         * @brief Busca todas as reservas de um hóspede
         * @param email Email do hóspede
         * @return Vector com todas as reservas do hóspede
         * 
         * Retorna reservas do hóspede em todos os quartos.
         * Útil para:
         * - Histórico de reservas do hóspede
         * - Verificar reservas ativas antes de excluir hóspede
         * - Estatísticas por hóspede
         * 
         * Complexidade: O(n*k) onde n = quartos, k = reservas por quarto
         */
        vector<Reserva*> pesquisarPorHospede(string email);
        
        /**
         * @brief Obtém lista de emails de hóspedes que têm reservas em um quarto
         * @param numero_quarto Número do quarto
         * @return Vector com emails dos hóspedes
         * 
         * Útil para listar quais hóspedes já utilizaram um quarto específico.
         */
        vector<string> pesquisarEmailsHospedesPorQuarto(int numero_quarto);
        
        /**
         * @brief Remove todas as reservas de um quarto
         * @param numero_quarto Número do quarto
         * @return true se removidas com sucesso, false se quarto não encontrado
         * 
         * Remove todas as reservas de todos os hóspedes neste quarto.
         * Utilizado quando um quarto é excluído do sistema para manter
         * integridade referencial.
         * 
         * IMPORTANTE: Não libera a memória dos objetos. O chamador deve
         * iterar pelas reservas e fazer delete de cada uma.
         * 
         * Exemplo de uso:
         * @code
         * // Antes de remover o quarto
         * vector<Reserva*> reservas = container.pesquisarPorQuarto(101);
         * container.removerTodasPorQuarto(101);
         * for(Reserva* r : reservas) {
         *     delete r;
         * }
         * @endcode
         */
        bool removerTodasPorQuarto(int numero_quarto);
        
        /**
         * @brief Remove todas as reservas de um hóspede
         * @param email Email do hóspede
         * @return true se removidas com sucesso, false se hóspede não encontrado
         * 
         * Remove todas as reservas do hóspede em todos os quartos.
         * Utilizado quando um hóspede é excluído do sistema para manter
         * integridade referencial.
         * 
         * IMPORTANTE: Não libera a memória dos objetos. O chamador deve
         * iterar pelas reservas e fazer delete de cada uma.
         */
        bool removerTodasPorHospede(string email);
        
        /**
         * @brief Atualiza os dados de uma reserva existente
         * @param reserva Ponteiro para a reserva com dados atualizados
         * @return true se atualizada com sucesso, false se não encontrada
         * 
         * Busca a reserva pelo código e substitui o ponteiro.
         * O código da reserva NÃO pode ser alterado (chave primária).
         * 
         * Pode atualizar: datas de chegada/partida e valor total.
         * 
         * IMPORTANTE: Ao alterar datas, deve-se:
         * 1. Validar nova disponibilidade com ValidarReserva
         * 2. Recalcular valor total automaticamente
         * 3. Atualizar no container
         * 
         * O ponteiro antigo não é liberado automaticamente.
         * 
         * Exemplo de uso:
         * @code
         * Reserva* r = container.pesquisar("ABC1234567");
         * if(r != nullptr) {
         *     // Alterar datas
         *     r->setChegada(novaDataChegada);
         *     r->setPartida(novaDataPartida);
         *     
         *     // Recalcular valor
         *     double novoValor = ValidarReserva::calcularValorTotal(quarto, novaChegada, novaPartida);
         *     Dinheiro d;
         *     d.setValor(novoValor);
         *     r->setDinheiro(d);
         *     
         *     container.atualizar(r);
         * }
         * @endcode
         */
        bool atualizar(Reserva*);
};

#endif
