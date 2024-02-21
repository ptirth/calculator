#include "tokens.h"
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
