#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED
#include <string>

using namespace std;

class Data{
    private:
        string data;
        bool validar(string);

    public:
        bool setValor(string);
        string getValor();
        
};

inline string Data::getValor(){
    return data; 
}

#endif 