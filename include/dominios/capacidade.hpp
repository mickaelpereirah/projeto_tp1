#ifndef CAPACIDADE_HPP_INCLUDED
#define CAPACIDADE_HPP_INCLUDED


class Capacidade{
    private:
        int valor;
        bool validar(int);
    public:
        bool setValor(int);
        int getValor();
};

inline int Capacidade::getValor(){
    return valor;
}


#endif