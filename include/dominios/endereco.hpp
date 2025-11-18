#ifndef ENDERECO_HPP_INCLUDED
#define ENDERECO_HPP_INCLUDED
#include <string>

using namespace std;

class Endereco{
    private:
        string texto;
        bool validar(string);

    public:
        void setValor(string);
        string getValor();
        
};

inline string Endereco::getValor(){
    return texto; 
}

#endif 