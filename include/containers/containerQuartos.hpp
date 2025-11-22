/**
 * @file containerQuartos.hpp
 * @brief Definição da classe ContainerQuarto para armazenamento de quartos
 */

#ifndef CONTAINER_QUARTOS_HPP_INCLUDED
#define CONTAINER_QUARTOS_HPP_INCLUDED 

#include <unordered_map>
#include <vector>
#include <string>
#include "quarto.hpp"

using namespace std;

/**
 * @class ContainerQuarto
 * @brief Container para armazenar e gerenciar quartos do sistema
 * 
 * Esta classe implementa um container para armazenamento em memória de objetos
 * do tipo Quarto. Utiliza uma estrutura de unordered_map onde a chave é o código
 * do hotel e o valor é um vector de quartos, permitindo que cada hotel possua
 * múltiplos quartos (relacionamento 1:N).
 * 
 * Características principais:
 * - Um hotel pode ter vários quartos
 * - Cada quarto possui número único no sistema (001-999)
 * - Busca por hotel retorna todos os seus quartos
 * - Busca por número retorna quarto específico
 * - Permite remoção de quarto individual ou de todos os quartos de um hotel
 * 
 * Estrutura de dados:
 * @code
 * unordered_map<string, vector<Quarto*>>
 *     Chave: código do hotel
 *     Valor: vector com todos os quartos deste hotel
 * @endcode
 * 
 * Regras de negócio:
 * - Número do quarto: 001 a 999
 * - Capacidade: 1, 2, 3 ou 4 pessoas
 * - Diária: 0.01 a 1.000.000,00
 * - Ramal: 00 a 50
 */
class ContainerQuarto {
    private:
        /**
         * @brief Mapa hash para armazenar quartos agrupados por hotel
         * 
         * Chave: Código do hotel (string)
         * Valor: Vector de ponteiros para quartos deste hotel
         * 
         * Esta estrutura permite:
         * - Buscar todos os quartos de um hotel em O(1)
         * - Adicionar novos quartos a um hotel existente
         * - Remover todos os quartos de um hotel de uma vez
         */
        unordered_map<string, vector<Quarto*>> container;
        
    public: 
        /**
         * @brief Inclui um novo quarto no container associado a um hotel
         * @param quarto Ponteiro para o quarto a ser incluído
         * @param codigo_hotel Código do hotel ao qual o quarto pertence
         * @return true se incluído com sucesso, false se o número já existe
         * 
         * O número do quarto deve ser único no sistema. Se já existir um quarto
         * com o mesmo número (mesmo em outro hotel), a operação falha.
         * 
         * Validações realizadas:
         * - Número do quarto único (001-999)
         * - Capacidade válida (1, 2, 3 ou 4)
         * - Diária válida (0.01 a 1.000.000,00)
         * - Ramal válido (00 a 50)
         * 
         * Se o hotel ainda não possui quartos, cria uma nova entrada no map.
         * 
         * Exemplo de uso:
         * @code
         * Quarto* q = new Quarto();
         * q->setNumero(numero);
         * q->setCapacidade(capacidade);
         * if(container.incluir(q, "HTL0001")) {
         *     cout << "Quarto incluído com sucesso";
         * }
         * @endcode
         */
        bool incluir(Quarto*, string codigo_hotel);
        
        /**
         * @brief Remove um quarto específico do container
         * @param numero Número do quarto a ser removido (001-999)
         * @return true se removido com sucesso, false se não encontrado
         * 
         * Busca o quarto em todos os vetores de hotéis pelo número e remove.
         * Se era o único quarto do hotel, remove a entrada do hotel do map.
         * 
         * ATENÇÃO: Esta operação não verifica se há reservas associadas ao quarto.
         * O chamador deve garantir integridade referencial antes de remover.
         * 
         * IMPORTANTE: Não libera a memória do objeto Quarto. O chamador deve
         * fazer delete do ponteiro se necessário.
         */
        bool remover(int numero);
        
        /**
         * @brief Remove TODOS os quartos de um hotel específico
         * @param codigo_hotel Código do hotel cujos quartos serão removidos
         * @return true se removido com sucesso, false se hotel não encontrado
         * 
         * Útil quando um hotel é excluído do sistema - remove todos os seus
         * quartos de uma vez para manter integridade referencial.
         * 
         * ATENÇÃO: Deve verificar se há reservas nos quartos antes de remover.
         * 
         * IMPORTANTE: Não libera a memória dos objetos Quarto. O chamador deve
         * iterar pelos quartos e fazer delete de cada um se necessário.
         */
        bool removerTodosPorHotel(string codigo_hotel);
        
        /**
         * @brief Busca todos os quartos de um hotel
         * @param codigo_hotel Código do hotel
         * @return Vector com ponteiros para todos os quartos do hotel
         * 
         * Se o hotel não possui quartos, retorna vector vazio.
         * Complexidade: O(1) para acessar o vector do hotel
         * 
         * Exemplo de uso:
         * @code
         * vector<Quarto*> quartos = container.pesquisar("HTL0001");
         * if(quartos.empty()) {
         *     cout << "Hotel não possui quartos cadastrados";
         * } else {
         *     cout << "Total de quartos: " << quartos.size();
         *     for(Quarto* q : quartos) {
         *         cout << "Quarto " << q->getNumero().getValor();
         *     }
         * }
         * @endcode
         */
        vector<Quarto*> pesquisar(string codigo_hotel);
        
        /**
         * @brief Busca um quarto específico por número
         * @param numero Número do quarto a ser buscado (001-999)
         * @return Ponteiro para o quarto encontrado ou nullptr se não existir
         * 
         * Busca em todos os vetores de todos os hotéis até encontrar
         * o quarto com o número especificado.
         * Complexidade: O(n*m) onde n = número de hotéis e m = média de quartos por hotel
         * 
         * Exemplo de uso:
         * @code
         * Quarto* q = container.pesquisarPorNumero(101);
         * if(q != nullptr) {
         *     cout << "Quarto " << q->getNumero().getValor();
         *     cout << " - Diária: R$ " << q->getDinheiro().getValor();
         * } else {
         *     cout << "Quarto não encontrado";
         * }
         * @endcode
         */
        Quarto* pesquisarPorNumero(int numero);
        
        /**
         * @brief Atualiza os dados de um quarto existente
         * @param quarto Ponteiro para o quarto com dados atualizados
         * @return true se atualizado com sucesso, false se não encontrado
         * 
         * Busca o quarto pelo número e substitui o ponteiro no vector.
         * O número do quarto NÃO pode ser alterado (é a chave primária).
         * 
         * Pode atualizar: capacidade, diária e ramal.
         * 
         * IMPORTANTE: O ponteiro antigo não é liberado. Se necessário,
         * faça delete antes de atualizar para evitar memory leak.
         * 
         * Exemplo de uso:
         * @code
         * Quarto* q = container.pesquisarPorNumero(101);
         * if(q != nullptr) {
         *     Capacidade novaCapacidade;
         *     novaCapacidade.setValor(4);
         *     q->setCapacidade(novaCapacidade);
         *     container.atualizar(q);
         * }
         * @endcode
         */
        bool atualizar(Quarto*);
};

#endif
