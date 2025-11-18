#ifndef EMAIL_HPP_INCLUDED
#define EMAIL_HPP_INCLUDED

#include <string>
using namespace std;

class Email
{
private:
    string email;
    bool validar(string email);

public:
    void setValor(string email);
    string getValor();
};

inline string Email::getValor()
{
    return email;
}

#endif
