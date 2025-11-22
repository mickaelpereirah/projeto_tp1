/**
 * @file validarReserva.hpp
 * @brief Serviço de validação de reservas e cálculos de valores
 */

#ifndef VALIDAR_RESERVA_HPP_INCLUDED
#define VALIDAR_RESERVA_HPP_INCLUDED

#include "reserva.hpp"
#include "quarto.hpp"
#include "centralContainers.hpp"
#include <vector>

using namespace std;

/**
 * @class ValidarReserva
 * @brief Valida regras de negócio para reservas e calcula valores
 * 
 * **Responsabilidades:**
 * - Verificar disponibilidade de quartos
 * - Detectar conflitos de datas
 * - Calcular valores totais
 * - Validar períodos de reserva
 * 
 * **Regras de Negócio:**
 * - Quarto não pode ter reservas sobrepostas
 * - Data de chegada deve ser anterior à data de partida
 * - Valor = (número de dias) × (diária do quarto)
 * - Mínimo de 1 dia de reserva
 */
class ValidarReserva
{
public:
    /**
     * @brief Verifica se há conflito de datas para um quarto
     * @param numero_quarto Número do quarto a ser verificado
     * @param chegada Data de chegada da nova reserva
     * @param partida Data de partida da nova reserva
     * @param codigo_reserva_atual Código da reserva sendo editada (ignora na verificação)
     * @return true se NÃO houver conflito (quarto disponível), false se houver conflito
     * 
     * **Lógica de Conflito:**
     * Duas reservas conflitam se houver sobreposição de datas:
     * - Nova reserva inicia durante reserva existente
     * - Nova reserva termina durante reserva existente
     * - Nova reserva engloba completamente reserva existente
     * 
     * **Exemplo de Conflito:**
     * @code
     * Reserva Existente: 10/01 até 15/01
     * Nova Reserva:      12/01 até 17/01  → CONFLITO
     * Nova Reserva:      08/01 até 12/01  → CONFLITO
     * Nova Reserva:      09/01 até 16/01  → CONFLITO
     * Nova Reserva:      16/01 até 20/01  → SEM CONFLITO (checkout/checkin mesmo dia)
     * @endcode
     * 
     * **Exemplo de uso:**
     * @code
     * if(ValidarReserva::verificarDisponibilidade(101, Data(10,1,2025), Data(15,1,2025))) {
     *     cout << "Quarto disponível para reserva!" << endl;
     * } else {
     *     cout << "Quarto indisponível neste período!" << endl;
     * }
     * @endcode
     */
    static bool verificarDisponibilidade(int numero_quarto, Data chegada, Data partida, string codigo_reserva_atual = "");

    /**
     * @brief Calcula o valor total da reserva baseado na diária do quarto
     * @param quarto Ponteiro para o quarto
     * @param chegada Data de chegada
     * @param partida Data de partida
     * @return double Valor total (número de dias × valor da diária)
     * 
     * **Fórmula:**
     * Valor Total = calcularNumeroDias(chegada, partida) × quarto->getDiaria()
     * 
     * **Exemplo de uso:**
     * @code
     * Quarto* q = container.pesquisar(101); // diária = R$ 150,00
     * Data chegada(10, 1, 2025);
     * Data partida(13, 1, 2025); // 3 dias
     * double valor = ValidarReserva::calcularValorTotal(q, chegada, partida);
     * cout << "Valor total: R$ " << valor << endl; // R$ 450,00
     * @endcode
     */
    static double calcularValorTotal(Quarto* quarto, Data chegada, Data partida);

    /**
     * @brief Calcula o número de dias entre duas datas
     * @param chegada Data de chegada (data inicial)
     * @param partida Data de partida (data final)
     * @return int Número de dias (partida - chegada)
     * 
     * **Implementação:**
     * - Converte datas para dias julianos ou timestamp
     * - Calcula diferença absoluta
     * - Retorna número inteiro de dias
     * 
     * **Exemplo de uso:**
     * @code
     * Data chegada(10, 1, 2025);
     * Data partida(13, 1, 2025);
     * int dias = ValidarReserva::calcularNumeroDias(chegada, partida);
     * cout << "Período: " << dias << " dia(s)" << endl; // 3 dias
     * @endcode
     */
    static int calcularNumeroDias(Data chegada, Data partida);

    /**
     * @brief Compara duas datas (ordem cronológica)
     * @param data1 Primeira data
     * @param data2 Segunda data
     * @return int -1 se data1 < data2, 0 se iguais, 1 se data1 > data2
     * 
     * **Uso:**
     * - Validar ordem de datas (chegada antes de partida)
     * - Ordenar reservas cronologicamente
     * - Verificar períodos válidos
     * 
     * **Exemplo de uso:**
     * @code
     * Data d1(10, 1, 2025);
     * Data d2(15, 1, 2025);
     * int resultado = ValidarReserva::compararDatas(d1, d2);
     * if(resultado == -1) {
     *     cout << "d1 é anterior a d2" << endl;
     * }
     * @endcode
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
     * 
     * **Lógica de Conflito:**
     * Duas reservas conflitam se:
     * - (chegada2 >= chegada1 && chegada2 < partida1) OU
     * - (partida2 > chegada1 && partida2 <= partida1) OU
     * - (chegada2 <= chegada1 && partida2 >= partida1)
     * 
     * **Casos Cobertos:**
     * 1. Sobreposição no início
     * 2. Sobreposição no fim
     * 3. Sobreposição total (engloba completamente)
     * 4. Checkout/checkin no mesmo dia = SEM CONFLITO
     */
    static bool temConflitoData(Data chegada1, Data partida1, Data chegada2, Data partida2);
};

#endif // VALIDAR_RESERVA_HPP_INCLUDED
