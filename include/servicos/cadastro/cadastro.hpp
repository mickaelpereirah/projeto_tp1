/**
 * @file cadastro.hpp
 * @brief Definição da classe base Cadastro para entrada de dados via terminal
 */

#ifndef CADASTRO_HPP_INCLUDED
#define CADASTRO_HPP_INCLUDED

#include <unordered_map>
#include <string>
#include "DOMINIOS.hpp"

using namespace std;

/**
 * @class Cadastro
 * @brief Classe base com métodos auxiliares para entrada de dados dos domínios
 * 
 * Esta classe fornece métodos para solicitar e validar entrada de dados do usuário
 * via terminal para todos os domínios do sistema. Cada método solicita o dado,
 * valida e retorna um objeto do domínio correspondente já validado.
 * 
 * É utilizada como classe base por outras classes de serviço que necessitam
 * coletar dados do usuário (cadastro, atualização, etc.).
 * 
 * **CARACTERÍSTICAS:**
 * - Solicita dados via terminal (cin/cout)
 * - Valida entrada usando regras dos domínios
 * - Repete solicitação até entrada válida
 * - Exibe mensagens de erro amigáveis
 * - Retorna objetos já validados
 * 
 * **PADRÃO DE USO:**
 * Todas as classes que herdam de Cadastro podem usar estes métodos
 * para coletar dados do usuário de forma consistente e validada.
 */
class Cadastro
{
public:
    /**
     * @brief Solicita e cria um objeto Capacidade válido
     * @return Capacidade Objeto validado (1, 2, 3 ou 4)
     * 
     * Solicita ao usuário digitar um valor de capacidade.
     * Repete até receber valor válido (1, 2, 3 ou 4).
     */
    Capacidade criar_capacidade();
    
    /**
     * @brief Solicita e cria um objeto Cartao válido
     * @return Cartao Objeto validado (16 dígitos + Luhn)
     * 
     * Solicita ao usuário digitar número de cartão.
     * Valida formato (16 dígitos) e algoritmo de Luhn.
     * Repete até receber cartão válido.
     */
    Cartao criar_cartao();
    
    /**
     * @brief Solicita e cria um objeto Codigo válido
     * @return Codigo Objeto validado (10 caracteres alfanuméricos)
     * 
     * Solicita ao usuário digitar código.
     * Valida 10 caracteres alfanuméricos (a-z, 0-9).
     * Repete até receber código válido.
     */
    Codigo criar_codigo();
    
    /**
     * @brief Solicita e cria um objeto Dinheiro válido
     * @return Dinheiro Objeto validado (0.01 a 1.000.000,00)
     * 
     * Solicita ao usuário digitar valor monetário.
     * Valida intervalo (0.01 a 1.000.000,00).
     * Repete até receber valor válido.
     */
    Dinheiro criar_dinheiro();
    
    /**
     * @brief Solicita e cria um objeto Email válido
     * @return Email Objeto validado (formato local@dominio)
     * 
     * Solicita ao usuário digitar email.
     * Valida formato (parte local e domínio).
     * Repete até receber email válido.
     */
    Email criar_email();
    
    /**
     * @brief Solicita e cria um objeto Endereco válido
     * @return Endereco Objeto validado (5-30 caracteres)
     * 
     * Solicita ao usuário digitar endereço.
     * Valida comprimento e caracteres permitidos.
     * Repete até receber endereço válido.
     */
    Endereco criar_endereco();
    
    /**
     * @brief Solicita e cria um objeto Nome válido
     * @return Nome Objeto validado (5-20 caracteres, capitalizado)
     * 
     * Solicita ao usuário digitar nome.
     * Valida comprimento e capitalização.
     * Repete até receber nome válido.
     */
    Nome criar_nome();
    
    /**
     * @brief Solicita e cria um objeto Numero válido
     * @return Numero Objeto validado (001-999)
     * 
     * Solicita ao usuário digitar número de quarto.
     * Valida intervalo (1 a 999).
     * Repete até receber número válido.
     */
    Numero criar_numero();
    
    /**
     * @brief Solicita e cria um objeto Ramal válido
     * @return Ramal Objeto validado (00-50)
     * 
     * Solicita ao usuário digitar ramal.
     * Valida intervalo (0 a 50).
     * Repete até receber ramal válido.
     */
    Ramal criar_ramal();
    
    /**
     * @brief Solicita e cria um objeto Senha válido
     * @return Senha Objeto validado (5 caracteres com requisitos)
     * 
     * Solicita ao usuário digitar senha.
     * Valida comprimento e requisitos de segurança.
     * Repete até receber senha válida.
     */
    Senha criar_senha();
    
    /**
     * @brief Solicita e cria um objeto Telefone válido
     * @return Telefone Objeto validado (+14 dígitos)
     * 
     * Solicita ao usuário digitar telefone internacional.
     * Valida formato (+DDDDDDDDDDDDDD).
     * Repete até receber telefone válido.
     */
    Telefone criar_telefone();
};

#endif // CADASTRO_HPP_INCLUDED
