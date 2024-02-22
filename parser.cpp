#include "tokens.h"
#include "parser.h"

double primary()
{
    Token t = get();

    if (t.type == '8')
        return t.value;
    else if (t.type == '(')
        return expression();
    else
        throw Bad_expression_error();
}

double term()
{
    double left{primary()};
    while (true)
    {
        Token t = get();
        if (t.type == '*')
            left *= primary();
        if (t.type == '/')
            left /= primary();
        else
        {
            putback(t);
            break;
        }
    }
    return left;
}

double expression()
{
    double left{term()};
    while (true)
    {
        Token t = get();
        switch (t.type)
        {
        case '+':
        {
            left += term();
            break;
        }
        case '-':
        {
            left -= term();
            break;
        }
        case ';':
        case ')':
            goto end_of_exp;
        default:
            throw Bad_operator_error();
        }
    }
    end_of_exp: ;
    return left;
}
