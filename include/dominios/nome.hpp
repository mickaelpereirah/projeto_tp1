#ifndef NOME_HPP_INCLUDED
#define NOME_HPP_INCLUDED
#include <string>

using namespace std;

class Nome {
    private:
        string texto;
        bool validar(string);

    public:
        void setValor(string);
        string getValor();
};

inline string Nome::getValor(){
    return texto; 
}

#endif
