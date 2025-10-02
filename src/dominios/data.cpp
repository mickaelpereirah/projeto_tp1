//#include "../include/dominios/DOMINIOS.hpp"
#include "data.hpp"
#include <string>
#include <regex>

using namespace std;

bool validarData(const string data) {

    regex padrao(R"(^\d{2}-[A-Za-z]{3}-\d{4}$)");

    return regex_match(data, padrao);
}

bool validar_dia(string);
bool validar_mes(string);
bool validar_ano(string);

bool Data::validar(string data){
    if(!validarData(data)){
        return false;
    }

    // validar_ano()
    //validar_mes()
    //validar_dia()
        // se o mes for fev
            //bool e_bissextp = bissexto()



}
