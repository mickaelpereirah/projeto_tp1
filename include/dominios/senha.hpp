#ifndef SENHA_HPP_INCLUDED
#define SENHA_HPP_INCLUDED
#include <string>

using namespace std;

class Senha {
    private:
        string texto;
        bool validar(string);

    public:
        void setValor(string);
        string getValor();
};

inline string Senha::getValor() {
    return texto;
}

#endif