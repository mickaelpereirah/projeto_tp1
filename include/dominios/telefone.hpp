#ifndef TELEFONE_HPP_INCLUDED
#define TELEFONE_HPP_INCLUDED
#include <string>

using namespace std;

class Telefone {
    private:
        string texto;
        bool validar(string);

    public:
        void setValor(string);
        string getValor();
};

inline string Telefone::getValor() {
    return texto;
}

#endif
