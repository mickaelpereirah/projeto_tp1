/**
 * @file containerHospedes.hpp
 * @brief Definição da classe ContainerHospede para armazenamento de hóspedes
 */

#ifndef CONTAINER_HOSPEDES_HPP_INCLUDED
#define CONTAINER_HOSPEDES_HPP_INCLUDED 

#include <unordered_map>
#include <vector>
#include <string>
#include "hospede.hpp"

using namespace std;

/**
 * @class ContainerHospede
 * @brief Container para armazenar e gerenciar hóspedes do sistema
 * 
 * Esta classe implementa um container para armazenamento em memória de objetos
 * do tipo Hospede. Utiliza um unordered_map com o email do hóspede como chave,
 * garantindo acesso rápido O(1) e unicidade de emails no sistema.
 * 
 * O container é responsável por:
 * - Armazenar hóspedes de forma única (um email = um hóspede)
 * - Permitir busca eficiente por email
 * - Gerenciar inclusão, remoção e atualização de hóspedes
 * - Manter a integridade dos dados (não permite emails duplicados)
 * - Listar todos os hóspedes cadastrados no sistema
 * 
 * Diferente dos containers de Hotel e Quarto, os hóspedes não são vinculados
 * diretamente a um hotel específico no container. A associação com hotéis é
 * feita através das reservas.
 * 
 * Regras de negócio:
 * - Email: formato válido, único no sistema (chave primária)
 * - Nome: 5-20 caracteres, primeira letra maiúscula
 * - Endereço: 5-30 caracteres
 * - Cartão: 16 dígitos com validação de Luhn
 * 
 * IMPORTANTE: O container NÃO é responsável por liberar a memória dos objetos.
 * A responsabilidade de delete dos ponteiros é de quem criou os objetos.
 */
class ContainerHospede {
    private:
        /**
         * @brief Mapa hash para armazenar hóspedes
         * 
         * Chave: Email do hóspede (string)
         * Valor: Ponteiro para o objeto Hospede
         * 
         * Utiliza unordered_map para garantir O(1) nas operações de busca,
         * inserção e remoção. O email é usado como chave por ser único e
         * imutável após o cadastro.
         */
        unordered_map<string, Hospede*> container;
        
    public: 
        /**
         * @brief Inclui um novo hóspede no container
         * @param hospede Ponteiro para o hóspede a ser incluído
         * @return true se incluído com sucesso, false se o email já existe
         * 
         * O email do hóspede é usado como chave. Se já existir um hóspede
         * com o mesmo email, a operação falha e retorna false.
         * 
         * Validações que devem ser feitas ANTES de incluir:
         * - Email em formato válido
         * - Nome: 5-20 caracteres, primeira letra maiúscula
         * - Endereço: 5-30 caracteres
         * - Cartão: 16 dígitos com algoritmo de Luhn válido
         * 
         * Exemplo de uso:
         * @code
         * Hospede* h = new Hospede();
         * h->setEmail(email);
         * h->setNome(nome);
         * h->setEndereco(endereco);
         * h->setCartao(cartao);
         * if(container.incluir(h)) {
         *     cout << "Hóspede cadastrado com sucesso";
         * } else {
         *     cout << "Email já cadastrado no sistema";
         *     delete h;
         * }
         * @endcode
         */
        bool incluir(Hospede*);
        
        /**
         * @brief Remove um hóspede do container
         * @param email Email do hóspede a ser removido
         * @return true se removido com sucesso, false se não encontrado
         * 
         * ATENÇÃO: Esta operação não verifica se o hóspede possui reservas ativas.
         * O chamador deve garantir integridade referencial antes de remover,
         * verificando se há reservas associadas ao hóspede.
         * 
         * IMPORTANTE: Este método apenas remove a referência do container.
         * NÃO libera a memória do objeto. Quem chamou deve fazer delete
         * do ponteiro se necessário.
         * 
         * Exemplo de uso:
         * @code
         * Hospede* h = container.pesquisar("hospede@email.com");
         * if(h != nullptr) {
         *     // Verificar se possui reservas antes de remover
         *     if(!possuiReservasAtivas(h)) {
         *         if(container.remover("hospede@email.com")) {
         *             delete h;
         *             cout << "Hóspede removido com sucesso";
         *         }
         *     }
         * }
         * @endcode
         */
        bool remover(string);
        
        /**
         * @brief Busca um hóspede por email
         * @param email Email do hóspede a ser buscado
         * @return Ponteiro para o hóspede encontrado ou nullptr se não existir
         * 
         * Complexidade: O(1) em média devido ao uso de unordered_map
         * 
         * Exemplo de uso:
         * @code
         * Hospede* h = container.pesquisar("hospede@email.com");
         * if(h != nullptr) {
         *     cout << "Hóspede: " << h->getNome().getValor() << endl;
         *     cout << "Endereço: " << h->getEndereco().getValor() << endl;
         *     cout << "Cartão: " << h->getCartao().getValor() << endl;
         * } else {
         *     cout << "Hóspede não encontrado";
         * }
         * @endcode
         */
        Hospede *pesquisar(string);
        
        /**
         * @brief Atualiza os dados de um hóspede existente
         * @param hospede Ponteiro para o hóspede com dados atualizados
         * @return true se atualizado com sucesso, false se não encontrado
         * 
         * Busca o hóspede pelo email e substitui o ponteiro no container.
         * O email NÃO pode ser alterado (é a chave primária).
         * 
         * Pode atualizar: nome, endereço e cartão.
         * 
         * IMPORTANTE: O ponteiro antigo não é liberado. Se necessário,
         * faça delete antes de atualizar para evitar memory leak.
         * 
         * Exemplo de uso:
         * @code
         * Hospede* h = container.pesquisar("hospede@email.com");
         * if(h != nullptr) {
         *     Nome novoNome;
         *     novoNome.setValor("Novo Nome");
         *     h->setNome(novoNome);
         *     
         *     if(container.atualizar(h)) {
         *         cout << "Hóspede atualizado com sucesso";
         *     }
         * }
         * @endcode
         */
        bool atualizar(Hospede*);
        
        /**
         * @brief Lista todos os hóspedes cadastrados no sistema
         * @return Vector com ponteiros para todos os hóspedes
         * 
         * Útil para:
         * - Exibir relatórios gerais do sistema
         * - Estatísticas de hóspedes cadastrados
         * - Busca de hóspedes sem filtro de hotel
         * 
         * Se não houver hóspedes cadastrados, retorna vector vazio.
         * 
         * Exemplo de uso:
         * @code
         * vector<Hospede*> todosHospedes = container.listarTodos();
         * cout << "Total de hóspedes no sistema: " << todosHospedes.size() << endl;
         * 
         * for(Hospede* h : todosHospedes) {
         *     cout << h->getNome().getValor() << " - " 
         *          << h->getEmail().getValor() << endl;
         * }
         * @endcode
         */
        vector<Hospede*> listarTodos();
};

#endif
