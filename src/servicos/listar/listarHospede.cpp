#include "listar/listarHospede.hpp"

using namespace std;

// SOLUÇÃO 1: Lista TODOS os hóspedes cadastrados no sistema
vector<Hospede*> ListarHospede::listar_todos_hospedes()
{
    return CentralContainers::getContainerHospedes().listarTodos();
}

// SOLUÇÃO 2: Lista apenas hóspedes que TEM RESERVAS em um hotel específico
vector<Hospede*> ListarHospede::listar_hospedes_por_hotel(Hotel* hotel)
{
    vector<Hospede*> resultado;
    set<string> emails_unicos;  // Para evitar hóspedes duplicados
    
    // Obter todos os quartos do hotel
    vector<Quarto*> quartos = ListarQuarto::listar_quartos(hotel);
    
    // Para cada quarto, buscar os emails dos hóspedes que têm reservas
    for (Quarto* quarto : quartos)
    {
        int numero_quarto = quarto->getNumero().getValor();
        vector<string> emails_quarto = CentralContainers::getContainerReservas().pesquisarEmailsHospedesPorQuarto(numero_quarto);
        
        // Adicionar os emails ao set para garantir unicidade
        for (string email : emails_quarto)
        {
            emails_unicos.insert(email);
        }
    }
    
    // Buscar cada hóspede pelo email e adicionar ao resultado
    for (string email : emails_unicos)
    {
        Hospede* hospede = CentralContainers::getContainerHospedes().pesquisar(email);
        if (hospede != nullptr)
        {
            resultado.push_back(hospede);
        }
    }
    
    return resultado;
}

// Método padrão - usa Solução 1 (todos os hóspedes)
vector<Hospede*> ListarHospede::listar_hospedes(Hotel* hotel)
{
    return listar_todos_hospedes();
}
