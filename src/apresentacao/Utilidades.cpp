#include "Utilidades.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

void Utilidades::limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Utilidades::pausar(string mensagem)
{
    cout << endl << mensagem;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Utilidades::mostrarCabecalho(string titulo, int largura)
{
    mostrarLinha('=', largura);
    
    // Centralizar o título
    int espacos = (largura - titulo.length()) / 2;
    for (int i = 0; i < espacos; i++)
        cout << " ";
    
    cout << titulo << endl;
    mostrarLinha('=', largura);
}

void Utilidades::mostrarMensagem(string mensagem, bool erro)
{
    if (erro)
    {
        cout << endl << "[ERRO] " << mensagem << endl;
    }
    else
    {
        cout << endl << mensagem << endl;
    }
}

void Utilidades::mostrarSucesso(string mensagem)
{
    cout << endl << "[SUCESSO] " << mensagem << endl;
}

void Utilidades::mostrarErro(string mensagem)
{
    cout << endl << "[ERRO] " << mensagem << endl;
}

int Utilidades::lerOpcao(int min, int max)
{
    int opcao;
    string input;
    
    while (true)
    {
        cout << endl << "Escolha uma opcao (" << min << "-" << max << "): ";
        getline(cin, input);
        
        try
        {
            opcao = stoi(input);
            
            if (opcao >= min && opcao <= max)
            {
                return opcao;
            }
            else
            {
                mostrarErro("Opcao invalida! Digite um numero entre " + to_string(min) + " e " + to_string(max) + ".");
            }
        }
        catch (const invalid_argument &)
        {
            mostrarErro("Entrada invalida! Digite um numero.");
        }
        catch (const out_of_range &)
        {
            mostrarErro("Numero muito grande! Digite um numero entre " + to_string(min) + " e " + to_string(max) + ".");
        }
    }
}

string Utilidades::lerString(string prompt)
{
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

bool Utilidades::confirmar(string pergunta)
{
    string resposta;
    
    while (true)
    {
        cout << endl << pergunta << " (S/N): ";
        getline(cin, resposta);
        
        if (resposta == "S" || resposta == "s")
        {
            return true;
        }
        else if (resposta == "N" || resposta == "n")
        {
            return false;
        }
        else
        {
            mostrarErro("Resposta invalida! Digite S para Sim ou N para Nao.");
        }
    }
}

void Utilidades::mostrarLinha(char caractere, int largura)
{
    for (int i = 0; i < largura; i++)
        cout << caractere;
    cout << endl;
}
