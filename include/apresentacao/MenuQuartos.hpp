#ifndef MENU_QUARTOS_HPP_INCLUDED
#define MENU_QUARTOS_HPP_INCLUDED

#include "hotel.hpp"
#include "quarto.hpp"
#include <vector>

using namespace std;

class MenuQuartos
{
public:
    static void exibir(Hotel* hotel);

private:
    static vector<Quarto*> listarQuartos(Hotel* hotel);
    static void exibirListaQuartos(vector<Quarto*> quartos);
    static void listarQuartosMenu(Hotel* hotel);
    static void verDetalhesQuarto(Hotel* hotel);
    static void mostrarDetalhesQuarto(Quarto* quarto);
    static void criarQuarto(Hotel* hotel);
    static void editarQuarto(Hotel* hotel);
    static void excluirQuarto(Hotel* hotel);
    static Quarto* selecionarQuarto(vector<Quarto*> quartos);
};

#endif
