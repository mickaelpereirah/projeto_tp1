/**
 * @file containerGerentes.hpp
 * @brief Definição da classe ContainerGerente para armazenamento de gerentes
 */

#ifndef CONTAINER_GERENTES_HPP_INCLUDED
#define CONTAINER_GERENTES_HPP_INCLUDED 

#include <unordered_map>
#include <string>
#include "gerente.hpp"

using namespace std;

/**
 * @class ContainerGerente
 * @brief Container para armazenar e gerenciar gerentes do sistema
 * 
 * Esta classe implementa um container para armazenamento em memória de objetos
 * do tipo Gerente. Utiliza um unordered_map com o email do gerente como chave,
 * garantindo acesso rápido O(1) e unicidade de emails.
 * 
 * O container é responsável por:
 * - Armazenar gerentes de forma única (um email = um gerente)
 * - Permitir busca eficiente por email
 * - Gerenciar inclusão, remoção e atualização de gerentes
 * - Manter a integridade dos dados (não permite emails duplicados)
 * 
 * IMPORTANTE: O container NÃO é responsável por liberar a memória dos objetos.
 * A responsabilidade de delete dos ponteiros é de quem criou os objetos.
 */
class ContainerGerente {
    private:
        /**
         * @brief Mapa hash para armazenar gerentes
         * 
         * Chave: Email do gerente (string)
         * Valor: Ponteiro para o objeto Gerente
         * 
         * Utiliza unordered_map para garantir O(1) nas operações de busca,
         * inserção e remoção.
         */
        unordered_map<string, Gerente*> container;
        
    public: 
        /**
         * @brief Inclui um novo gerente no container
         * @param gerente Ponteiro para o gerente a ser incluído
         * @return true se incluído com sucesso, false se o email já existe
         * 
         * O email do gerente é usado como chave. Se já existir um gerente
         * com o mesmo email, a operação falha e retorna false.
         * 
         * Exemplo de uso:
         * @code
         * Gerente* g = new Gerente();
         * g->setEmail(email);
         * if(container.incluir(g)) {
         *     cout << "Gerente incluído com sucesso";
         * }
         * @endcode
         */
        bool incluir(Gerente*);
        
        /**
         * @brief Remove um gerente do container
         * @param email Email do gerente a ser removido
         * @return true se removido com sucesso, false se não encontrado
         * 
         * IMPORTANTE: Este método apenas remove a referência do container.
         * NÃO libera a memória do objeto. Quem chamou deve fazer delete
         * do ponteiro se necessário.
         * 
         * Exemplo de uso:
         * @code
         * Gerente* g = container.pesquisar("email@exemplo.com");
         * if(container.remover("email@exemplo.com")) {
         *     delete g;  // Liberar memória se necessário
         * }
         * @endcode
         */
        bool remover(string);
        
        /**
         * @brief Busca um gerente por email
         * @param email Email do gerente a ser buscado
         * @return Ponteiro para o gerente encontrado ou nullptr se não existir
         * 
         * Complexidade: O(1) em média devido ao uso de unordered_map
         * 
         * Exemplo de uso:
         * @code
         * Gerente* g = container.pesquisar("email@exemplo.com");
         * if(g != nullptr) {
         *     cout << "Gerente encontrado: " << g->getNome().getValor();
         * } else {
         *     cout << "Gerente não encontrado";
         * }
         * @endcode
         */
        Gerente *pesquisar(string);
        
        /**
         * @brief Atualiza os dados de um gerente existente
         * @param gerente Ponteiro para o gerente com dados atualizados
         * @return true se atualizado com sucesso, false se não encontrado
         * 
         * Busca o gerente pelo email e substitui o ponteiro no container.
         * O email NÃO pode ser alterado (é a chave primária).
         * 
         * IMPORTANTE: O ponteiro antigo não é liberado. Se necessário,
         * faça delete antes de atualizar para evitar memory leak.
         * 
         * Exemplo de uso:
         * @code
         * Gerente* g = container.pesquisar("email@exemplo.com");
         * g->setNome(novoNome);
         * container.atualizar(g);
         * @endcode
         */
        bool atualizar(Gerente*);
};

#endif
