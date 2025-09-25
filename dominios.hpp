#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

using namespace std;


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

class Cartao{
    private:
        string digitos;
        bool validar(string);
    public:
        bool setValor(string);
        string getValor();
};

inline string Cartao::getValor(){
    return digitos;
}


class Caracteres{
    private:
        string caracteres;
        bool validar(string);
    public:
        bool setValor(string);
        string getValor();
};

inline string Caracteres::getValor(){
    return caracteres;
}

class Email{
    private:
        string email;
        bool validar(string);
    public:
        bool setValor(string);
        string getValor();
};

inline string Email::getValor(){
    return email;
}
#endif // DOMINIOS_HPP_INCLUDED
