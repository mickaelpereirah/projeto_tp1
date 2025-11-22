#ifndef VALIDAR_RESERVA_HPP_INCLUDED
#define VALIDAR_RESERVA_HPP_INCLUDED

#include "reserva.hpp"
#include "quarto.hpp"
#include "centralContainers.hpp"
#include <vector>

using namespace std;

/**
 * @class ValidarReserva
 * @brief Classe responsável por validações de negócio para reservas
 * 
 * Valida conflitos de datas e calcula valores automaticamente.
 */
class ValidarReserva
{
public:
    /**
     * @brief Verifica se há conflito de datas para um quarto
     * @param numero_quarto Número do quarto
     * @param chegada Data de chegada da nova reserva
     * @param partida Data de partida da nova reserva
     * @param codigo_reserva_atual Código da reserva sendo editada (opcional, para ignorar)
     * @return true se NÃO houver conflito, false se houver conflito
     */
    static bool verificarDisponibilidade(int numero_quarto, Data chegada, Data partida, string codigo_reserva_atual = "");

    /**
     * @brief Calcula o valor total da reserva baseado na diária do quarto
     * @param quarto Ponteiro para o quarto
     * @param chegada Data de chegada
     * @param partida Data de partida
     * @return Valor total calculado (número de dias * valor da diária)
     */
    static double calcularValorTotal(Quarto* quarto, Data chegada, Data partida);

    /**
     * @brief Calcula o número de dias entre duas datas
     * @param chegada Data de chegada
     * @param partida Data de partida
     * @return Número de dias
     */
    static int calcularNumeroDias(Data chegada, Data partida);

    /**
     * @brief Compara duas datas
     * @param data1 Primeira data
     * @param data2 Segunda data
     * @return -1 se data1 < data2, 0 se iguais, 1 se data1 > data2
     */
    static int compararDatas(Data data1, Data data2);

private:
    /**
     * @brief Verifica se duas reservas têm conflito de datas
     * @param chegada1 Data de chegada da reserva 1
     * @param partida1 Data de partida da reserva 1
     * @param chegada2 Data de chegada da reserva 2
     * @param partida2 Data de partida da reserva 2
     * @return true se houver conflito, false caso contrário
     */
    static bool temConflitoData(Data chegada1, Data partida1, Data chegada2, Data partida2);
};

#endif
