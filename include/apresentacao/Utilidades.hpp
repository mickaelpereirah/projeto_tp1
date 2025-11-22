#ifndef UTILIDADES_HPP_INCLUDED
#define UTILIDADES_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Utilidades
 * @brief Classe com funções auxiliares para a interface de usuário
 * 
 * Fornece métodos estáticos para facilitar a interação com o usuário
 * através do terminal, incluindo limpeza de tela, pausas e formatação.
 */
class Utilidades
{
public:
    /**
     * @brief Limpa a tela do terminal
     */
    static void limparTela();

    /**
     * @brief Pausa a execução e aguarda o usuário pressionar ENTER
     * @param mensagem Mensagem a ser exibida antes da pausa (padrão: "Pressione ENTER para continuar...")
     */
    static void pausar(string mensagem = "Pressione ENTER para continuar...");

    /**
     * @brief Exibe um cabeçalho formatado
     * @param titulo Título a ser exibido no cabeçalho
     * @param largura Largura total do cabeçalho (padrão: 60)
     */
    static void mostrarCabecalho(string titulo, int largura = 60);

    /**
     * @brief Exibe uma mensagem formatada
     * @param mensagem Mensagem a ser exibida
     * @param erro Se true, exibe como erro (padrão: false)
     */
    static void mostrarMensagem(string mensagem, bool erro = false);

    /**
     * @brief Exibe uma mensagem de sucesso
     * @param mensagem Mensagem de sucesso
     */
    static void mostrarSucesso(string mensagem);

    /**
     * @brief Exibe uma mensagem de erro
     * @param mensagem Mensagem de erro
     */
    static void mostrarErro(string mensagem);

    /**
     * @brief Lê uma opção numérica do usuário dentro de um intervalo
     * @param min Valor mínimo aceito
     * @param max Valor máximo aceito
     * @return Opção válida escolhida pelo usuário
     */
    static int lerOpcao(int min, int max);

    /**
     * @brief Lê uma string do usuário
     * @param prompt Texto a ser exibido antes da entrada
     * @return String digitada pelo usuário
     */
    static string lerString(string prompt);

    /**
     * @brief Solicita confirmação do usuário (S/N)
     * @param pergunta Pergunta a ser feita
     * @return true se confirmado (S), false caso contrário (N)
     */
    static bool confirmar(string pergunta);

    /**
     * @brief Exibe uma linha separadora
     * @param caractere Caractere usado para desenhar a linha (padrão: '=')
     * @param largura Largura da linha (padrão: 60)
     */
    static void mostrarLinha(char caractere = '=', int largura = 60);
};

#endif
