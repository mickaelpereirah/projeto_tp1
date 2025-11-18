#ifndef DINHEIRO_HPP_INCLUDED
#define DINHEIRO_HPP_INCLUDED
#include <string>

using namespace std;

class Dinheiro
{
private:
    int valor;
    bool validar(double);

public:
    void setValor(double);
    double getValor();
};

inline double Dinheiro::getValor()
{
    return valor / 100.00;
}

#endif
