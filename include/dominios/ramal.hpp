#ifndef RAMAL_HPP_INCLUDED
#define RAMAL_HPP_INCLUDED

using namespace std;

class Ramal {
    private:
        int valor;
        bool validar(int);

    public:
        void setValor(int);
        int getValor();
};

inline int Ramal::getValor() {
    return valor;
}

#endif