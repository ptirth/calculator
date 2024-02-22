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
        switch (t.type)
        {
        case '*':
        {
            left *= primary();
            break;
        }
        case '/':
        {
            left /= primary();
            break;
        }
        default:
        {
            putback(t);
            goto end_of_term;
        }
        }
    }
    end_of_term: ;
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
