#include "email.hpp"
#include <stdexcept>

bool Email::validar(string email)
{

    int pos = -1;
    for (int i = 0; i < (int)email.size(); i++)
    {
        if (email[i] == '@')
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
        return false;

    string local = email.substr(0, pos);
    string dominio = email.substr(pos + 1);

    if (local.empty() || dominio.empty())
        return false;

    if (local.size() > 64 || dominio.size() > 255)
        return false;

    if (local[0] == '.' || local[0] == '-' ||
        local.back() == '.' || local.back() == '-')
        return false;

    for (int i = 0; i < (int)local.size(); i++)
    {
        char c = local[i];

        bool letraMai = (c >= 'A' && c <= 'Z');
        bool letraMin = (c >= 'a' && c <= 'z');
        bool numero = (c >= '0' && c <= '9');
        bool ponto = (c == '.');
        bool hifen = (c == '-');

        if (!(letraMai || letraMin || numero || ponto || hifen))
            return false;
    }

    if (dominio[0] == '-' || dominio.back() == '-')
        return false;

    bool temPonto = false;

    for (int i = 0; i < (int)dominio.size(); i++)
    {
        char c = dominio[i];

        bool letraMai = (c >= 'A' && c <= 'Z');
        bool letraMin = (c >= 'a' && c <= 'z');
        bool numero = (c >= '0' && c <= '9');
        bool ponto = (c == '.');
        bool hifen = (c == '-');

        if (!(letraMai || letraMin || numero || ponto || hifen))
            return false;

        if (ponto)
            temPonto = true;
    }

    if (!temPonto)
        return false;

    return true;
}

void Email::setValor(string email)
{
    if (!validar(email))
    {
        throw std::invalid_argument("Email invalido");
    }
    this->email = email;
}
