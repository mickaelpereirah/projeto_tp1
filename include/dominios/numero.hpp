#ifndef NUMERO_HPP_INCLUDED
#define NUMERO_HPP_INCLUDED

using namespace std;

class Numero {
    private:
        int valor;
        bool validar(int);

    public:
        void setValor(int);
        int getValor();
};

inline int Numero::getValor() {
    return valor;
}

#endif