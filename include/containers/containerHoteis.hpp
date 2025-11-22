/**
 * @file containerHoteis.hpp
 * @brief Definição da classe ContainerHotel para armazenamento de hotéis
 */

#ifndef CONTAINER_HOTEIS_HPP_INCLUDED
#define CONTAINER_HOTEIS_HPP_INCLUDED 

#include <unordered_map>
#include <vector>
#include <string>
#include "hotel.hpp"

using namespace std;

/**
 * @class ContainerHotel
 * @brief Container para armazenar e gerenciar hotéis do sistema
 * 
 * Esta classe implementa um container para armazenamento em memória de objetos
 * do tipo Hotel. Utiliza uma estrutura de unordered_map onde a chave é o email
 * do gerente e o valor é um vector de hotéis, permitindo que cada gerente
 * possua múltiplos hotéis (relacionamento 1:N).
 * 
 * Características principais:
 * - Um gerente pode ter vários hotéis
 * - Cada hotel possui código único no sistema
 * - Busca por gerente retorna todos os seus hotéis
 * - Busca por código retorna hotel específico
 * - Permite remoção de hotel individual ou de todos os hotéis de um gerente
 * 
 * Estrutura de dados:
 * @code
 * unordered_map<string, vector<Hotel*>>
 *     Chave: email do gerente
 *     Valor: vector com todos os hotéis deste gerente
 * @endcode
 */
class ContainerHotel {
    private:
        /**
         * @brief Mapa hash para armazenar hotéis agrupados por gerente
         * 
         * Chave: Email do gerente (string)
         * Valor: Vector de ponteiros para hotéis deste gerente
         * 
         * Esta estrutura permite:
         * - Buscar todos os hotéis de um gerente em O(1)
         * - Adicionar novos hotéis a um gerente existente
         * - Remover todos os hotéis de um gerente de uma vez
         */
        unordered_map<string, vector<Hotel*>> container;
        
    public: 
        /**
         * @brief Inclui um novo hotel no container associado a um gerente
         * @param hotel Ponteiro para o hotel a ser incluído
         * @param email_gerente Email do gerente proprietário do hotel
         * @return true se incluído com sucesso, false se o código já existe
         * 
         * O código do hotel deve ser único no sistema. Se já existir um hotel
         * com o mesmo código (mesmo de outro gerente), a operação falha.
         * 
         * Se o gerente ainda não possui hotéis, cria uma nova entrada no map.
         * Caso contrário, adiciona ao vector existente.
         * 
         * Exemplo de uso:
         * @code
         * Hotel* h = new Hotel();
         * h->setCodigo(codigo);
         * h->setNome(nome);
         * if(container.incluir(h, "gerente@email.com")) {
         *     cout << "Hotel incluído com sucesso";
         * }
         * @endcode
         */
        bool incluir(Hotel*, string email_gerente);
        
        /**
         * @brief Remove um hotel específico do container
         * @param codigo Código do hotel a ser removido
         * @return true se removido com sucesso, false se não encontrado
         * 
         * Busca o hotel em todos os vetores de gerentes pelo código e remove.
         * Se era o único hotel do gerente, remove a entrada do gerente do map.
         * 
         * IMPORTANTE: Não libera a memória do objeto Hotel. O chamador deve
         * fazer delete do ponteiro se necessário.
         */
        bool remover(string codigo);
        
        /**
         * @brief Remove TODOS os hotéis de um gerente específico
         * @param email_gerente Email do gerente cujos hotéis serão removidos
         * @return true se removido com sucesso, false se gerente não encontrado
         * 
         * Útil quando um gerente é excluído do sistema - remove todos os seus
         * hotéis de uma vez para manter integridade referencial.
         * 
         * IMPORTANTE: Não libera a memória dos objetos Hotel. O chamador deve
         * iterar pelos hotéis e fazer delete de cada um se necessário.
         */
        bool removerTodosPorGerente(string email_gerente);
        
        /**
         * @brief Busca todos os hotéis de um gerente
         * @param email_gerente Email do gerente
         * @return Vector com ponteiros para todos os hotéis do gerente
         * 
         * Se o gerente não possui hotéis, retorna vector vazio.
         * Complexidade: O(1) para acessar o vector do gerente
         * 
         * Exemplo de uso:
         * @code
         * vector<Hotel*> hoteis = container.pesquisar("gerente@email.com");
         * if(hoteis.empty()) {
         *     cout << "Gerente não possui hotéis cadastrados";
         * } else {
         *     cout << "Total de hotéis: " << hoteis.size();
         * }
         * @endcode
         */
        vector<Hotel*> pesquisar(string email_gerente);
        
        /**
         * @brief Busca um hotel específico por código
         * @param codigo Código do hotel a ser buscado
         * @return Ponteiro para o hotel encontrado ou nullptr se não existir
         * 
         * Busca em todos os vetores de todos os gerentes até encontrar
         * o hotel com o código especificado.
         * Complexidade: O(n*m) onde n = número de gerentes e m = média de hotéis por gerente
         * 
         * Exemplo de uso:
         * @code
         * Hotel* h = container.pesquisarPorCodigo("HTL0001");
         * if(h != nullptr) {
         *     cout << "Hotel: " << h->getNome().getValor();
         * }
         * @endcode
         */
        Hotel* pesquisarPorCodigo(string codigo);
        
        /**
         * @brief Atualiza os dados de um hotel existente
         * @param hotel Ponteiro para o hotel com dados atualizados
         * @return true se atualizado com sucesso, false se não encontrado
         * 
         * Busca o hotel pelo código e substitui o ponteiro no vector.
         * O código do hotel NÃO pode ser alterado (é a chave primária).
         * 
         * IMPORTANTE: O ponteiro antigo não é liberado. Se necessário,
         * faça delete antes de atualizar para evitar memory leak.
         * 
         * Exemplo de uso:
         * @code
         * Hotel* h = container.pesquisarPorCodigo("HTL0001");
         * h->setNome(novoNome);
         * container.atualizar(h);
         * @endcode
         */
        bool atualizar(Hotel*);
};

#endif
