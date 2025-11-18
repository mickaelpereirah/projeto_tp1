#ifndef CODIGO_HPP_INCLUDED
#define CODIGO_HPP_INCLUDED
#include <string>

using namespace std;

class Codigo{
    private:
        string caracteres;
        bool validar(string);
    public:
        void setValor(string);
        string getValor();
};

inline string Codigo::getValor(){
    return caracteres;
}

#endif