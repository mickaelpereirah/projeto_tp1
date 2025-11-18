#ifndef CARTAO_HPP_INCLUDED
#define CARTAO_HPP_INCLUDED
#include <string>

using namespace std;

class Cartao{
    private:
        string digitos;
        bool validar(string);
    public:
        void setValor(string);
        string getValor();
};

inline string Cartao::getValor(){
    return digitos;
}

#endif