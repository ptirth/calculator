#include "tokens.h"
#include <iostream>
#include <string>

std::string Token::to_string()
{
    std::string t_str = "T(";
    t_str += type;
    t_str += ",";
    t_str += std::to_string(value);
    t_str += ")";
    return t_str;
}

bool full{false};
Token buffer;

void putback(Token t)
{
    if (full)
        throw Buffer_full_error();
    buffer = t;
    full = true;
}

Token get()
{
    if (full)
    {
        full = false;
        return buffer;
    }

    char c;
    if (!(std::cin >> c))
        return Token{'q'};  // Type 'q' indicates quit signal

    switch (c)
    {
    case '+': case '-': case '*': case '/':
    case '(': case ')': case ';': case 'q':
        return Token{c};
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        std::cin.putback(c);
        double value;
        std::cin >> value;
        return Token{'8', value};  // Type '8' indicates number token
    }
    default:
        throw Bad_token_error {};
    }
}
