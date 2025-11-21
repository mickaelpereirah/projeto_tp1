#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "DOMINIOS.hpp"
#include "cadastro/cadastroGerente.hpp"
#include "cadastro/cadastroHotel.hpp"
#include "cadastro/cadastroQuarto.hpp"
#include "cadastro/cadastroHospede.hpp"
#include "cadastro/cadastroReserva.hpp"
#include "centralContainers.hpp"
#include "listar/listarHotel.hpp"

using namespace std;

int main()
{
    cout << "========== TESTE COMPLETO ==========" << endl;
    cout << endl;

    // 1. Criar um gerente
    cout << ">>> PASSO 1: Criando gerente..." << endl;
    CadastroGerente cadastro_gerente;
    cadastro_gerente.novo_gerente();

    // Obter o gerente criado (precisamos do email para buscar)
    // Vamos assumir que o usuário digitou um email, então vamos usar o primeiro gerente do container
    // Na prática, você salvaria o email durante o cadastro
    Gerente* gerente = nullptr;
    // Por simplicidade, vamos criar o gerente manualmente para ter controle do email
    gerente = cadastro_gerente.criar_gerente();
    string email_gerente = gerente->getEmail().getValor();
    CentralContainers::getContainerGerentes().incluir(gerente);
    cout << "Gerente criado com email: " << email_gerente << endl;
    cout << endl;

    // 2. Criar dois hotéis para esse gerente
    cout << ">>> PASSO 2: Criando primeiro hotel..." << endl;
    CadastroHotel cadastro_hotel;
    Hotel* hotel1 = cadastro_hotel.criar_hotel();
    string codigo_hotel1 = hotel1->getCodigo().getValor();
    CentralContainers::getContainerHoteis().incluir(hotel1, email_gerente);
    cout << "Hotel 1 criado com código: " << codigo_hotel1 << endl;
    cout << endl;

    cout << ">>> PASSO 3: Criando segundo hotel..." << endl;
    Hotel* hotel2 = cadastro_hotel.criar_hotel();
    string codigo_hotel2 = hotel2->getCodigo().getValor();
    CentralContainers::getContainerHoteis().incluir(hotel2, email_gerente);
    cout << "Hotel 2 criado com código: " << codigo_hotel2 << endl;
    cout << endl;

    // 3. Criar um quarto em cada hotel
    cout << ">>> PASSO 4: Criando quarto no primeiro hotel..." << endl;
    CadastroQuarto cadastro_quarto;
    Quarto* quarto1 = cadastro_quarto.criar_quarto();
    int numero_quarto1 = quarto1->getNumero().getValor();
    CentralContainers::getContainerQuartos().incluir(quarto1, codigo_hotel1);
    cout << "Quarto 1 criado com número: " << numero_quarto1 << " no hotel " << codigo_hotel1 << endl;
    cout << endl;

    cout << ">>> PASSO 5: Criando quarto no segundo hotel..." << endl;
    Quarto* quarto2 = cadastro_quarto.criar_quarto();
    int numero_quarto2 = quarto2->getNumero().getValor();
    CentralContainers::getContainerQuartos().incluir(quarto2, codigo_hotel2);
    cout << "Quarto 2 criado com número: " << numero_quarto2 << " no hotel " << codigo_hotel2 << endl;
    cout << endl;

    // 4. Criar um hóspede
    cout << ">>> PASSO 6: Criando hóspede..." << endl;
    CadastroHospede cadastro_hospede;
    Hospede* hospede = cadastro_hospede.criar_hospede();
    string email_hospede = hospede->getEmail().getValor();
    CentralContainers::getContainerHospedes().incluir(hospede);
    cout << "Hóspede criado com email: " << email_hospede << endl;
    cout << endl;

    // 5. Criar uma reserva para cada quarto (mesmo hóspede, datas diferentes)
    cout << ">>> PASSO 7: Criando primeira reserva (quarto 1)..." << endl;
    CadastroReserva cadastro_reserva;
    Reserva* reserva1 = cadastro_reserva.criar_reserva();
    string codigo_reserva1 = reserva1->getCodigo().getValor();
    CentralContainers::getContainerReservas().incluir(reserva1, numero_quarto1, email_hospede);
    cout << "Reserva 1 criada com código: " << codigo_reserva1 << " para quarto " << numero_quarto1 << endl;
    cout << "Data chegada: " << reserva1->getChegada().getValor() << endl;
    cout << "Data partida: " << reserva1->getPartida().getValor() << endl;
    cout << endl;

    cout << ">>> PASSO 8: Criando segunda reserva (quarto 2)..." << endl;
    Reserva* reserva2 = cadastro_reserva.criar_reserva();
    string codigo_reserva2 = reserva2->getCodigo().getValor();
    CentralContainers::getContainerReservas().incluir(reserva2, numero_quarto2, email_hospede);
    cout << "Reserva 2 criada com código: " << codigo_reserva2 << " para quarto " << numero_quarto2 << endl;
    cout << "Data chegada: " << reserva2->getChegada().getValor() << endl;
    cout << "Data partida: " << reserva2->getPartida().getValor() << endl;
    cout << endl;

    // 6. Verificar os dados criados
    cout << "========== VERIFICAÇÃO FINAL ==========" << endl;
    cout << endl;

    cout << "Gerente: " << gerente->getNome().getValor() << " (" << email_gerente << ")" << endl;
    vector<Hotel*> hoteis_gerente = ListarHotel::listar_hoteis(gerente);
    cout << "Hotéis do gerente: " << hoteis_gerente.size() << endl;
    for (Hotel* h : hoteis_gerente) {
        cout << "  - " << h->getNome().getValor() << " (" << h->getCodigo().getValor() << ")" << endl;
    }
    cout << endl;

    cout << "Quartos do hotel 1: " << endl;
    vector<Quarto*> quartos_hotel1 = CentralContainers::getContainerQuartos().pesquisar(codigo_hotel1);
    for (Quarto* q : quartos_hotel1) {
        cout << "  - Quarto " << q->getNumero().getValor() << endl;
    }
    cout << endl;

    cout << "Quartos do hotel 2: " << endl;
    vector<Quarto*> quartos_hotel2 = CentralContainers::getContainerQuartos().pesquisar(codigo_hotel2);
    for (Quarto* q : quartos_hotel2) {
        cout << "  - Quarto " << q->getNumero().getValor() << endl;
    }
    cout << endl;

    cout << "Reservas do hóspede " << email_hospede << ": " << endl;
    vector<Reserva*> reservas_hospede = CentralContainers::getContainerReservas().pesquisarPorHospede(email_hospede);
    for (Reserva* r : reservas_hospede) {
        cout << "  - Reserva " << r->getCodigo().getValor()
             << " (Chegada: " << r->getChegada().getValor()
             << ", Partida: " << r->getPartida().getValor() << ")" << endl;
    }
    cout << endl;

    cout << "========== TESTE CONCLUÍDO ==========" << endl;

    return 0;
}
